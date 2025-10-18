//travesing a linked list
#include<iostream>
using namespace std;

class node
{
    public:
    int data ;
    node* next;
    node(int x)
    {
        data=x;
        next=NULL;
    }
};

void printlist(node* head)
{
    node* curr=head;
    while(curr!=nullptr)
    {
        cout<<(curr->data)<<"->";
        curr=curr->next;
    }
    cout << "NULL" << endl;
}

void printList(node* head)
{
    while(head!=nullptr)
    {
        cout<<(head->data)<<"->";
        head=head->next;
    }
    cout << "NULL" << endl;
}

int main()
{
    node * head=new node(10);
    head->next = new node(20);
    head->next->next = new node(30);
    printlist(head);
    printList(head);
    return 0;
}