/**
 * @file bellman_ford.c
 * @brief Bellman-Ford single-source shortest paths (handles negative weights and detects negative cycles)
 *
 * Problem statement:
 * Given a directed, weighted graph (may contain negative weights),
 * compute shortest distances from a source vertex to all other vertices.
 * If a negative-weight cycle reachable from the source exists, report it.
 *
 * Complexity:
 * - Time: O(V * E)
 * - Space: O(V + E)
 *
 * How to compile:
 * gcc bellman_ford.c -o bellman_ford
 * ./bellman_ford
 *
 * Example output (for the embedded sample graph):
 * Vertex   Distance from Source(0)
 * 0        0
 * 1        2
 * 2        7
 * 3        4
 * 4       -2
 */

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>

#define INF INT_MAX

/* Edge structure */
struct Edge {
    int src;
    int dest;
    int weight;
};

/* Graph structure using edge list representation */
struct Graph {
    int V;              // number of vertices
    int E;              // number of edges
    struct Edge* edges; // array of edges
};

struct Graph* createGraph(int V, int E) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->V = V;
    graph->E = E;
    graph->edges = (struct Edge*)malloc(E * sizeof(struct Edge));
    return graph;
}

void freeGraph(struct Graph* graph) {
    if (!graph) return;
    free(graph->edges);
    free(graph);
}

/* Bellman-Ford implementation */
bool bellmanFord(struct Graph* graph, int src, int* dist) {
    int V = graph->V;
    int E = graph->E;

    /* Step 1: initialize distances */
    for (int i = 0; i < V; i++) {
        dist[i] = INF;
    }
    dist[src] = 0;

    /* Step 2: relax edges V-1 times */
    for (int i = 1; i <= V - 1; i++) {
        bool updated = false;
        for (int j = 0; j < E; j++) {
            int u = graph->edges[j].src;
            int v = graph->edges[j].dest;
            int w = graph->edges[j].weight;
            if (dist[u] != INF && dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                updated = true;
            }
        }
        /* Optimization: if no update in this pass, break early */
        if (!updated) break;
    }

    /* Step 3: check for negative-weight cycles */
    for (int j = 0; j < E; j++) {
        int u = graph->edges[j].src;
        int v = graph->edges[j].dest;
        int w = graph->edges[j].weight;
        if (dist[u] != INF && dist[u] + w < dist[v]) {
            return false; // negative cycle detected
        }
    }

    return true; // no negative cycle reachable from src
}

int main() {
    /*
     * Sample graph from CLRS (classic example)
     * V = 5, E = 10
     * Edges:
     * 0 -> 1 (6)
     * 0 -> 2 (7)
     * 1 -> 2 (8)
     * 1 -> 3 (5)
     * 1 -> 4 (-4)
     * 2 -> 3 (-3)
     * 2 -> 4 (9)
     * 3 -> 1 (-2)
     * 4 -> 3 (7)
     * 4 -> 0 (2)
     *
     * Expected shortest distances from source 0:
     * 0: 0, 1: 2, 2: 7, 3: 4, 4: -2
     */

    int V = 5;
    int E = 10;
    struct Graph* graph = createGraph(V, E);

    graph->edges[0].src = 0; graph->edges[0].dest = 1; graph->edges[0].weight = 6;
    graph->edges[1].src = 0; graph->edges[1].dest = 2; graph->edges[1].weight = 7;
    graph->edges[2].src = 1; graph->edges[2].dest = 2; graph->edges[2].weight = 8;
    graph->edges[3].src = 1; graph->edges[3].dest = 3; graph->edges[3].weight = 5;
    graph->edges[4].src = 1; graph->edges[4].dest = 4; graph->edges[4].weight = -4;
    graph->edges[5].src = 2; graph->edges[5].dest = 3; graph->edges[5].weight = -3;
    graph->edges[6].src = 2; graph->edges[6].dest = 4; graph->edges[6].weight = 9;
    graph->edges[7].src = 3; graph->edges[7].dest = 1; graph->edges[7].weight = -2;
    graph->edges[8].src = 4; graph->edges[8].dest = 3; graph->edges[8].weight = 7;
    graph->edges[9].src = 4; graph->edges[9].dest = 0; graph->edges[9].weight = 2;

    int* dist = (int*)malloc(V * sizeof(int));

    int source = 0;
    bool ok = bellmanFord(graph, source, dist);

    if (!ok) {
        printf("Graph contains a negative-weight cycle reachable from source %d\n", source);
    } else {
        printf("Vertex   Distance from Source(%d)\n", source);
        for (int i = 0; i < V; i++) {
            if (dist[i] == INF) {
                printf("%d        INF\n", i);
            } else {
                printf("%d        %d\n", i, dist[i]);
            }
        }
    }

    free(dist);
    freeGraph(graph);
    return 0;
}
