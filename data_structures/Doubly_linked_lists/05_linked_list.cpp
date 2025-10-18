//Insert at the end of singly linked list
#include <iostream>
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

node *insertend(node* head, int x)
{
    node *temp=new node(x);
    if(head==nullptr)
    {
        return temp;
    }
    node* curr=head;
    while(curr->next!=NULL)
    {
        curr=curr->next;
    }
    curr->next=temp;
    return head;
}

int main()
{
    node* head=NULL;
    head=insertend(head,10);
    head=insertend(head,20);
    head=insertend(head,30);
    return 0;
}