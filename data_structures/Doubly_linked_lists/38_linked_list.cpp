// Pairwise swap nodes of a linked list
#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = nullptr;
    }
};

// Method 1
void pairwiseSwap(Node* head) {
    if (head == nullptr) {
        return;
    }

    Node* curr = head;
    while (curr != nullptr && curr->next != nullptr) {
        swap(curr->data, curr->next->data);
        curr = curr->next->next;
    }
}
int main() {
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);

    pairwiseSwap(head);

    while (head != nullptr) {
        cout << head->data << " ";
        head = head->next;
    }

    return 0;
}