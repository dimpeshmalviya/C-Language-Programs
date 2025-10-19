#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    vector<int> topologicalSort(int V, vector<vector<int>>& adj) {
        vector<int> indegree(V, 0);
        for (int i = 0; i < V; i++)
            for (int v : adj[i]) indegree[v]++;
        
        queue<int> q;
        for (int i = 0; i < V; i++)
            if (indegree[i] == 0) q.push(i);
        
        vector<int> result;
        while (!q.empty()) {
            int u = q.front(); q.pop();
            result.push_back(u);
            
            for (int v : adj[u])
                if (--indegree[v] == 0) q.push(v);
        }
        
        return result.size() == V ? result : vector<int>();
    }
};

int main() {
    Solution s;
    
    // DAG: 0 -> 1 -> 3
    //      |    |    ^
    //      v    v    |
    //      2 -------->
    int V = 4;
    vector<vector<int>> adj = {{1, 2}, {3}, {3}, {}};
    
    vector<int> result = s.topologicalSort(V, adj);
    
    if (result.empty()) {
        cout << "Graph has a cycle!" << endl;
    } else {
        cout << "Topological Sort: ";
        for (int node : result) cout << node << " ";
        cout << endl;
    }
    
    // Cyclic graph test
    vector<vector<int>> adj2 = {{1}, {2}, {0}};
    result = s.topologicalSort(3, adj2);
    
    if (result.empty()) {
        cout << "Cyclic graph: No topological sort possible" << endl;
    }
    
    return 0;
}