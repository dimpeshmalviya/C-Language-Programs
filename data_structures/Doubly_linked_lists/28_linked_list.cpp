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
//Naive method
node *reverlist(node* head)
{
    vector<int>arr;
    for(node* curr=head;curr!=nullptr;curr=curr->next)
    {
        arr.push_back(curr->data);
        
    }
    for(node* curr=head;curr!=nullptr;curr=curr->next)
    {
        arr.pop_back();
        
    }
    return head;
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