#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <stack>

class Graph {
private:
    int numVertices;
    std::unordered_map<int, std::vector<int>> adjacencyList;

public:
    Graph(int vertices) : numVertices(vertices) {}

    void addEdge(int src, int dest) {
        adjacencyList[src].push_back(dest);
        adjacencyList[dest].push_back(src);
    }

    void display() {
        std::cout << "Graph Structure (Adjacency List):" << std::endl;
        for (auto &vertex : adjacencyList) {
            std::cout << vertex.first << ": ";
            for (int neighbor : vertex.second) {
                std::cout << neighbor << " ";
            }
            std::cout << std::endl;
        }
    }

    void DFS(int startVertex) {
        std::vector<bool> visited(numVertices, false);
        std::stack<int> s;

        s.push(startVertex);
        visited[startVertex] = true;

        std::cout << "DFS Traversal: ";
        while (!s.empty()) {
            int currentVertex = s.top();
            s.pop();
            std::cout << currentVertex << " ";

            for (auto it = adjacencyList[currentVertex].rbegin();
                 it != adjacencyList[currentVertex].rend(); ++it) {
                if (!visited[*it]) {
                    s.push(*it);
                    visited[*it] = true;
                }
            }
        }
        std::cout << std::endl;
    }

    void BFS(int startVertex) {
        std::vector<bool> visited(numVertices, false);
        std::queue<int> q;

        q.push(startVertex);
        visited[startVertex] = true;

        std::cout << "BFS Traversal: ";
        while (!q.empty()) {
            int currentVertex = q.front();
            q.pop();
            std::cout << currentVertex << " ";

            for (int neighbor : adjacencyList[currentVertex]) {
                if (!visited[neighbor]) {
                    q.push(neighbor);
                    visited[neighbor] = true;
                }
            }
        }
        std::cout << std::endl;
    }
};

#endif 
