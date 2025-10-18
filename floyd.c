/*
Program Name: Floyd–Warshall Algorithm
Problem Statement: shortest distances between all pairs of vertices in a weighted graph using the Floyd–Warshall algorithm

Time Complexity: O(V^3) where V is the number of vertices
Space Complexity: O(V^2)

Example:
Input Graph:
        0   5   INF 10
        INF 0   3   INF
        INF INF 0   1
        INF INF INF 0

Output:
Shortest distances between every pair of vertices:
        0   5   8   9
        INF 0   3   4
        INF INF 0   1
        INF INF INF 0
*/

#include <stdio.h>
#define V 4 // number of vertices
#define INF 99999  // infinity


void printSolution(int dist[V][V]) {
    printf("Shortest distances between every pair of vertices:\n");
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (dist[i][j] == INF)
                printf("%7s", "INF");
            else
                printf("%7d", dist[i][j]);
        }
        printf("\n");
    }
}

// Floyd–Warshall algorithm
void floydWarshall(int graph[V][V]) {
    int dist[V][V];

    // Initialize distance matrix same as input graph
    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++)
            dist[i][j] = graph[i][j];

    // Update dist matrix
    for (int k = 0; k < V; k++) {
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                if (dist[i][k] + dist[k][j] < dist[i][j])
                    dist[i][j] = dist[i][k] + dist[k][j];
            }
        }
    }

    // print output
    printSolution(dist);
}

int main() {
    // Example 
    int graph[V][V] = {
        {0, 5, INF, 10},
        {INF, 0, 3, INF},
        {INF, INF, 0, 1},
        {INF, INF, INF, 0}
    };

    floydWarshall(graph);

    return 0;
}