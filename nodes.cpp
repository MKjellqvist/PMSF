/* 
 * File:   nodes.cpp
 * Author: Martin Kjellqvist <martin.kjellqvist@miun.se>
 *
 * Created on October 3, 2017, 5:10 PM
 */

#include "nodes.h"

#include "graph.h"

namespace adjacency_list_graph {

    bool operator<(const edge& lhs, const edge& rhs) {
        return lhs.weight < rhs.weight;
    }

    edge::operator int() {
        return source();
    }

    int edge::source() {
        return first;
    }
    
    std::ostream& operator <<(std::ostream& o, const edge& e){
        return o << e.first << " > " << e.second << " : " << e.weight << "\n";
    }
    
    std::vector<edge> vertex::get_neighbors() {
        std::vector<edge> result;
        for(auto e : owner->adjacency_list){
            if (e.source() == this->index){
                result.push_back(e);
            }
        }
        return result;
    }

    vertex::vertex(const graph* g, int i):owner(g), index(i) {
        
    }
    
    int vertex::get_index() const{
            return index;
    }
    bool vertex::operator<(const vertex& rhs) const{
        return index < rhs.index;
    }

    
    std::ostream& operator <<(std::ostream& o, const vertex& v){
        return o << v.get_index() << "\n";
    }
}

