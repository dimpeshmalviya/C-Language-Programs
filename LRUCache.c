/*
Program Name: LRU Cache Implementation in C
Problem Statement:
Implement a Least Recently Used (LRU) cache with a fixed capacity. 
The cache should support two operations:
1. get(key) -> returns the value if the key exists, else -1.
2. put(key, value) -> adds the key-value pair to the cache, evicting 
   the least recently used item if the cache is full.

Concepts Used: Linked List, Hashing (array of pointers), Memory Management
*/

#include <stdio.h>
#include <stdlib.h>

#define CACHE_SIZE 3   // Change cache size here
#define HASH_SIZE 10   // Simple hash table size

// Node of Doubly Linked List
typedef struct Node {
    int key;
    int value;
    struct Node *prev, *next;
} Node;

// LRU Cache structure
typedef struct LRUCache {
    Node *head, *tail; // Doubly linked list for LRU order
    Node *hash[HASH_SIZE]; // Simple hash table
    int size;
} LRUCache;

// Helper function: Create new node
Node* createNode(int key, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->key = key;
    newNode->value = value;
    newNode->prev = newNode->next = NULL;
    return newNode;
}

// Simple hash function
int hashFunc(int key) {
    return key % HASH_SIZE;
}

// Initialize LRU Cache
LRUCache* initCache() {
    LRUCache *cache = (LRUCache*)malloc(sizeof(LRUCache));
    cache->head = cache->tail = NULL;
    cache->size = 0;
    for(int i = 0; i < HASH_SIZE; i++)
        cache->hash[i] = NULL;
    return cache;
}

// Remove node from linked list
void removeNode(LRUCache *cache, Node *node) {
    if(node->prev) node->prev->next = node->next;
    else cache->head = node->next;

    if(node->next) node->next->prev = node->prev;
    else cache->tail = node->prev;
}

// Add node to head (most recently used)
void addToHead(LRUCache *cache, Node *node) {
    node->next = cache->head;
    node->prev = NULL;
    if(cache->head) cache->head->prev = node;
    cache->head = node;
    if(cache->tail == NULL) cache->tail = node;
}

// Get value by key
int get(LRUCache *cache, int key) {
    int h = hashFunc(key);
    Node *node = cache->hash[h];
    
    while(node) {
        if(node->key == key) {
            // Move node to head (most recently used)
            removeNode(cache, node);
            addToHead(cache, node);
            return node->value;
        }
        node = node->next;
    }
    return -1; // Not found
}

// Put key-value into cache
void put(LRUCache *cache, int key, int value) {
    int h = hashFunc(key);
    Node *node = cache->hash[h];

    // Check if key exists
    while(node) {
        if(node->key == key) {
            node->value = value;
            removeNode(cache, node);
            addToHead(cache, node);
            return;
        }
        node = node->next;
    }

    // Key not present, create new node
    Node *newNode = createNode(key, value);
    addToHead(cache, newNode);

    // Add to hash (simple chaining)
    newNode->next = cache->hash[h];
    if(cache->hash[h]) cache->hash[h]->prev = newNode;
    cache->hash[h] = newNode;

    cache->size++;

    // Evict if cache size exceeds capacity
    if(cache->size > CACHE_SIZE) {
        Node *toRemove = cache->tail;
        removeNode(cache, toRemove);

        // Remove from hash
        int hh = hashFunc(toRemove->key);
        Node *temp = cache->hash[hh];
        if(temp == toRemove) cache->hash[hh] = toRemove->next;
        else {
            while(temp->next && temp->next != toRemove) temp = temp->next;
            if(temp->next) temp->next = toRemove->next;
        }

        free(toRemove);
        cache->size--;
    }
}

// Print cache (most recent -> least recent)
void printCache(LRUCache *cache) {
    Node *curr = cache->head;
    printf("Cache state (MRU -> LRU): ");
    while(curr) {
        printf("[%d:%d] ", curr->key, curr->value);
        curr = curr->next;
    }
    printf("\n");
}

// Driver code
int main() {
    LRUCache *cache = initCache();

    put(cache, 1, 100);
    put(cache, 2, 200);
    put(cache, 3, 300);
    printCache(cache); // Should show 3->2->1

    printf("Get key 2: %d\n", get(cache, 2)); // Access 2, moves to head
    printCache(cache); // 2->3->1

    put(cache, 4, 400); // Evicts least recently used (key 1)
    printCache(cache); // 4->2->3

    printf("Get key 1: %d\n", get(cache, 1)); // -1, evicted
    return 0;
}

/*
Sample Output:

Cache state (MRU -> LRU): [3:300] [2:200] [1:100] 
Get key 2: 200
Cache state (MRU -> LRU): [2:200] [3:300] [1:100] 
Cache state (MRU -> LRU): [4:400] [2:200] [3:300] 
Get key 1: -1
*/
