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

//Method 1
void printnthfromend(node* head, int n)
{
    int len = 0;
    node* curr = head;
    for(; curr != nullptr; curr = curr->next)
    {
        len++;
    }
    if(n > len)
    {
        return;
    }
    curr = head;
    for(int i = 1; i < len - n + 1; i++)
    {
        curr = curr->next;
    }
    cout << (curr->data) << " ";
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