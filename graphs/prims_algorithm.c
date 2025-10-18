/**
 * @file prims_algorithm.c
 * @brief Implementation of Prim's Algorithm for Minimum Spanning Tree (MST).
 *
 * @details
 * Program Name: Prim's Algorithm
 *
 * Problem Statement:
 * Implement Prim's algorithm to find the Minimum Spanning Tree (MST) of
 * a weighted undirected graph represented using an adjacency matrix.
 *
 * Input/Output Example:
 * - Graph (Weight Matrix):
 *   0  2  0  6  0
 *   2  0  3  8  5
 *   0  3  0  0  7
 *   6  8  0  0  9
 *   0  5  7  9  0
 * - Output (Edges in MST):
 *   0 - 1 : 2
 *   1 - 2 : 3
 *   0 - 3 : 6
 *   1 - 4 : 5
 *
 * Complexity:
 * - Time Complexity: O(V^2), where V is the number of vertices.
 * - Space Complexity: O(V^2) for adjacency matrix.
 *
 * How to compile and run:
 * gcc prims_algorithm.c -o prims_algorithm
 * ./prims_algorithm
 */

#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

#define V 5  // Number of vertices

// Function to find vertex with minimum key value not included in MST
int minKey(int key[], bool mstSet[]) {
    int min = INT_MAX, min_index = -1;

    for (int v = 0; v < V; v++)
        if (mstSet[v] == false && key[v] < min) {
            min = key[v];
            min_index = v;
        }

    return min_index;
}

// Function to print MST
void printMST(int parent[], int graph[V][V]) {
    printf("Edge \tWeight\n");
    for (int i = 1; i < V; i++)
        printf("%d - %d \t%d\n", parent[i], i, graph[i][parent[i]]);
}

// Function to construct and print MST using Prim's algorithm
void primMST(int graph[V][V]) {
    int parent[V];   // Store MST
    int key[V];      // Key values used to pick min weight edge
    bool mstSet[V];  // To represent vertices included in MST

    // Initialize all keys as infinite and mstSet[] as false
    for (int i = 0; i < V; i++) {
        key[i] = INT_MAX;
        mstSet[i] = false;
    }

    // Start from the first vertex
    key[0] = 0;
    parent[0] = -1; // First node is always root of MST

    for (int count = 0; count < V - 1; count++) {
        int u = minKey(key, mstSet); // Pick min key vertex
        mstSet[u] = true;

        // Update key and parent index of adjacent vertices
        for (int v = 0; v < V; v++)
            if (graph[u][v] && mstSet[v] == false && graph[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph[u][v];
            }
    }

    printMST(parent, graph);
}

// Main driver function
int main() {
    int graph[V][V] = {
        {0, 2, 0, 6, 0},
        {2, 0, 3, 8, 5},
        {0, 3, 0, 0, 7},
        {6, 8, 0, 0, 9},
        {0, 5, 7, 9, 0}
    };

    printf("Minimum Spanning Tree using Prim's Algorithm:\n");
    primMST(graph);

    return 0;
}
