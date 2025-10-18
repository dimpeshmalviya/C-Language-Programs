/**
 * @file floyd_warshall.c
 * @brief Implementation of Floyd–Warshall Algorithm for All-Pairs Shortest Path.
 *
 * @details
 * Program Name: Floyd–Warshall Algorithm
 *
 * Problem Statement:
 * Given a weighted graph (directed or undirected), find the shortest
 * distance between every pair of vertices using the Floyd–Warshall algorithm.
 *
 * Input/Output Example:
 * Number of vertices: 4
 * Adjacency matrix (INF = 99999):
 * 0   3  INF   7
 * 8   0   2  INF
 * 5  INF   0   1
 * 2  INF INF   0
 *
 * Output (Shortest Distance Matrix):
 * 0   3   5   6
 * 5   0   2   3
 * 3   6   0   1
 * 2   5   7   0
 *
 * Complexity:
 * - Time Complexity: O(V^3), where V is the number of vertices.
 * - Space Complexity: O(V^2), for storing the distance matrix.
 *
 * How to compile and run:
 * gcc floyd_warshall.c -o floyd_warshall
 * ./floyd_warshall
 */

#include <stdio.h>

#define MAX_VERTICES 50
#define INF 99999   // Large value to represent "infinity"

// --- Function to print a matrix ---
void printMatrix(int dist[MAX_VERTICES][MAX_VERTICES], int vertices) {
    printf("\nShortest Distance Matrix:\n");
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            if (dist[i][j] == INF)
                printf("%7s", "INF");
            else
                printf("%7d", dist[i][j]);
        }
        printf("\n");
    }
}

// --- Floyd–Warshall Algorithm ---
void floydWarshall(int graph[MAX_VERTICES][MAX_VERTICES], int vertices) {
    int dist[MAX_VERTICES][MAX_VERTICES];

    // Step 1: Initialize distance matrix same as input graph
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            dist[i][j] = graph[i][j];
        }
    }

    // Step 2: Update distances using each vertex as an intermediate
    for (int k = 0; k < vertices; k++) {
        for (int i = 0; i < vertices; i++) {
            for (int j = 0; j < vertices; j++) {
                // If vertex k is on the shortest path from i to j, then update dist[i][j]
                if (dist[i][k] != INF && dist[k][j] != INF &&
                    dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    // Step 3: Print the result
    printMatrix(dist, vertices);
}

// --- Main Driver Function ---
int main() {
    int vertices = 4;
    int graph[MAX_VERTICES][MAX_VERTICES] = {
        {0,   3, INF,   7},
        {8,   0,   2, INF},
        {5, INF,   0,   1},
        {2, INF, INF,   0}
    };

    printf("Floyd–Warshall Algorithm: All-Pairs Shortest Paths\n");
    floydWarshall(graph, vertices);

    return 0;
}
