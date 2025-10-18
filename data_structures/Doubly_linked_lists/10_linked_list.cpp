// Doubly Linked list
#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node* next;
    Node* prev;
    //constructor
    Node(int value) : data(value), next(nullptr), prev(nullptr) {}
};

int main()
{
    Node* head = new Node(10);
    Node* temp = new Node(20);
    Node* temp1 = new Node(30);
    head->next = temp;
    temp->prev = head;
    temp->next = temp1;
    temp1->prev = temp;
    return 0;
}