#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

void dijkstra(int startNode, int numNodes, const vector<vector<pair<int, int>>>& adj) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> dist(numNodes + 1, numeric_limits<int>::max());

    dist[startNode] = 0;
    pq.push({0, startNode});

    while (!pq.empty()) {
        int d = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        if (d > dist[u]) {
            continue;
        }

        for (auto& edge : adj[u]) {
            int v = edge.first;
            int weight = edge.second;

            if (dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                pq.push({dist[v], v});
            }
        }
    }

    for (int i = 1; i <= numNodes; ++i) {
        if (dist[i] == numeric_limits<int>::max()) {
            cout << "Distance from " << startNode << " to " << i << ": Infinity" << endl;
        } else {
            cout << "Distance from " << startNode << " to " << i << ": " << dist[i] << endl;
        }
    }
}

int main() {
    int numNodes, numEdges;
    cin >> numNodes >> numEdges;

    vector<vector<pair<int, int>>> adj(numNodes + 1);

    for (int i = 0; i < numEdges; ++i) {
        int u, v, weight;
        cin >> u >> v >> weight;
        adj[u].push_back({v, weight});
        adj[v].push_back({u, weight}); 
    }

    int startNode;
    cin >> startNode;

    dijkstra(startNode, numNodes, adj);

    return 0;
}