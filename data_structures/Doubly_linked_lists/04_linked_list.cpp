//Recursively display the linked list and also insert at begining of singly linked list
#include<iostream>
using namespace std;

class node{
    int data;
    node* next;
public:
    node(int x){
        data = x;
        next = NULL;
    }
    void display(node *head);
    node* insertbegin(node *head, int x);
};

void node::display(node *head)
{
    if(head == NULL)
        return;
    cout << head->data << "->";
    display(head->next);
}

node* node::insertbegin(node *head, int x)
{
    node* temp=new node(x);
    temp->next=head;
    return temp;
}

int main()
{
    node *head=NULL;
    head=head->insertbegin(head,10);
    head=head->insertbegin(head,20);
    head=head->insertbegin(head,30);
    head->display(head);
    return 0;
}