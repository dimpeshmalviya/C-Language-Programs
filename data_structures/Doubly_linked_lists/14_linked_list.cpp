//Delete head of doubly linked list
#include<iostream>
using namespace std;
class node{
    public:
    int data;
    node* next;
    node* prev;
    node(int x)
    {
        data=x;
        next=NULL;
        prev=NULL;
    }
};
node *delhead(node* head)
{
    if(head==NULL) return NULL;
    if(head->next==NULL)
    {
        delete head;
        return NULL;
    }
    else{
        node* temp=head;
        head=head->next;
        head->prev=NULL;
        delete temp;
        return head;
    }
}

int main() {
    node* head = new node(1);
    head->next = new node(2);
    head->prev = head;
    head->next->next = new node(3);
    head->next->prev = head->next;
    head->next->next->next = new node(4);
    head->next->next->prev = head->next->next;
    head->next->next->next->next = new node(5);
    head->next->next->next->prev = head->next->next->next;

    node* temp = head;
    cout << "Original list: ";
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;

    head = delhead(head);

    temp = head;
    cout << "Updated list: ";
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;

    return 0;
}