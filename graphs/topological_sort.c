/*
Program Name: Topological Sort (Using DFS)
Problem Statement:
    Write a C program to perform Topological Sorting on a Directed Acyclic Graph (DAG)
    using Depth-First Search (DFS).
Example:
    Input:
        Enter number of vertices: 6
        Enter number of edges: 6
        Enter edges (u v):
        5 2
        5 0
        4 0
        4 1
        2 3
        3 1
    Output:
        Topological Sort: 5 4 2 3 1 0
Compilation:
    gcc topological_sort.c -o topo
Execution:
    ./topo
Time Complexity: O(V + E)
Space Complexity: O(V)
*/

#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int adj[MAX][MAX];
int visited[MAX];
int stack[MAX];
int top = -1;

void dfs(int v, int n)
{
    visited[v] = 1;
    for (int i = 0; i < n; i++)
    {
        if (adj[v][i] && !visited[i])
            dfs(i, n);
    }
    stack[++top] = v;
}

int main()
{
    int n, e, u, v;
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    printf("Enter number of edges: ");
    scanf("%d", &e);

    for (int i = 0; i < e; i++)
    {
        scanf("%d%d", &u, &v);
        adj[u][v] = 1;
    }

    for (int i = 0; i < n; i++)
        visited[i] = 0;

    for (int i = 0; i < n; i++)
        if (!visited[i])
            dfs(i, n);

    printf("Topological Sort: ");
    while (top >= 0)
        printf("%d ", stack[top--]);
    printf("\n");

    return 0;
}
