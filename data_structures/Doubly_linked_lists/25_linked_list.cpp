//Middle of linked list
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

//Efficient solution
void printMiddle(node* head)
{
    if(head==nullptr)
    {
        return;
    }
    node* slow=head,*fast=head;
    while(fast!=nullptr&&fast->next!=nullptr)
    {
        slow=slow->next;
        fast=fast->next->next;
    }
    cout<<(slow->data);
}

int main()
{
    node* head = new node(1);
    head->next = new node(2);
    head->next->next = new node(3);
    head->next->next->next = new node(4);
    head->next->next->next->next = new node(5);

    printMiddle(head);

    return 0;
}