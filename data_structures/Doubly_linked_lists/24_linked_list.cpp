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

//Naive solution
void printMiddle(node* head)
{
    if(head==NULL)
    {
        return;
    }
    int count=0;
    node* curr;
    for(curr=head;curr!=nullptr;curr=curr->next)
    {
        count++;
    }
    curr = head;
    for(int i=0;i<count/2;i++)
    {
        curr=curr->next;
    }
    cout << curr->data;
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