//insert at the begining of doubly linked list
#include<iostream>
using namespace std;
class node{
    public:
    int data;
    node* next;
    node* prev;
    node(int d)
    {
        data=d;
        next=NULL;
        prev=NULL;
    }
};
node *begininsert(node* head,int data)
{
    node* temp=new node(data);
    temp->next=head;
    if(head!=NULL)
    {
        head->prev=temp;
    }
    return temp;
}

void printlist(node* head)
{
    while(head!=NULL)
    {
        cout<<head->data<<" ";
        head=head->next;
    }
    cout<<endl;
}

int main()
{
    node* head=NULL;
    head=begininsert(head,10);
    head=begininsert(head,20);
    head=begininsert(head,30);
    printlist(head);
    return 0;
}