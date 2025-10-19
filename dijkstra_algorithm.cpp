#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

class Solution {
public:
    vector<int> dijkstra(int V, vector<vector<pair<int, int>>>& adj, int src) {
        vector<int> dist(V, INT_MAX);
        dist[src] = 0;
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        pq.push({0, src});
        
        while (!pq.empty()) {
            auto [d, u] = pq.top();
            pq.pop();
            
            if (d > dist[u]) continue;
            
            for (auto [v, w] : adj[u]) {
                if (dist[u] + w < dist[v]) {
                    dist[v] = dist[u] + w;
                    pq.push({dist[v], v});
                }
            }
        }
        return dist;
    }
};

int main() {
    Solution s;
    
    // Graph: 0 --4--> 1 --3--> 2
    //        |        |        |
    //        2        1        2
    //        v        v        v
    //        3 <--5-- 4 <------'
    int V = 5;
    vector<vector<pair<int, int>>> adj(V);
    adj[0] = {{1, 4}, {3, 2}};
    adj[1] = {{2, 3}, {4, 1}};
    adj[2] = {{4, 2}};
    adj[3] = {};
    adj[4] = {{3, 5}};
    
    vector<int> dist = s.dijkstra(V, adj, 0);
    
    cout << "Shortest distances from node 0:" << endl;
    for (int i = 0; i < V; i++) {
        cout << "To node " << i << ": ";
        if (dist[i] == INT_MAX) cout << "INF";
        else cout << dist[i];
        cout << endl;
    }
    
    return 0;
}