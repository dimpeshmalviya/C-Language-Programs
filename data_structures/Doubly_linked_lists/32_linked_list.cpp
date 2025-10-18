//detect loop in a linked list
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
//method 1 : Naive O(n^2)
//method 2 : if modification to linked list structure are allowed O(n)
//method 3 : Chnages|reference|pointers
bool isloop(node* head)
{
    node* temp = new node;
    node* curr = head;
    while(curr != nullptr)
    {
        if(curr->next == nullptr)
        {
            delete temp;
            return false;
        }
        if(curr->next == temp)
        {
            delete temp;
            return true;
        }
        node* next = curr->next;
        curr->next = temp;
        curr = next;
    }
    delete temp;
    return false;
}
//method 4 : hashing
bool isloop(node* head)
{
    unordered_set<node*> s;
    for(node* curr = head; curr != nullptr; curr = curr->next)
    {
        if(s.find(curr) != s.end())
        {
            return true;
        }
        s.insert(curr);
    }
    return false;
}
int main()
{
    node* head = new node(1);
    head->next = new node(2);
    head->next->next = new node(3);
    head->next->next->next = head->next;

    if (isloop(head))
        cout << "Loop detected";
    else
        cout << "No loop detected";

    return 0;
}