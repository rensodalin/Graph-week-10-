#include <iostream>
#include "Graph.h"

int main() {
    int numVertices = 5;
    Graph graph(numVertices);
    graph.addEdge(0, 1);
    graph.addEdge(0, 4);
    graph.addEdge(1, 2);
    graph.addEdge(1, 3);
    graph.addEdge(3, 4);
    std::cout << "Graph Structure:" << std::endl;
    graph.display();
    std::cout << "\nDepth-First Search (DFS) starting from vertex 0:" << std::endl;
    graph.DFS(0);
    std::cout << "\nBreadth-First Search (BFS) starting from vertex 0:" << std::endl;
    graph.BFS(0);

    return 0;
}
