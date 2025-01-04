#include <iostream>
#include <vector>
#include <utility>
#include <unordered_map>
#include <climits>
#include <queue>
#include <algorithm>

class Graph {
    public:
        std::unordered_map<std::string, int> vertex;
        std::vector<std::vector<std::pair<int,int>>> adjList;

        struct Edge {
            int origin = 0;
            int destination = 0;
            
            // Overload the == operator
            bool operator==(const Edge& other) const {
                return origin == other.origin && destination == other.destination;
            }
        };

        // Comparator for the min priority queue
        struct Compare {
            bool operator()(const std::pair<int, int>& a, const std::pair<int, int>& b) {
                return a.second > b.second; // Min-heap based on the value of the pair
            }
        };

        struct ComparePrims {
            bool operator()(const std::pair<Edge, int>& a, const std::pair<Edge, int>& b) {
                return a.second > b.second; // Min-heap based on the value of the pair
            }
        };

        struct Prop{
                int cost = INT_MAX;
                int prevIndex = INT_MAX;
                std::string prevVertex = "IDK";
                bool visited = false;
                // Min priority queue using custom comparator
                std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, Compare> currentDest;
            };

        Graph(std::unordered_map<std::string, int> vertex, std::vector<std::vector<std::pair<int,int>>> adjList) {
            this->vertex = vertex;
            this->adjList = adjList;
        }

        void printGraph() {
            std::cout << "{";
            for (int i=0;i<adjList.size();i++){
                std::cout << "{";
                for (int j=0;j<adjList[i].size();j++) {
                    j == adjList[i].size() - 1 ? std::cout << "{" << adjList[i][j].first << "," << adjList[i][j].second << "}" : std::cout << "{" << adjList[i][j].first << "," << adjList[i][j].second << "},";
                }
                std::cout << "}";
            }
            std::cout << "}" << '\n';
        }

        void printConventionalGraph() { //unweighted // {{1,2},{1,3},{2,1},{2,3},{3,2}} // [[1,2],[1,3],[2,1],[2,3],[3,2]]
            std::cout << "[";
            for (int i=0;i<adjList.size();i++) {
                for (int j=0;j<adjList[i].size();j++) {
                    i == adjList.size()-1 ? std::cout << "[" << i << "," << adjList[i][j].first << "]" : std::cout << "[" << i << "," << adjList[i][j].first << "],";
                }
            }
            std::cout << "]" << '\n';
        }

        void printVertex() {

        }

        // There's a possibility of inserting double vertex value.
        void insertVertex(std::string name) {
            if (vertex.find(name) == vertex.end()) {
                vertex[name] = vertex.size(); 
                adjList.emplace_back(); //extend the size
            } else {
                std::cout << "Failed to insert " << name << " because it's already exist" << '\n';
            }
        }

        int vertexIndex(std::string name) {
            if (vertex.find(name) != vertex.end()) {
                return vertex[name];
            } else {
                std::cout << "Vertex " << name << " doesn't exist. Please create it first" << '\n';
                return -1;
            }
        }

        std::string vertexString(int index) {
            
        }

        void insertEdge(int origin, int destination, int weight) {
            if (origin < adjList.size()) {
                std::pair<int,int> tempEdge(destination, weight);
                adjList[origin].push_back(tempEdge);
            } else {
                std::cout << "Please create the origin vertex first" << '\n';
            }   
        }

        // Delete a vertex by its key
        void deleteVertex(std::string name) {
            int currentIndex = vertexIndex(name);
            int lastIndex = vertex.size()-1;

            if (vertex.find(name) != vertex.end()) {
                // delete the vertex & adjList
                vertex.erase(name);
                adjList.erase(adjList.begin() + currentIndex);
            } else {
                std::cout << "Vertex doesn't exist" << '\n';
                return;
            }

            // If it's not the last index in the vertex, change some of the vertex indices
            if (currentIndex != lastIndex) {
                for (auto& pair : vertex) {
                    if (pair.second > currentIndex) {
                        pair.second--;
                    }
                }
            } 
        }

        // Delete a vertex by its index
        void deleteVertex(int currentIndex) {
            int lastIndex = vertex.size()-1;

            if (currentIndex <= lastIndex) {
                // delete the vertex & adjList
                for (auto it=vertex.begin(); it!=vertex.end();) {
                    if (it->second == currentIndex) {
                        it = vertex.erase(it); // update the iterator & delete the vertex
                    } else {
                        ++it;
                    }
                }
                adjList.erase(adjList.begin() + currentIndex);
            } else {
                std::cout << "Vertex doesn't exist" << '\n';
                return;
            }

            // If it's not the last index in the vertex, change some of the vertex indices
            if (currentIndex != lastIndex) {
                for (auto& pair : vertex) {
                    if (pair.second > currentIndex) {
                        pair.second--;
                    }
                }
            } 
        }

        void deleteEdge(int origin, int destination) {

        }

        void dijkstra(std::string origin, std::string destination) {
            // struct Prop{
            //     int cost = INT_MAX;
            //     int prevIndex = INT_MAX;
            //     std::string prevVertex = "IDK";
            //     bool visited = false;
            //     std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, Compare> nextDest;
            // };
            std::unordered_map<int,Prop> path;
            int originIndex = vertexIndex(origin);
            int destIndex = vertexIndex(destination);
            Prop originProp;
            originProp.cost = 0;
            originProp.visited = true;
            path[originIndex] = originProp;

            while (path[destIndex].visited == false) {
                
                for (int i=0; i<adjList[originIndex].size();i++) {
                    int currentDest = adjList[originIndex][i].first;
                    int currentDestWeight = adjList[originIndex][i].second;

                    // Calculate the cost
                    int currentCost = path[originIndex].cost + currentDestWeight;
                    if (currentCost < path[currentDest].cost) {
                        path[currentDest].cost = currentCost;
                    }
                    // Put the cost in the priority queue to decide where to visit next
                    std::pair<int,int> currentDestIndexCost(currentDest, path[currentDest].cost);
                    path[originIndex].currentDest.push(currentDestIndexCost);

                    path[currentDest].prevIndex = originIndex;
                }

                // Get the next vertex to visit

                // //if the queue is empty, back to the previous index or all visited
                // while (path[originIndex].currentDest.empty() || ) { 

                // } 
                std::pair<int,int> currentDestToVisit = path[originIndex].currentDest.top();
                path[originIndex].currentDest.pop();
                originIndex = currentDestToVisit.first;
                path[originIndex].visited = true; // already the new index

            } 
            std::cout << path[destIndex].cost << '\n';
            // boundary: the next destination doesn't have path to the final destination
        }

        std::pair<Edge, int> smallestEdge() {
            std::priority_queue<std::pair<Edge, int>, ComparePrims> edgesQueue;

            // List all the edges to the priority queue according to its weight 
            for (int i=0;i<adjList.size();i++) {
                for (int j=0;j<adjList[i].size();j++) {
                    Edge tempEdges;
                    tempEdges.origin = i;
                    tempEdges.destination = adjList[i][j].first;
                    int cost = adjList[i][j].second;
                    std::pair<Edge,int> tempEdgesPair(tempEdges,cost);
                    edgesQueue.push(tempEdgesPair);
                }
            }
            return edgesQueue.top();
        }

        // Connected undirected Graph
        void prims() {
            // Find the smallest Edge
            // std::priority_queue<std::pair<Edge, int>, std::vector<std::pair<Edge, int>>, ComparePrims> edges;
            std::priority_queue<std::pair<Edge, int>, ComparePrims> edgesQueueTemp;
            std::vector<std::vector<std::pair<int,int>>> copyAdjList = adjList;
            std::vector<std::vector<std::pair<int,int>>> newAdjList(vertex.size());
            std::vector<int> availableVertex;
            std::unordered_map<Edge,int> initialEdges;
            int cost = 0;
            
            // Get the initial (smallest) edge. First edge of the spanning tree
            std::pair<Edge, int> currentEdge = smallestEdge();

            // YOU DON'T ACTUALLY HAVE TO USE PRIORITY QUEUE. JUST USE TEMPORARY VARIABLE. IF THE VARIABLE IS SMALLER, CHANGE, IF NOT ITERATE. 
            // IN THE END, YOU WILL GET THE SMALLEST VARIABLE. THIS WAY, YOU CAN GET THE INDEX[I][J] IN THE COPYADJLIST SO THAT YOU CAN DELETE IT 
            // MUCH EASIER
            
            // LOOP STARTS HERE

            // Update the total cost
            cost += currentEdge.second;

            // Put the first edge into the new adjList
            newAdjList[currentEdge.first.origin].push_back(std::pair<int,int>(currentEdge.first.destination, currentEdge.second));

            // Delete the used edge in the copyAdjList
            //copyAdjList[currentEdge.first.origin].erase();

            // Add the spanning tree's vertex into a vector
            bool originExist = false;
            bool destinationExist = false;
            for (int i=0;i<availableVertex.size();i++) {
                // In assumption of simple graph (no self loop)
                if (availableVertex[i] == currentEdge.first.origin) originExist = true;
                if (availableVertex[i] == currentEdge.first.destination) destinationExist = true;
            }
            if (originExist) availableVertex.push_back(currentEdge.first.origin);
            if (destinationExist) availableVertex.push_back(currentEdge.first.destination);

            // MISSING 1 CONDITIONAL => LIST THE EDGES THAT DOESN'T CREATE A CYCLE. IF THE EDGE CREATE A CYCLE, DELETE IT FROM THE COPYADJLIST
            // List the edges connected to the current spanning tree's vertices
            for (int i=0;i<availableVertex.size();i++) {
                int origin = availableVertex[i];
                for (int j=0;j<copyAdjList[origin].size();j++) { // Assume the undirected graph is a double directed
                    Edge tempEdges;
                    tempEdges.origin = origin; 
                    tempEdges.destination = copyAdjList[origin][j].first;
                    int cost = copyAdjList[i][j].second;
                    std::pair<Edge,int> tempEdgesPair(tempEdges,cost);
                    edgesQueueTemp.push(tempEdgesPair);
                }
            }

            // IT WILL CREATE A CYCLE IF THE BOTH THE EDGE'S VERTICES ARE ALREADY IN AVAILABLEVERTEX

            // Get the smallest edge connected to the current spanning tree's vertices
            currentEdge = edgesQueueTemp.top();

            // Clear the temporary priority queue
            while (!edgesQueueTemp.empty()) {
                edgesQueueTemp.pop();
            }
            // the smallest can actually be edited.
            

        }
        

};

int main() {
    // GRAPH 1
    std::unordered_map<std::string, int> initialVertex = {
        {"Station A",0},
        {"Station B",1},
        {"Station C",2},
        };
    std::vector<std::vector<std::pair<int,int>>> initialAdjList = { 
            {{1,10}, {2,20}}, 
            {{0,10}, {2,40}}, 
            {{1,40}, {0,20}}
        };
    Graph graph1 = Graph(initialVertex,initialAdjList);
    // graph1.printGraph();
    // graph1.printConventionalGraph();

    // GRAPH 2
    std::unordered_map<std::string, int> initialVertex2 = {
    {"Node 1", 0},
    {"Node 2", 1},
    {"Node 3", 2},
    {"Node 4", 3},
    {"Node 5", 4},
    };
    std::vector<std::vector<std::pair<int, int>>> initialAdjList2 = { 
        {{1, 15}},             // Node 1 connects to Node 2 (15)
        {{2, 25}},             // Node 2 connects to Node 3 (25)
        {{3, 35}},             // Node 3 connects to Node 4 (35)
        {{4, 45}},             // Node 4 connects to Node 5 (45)
        {{0, 55}},             // Node 5 connects back to Node 1 (55)
    };
    Graph graph2 = Graph(initialVertex2, initialAdjList2);

    // GRAPH 3
    std::unordered_map<std::string, int> initialVertex3 = {
    {"Center", 0},
    {"Leaf 1", 1},
    {"Leaf 2", 2},
    {"Leaf 3", 3},
    {"Leaf 4", 4},
    };
    std::vector<std::vector<std::pair<int, int>>> initialAdjList3 = { 
        {{1, 10}, {2, 20}, {3, 30}, {4, 40}},  // Center connects to all leaves
        {{0, 10}},                             // Leaf 1 connects back to Center
        {{0, 20}},                             // Leaf 2 connects back to Center
        {{0, 30}},                             // Leaf 3 connects back to Center
        {{0, 40}},                             // Leaf 4 connects back to Center
    };
    Graph graph3 = Graph(initialVertex3, initialAdjList3);

    // graph2.printConventionalGraph();
    // graph2.dijkstra("Node 1","Node 3");

    return 0;
}

/*
If the vertex is represented by a std::string, a direct mapping (e.g., std::unordered_map<std::string, std::vector<std::pair<std::string, int>>>) 
would make operations like indexing or iterating over edges less efficient.

When using a direct map from vertices to edges, every access involves a hash lookup for the vertex key. With an index-based approach, you only perform this lookup once when processing the vertex, then work with efficient vector indices.
*/


/*
REASONS TO USE THE KEY (STRING) AS A PARAMETER ON deleteVertex()
Human-readable: The key is typically a meaningful name (e.g., "London") that is easy to use and understand.
Direct lookup: The std::map or std::unordered_map is designed for fast key-based lookups, making this approach efficient.
Consistency with insertion: Since insertion typically involves a string key, using the same for deletion keeps the API consistent.

REASONS TO USE THE VALUE (INDEX/INT) AS A PARAMETER ON deleteVertex()
Efficient for pre-computed indices: If the index is already known (e.g., from an algorithm or data structure), passing the index avoids an extra lookup in the map.
Useful for applications where indices are primary identifiers (e.g., in numerical simulations or algorithm implementations).
 */