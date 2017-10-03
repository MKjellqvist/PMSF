/* 
 * File:   nodes.h
 * Author: Martin Kjellqvist <martin.kjellqvist@miun.se>
 *
 * Created on October 3, 2017, 5:10 PM
 */

#ifndef NODES_H
#define NODES_H

#include <vector>
#include <iostream>

namespace adjacency_list_graph{

class graph;

struct edge{
    int first;
    int second;
    double weight;
    int source();
    operator int();
};
std::ostream& operator >> (std::ostream& , const edge& e);

bool operator <(const edge&, const edge&);

struct vertex{
    vertex(const graph * owner, int index);
    std::vector<edge> get_neighbors();
    int get_index() const;
    bool operator < (const vertex& rhs) const;
private:
    const graph* owner;
    int index;
};

std::ostream& operator >> (std::ostream& , const vertex& v);

}

#endif /* NODES_H */

