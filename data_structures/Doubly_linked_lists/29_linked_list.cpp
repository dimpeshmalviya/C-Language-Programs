//Reverse a linked list iterative
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
//Efficient approach
node *reverlist(node* head)
{
    node* curr=head;
    node* prev=nullptr;
    while(curr!=nullptr)
    {
        node* next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
    }
    return prev;
}
int main()
{
    node* head = new node(1);
    head->next = new node(2);
    head->next->next = new node(3);
    head->next->next->next = new node(4);
    head->next->next->next->next = new node(5);

    head = reverlist(head);

    for(node* curr = head; curr != nullptr; curr = curr->next)
    {
        cout << curr->data << " ";
    }
    cout << endl;

    return 0;
}