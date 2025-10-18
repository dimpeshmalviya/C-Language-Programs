// Sorted insert in a singly linked list
#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *next;
    node(int x)
    {
        data = x;
        next = nullptr;
    }
};

node* sortedinsert(node* head, int x)
{
    node* temp = new node(x);
    if (head == nullptr)
    {
        return temp;
    }
    if (x < head->data)
    {
        temp->next = head;
        return temp;
    }
    node *curr = head;
    while (curr->next != nullptr && curr->next->data < x)
    {
        curr = curr->next;
    }
    temp->next = curr->next;
    curr->next = temp;
    return head;
}
int main()
{
    node* head = nullptr;
    head = sortedinsert(head, 5);
    head = sortedinsert(head, 10);
    head = sortedinsert(head, 1);
    head = sortedinsert(head, 7);
    node* curr = head;
    while (curr != nullptr)
    {
        cout << curr->data << " ";
        curr = curr->next;
    }
    return 0;
}