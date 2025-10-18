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

// Method 2
Node* pairwiseSwap(Node* head) {
    if (head == nullptr || head->next == nullptr) {
        return head;
    }
    Node* curr = head->next;
    Node* prev = head;
    head = head->next;
    while(curr != nullptr && curr->next != nullptr) {
        prev->next = curr->next;
        prev = curr;
        Node* next = curr->next->next;
        curr->next->next = curr;
        curr = next;
    }
    prev->next = curr;
    return head;
}

int main() {
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);

    head = pairwiseSwap(head);

    while (head != nullptr) {
        cout << head->data << " ";
        head = head->next;
    }

    return 0;
}