/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   graph.h
 * Author: Martin Kjellqvist <martin.kjellqvist@miun.se>
 *
 * Created on October 3, 2017, 5:08 PM
 */

#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
#include <set>

#include "nodes.h"

namespace adjacency_list_graph{

  
class graph {
public:
    vertex get_vertex(int index) const;
    std::vector<edge> get_adjacency_list() const;
    /**
     * 
     * @param start, index of first element in range
     * @param end index, range not including end element.
     * @return 
     */
    std::vector<edge> get_adjacency_list(int start, int end) const;    
    
    std::set<vertex> get_vertexes(int start, int end) const;

    std::set<vertex> get_vertexes() const;
    
private:
    graph();
    std::vector<edge> adjacency_list;

    friend graph read_adjacency_list(std::istream& filename);
    friend class vertex;
    friend class edge;
};

graph read_adjacency_list(std::istream& input);
        
}
#endif /* GRAPH_H */

