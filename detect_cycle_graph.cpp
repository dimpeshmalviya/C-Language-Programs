#include <iostream>
#include <vector>
using namespace std;

class Solution {
    bool dfs(vector<vector<int>>& adj, int node, int parent, vector<bool>& vis) {
        vis[node] = true;
        for (int neighbor : adj[node]) {
            if (!vis[neighbor]) {
                if (dfs(adj, neighbor, node, vis)) return true;
            } else if (neighbor != parent) {
                return true;
            }
        }
        return false;
    }
    
public:
    bool hasCycle(int V, vector<vector<int>>& adj) {
        vector<bool> vis(V, false);
        for (int i = 0; i < V; i++) {
            if (!vis[i] && dfs(adj, i, -1, vis)) return true;
        }
        return false;
    }
};

int main() {
    Solution s;
    
    // Graph with cycle: 0-1-2-0
    vector<vector<int>> adj1 = {{1}, {0, 2}, {1, 0}};
    cout << "Graph 1 (0-1-2-0): " << (s.hasCycle(3, adj1) ? "Has cycle" : "No cycle") << endl;
    
    // Graph without cycle: 0-1-2
    vector<vector<int>> adj2 = {{1}, {0, 2}, {1}};
    cout << "Graph 2 (0-1-2): " << (s.hasCycle(3, adj2) ? "Has cycle" : "No cycle") << endl;
    
    // Disconnected graph with cycle: 0-1 and 2-3-4-2
    vector<vector<int>> adj3 = {{1}, {0}, {3, 4}, {2, 4}, {2, 3}};
    cout << "Graph 3 (disconnected): " << (s.hasCycle(5, adj3) ? "Has cycle" : "No cycle") << endl;
    
    return 0;
}