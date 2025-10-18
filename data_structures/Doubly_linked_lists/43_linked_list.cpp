// palindrome Linked list check
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

node *reverlist(node *head)
{
    node *curr = head;
    node *prev = nullptr;
    while (curr != nullptr)
    {
        node *next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

bool is_palindome(node *head)
{
    if (head == nullptr)
    {
        return true;
    }
    node *slow = head, *fast = head;
    while (fast->next != nullptr && fast->next->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    node *rev = reverlist(slow->next);
    node *curr = head;
    while (rev != nullptr)
    {
        if (rev->data != curr->data)
        {
            return false;
        }
        rev = rev->next;
        curr = curr->next;
    }
    return true;
}
int main()
{
    node *head = new node(1);
    head->next = new node(2);
    head->next->next = new node(3);
    head->next->next->next = new node(2);
    head->next->next->next->next = new node(1);

    if (is_palindome(head))
        cout << "The linked list is a palindrome.";
    else
        cout << "The linked list is not a palindrome.";

    return 0;
}