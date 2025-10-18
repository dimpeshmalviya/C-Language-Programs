//simple Linked List Implementation
#include<iostream>
using namespace std;
class node
{
    int data;
    node* next; // self-referential structure
public:
    node(int x) // constructor
    {
        data = x;
        next = nullptr;
    }

    void setNext(node* n) { next = n; }
};
int main()
{
    node *head = new node(10);
    node *temp1 = new node(20);
    node *temp2 = new node(30);
    head->setNext(temp1);
    temp1->setNext(temp2);
    return 0;
}