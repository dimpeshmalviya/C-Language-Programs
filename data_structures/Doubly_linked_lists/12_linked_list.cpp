//Insert at end doubly linked list
#include<iostream>
using namespace std;

class node{
    public:
    int data;
    node *next;
    node *prev;
    node (int x)
    {
        data=x;
        next=NULL;
        prev=NULL;
    }
};

node *insertend(node *head , int data)
{
    node *temp=new node(data);
    if(head==NULL)
    {
        return temp;
    }
    node *curr=head;
    while(curr->next!=NULL)
    {
        curr=curr->next;
    }
    curr->next=temp;
    temp->prev=curr;
    return head;
}

int main()
{
    node *head=NULL;
    head=insertend(head,10);
    head=insertend(head,20);
    return 0;
}