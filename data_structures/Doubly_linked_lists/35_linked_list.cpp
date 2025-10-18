//delete node with only one pointer given to it
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

void deletenode(Node* ptr)
{
    if (ptr == nullptr) {
        return; 
    }

    if (ptr->next == nullptr) {
        delete ptr; 
        return;
    }

    Node* temp = ptr->next;
    ptr->data = temp->data;
    ptr->next = temp->next;
    delete(temp);
}
int main() {
    Node* head = new Node(1);
    head->next = new Node(2);
    deletenode(head);
    return 0;
}