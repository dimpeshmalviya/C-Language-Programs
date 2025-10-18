#include <bits/stdc++.h>
using namespace std;

// Node structure for the cache
struct Node {
    int key, value, freq;
    Node *prev, *next;
    Node(int k, int v) : key(k), value(v), freq(1), prev(nullptr), next(nullptr) {}
};

// Doubly Linked List to store nodes of same frequency
class DLList {
public:
    Node *head, *tail;
    int size;

    DLList() {
        head = new Node(0, 0);
        tail = new Node(0, 0);
        head->next = tail;
        tail->prev = head;
        size = 0;
    }

    void addNode(Node *node) {
        node->next = head->next;
        node->prev = head;
        head->next->prev = node;
        head->next = node;
        size++;
    }

    void removeNode(Node *node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
        size--;
    }

    Node* removeLast() {
        if (size == 0) return nullptr;
        Node *node = tail->prev;
        removeNode(node);
        return node;
    }
};

class LFUCache {
public:
    int capacity, minFreq;
    unordered_map<int, Node*> keyNode;
    unordered_map<int, DLList*> freqList;

    LFUCache(int capacity) {
        this->capacity = capacity;
        minFreq = 0;
    }

    void updateFreq(Node *node) {
        int freq = node->freq;
        freqList[freq]->removeNode(node);

        if (freq == minFreq && freqList[freq]->size == 0)
            minFreq++;

        node->freq++;
        if (!freqList.count(node->freq))
            freqList[node->freq] = new DLList();

        freqList[node->freq]->addNode(node);
    }

    int get(int key) {
        if (!keyNode.count(key)) return -1;
        Node *node = keyNode[key];
        updateFreq(node);
        return node->value;
    }

    void put(int key, int value) {
        if (capacity == 0) return;

        if (keyNode.count(key)) {
            Node *node = keyNode[key];
            node->value = value;
            updateFreq(node);
        } else {
            if (keyNode.size() >= capacity) {
                DLList *list = freqList[minFreq];
                Node *toRemove = list->removeLast();
                keyNode.erase(toRemove->key);
            }

            Node *newNode = new Node(key, value);
            minFreq = 1;

            if (!freqList.count(minFreq))
                freqList[minFreq] = new DLList();

            freqList[minFreq]->addNode(newNode);
            keyNode[key] = newNode;
        }
    }
};

int main() {
    LFUCache lfu(2);

    lfu.put(1, 1);
    lfu.put(2, 2);
    cout << lfu.get(1) << endl; // returns 1

    lfu.put(3, 3); // evicts key 2
    cout << lfu.get(2) << endl; // returns -1 (not found)
    cout << lfu.get(3) << endl; // returns 3

    lfu.put(4, 4); // evicts key 1
    cout << lfu.get(1) << endl; // returns -1 (not found)
    cout << lfu.get(3) << endl; // returns 3
    cout << lfu.get(4) << endl; // returns 4

    return 0;
}
