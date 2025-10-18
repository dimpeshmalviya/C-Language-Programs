// Remove duplicates from a sorted singly linked list
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

node* removeDups(node* head)
{
    if (head == nullptr) return head;

    node *curr = head;
    while (curr != nullptr && curr->next != nullptr)
    {
        if (curr->data == curr->next->data)
        {
            node* temp = curr->next;
            curr->next = curr->next->next;
            delete(temp);
        }
        else {
            curr = curr->next;
        }
    }
    return head; 
}
int main()
{
    node* head = new node(1);
    head->next = new node(1);
    head->next->next = new node(2);
    head = removeDups(head);
    while (head != nullptr)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
    return 0;
}