#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int u, v, w;
} Edge;

int find(int parent[], int i) {
    if (parent[i] == i)
        return i;
    return parent[i] = find(parent, parent[i]);
}

void unionSet(int parent[], int rank[], int u, int v) {
    int pu = find(parent, u);
    int pv = find(parent, v);
    if (rank[pu] < rank[pv])
        parent[pu] = pv;
    else if (rank[pu] > rank[pv])
        parent[pv] = pu;
    else {
        parent[pv] = pu;
        rank[pu]++;
    }
}

int compare(const void *a, const void *b) {
    return ((Edge *)a)->w - ((Edge *)b)->w;
}

void kruskal(int n, Edge edges[], int e) {
    qsort(edges, e, sizeof(Edge), compare);

    int parent[n + 1], rank[n + 1];
    for (int i = 1; i <= n; i++) {
        parent[i] = i;
        rank[i] = 0;
    }

    int totalCost = 0;
    printf("Edges in Minimum Cost Network:\n");

    for (int i = 0; i < e; i++) {
        int pu = find(parent, edges[i].u);
        int pv = find(parent, edges[i].v);

        if (pu != pv) {
            printf("%d - %d (Cost: %d)\n", edges[i].u, edges[i].v, edges[i].w);
            totalCost += edges[i].w;
            unionSet(parent, rank, pu, pv);
        }
    }

    printf("Total Minimum Cost = %d\n", totalCost);
}

int main() {
    int n = 4;
    Edge edges[] = {
        {1, 2, 5},
        {1, 3, 10},
        {2, 3, 4},
        {2, 4, 11},
        {3, 4, 9}
    };
    int e = sizeof(edges) / sizeof(edges[0]);
    kruskal(n, edges, e);
    return 0;
}