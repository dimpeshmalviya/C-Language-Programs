//clone a linked list using a random pointer
#include <iostream>

using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* random;

    Node(int value) {
        data = value;
        next = nullptr;
        random = nullptr;
    }
};

Node* clone(Node* head) {
    Node* curr = head;
    Node* temp;

    // create a copy of each node and link them together
    while (curr != nullptr) {
        temp = new Node(curr->data);
        temp->next = curr->next;
        curr->next = temp;
        curr = temp->next;
    }

    // assign random pointers to the cloned nodes
    curr = head;
    while (curr != nullptr) {
        if (curr->random != nullptr) {
            curr->next->random = curr->random->next;
        }
        curr = curr->next->next;
    }

    // separate the original and cloned lists
    Node* original = head;
    Node* cloned = head->next;
    temp = cloned;

    while (original != nullptr && cloned != nullptr) {
        original->next = original->next->next;
        original = original->next;

        if (original != nullptr) {
            cloned->next = original->next;
            cloned = cloned->next;
        }
    }

    return temp;
}

int main() {
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    head->random = head->next->next;
    head->next->random = head;
    head->next->next->random = head->next->next->next->next;
    head->next->next->next->random = head->next->next->next->next;
    head->next->next->next->next->random = head->next;

    Node* clonedHead = clone(head);

    // print the cloned list
    while (clonedHead != nullptr) {
        cout << clonedHead->data << " ";
        clonedHead = clonedHead->next;
    }

    return 0;
}