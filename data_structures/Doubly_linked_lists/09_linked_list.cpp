// Search in Linked list(Iterative and Recursive)
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
        next = NULL;
    }
};
// Iterative approach
int searchIterative(node *head, int x)
{
    int pos = 1;
    node *temp = head;
    while (temp != NULL)
    {
        if (temp->data == x)
        {
            return pos;
        }
        else
        {
            pos++;
            temp = temp->next;
        }
    }
    return -1;
}
// Recursive approach
int searchRecursive(node *head, int x)
{
    if (head == NULL)
    {
        return -1;
    }
    if (head->data == x)
    {
        return 1;
    }
    else
    {
        int res = searchRecursive(head->next, x);
        if (res == -1)
        {
            return -1;
        }
        else
        {
            return (res + 1);
        }
    }
}
int main()
{
    node *head = new node(1);
    head->next = new node(2);
    head->next->next = new node(3);
    head->next->next->next = new node(4);
    head->next->next->next->next = new node(5);

    int x = 3;
    int pos = searchIterative(head, x);
    if (pos != -1)
        cout << "Element " << x << " found at position " << pos << endl;
    else
        cout << "Element " << x << " not found" << endl;

    return 0;
}
