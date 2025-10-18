// Circular linked list traversal
#include<iostream>
using namespace std;

class node {
public:
    int data;
    node* next;
    node(int x) {
        data = x;
        next = NULL;
    }
};

// Method 1
void printlist(node* head) {
    if (head == NULL) return;
    cout << (head->data) << "->";
    for (node* p = head->next; p != head; p = p->next) {
        cout << (p->data) << "->";
    }
    cout << endl;
}

// Method 2
void printlist2(node* head) {
    if (head == NULL) return;
    node* p = head;
    do {
        cout << (p->data);
        if (p->next != head) cout << "->";
        p = p->next;
    } while (p != head);
    cout << endl;
}

int main() {
    node* head = new node(10);
    head->next = new node(20);
    head->next->next = new node(30);
    head->next->next->next = new node(40);
    head->next->next->next->next = head;

    printlist(head);
    printlist2(head);

    return 0;
}