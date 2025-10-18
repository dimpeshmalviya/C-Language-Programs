//Delete last node of sdoubly linked list
#include<iostream>
using namespace std;
class node{
    public:
    int data;
    node* next;
    node* prev;
    node(int x)
    {
        data=x;
        next=NULL;
        prev=NULL;
    }
};
node *dellast(node *head)
{
    if (head == NULL) return NULL;
    if (head->next == NULL)
    {
        delete head;
        return NULL;
    }
    node* curr = head;
    while (curr->next != NULL)
    {
        curr = curr->next;
    }
    curr->prev->next = NULL;
    delete curr;
    return head;
}
int main()
{
    node* head = new node(1);
    head->next = new node(2);
    head->next->prev = head;
    head->next->next = new node(3);
    head->next->next->prev = head->next;

    head = dellast(head);

    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }

    return 0;
}