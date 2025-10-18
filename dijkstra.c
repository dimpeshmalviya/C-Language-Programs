/*
Program Name: Dijkstra's Algorithm
Problem Statement: shortest distance from a source vertex to all other vertices in a weighted graph using Dijkstra's algorithm.

Time Complexity: O(V^2) where V is the number of vertices
Space Complexity: O(V) 

Example:

Input:
Number of vertices = 5
Graph (Adjacency Matrix):

        0   10  0   30  100
        10  0   50  0   0
        0   50  0   20  10
        30  0   20  0   60
        100 0   10  60  0

Source: 0

Output:
Vertex   Distance from Source
0        0
1        10
2        50
3        30
4        60

*/

#include <stdio.h>
#include <stdbool.h>
#define V 5 // number of vertices

// find vertex with minm distance 
int minDistance(int dist[], bool visited[]) {
    int min = 999999, min_index;

    for (int v = 0; v < V; v++)
        if (!visited[v] && dist[v] <= min) {
            min = dist[v];
            min_index = v;
        }

    return min_index;
}

void printSolution(int dist[]) {
    printf("Vertex \t Distance from Source\n");
    for (int i = 0; i < V; i++)
        printf("%d \t %d\n", i, dist[i]);
}

void dijkstra(int graph[V][V], int src) {
    int dist[V];       // shortest distance from src to i
    bool visited[V];   // holds visited vertices

    // Initialize distance = infinite and visited = false
    for (int i = 0; i < V; i++) {
        dist[i] = 999999;
        visited[i] = false;
    }

    dist[src] = 0; // Distance of source vertex from itself

    // Find shortest path
    for (int count = 0; count < V - 1; count++) {
        int u = minDistance(dist, visited); // Pick minm distance
        visited[u] = true;

        // Update dist[v] if not visited 
        for (int v = 0; v < V; v++)
            if (!visited[v] && graph[u][v] && dist[u] + graph[u][v] < dist[v])
                dist[v] = dist[u] + graph[u][v];
    }

    // print the final array
    printSolution(dist);
}

int main() {
    // example graph  
    int graph[V][V] = {
        {0, 10, 0, 30, 100},
        {10, 0, 50, 0, 0},
        {0, 50, 0, 20, 10},
        {30, 0, 20, 0, 60},
        {100, 0, 10, 60, 0}
    };

    int source = 0; // source vertex
    dijkstra(graph, source);

    return 0;
}