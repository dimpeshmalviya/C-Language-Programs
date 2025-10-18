//LRU Cache design
#include<iostream>
#include<list>
#include<unordered_map>

using namespace std;

class Node {
    public :
    int key;
    int value;
    Node(int k, int v) : key(k), value(v) {}
};

class LRUCache {
private:
    int capacity;
    list<Node> dll;
    unordered_map<int, list<Node>::iterator> hashTable;

public:
    LRUCache(int c) : capacity(c) {}

    void refer(int x) {
        if (hashTable.find(x) != hashTable.end()) {
            Node node = *hashTable[x];
            dll.erase(hashTable[x]);
            dll.push_front(node);
            hashTable[x] = dll.begin();
        } else {
            if (dll.size() == capacity) {
                hashTable.erase(dll.rbegin()->key);
                dll.pop_back();
            }
            dll.push_front(Node(x, x));
            hashTable[x] = dll.begin();
        }
    }
};

int main() {
    LRUCache cache(2);
    cache.refer(1);
    cache.refer(2);
    cache.refer(1);
    cache.refer(3);
    cache.refer(4);
    return 0;
}