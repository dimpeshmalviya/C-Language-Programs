/*
Program Name: Detect Cycle in Directed Graph (Using DFS)
Problem Statement:
    Write a C program to detect if a Directed Graph contains a cycle using DFS.
Example:
    Input:
        Enter number of vertices: 4
        Enter number of edges: 4
        Enter edges (u v):
        0 1
        1 2
        2 3
        3 1
    Output:
        Cycle detected in the graph.
Compilation:
    gcc detect_cycle_directed.c -o detect_cycle
Execution:
    ./detect_cycle
Time Complexity: O(V + E)
Space Complexity: O(V)
*/

#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int adj[MAX][MAX];
int visited[MAX];
int recStack[MAX];
int n;

int dfs(int v)
{
    visited[v] = 1;
    recStack[v] = 1;

    for (int i = 0; i < n; i++)
    {
        if (adj[v][i])
        {
            if (!visited[i] && dfs(i))
                return 1;
            else if (recStack[i])
                return 1;
        }
    }

    recStack[v] = 0;
    return 0;
}

int main()
{
    int e, u, v;
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
    {
        visited[i] = 0;
        recStack[i] = 0;
    }

    int cycleFound = 0;
    for (int i = 0; i < n; i++)
    {
        if (!visited[i] && dfs(i))
        {
            cycleFound = 1;
            break;
        }
    }

    if (cycleFound)
        printf("Cycle detected in the graph.\n");
    else
        printf("No cycle found in the graph.\n");

    return 0;
}
