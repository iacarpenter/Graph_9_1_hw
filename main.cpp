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

    std::vector<int> undirected_out = undirected_g.out_degrees();
    std::cout << "----undirected graph out-degrees----" << std::endl;
    for (int i : undirected_out)
        std::cout << i << std::endl;
    std::vector<int> undirected_in = undirected_g.in_degrees();
    std::cout << "----undirected graph in-degrees----" << std::endl;
    for (int i : undirected_in)
        std::cout << i << std::endl;
    std::vector<std::vector<double>> undir_adj_matrix = undirected_g.construct_adjacency_matrix();
    std::cout << "----undirected graph adjacency matrix----" << std::endl;
    for (std::vector<double> &v : undir_adj_matrix) {
        for (int i : v)
            std::cout << i << " ";
        std::cout << std::endl;
    }

    std::vector<int> directed_out = directed_g.out_degrees();
    std::cout << "----directed graph out-degrees----" << std::endl;
    for (int i : directed_out)
        std::cout << i << std::endl;
    std::vector<int> directed_in = directed_g.in_degrees();
    std::cout << "----directed graph in-degrees----" << std::endl;
    for (int i : directed_in)
        std::cout << i << std::endl;
    std::vector<std::vector<double>> dir_adj_matrix = directed_g.construct_adjacency_matrix();
    std::cout << "----directed graph adjacency matrix----" << std::endl;
    for (std::vector<double> &v : dir_adj_matrix) {
        for (int i : v)
            std::cout << i << " ";
        std::cout << std::endl;
    }

    std::vector<int> directed_g_ordering = directed_g.top_sort(directed_in);
    std::cout << "----directed graph topological ordering----" << std::endl;
    for (int i : directed_g_ordering)
        std::cout << i << std::endl;

    std::vector<std::pair<int, int>> directed_unweighted_paths = directed_g.unweighted_shortest_path(0);
    std::cout << "----directed graph unweighted shortest paths----" << std::endl;
    for (int i = 0; i < directed_unweighted_paths.size(); ++i) {
        std::pair<int, int> &p = directed_unweighted_paths[i];
        std::cout << "Vertex " << i << ":" << std::endl;
        std::cout << "    distance: " << p.first << std::endl;
        std::cout << "    preceding vertex: " << p.second << std::endl;
    }
}