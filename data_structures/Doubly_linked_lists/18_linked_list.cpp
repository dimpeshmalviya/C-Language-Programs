//Insert at the begininig of circulat linked list
#include<iostream>

class node{
    public:
    int data;
    node* next;
    node(int x)
    {
        data=x;
        next=NULL;
    }
};

//Naive method
node* insertNaive(node *head, int x)
{
    node* temp=new node(x);
    if(head==NULL)
    {
        temp->next=temp;
    }
    else{
        node *curr=head;
        while(curr->next!=head)
        {
            curr=curr->next;
        }
    curr->next=temp;
    temp->next=head;
    }
    return temp;
}

//Efficient method
node* insertEfficient(node *head, int x)
{
    node* temp=new node(x);
    if(head==NULL)
    {
        temp->next=temp;
        return temp;
    }
    else{
        temp->next=head->next;
        head->next=temp;
        int t=head->data;
        head->data=temp->data;
        temp->data=t;
        return head;
    }
}

int main()
{
    node* head = NULL;
    head = insertEfficient(head, 10);
    head = insertEfficient(head, 20);
    head = insertEfficient(head, 30);

    node* curr = head;
    while(true)
    {
        std::cout << curr->data << " ";
        curr = curr->next;
        if(curr == head) break;
    }
    return 0;
}
