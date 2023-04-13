#ifndef CDS242_GRAPH_H
#define CDS242_GRAPH_H

#include <vector>
#include <stdexcept>

class graph_error : public std::runtime_error {
public:
    graph_error(const std::string& what)
        : std::runtime_error(what)
    {}
};

class Graph {
public:
    Graph(std::size_t v, bool d);
    /*
     * Adds an edge leading from v1 to v2 if the graph is directed. If the
     * graph is undirected the edge leads both ways.
     * */
    void add_edge(int v1, int v2, double w = 0);
    int size();
    std::vector<int> out_degrees();
    std::vector<int> in_degrees();
    std::vector<std::vector<double>> construct_adjacency_matrix();
    /*
     * Takes a vector of integers representing the in degrees of the
     * vertices of the graph, with the integer at index i being the
     * in degree of the vertex with id i. Returns a vector of integers
     * with the ids of the vectors in topological sorted order.
     * */
    std::vector<int> top_sort(std::vector<int> in_deg);
    /*
     * Takes an integer s that is the id of the start vertex. Returns a
     * vector of pairs of integers, with the pair at index i corresponding
     * to the vertex with id i. The first integer in the pair represents
     * the distance of vertex i from vertex s, and the second integer is
     * the id of the vertex that precedes i in its path from s.
     * */
    std::vector<std::pair<int, int>> unweighted_shortest_path(int s);
    void print_graph();

private:
    struct Edge {
        int vtx1;
        int vtx2; // vertex that the edge leads to if the graph is undirected
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