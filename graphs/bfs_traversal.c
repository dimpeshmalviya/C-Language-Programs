/**
 * @file bfs_traversal.c
 * @brief Implementation of Breadth-First Search (BFS) for a graph.
 *
 * @details
 * Program Name: Breadth-First Search (BFS) Traversal
 *
 * Problem Statement:
 * Implement the BFS algorithm to traverse a graph starting from a given
 * vertex. The graph is represented using an adjacency list. A queue is
 * used to keep track of the next vertices to visit.
 *
 * Input/Output Example:
 * - Graph Structure:
 * 0 -> 1 -> 2
 * 1 -> 0 -> 3
 * 2 -> 0 -> 3
 * 3 -> 1 -> 2
 * - Starting Vertex: 0
 * - Output (BFS Traversal): 0 1 2 3
 *
 * Complexity:
 * - Time Complexity: O(V + E), where V is the number of vertices and E is the number of edges.
 * - Space Complexity: O(V), for the visited array and the queue.
 *
 * How to compile and run:
 * gcc bfs_traversal.c -o bfs_traversal
 * ./bfs_traversal
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_VERTICES 50

// --- Queue Implementation for BFS ---
struct Queue {
    int items[MAX_VERTICES];
    int front;
    int rear;
};

struct Queue* createQueue() {
    struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
    q->front = -1;
    q->rear = -1;
    return q;
}

bool isEmpty(struct Queue* q) {
    return q->rear == -1;
}

void enqueue(struct Queue* q, int value) {
    if (q->rear == MAX_VERTICES - 1)
        printf("Queue is full!\n");
    else {
        if (q->front == -1)
            q->front = 0;
        q->rear++;
        q->items[q->rear] = value;
    }
}

int dequeue(struct Queue* q) {
    int item;
    if (isEmpty(q)) {
        printf("Queue is empty\n");
        item = -1;
    } else {
        item = q->items[q->front];
        q->front++;
        if (q->front > q->rear) {
            q->front = q->rear = -1;
        }
    }
    return item;
}

// --- Graph Implementation (Adjacency List) ---
struct Node {
    int vertex;
    struct Node* next;
};

struct Graph {
    int numVertices;
    struct Node** adjLists;
    bool* visited;
};

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
    // Add edge from src to dest
    struct Node* newNode = createNode(dest);
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;

    // Add edge from dest to src (for undirected graph)
    newNode = createNode(src);
    newNode->next = graph->adjLists[dest];
    graph->adjLists[dest] = newNode;
}

// --- BFS Algorithm ---
void BFS(struct Graph* graph, int startVertex) {
    struct Queue* q = createQueue();

    graph->visited[startVertex] = true;
    enqueue(q, startVertex);

    while (!isEmpty(q)) {
        int currentVertex = dequeue(q);
        printf("%d ", currentVertex);

        struct Node* temp = graph->adjLists[currentVertex];
        while (temp) {
            int adjVertex = temp->vertex;
            if (!graph->visited[adjVertex]) {
                graph->visited[adjVertex] = true;
                enqueue(q, adjVertex);
            }
            temp = temp->next;
        }
    }
    free(q);
}

// Main driver function
int main() {
    int numVertices = 4;
    struct Graph* graph = createGraph(numVertices);
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 2, 3);
    
    printf("Breadth First Traversal starting from vertex 0:\n");
    BFS(graph, 0);
    printf("\n");

    // Free allocated memory
    for(int i = 0; i < numVertices; i++) {
        struct Node* current = graph->adjLists[i];
        while(current != NULL) {
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