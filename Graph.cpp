#include <iostream>
#include "Graph.h"

Graph::Graph(std::size_t v, bool d) {
    directed = d;
    vertex_count = v;
    for (int i = 0; i < v; ++i)
        vertices.push_back(Vertex(i));
}

void Graph::add_edge(int v1, int v2, double w /* = 0 */) {
    vertices[v1].edges.push_back(Edge(v1, v2, w));
    if (!directed)
        vertices[v2].edges.push_back(Edge(v2, v1, w));
}

int Graph::size() {
    return vertex_count;
}

void Graph::print_graph() {
    std::cout << "Printing graph: " << std::endl;
    for (Vertex i : vertices) {
        std::cout << "Vertex " << i.id << " edges:" << std::endl;
        for (Edge e : i.edges) {
            std::cout << "  Vertex " << e.vtx2 << " is adjacent to " << e.vtx1 << " with weight " << e.weight << std::endl;
        }
    }
}

Graph::Edge::Edge(int v1, int v2, double w) {
    vtx1 = v1;
    vtx2 = v2;
    weight = w;
}

Graph::Vertex::Vertex(int i) {
    id = i;
}