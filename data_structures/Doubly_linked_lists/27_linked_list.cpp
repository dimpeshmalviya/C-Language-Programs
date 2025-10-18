//Nth Node from the end of the linked list
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

//Method 2
void printnthfromend(node* head, int n)
{
    if(head==nullptr)
    {
        return ;
    }
    node* first=head;
    for(int i=0;i<n;i++)
    {
        if(first==nullptr)
        {
            return ;
        }
        first = first->next;
    }
    node* second=head;
    while(first!=nullptr)
    {
        second=second->next;
        first=first->next;
    }
    cout<<(second->data);
}

int main()
{
    node* head = new node(1);
    head->next = new node(2);
    head->next->next = new node(3);
    head->next->next->next = new node(4);
    head->next->next->next->next = new node(5);

    int n = 2;
    printnthfromend(head, n);

    return 0;
}