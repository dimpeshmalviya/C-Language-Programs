// merge two sorted linked list
#include <iostream>

using namespace std;

class Node
{
public:
    int key;
    int value;
    Node* next;
    Node(int k, int v) : key(k), value(v), next(nullptr) {}
};

Node* sortedmerge(Node* a, Node* b)
{
    if (a == nullptr)
        return b;
    if (b == nullptr)
        return a;
    Node* head = nullptr;
    Node* tail = nullptr;
    if (a->key <= b->key) 
    {
        head = tail = a;
        a = a->next;
    }
    else
    {
        head = tail = b;
        b = b->next;
    }
    while (a != nullptr && b != nullptr)
    {
        if (a->key < b->key) 
        {
            tail->next = a;
            tail = a;
            a = a->next;
        }
        else
        {
            tail->next = b;
            tail = b;
            b = b->next;
        }
    }
    if (a == nullptr)
    {
        tail->next = b;
    }
    else
    {
        tail->next = a;
    }
    return head;
}
int main() {
    Node* a = new Node(1, 10);
    a->next = new Node(3, 30);
    a->next->next = new Node(5, 50);

    Node* b = new Node(2, 20);
    b->next = new Node(4, 40);

    Node* merged = sortedmerge(a, b);

    while (merged != nullptr) {
        cout << "Key: " << merged->key << ", Value: " << merged->value << endl;
        merged = merged->next;
    }

    return 0;
}