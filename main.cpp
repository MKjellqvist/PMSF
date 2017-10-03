/* 
 * File:   main.cpp
 * Author: Martin Kjellqvist <martin.kjellqvist@miun.se>
 *
 * Created on October 3, 2017, 5:08 PM
 */

#include <cstdlib>

#include <vector>
#include <queue>
#include <limits>
#include <sstream>

#include "graph.h"

using namespace adjacency_list_graph;

using edgelist = std::vector<edge>;

edgelist algorithm2(graph* G, int list_start, int list_end, std::vector<int>& color,
        std::vector<int>& visited) {
    edgelist edges = G->get_adjacency_list(list_start, list_end);
    std::priority_queue<edge> H;
    edgelist MST;

    for (auto v : edges) {
        if (color[v])
            continue;
        auto my_color = color[v] = v + 1;
        H.push(v);
        while (H.size()) {
            auto w = H.top();
            H.pop();
            if (color[w] != my_color)
                break;
            bool off_colored_neibour = false;
            for (auto u : G->get_vertex(w).get_neighbors()) {
                if (color[u] != 0 && color[u] != my_color) {
                    off_colored_neibour = true;
                }
            }
            if (off_colored_neibour)
                break;
            if (!visited[w]) {
                visited[w] = true;
            }
            MST.push_back(w);
            bool replaced_w = false;
            for (auto neighbor : G->get_vertex(w).get_neighbors()) {
                if (!color[neighbor])
                    color[neighbor] = my_color;
                std::priority_queue<edge> replace_w;
                while (H.size()) {
                    auto h_u = H.top();
                    H.pop();
                    if (h_u.second == neighbor.second
                            && h_u.weight > neighbor.weight) {
                        replace_w.push(neighbor);
                        replaced_w = true;
                    } else {
                        replace_w.push(h_u);
                    }
                }
                H.swap(replace_w);
                if (!replaced_w)
                    H.push(neighbor);
            }
        }
    }
}
int p = 1;

edgelist algorithm1(graph* G, int baseN) {
    auto n = G->get_vertexes().size();
    std::vector<int> visited(n);
    std::vector<int> color(n);
    edgelist MSF;
    for (int i = 0; i < p; i++) {
        while (n > baseN) {
            // initialization, don't think this is needed.
            int startI = i * n / p;
            int endI = (i+1) * n / p -1;
            for (int i = startI; i <= endI; i++ ){
                visited[i] = color[i] = 0;
            }
            
            auto mst_list = algorithm2(G, startI, endI + 1, color, visited);
            
            edgelist MST;
            
            for (int i = startI; i <= endI; i++ ){
                if(!visited[i]){
                    // Find lightest incident edge
                    edge min_edge;
                    min_edge.weight = std::numeric_limits<double>::max();
                    
                    for(auto e: mst_list){
                        if(e.second == i &&  e.weight < min_edge.weight){
                            min_edge = e;
                        }
                    }
                    
                    if(min_edge.weight < std::numeric_limits<double>::max())
                        MST.push_back(min_edge);
                }
            }
            
            
        }
    }
}
std::string graph_string = R"smurf(
        1 2 7
        2 1 7
        2 3 11
        3 2 11
        1 4 4
        4 1 4
        2 4 9
        4 2 9
        2 5 10
        5 2 10
        4 5 15
        5 4 15
        4 6 6
        6 1 6
        5 6 12
        6 5 12
        5 7 8
        7 5 8
        6 7 13
        7 6 13
)smurf";

int main(int argc, char** argv) {
    std::stringstream is(graph_string);
    graph g = read_adjacency_list(is);
    algorithm1(&g, 4);
    return 0;
}

