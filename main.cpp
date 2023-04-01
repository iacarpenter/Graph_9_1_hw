#include <iostream>
#include "Graph.h"

int main() {
    std::cout << "----undirected graph----" << std::endl;
    Graph undirected_g (10, false);
    undirected_g.add_edge(0, 2, 10.5);
    undirected_g.add_edge(1, 7);
    undirected_g.add_edge(0, 1);
    undirected_g.print_graph();

    std::cout << "----directed graph----" << std::endl;
    Graph directed_g (10, true);
    directed_g.add_edge(0, 2, 10.5);
    directed_g.add_edge(1, 7);
    directed_g.add_edge(0, 1);
    directed_g.print_graph();
}
