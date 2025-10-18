//Reverse a doubly linked list
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
node *reverseDll(node *head)
{
    if(head==NULL||head->next==NULL)
    {
        return head;
    }
    node* prev=NULL;
    node* curr=head;
    while(curr!=NULL)
    {
        prev=curr->prev;
        curr->prev=curr->next;
        curr->next=prev;
        prev=curr;
        curr=curr->prev;
    }
    return prev;
}
void printList(node* head) {
    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}
int main() {
    node* head = new node(1);
    head->next = new node(2);
    head->next->prev = head;
    head->next->next = new node(3);
    head->next->next->prev = head->next;
    head->next->next->next = new node(4);
    head->next->next->next->prev = head->next->next;
    cout << "Original List: ";
    printList(head);
    head = reverseDll(head);
    cout << "Reversed List: ";
    printList(head);
    return 0;
}