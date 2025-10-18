#include <bits/stdc++.h>
using namespace std;

// Function to perform Kahn's Algorithm (BFS) topological sort
vector<int> kahnTopologicalSort(int V, vector<vector<int>> &adj) {
    vector<int> inDegree(V, 0);
    for (int u = 0; u < V; u++) {
        for (int v : adj[u])
            inDegree[v]++;
    }

    queue<int> q;
    for (int i = 0; i < V; i++) {
        if (inDegree[i] == 0)
            q.push(i);
    }

    vector<int> topoOrder;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        topoOrder.push_back(u);

        for (int v : adj[u]) {
            inDegree[v]--;
            if (inDegree[v] == 0)
                q.push(v);
        }
    }

    if (topoOrder.size() != V) {
        cout << "Graph contains a cycle! No valid topological ordering.\n";
        return {};
    }

    return topoOrder;
}

// DFS-based topological sort helper
bool dfs(int u, vector<vector<int>> &adj, vector<int> &visited, vector<int> &stack) {
    visited[u] = 1; // visiting
    for (int v : adj[u]) {
        if (visited[v] == 1) {
            // cycle detected
            return false;
        } else if (visited[v] == 0) {
            if (!dfs(v, adj, visited, stack))
                return false;
        }
    }
    visited[u] = 2; // visited
    stack.push_back(u);
    return true;
}

vector<int> dfsTopologicalSort(int V, vector<vector<int>> &adj) {
    vector<int> visited(V, 0);
    vector<int> stack;

    for (int i = 0; i < V; i++) {
        if (visited[i] == 0) {
            if (!dfs(i, adj, visited, stack)) {
                cout << "Graph contains a cycle! No valid topological ordering.\n";
                return {};
            }
        }
    }

    reverse(stack.begin(), stack.end());
    return stack;
}

int main() {
    int V = 6;
    vector<pair<int,int>> edges = {{5,2},{5,0},{4,0},{4,1},{2,3},{3,1}};

    vector<vector<int>> adj(V);
    for (auto &e : edges) {
        adj[e.first].push_back(e.second);
    }

    cout << "Topological Sort (Kahn's Algorithm - BFS): ";
    vector<int> bfsTopo = kahnTopologicalSort(V, adj);
    for (int x : bfsTopo)
        cout << x << " ";
    cout << "\n";

    cout << "Topological Sort (DFS-based): ";
    vector<int> dfsTopo = dfsTopologicalSort(V, adj);
    for (int x : dfsTopo)
        cout << x << " ";
    cout << "\n";

    return 0;
}
