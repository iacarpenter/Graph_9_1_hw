#ifndef CDS242_GRAPH_H
#define CDS242_GRAPH_H

#include <vector>

class Graph {
public:
    Graph(std::size_t v, bool d);
    void add_edge(int v1, int v2, double w = 0);
    int size();
    std::vector<int> out_degrees();
    std::vector<int> in_degrees();
    std::vector<std::vector<double>> construct_adjacency_matrix();
    void print_graph();

private:
    struct Edge {
        int vtx1;
        int vtx2;
        double weight;

        Edge(int v1, int v2, double w = 0);
    };

    struct Vertex {
        int id;
        std::vector<Edge> edges;

        Vertex(int i);
    };

private:
    bool directed;
    int vertex_count;
    std::vector<Vertex> vertices;
};

#endif // CDS242_GRAPH_H