/*
 * Bridge Edges in a Graph - Tarjan's Algorithm (C++)
 * 
 * This program finds all critical connections (bridges) in an undirected graph
 * using Tarjan's Algorithm. A bridge is an edge whose removal increases the
 * number of connected components in the graph.
 * 
 * Algorithm:
 * 1. Use DFS to traverse the graph
 * 2. Keep track of discovery time and low link value for each node
 * 3. An edge (u,v) is a bridge if low[v] > disc[u]
 * 
 * Time Complexity: O(V + E) where V is vertices and E is edges
 * Space Complexity: O(V) for recursion stack and auxiliary arrays
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Graph {
private:
    int V;                              // Number of vertices
    vector<vector<int>> adj;            // Adjacency list
    vector<int> disc;                   // Discovery time of each vertex
    vector<int> low;                    // Low link value of each vertex
    vector<bool> visited;               // Visited array
    vector<pair<int, int>> bridges;     // Store bridge edges
    int time;                           // Global time counter

public:
    // Constructor
    Graph(int vertices) : V(vertices) {
        adj.resize(V);
        disc.resize(V, -1);
        low.resize(V, -1);
        visited.resize(V, false);
        time = 0;
    }

    // Add an undirected edge to the graph
    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // DFS function to find bridges using Tarjan's algorithm
    void findBridgesDFS(int u, int parent) {
        // Mark current node as visited and set discovery time
        visited[u] = true;
        disc[u] = low[u] = ++time;

        // Traverse all adjacent vertices
        for (int v : adj[u]) {
            // If v is parent, skip (avoid going back to parent)
            if (v == parent) {
                continue;
            }

            // If v is not visited, recur for it
            if (!visited[v]) {
                findBridgesDFS(v, u);

                // Update low value of u
                low[u] = min(low[u], low[v]);

                // Check if edge (u,v) is a bridge
                // A bridge exists if low[v] > disc[u]
                if (low[v] > disc[u]) {
                    bridges.push_back({min(u, v), max(u, v)});
                }
            }
            // If v is already visited and not parent, update low[u]
            else {
                low[u] = min(low[u], disc[v]);
            }
        }
    }

    // Main function to find all bridges in the graph
    vector<pair<int, int>> findBridges() {
        // Reset data structures
        bridges.clear();
        fill(visited.begin(), visited.end(), false);
        fill(disc.begin(), disc.end(), -1);
        fill(low.begin(), low.end(), -1);
        time = 0;

        // Call DFS for each unvisited vertex (handles disconnected graphs)
        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                findBridgesDFS(i, -1);
            }
        }

        // Sort bridges for consistent output
        sort(bridges.begin(), bridges.end());
        return bridges;
    }

    // Print the graph structure
    void printGraph() {
        cout << "Graph Structure:\n";
        for (int i = 0; i < V; i++) {
            cout << "Vertex " << i << ": ";
            for (int v : adj[i]) {
                cout << v << " ";
            }
            cout << "\n";
        }
    }

    // Print all bridge edges
    void printBridges() {
        vector<pair<int, int>> bridgeEdges = findBridges();
        
        cout << "\nBridge Edges Found: " << bridgeEdges.size() << "\n";
        if (bridgeEdges.empty()) {
            cout << "No bridge edges found in the graph.\n";
        } else {
            cout << "Bridge edges:\n";
            for (auto bridge : bridgeEdges) {
                cout << "(" << bridge.first << ", " << bridge.second << ")\n";
            }
        }
    }
};

// Test function with example graphs
void testTarjanAlgorithm() {
    cout << "=== Testing Tarjan's Bridge Finding Algorithm ===\n\n";

    // Test Case 1: Graph with bridges
    cout << "Test Case 1: Graph with bridges\n";
    cout << "Graph: 0-1-2-3, 1-4, 2-5\n";
    Graph g1(6);
    g1.addEdge(0, 1);
    g1.addEdge(1, 2);
    g1.addEdge(2, 3);
    g1.addEdge(1, 4);
    g1.addEdge(2, 5);
    g1.printGraph();
    g1.printBridges();

    cout << "\n" << string(50, '-') << "\n\n";

    // Test Case 2: Graph without bridges (cycle)
    cout << "Test Case 2: Graph without bridges (cycle)\n";
    cout << "Graph: 0-1-2-3-0\n";
    Graph g2(4);
    g2.addEdge(0, 1);
    g2.addEdge(1, 2);
    g2.addEdge(2, 3);
    g2.addEdge(3, 0);
    g2.printGraph();
    g2.printBridges();

    cout << "\n" << string(50, '-') << "\n\n";

    // Test Case 3: Disconnected graph
    cout << "Test Case 3: Disconnected graph\n";
    cout << "Graph: 0-1, 2-3-4\n";
    Graph g3(5);
    g3.addEdge(0, 1);
    g3.addEdge(2, 3);
    g3.addEdge(3, 4);
    g3.printGraph();
    g3.printBridges();

    cout << "\n" << string(50, '-') << "\n\n";

    // Test Case 4: Tree (all edges are bridges)
    cout << "Test Case 4: Tree (all edges are bridges)\n";
    cout << "Graph: 0-1-2, 1-3, 1-4\n";
    Graph g4(5);
    g4.addEdge(0, 1);
    g4.addEdge(1, 2);
    g4.addEdge(1, 3);
    g4.addEdge(1, 4);
    g4.printGraph();
    g4.printBridges();
}

// Interactive function to create custom graph
void interactiveMode() {
    cout << "\n=== Interactive Mode ===\n";
    int V, E;
    cout << "Enter number of vertices: ";
    cin >> V;
    cout << "Enter number of edges: ";
    cin >> E;

    Graph g(V);
    cout << "Enter edges (format: u v):\n";
    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        g.addEdge(u, v);
    }

    g.printGraph();
    g.printBridges();
}

int main() {
    cout << "Bridge Edges in a Graph - Tarjan's Algorithm\n";
    cout << "============================================\n\n";

    // Run test cases
    testTarjanAlgorithm();

    // Ask user if they want to try interactive mode
    char choice;
    cout << "\nDo you want to try interactive mode? (y/n): ";
    cin >> choice;
    
    if (choice == 'y' || choice == 'Y') {
        interactiveMode();
    }

    cout << "\nProgram completed successfully!\n";
    return 0;
}
