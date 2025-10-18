/**
 * @file kruskal_mst.c
 * @brief Implementation of Kruskal's Algorithm to find Minimum Spanning Tree (MST).
 *
 * @details
 * Program Name: Kruskal's Algorithm
 *
 * Problem Statement:
 * Implement Kruskal's algorithm to find the Minimum Spanning Tree (MST) of a
 * connected, undirected, weighted graph. The algorithm sorts all edges in
 * non-decreasing order of their weights and picks edges one by one, ensuring
 * no cycles are formed (using Disjoint Set Union - DSU).
 *
 * Input Example:
 * Number of vertices: 4
 * Edges:
 * 0 - 1 (10)
 * 0 - 2 (6)
 * 0 - 3 (5)
 * 1 - 3 (15)
 * 2 - 3 (4)
 *
 * Output Example:
 * Edges in MST:
 * 2 -- 3 == 4
 * 0 -- 3 == 5
 * 0 -- 1 == 10
 * Total weight of MST: 19
 *
 * Complexity:
 * - Time Complexity: O(E log E) where E is the number of edges.
 * - Space Complexity: O(V) for parent and rank arrays.
 *
 * How to compile and run:
 * gcc kruskal_mst.c -o kruskal_mst
 * ./kruskal_mst
 */

#include <stdio.h>
#include <stdlib.h>

// --- Edge Structure ---
struct Edge {
    int src, dest, weight;
};

// --- Graph Structure ---
struct Graph {
    int V, E;
    struct Edge* edges;
};

// Create a graph with V vertices and E edges
struct Graph* createGraph(int V, int E) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->V = V;
    graph->E = E;
    graph->edges = (struct Edge*)malloc(E * sizeof(struct Edge));
    return graph;
}

// --- Disjoint Set (Union-Find) Implementation ---
struct Subset {
    int parent;
    int rank;
};

// Find set of an element (with path compression)
int find(struct Subset subsets[], int i) {
    if (subsets[i].parent != i)
        subsets[i].parent = find(subsets, subsets[i].parent);
    return subsets[i].parent;
}

// Union of two sets by rank
void Union(struct Subset subsets[], int x, int y) {
    int xroot = find(subsets, x);
    int yroot = find(subsets, y);

    if (subsets[xroot].rank < subsets[yroot].rank) {
        subsets[xroot].parent = yroot;
    } else if (subsets[xroot].rank > subsets[yroot].rank) {
        subsets[yroot].parent = xroot;
    } else {
        subsets[yroot].parent = xroot;
        subsets[xroot].rank++;
    }
}

// --- Comparator for qsort (to sort edges by weight) ---
int compareEdges(const void* a, const void* b) {
    struct Edge* e1 = (struct Edge*)a;
    struct Edge* e2 = (struct Edge*)b;
    return e1->weight - e2->weight;
}

// --- Kruskal's Algorithm ---
void KruskalMST(struct Graph* graph) {
    int V = graph->V;
    struct Edge result[V - 1];  // Will store the resulting MST
    int e = 0;                 // Index for result[]
    int i = 0;                 // Index for sorted edges

    // Step 1: Sort edges in increasing order by weight
    qsort(graph->edges, graph->E, sizeof(graph->edges[0]), compareEdges);

    // Allocate memory for disjoint sets
    struct Subset* subsets = (struct Subset*)malloc(V * sizeof(struct Subset));

    for (int v = 0; v < V; ++v) {
        subsets[v].parent = v;
        subsets[v].rank = 0;
    }

    // Step 2: Pick edges one by one
    while (e < V - 1 && i < graph->E) {
        struct Edge next_edge = graph->edges[i++];

        int x = find(subsets, next_edge.src);
        int y = find(subsets, next_edge.dest);

        // If including this edge doesn't cause a cycle, include it
        if (x != y) {
            result[e++] = next_edge;
            Union(subsets, x, y);
        }
        // else discard the edge
    }

    // Step 3: Print the result
    printf("Edges in the MST:\n");
    int totalWeight = 0;
    for (i = 0; i < e; ++i) {
        printf("%d -- %d == %d\n", result[i].src, result[i].dest, result[i].weight);
        totalWeight += result[i].weight;
    }
    printf("Total weight of MST: %d\n", totalWeight);

    free(subsets);
}

// --- Main Driver ---
int main() {
    int V = 4; // Number of vertices
    int E = 5; // Number of edges
    struct Graph* graph = createGraph(V, E);

    // Add edges
    graph->edges[0].src = 0;
    graph->edges[0].dest = 1;
    graph->edges[0].weight = 10;

    graph->edges[1].src = 0;
    graph->edges[1].dest = 2;
    graph->edges[1].weight = 6;

    graph->edges[2].src = 0;
    graph->edges[2].dest = 3;
    graph->edges[2].weight = 5;

    graph->edges[3].src = 1;
    graph->edges[3].dest = 3;
    graph->edges[3].weight = 15;

    graph->edges[4].src = 2;
    graph->edges[4].dest = 3;
    graph->edges[4].weight = 4;

    KruskalMST(graph);

    free(graph->edges);
    free(graph);

    return 0;
}
