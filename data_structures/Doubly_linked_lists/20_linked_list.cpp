//Delete head of circular lined list
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
//Naive method
node* deleteHead(node* head)
{
    if (head == NULL)return NULL;
    if(head->next==head)
    {
        delete head;
        return NULL;
    }
    node *curr=head;
    while(curr->next!=head)
    {
        curr=curr->next;
    }
    curr->next=head->next;
    delete head;
    return curr->next;
}
//Efficient method
node* deleteHead(node* head)
{
    if (head == NULL) return NULL;
    if (head->next == head)
    {
        delete head;
        return NULL;
    }
    head->data = head->next->data;
    node* temp = head->next;
    head->next = head->next->next;
    delete temp;
    return head;
}
int main()
{
    node* head = new node(1);
    head->next = new node(2);
    head->next->next = new node(3);
    head->next->next->next = head;

    head = deleteHead(head);

    while(head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }

    return 0;
}