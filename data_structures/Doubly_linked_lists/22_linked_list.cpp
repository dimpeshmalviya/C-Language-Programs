// Circluar doubly linke dlist
#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *next;
    node *prev;
    node(int x)
    {
        data = x;
        next = nullptr;
        prev = nullptr;
    }
};

node* head = nullptr;

node* insertAtHead(int x)
{
    node* temp = new node(x);
    if(head == nullptr)
    {
        temp->next = temp;
        temp->prev = temp;
        head = temp;
    }
    else
    {
        temp->next = head;
        temp->prev = head->prev;
        head->prev->next = temp;
        head->prev = temp;
    }
    return head;
}

int main()
{
    head = insertAtHead(5);
    head = insertAtHead(10);
    head = insertAtHead(15);
    node* curr = head;
    while(true)
    {
        cout << curr->data << " ";
        curr = curr->next;
        if(curr == head) break;
    }
    return 0;
}
