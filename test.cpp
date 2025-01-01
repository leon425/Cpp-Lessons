#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <sstream>
#include <unordered_map>

class Graph {
public:
    // Constructor: initialize the graph with no vertices or edges
    Graph() {}

    // Add a vertex to the graph
    void addVertex(const std::string& vertex) {
        if (vertexMap.find(vertex) == vertexMap.end()) {
            vertexMap[vertex] = adjList.size();
            adjList.emplace_back(); // Add an empty list for this vertex
        }
    }

    // Add a directed edge with a weight between two vertices
    void addEdge(const std::string& src, const std::string& dest, int weight) {
        addVertex(src); // Ensure src exists
        addVertex(dest); // Ensure dest exists

        int srcIndex = vertexMap[src];
        int destIndex = vertexMap[dest];
        adjList[srcIndex].emplace_back(destIndex, weight);
    }

    // Display the graph as an adjacency list
    void printGraph() const {
        for (const auto& [vertex, index] : vertexMap) {
            std::cout << vertex << ": ";
            for (const auto& [destIndex, weight] : adjList[index]) {
                std::cout << "(" << getVertexByIndex(destIndex) << ", " << weight << ") ";
            }
            std::cout << std::endl;
        }
    }

private:
    // A map from vertex name to its index
    std::unordered_map<std::string, int> vertexMap;

    // The adjacency list, where adjList[i] contains a list of (destination, weight) pairs
    std::vector<std::vector<std::pair<int, int>>> adjList;

    // Helper to get a vertex name by its index
    std::string getVertexByIndex(int index) const {
        for (const auto& [vertex, idx] : vertexMap) {
            if (idx == index) return vertex;
        }
        return "";
    }
};

int main() {
    Graph graph;
    graph.addEdge("A", "B", 1);
    graph.addEdge("A", "C", 2);
    graph.addEdge("B", "C", 3);
    graph.addEdge("C", "A", 4);

    graph.printGraph();
    return 0;
}
