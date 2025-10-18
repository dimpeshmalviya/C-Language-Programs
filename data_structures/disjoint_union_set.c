#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/**
 * Disjoint Set Union data structure with path compression and union by rank.
 * Supports efficient set operations in near-constant amortized time.
 */
typedef struct {
    int *parent;
    int *rank;
    int *size;
    int n;
} DSU;

/**
 * Initialize DSU with n elements (0 to n-1).
 * 
 * @param n Number of elements
 * @return Pointer to initialized DSU structure
 */
DSU* dsu_init(int n) {
    DSU *dsu = (DSU*)malloc(sizeof(DSU));
    dsu->n = n;
    dsu->parent = (int*)malloc(n * sizeof(int));
    dsu->rank = (int*)calloc(n, sizeof(int));
    dsu->size = (int*)malloc(n * sizeof(int));
    
    for (int i = 0; i < n; i++) {
        dsu->parent[i] = i;
        dsu->size[i] = 1;
    }
    
    return dsu;
}

/**
 * Find representative of set containing x with path compression.
 * 
 * @param dsu Pointer to DSU structure
 * @param x Element to find
 * @return Root of the set containing x
 */
int find(DSU *dsu, int x) {
    if (dsu->parent[x] != x) {
        dsu->parent[x] = find(dsu, dsu->parent[x]);
    }
    return dsu->parent[x];
}

/**
 * Merge sets containing x and y using union by rank.
 * 
 * @param dsu Pointer to DSU structure
 * @param x First element
 * @param y Second element
 * @return true if sets were merged, false if already in same set
 */
bool union_sets(DSU *dsu, int x, int y) {
    int px = find(dsu, x);
    int py = find(dsu, y);
    
    if (px == py) {
        return false;
    }
    
    if (dsu->rank[px] < dsu->rank[py]) {
        int temp = px;
        px = py;
        py = temp;
    }
    
    dsu->parent[py] = px;
    dsu->size[px] += dsu->size[py];
    
    if (dsu->rank[px] == dsu->rank[py]) {
        dsu->rank[px]++;
    }
    
    return true;
}

/**
 * Check if x and y are in the same set.
 * 
 * @param dsu Pointer to DSU structure
 * @param x First element
 * @param y Second element
 * @return true if in same set, false otherwise
 */
bool connected(DSU *dsu, int x, int y) {
    return find(dsu, x) == find(dsu, y);
}

/**
 * Get size of set containing x.
 * 
 * @param dsu Pointer to DSU structure
 * @param x Element to query
 * @return Number of elements in the set
 */
int get_size(DSU *dsu, int x) {
    return dsu->size[find(dsu, x)];
}

/**
 * Free memory allocated for DSU.
 * 
 * @param dsu Pointer to DSU structure
 */
void dsu_free(DSU *dsu) {
    free(dsu->parent);
    free(dsu->rank);
    free(dsu->size);
    free(dsu);
}

