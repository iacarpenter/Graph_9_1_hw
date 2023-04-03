#include <iostream>
#include "Graph.h"

Graph::Graph(std::size_t v, bool d) {
    directed = d;
    vertex_count = v;
    for (int i = 0; i < v; ++i)
        vertices.push_back(Vertex(i));
}

Graph::Edge::Edge(int v1, int v2, double w /* = 0 */) {
    vtx1 = v1;
    vtx2 = v2;
    weight = w;
}

Graph::Vertex::Vertex(int i) {
    id = i;
}

void Graph::add_edge(int v1, int v2, double w /* = 0 */) {
    vertices[v1].edges.push_back(Edge(v1, v2, w));
    if (!directed)
        vertices[v2].edges.push_back(Edge(v2, v1, w));
}

int Graph::size() {
    return vertex_count;
}

std::vector<int> Graph::out_degrees() {
    std::vector<int> out;
    for(Vertex v : vertices)
        out.push_back(v.edges.size());
    return out;
}

std::vector<int> Graph::in_degrees() {
    if (!directed)
        return out_degrees();
    std::vector<int> in(size());
    for (Vertex i : vertices) {
        for (Edge e : i.edges)
            in[e.vtx2]++;
    }
}

std::vector<std::vector<double>> Graph::construct_adjacency_matrix() {
    std::vector<std::vector<double>> matrix(size(), std::vector<double>(size()));
    if (!directed) {
        std::vector<int> degrees = out_degrees();
    }
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

