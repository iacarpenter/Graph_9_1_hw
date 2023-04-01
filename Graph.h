#ifndef CDS242_GRAPH_H
#define CDS242_GRAPH_H

#include <vector>;

class Graph {
public:
    Graph(int v, bool d);
    void add_edge(int v1, int v2, double w = 0);
    int size();
    void print_graph();

private:
    struct Vertex {
        int id;
        std::vector<Edge> edges;

        Vertex(); // TODO: constructor parameters
    };

    struct Edge {
        int vtx1;
        int vtx2;
        double weight;

        Edge(); // TODO: constructor parameters
    };

private:
    bool directed;
    int vertex_count;
    std::vector<Vertex> vertices;
};

#endif // CDS242_GRAPH_H