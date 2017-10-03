/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   graph.cpp
 * Author: Martin Kjellqvist <martin.kjellqvist@miun.se>
 * 
 * Created on October 3, 2017, 5:08 PM
 */

#include <iostream>

#include "graph.h"
namespace adjacency_list_graph {

    graph::graph() {
    }

    vertex graph::get_vertex(int index) const {
        return vertex(this, index);
    }

    std::vector<edge> graph::get_adjacency_list() const {
        return adjacency_list;
    }
    std::vector<edge> graph::get_adjacency_list(int start, int end) const {
        return std::vector<edge>(&adjacency_list[start], &adjacency_list[end]);
    }
    std::set<vertex> graph::get_vertexes(int start, int end) const {
        std::set<vertex> result;
        for(auto e:get_adjacency_list(start, end)){
            result.insert(vertex(this, e));
        }
        return result;
    }
    std::set<vertex> graph::get_vertexes() const {
        return get_vertexes(0, adjacency_list.size());
    }

    graph read_adjacency_list(std::istream& is) {
        graph g;
        edge e;
        while(is >> e.first >> e.second  >> e.weight){
            --e.first;
            --e.second;
            g.adjacency_list.push_back(e);
        }
        return g;
    }

}