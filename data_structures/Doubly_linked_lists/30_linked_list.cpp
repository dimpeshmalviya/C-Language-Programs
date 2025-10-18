// Recursive reverse a linked list
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
// method 1
node *recRev(node *head)
{
    if (head == nullptr)
    {
        return nullptr;
    }
    node *rest_head = recRev(head->next);
    node *rest_tail = rest_head;
    while (rest_tail->next != nullptr)
    {
        rest_tail = rest_tail->next;
    }
    rest_tail->next = head;
    head->next = nullptr;
    return rest_head;
}
// method 2
node *recrev(node *curr, node *prev)
{
    if (curr == nullptr)
    {
        return prev;
    }
    node *next = curr->next;
    curr->next = prev;
    return recrev(next, curr);
}
int main()
{
    node *head = new node(1);
    head->next = new node(2);
    head->next->next = new node(3);
    head->next->next->next = new node(4);
    head->next->next->next->next = new node(5);

    head = recRev(head);

    while (head != nullptr)
    {
        cout << head->data << " ";
        head = head->next;
    }

    return 0;
}