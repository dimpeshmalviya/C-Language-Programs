/**
 * Program Name: Dijkstra's Single-Source Shortest Path Algorithm
 *
 * Problem Statement:
 * Given a weighted graph and a source vertex, find the shortest distance
 * from the source to every other vertex in the graph. This implementation
 * handles graphs with non-negative edge weights.
 *
 * Input/Output Example:
 * - Input: A weighted graph (represented by an adjacency matrix) and a
 * source vertex (0).
 * - Output: The shortest distance from vertex 0 to every other vertex.
 * Vertex   Distance from Source
 * 0        0
 * 1        4
 * 2        12
 * ...      ...
 *
 * Complexity:
 * - Time Complexity: O(V^2), where V is the number of vertices. This is
 * because of the nested loops used to find the minimum distance vertex.
 * - Space Complexity: O(V) for the distance and visited arrays.
 *

 */

#include <stdio.h>
#include <limits.h>
#include <stdbool.h>

// Number of vertices in the graph
#define V 9

// Finds the vertex with the minimum distance value, from the set of
// vertices not yet included in the shortest path tree.
int minDistance(int dist[], bool sptSet[]) {
    int min = INT_MAX, min_index;

    for (int v = 0; v < V; v++) {
        if (sptSet[v] == false && dist[v] <= min) {
            min = dist[v];
            min_index = v;
        }
    }
    return min_index;
}

// Prints the constructed distance array
void printSolution(int dist[]) {
    printf("Vertex \t\t Distance from Source\n");
    for (int i = 0; i < V; i++) {
        printf("%d \t\t %d\n", i, dist[i]);
    }
}

// Implements Dijkstra's single-source shortest path algorithm
// for a graph represented using an adjacency matrix.
void dijkstra(int graph[V][V], int src) {
    int dist[V]; // The output array. dist[i] will hold the shortest distance from src to i.
    bool sptSet[V]; // sptSet[i] will be true if vertex i is included in the shortest path tree.

    // Initialize all distances as INFINITE and sptSet[] as false
    for (int i = 0; i < V; i++) {
        dist[i] = INT_MAX;
        sptSet[i] = false;
    }

    // Distance of source vertex from itself is always 0
    dist[src] = 0;

    // Find shortest path for all vertices
    for (int count = 0; count < V - 1; count++) {
        // Pick the minimum distance vertex from the set of vertices not yet processed.
        int u = minDistance(dist, sptSet);

        // Mark the picked vertex as processed
        sptSet[u] = true;

        // Update dist value of the adjacent vertices of the picked vertex.
        for (int v = 0; v < V; v++) {
            if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    // Print the constructed distance array
    printSolution(dist);
}

// Main function to drive the program.
int main() {
    // Example graph represented as an adjacency matrix.
    // 0 indicates no direct edge between vertices.
    int graph[V][V] = {{0, 4, 0, 0, 0, 0, 0, 8, 0},
                       {4, 0, 8, 0, 0, 0, 0, 11, 0},
                       {0, 8, 0, 7, 0, 4, 0, 0, 2},
                       {0, 0, 7, 0, 9, 14, 0, 0, 0},
                       {0, 0, 0, 9, 0, 10, 0, 0, 0},
                       {0, 0, 4, 14, 10, 0, 2, 0, 0},
                       {0, 0, 0, 0, 0, 2, 0, 1, 6},
                       {8, 11, 0, 0, 0, 0, 1, 0, 7},
                       {0, 0, 2, 0, 0, 0, 6, 7, 0}};

    dijkstra(graph, 0); // Find shortest path from source vertex 0

    return 0;
}