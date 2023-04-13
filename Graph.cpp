#include <iostream>
#include <limits>
#include <queue>
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
    return in;
}

std::vector<std::vector<double>> Graph::construct_adjacency_matrix() {
    double lowest_double = std::numeric_limits<double>::lowest();
    std::vector<std::vector<double>> matrix(size(), std::vector<double>(size(), lowest_double));
    for (Vertex i : vertices) {
        for (Edge e : i.edges) {
            matrix[e.vtx1][e.vtx2] = e.weight;
        }
    }
    return matrix;
}

std::vector<int> Graph::top_sort(std::vector<int> in_deg) {
    if (!directed)
        throw graph_error("called top_sort on an undirected graph");

    std::vector<int> sorted;
    std::queue<int> q;

    for (int i = 0; i < in_deg.size(); i++) {
        if (in_deg[i] == 0)
            q.push(i);
    }

    while (!q.empty()) {
        int v = q.front();
        q.pop();
        sorted.push_back(v);

        for (Edge e : vertices[v].edges) {
            int w = e.vtx2;
            if (--in_deg[w] == 0)
                q.push(w);
        }
    }

    return sorted;
}

std::vector<std::pair<int, int>> Graph::unweighted_shortest_path(int s) {
    std::queue<int> q;
    int max_int = std::numeric_limits<int>::max();
    std::vector<int> distances(size(), max_int);
    std::vector<std::pair<int, int>> shortest_path(size(), std::pair<int, int>(max_int, max_int));
    distances[s] = 0;
    q.push(s);

    while (!q.empty()) {
        int v = q.front();
        q.pop();

        for (Edge e : vertices[v].edges) {
            int w = e.vtx2;
            if (distances[w] == max_int) {
                distances[w] = ++distances[v];
                shortest_path[w].first = distances[w];
                shortest_path[w].second = v;
                q.push(w);
            }
        }
    }

    return shortest_path;
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

