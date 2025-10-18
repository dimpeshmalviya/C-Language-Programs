/**
 * @file dfs_traversal.c
 * @brief Implementation of Depth-First Search (DFS) for a graph.
 *
 * @details
 * Program Name: Depth-First Search (DFS) Traversal
 *
 * Problem Statement:
 * Implement the DFS algorithm to traverse a graph starting from a given
 * vertex. The graph is represented using an adjacency list. Recursion is
 * used to explore nodes depth-first.
 *
 * Input/Output Example:
 * - Graph Structure:
 * 0 -> 1 -> 2
 * 1 -> 0 -> 3
 * 2 -> 0 -> 3
 * 3 -> 1 -> 2
 * - Starting Vertex: 0
 * - Output (DFS Traversal): 0 2 3 1   (one valid DFS order)
 *
 * Complexity:
 * - Time Complexity: O(V + E), where V is the number of vertices and E is the number of edges.
 * - Space Complexity: O(V), for the visited array and recursion stack.
 *
 * How to compile and run:
 * gcc dfs_traversal.c -o dfs_traversal
 * ./dfs_traversal
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_VERTICES 50

// --- Node and Graph Structures ---
struct Node {
    int vertex;
    struct Node* next;
};

struct Graph {
    int numVertices;
    struct Node** adjLists;
    bool* visited;
};

// --- Utility Functions ---
struct Node* createNode(int v) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

struct Graph* createGraph(int vertices) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->numVertices = vertices;
    graph->adjLists = (struct Node**)malloc(vertices * sizeof(struct Node*));
    graph->visited = (bool*)malloc(vertices * sizeof(bool));

    for (int i = 0; i < vertices; i++) {
        graph->adjLists[i] = NULL;
        graph->visited[i] = false;
    }
    return graph;
}

void addEdge(struct Graph* graph, int src, int dest) {
    // Add edge src -> dest
    struct Node* newNode = createNode(dest);
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;

    // Add edge dest -> src (for undirected graph)
    newNode = createNode(src);
    newNode->next = graph->adjLists[dest];
    graph->adjLists[dest] = newNode;
}

// --- DFS Algorithm ---
void DFS(struct Graph* graph, int vertex) {
    graph->visited[vertex] = true;
    printf("%d ", vertex);

    struct Node* temp = graph->adjLists[vertex];
    while (temp != NULL) {
        int adjVertex = temp->vertex;
        if (!graph->visited[adjVertex]) {
            DFS(graph, adjVertex);
        }
        temp = temp->next;
    }
}

// Main driver
int main() {
    int numVertices = 4;
    struct Graph* graph = createGraph(numVertices);

    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 2, 3);

    printf("Depth First Traversal starting from vertex 0:\n");
    DFS(graph, 0);
    printf("\n");

    // Cleanup memory
    for (int i = 0; i < numVertices; i++) {
        struct Node* current = graph->adjLists[i];
        while (current != NULL) {
            struct Node* to_free = current;
            current = current->next;
            free(to_free);
        }
    }
    free(graph->adjLists);
    free(graph->visited);
    free(graph);

    return 0;
}
