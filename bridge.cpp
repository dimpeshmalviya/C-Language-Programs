#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> adj;
    vector<int> disc, low;
    vector<vector<int>> bridges;
    vector<bool> visited;
    int timeCounter = 0;

    void dfs(int u, int parent) {
        visited[u] = true;
        disc[u] = low[u] = ++timeCounter;

        for (int v : adj[u]) {
            if (v == parent) continue;

            if (!visited[v]) {
                dfs(v, u);
                low[u] = min(low[u], low[v]);

                // Bridge condition
                if (low[v] > disc[u])
                    bridges.push_back({u, v});
            } 
            else {
                // Back edge
                low[u] = min(low[u], disc[v]);
            }
        }
    }

    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        adj.assign(n, {});
        for (auto& e : connections) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        disc.assign(n, 0);
        low.assign(n, 0);
        visited.assign(n, false);

        for (int i = 0; i < n; i++)
            if (!visited[i]) dfs(i, -1);

        return bridges;
    }
};

int main() {
    Solution sol;
    int n = 5;
    vector<vector<int>> edges = {
        {0, 1}, {1, 2}, {2, 0}, {1, 3}, {3, 4}
    };

    vector<vector<int>> result = sol.criticalConnections(n, edges);

    cout << "Bridges found: [";
    for (int i = 0; i < result.size(); i++) {
        cout << "[" << result[i][0] << "," << result[i][1] << "]";
        if (i < result.size() - 1) cout << ", ";
    }
    cout << "]" << endl;

    return 0;
}
