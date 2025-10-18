//Detect and remove loop from linked list
#include<iostream>
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

bool isLoop(Node* head) {
    if (head == nullptr || head->next == nullptr) {
        return false;
    }

    Node* slow_p = head;
    Node* fast_p = head;

    while (fast_p != nullptr && fast_p->next != nullptr) {
        slow_p = slow_p->next;
        fast_p = fast_p->next->next;

        if (slow_p == fast_p) {
            return true;
        }
    }
    return false;
}

void removeLoop(Node* head) {
    Node* slow_p = head;
    Node* fast_p = head;

    while (fast_p != nullptr && fast_p->next != nullptr) {
        slow_p = slow_p->next;
        fast_p = fast_p->next->next;

        if (slow_p == fast_p) {
            break;
        }
    }

    if (slow_p == fast_p) {
        slow_p = head;
        while (slow_p->next != fast_p->next) {
            slow_p = slow_p->next;
            fast_p = fast_p->next;
        }
        fast_p->next = nullptr;
    }
}

int main() {
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = head->next;

    if (isLoop(head)) {
        removeLoop(head);
        cout << "Loop detected and removed from the linked list." << endl;
    } else {
        cout << "No loop detected in the linked list." << endl;
    }

    return 0;
}