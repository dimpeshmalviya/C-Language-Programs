// Delete kth of a circular linked list
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

node *deletekth(node *head, int k)
{
    if (head == NULL)
        return head;
    if (k == 1)
    {
        node *temp = head;
        while (temp->next != head)
            temp = temp->next;
        temp->next = head->next;
        delete head;
        return temp->next;
    }
    node *curr = head;
    for (int i = 0; i < k - 2; i++)
    {
        if (curr->next == head)
            return head;
        curr = curr->next;
    }
    node *temp = curr->next;
    curr->next = curr->next->next;
    delete temp;
    return head;
}
int main()
{
    node *head = new node(1);
    head->next = new node(2);
    head->next->next = new node(3);
    head->next->next->next = new node(4);
    head->next->next->next->next = new node(5);
    head->next->next->next->next->next = head;

    head = deletekth(head, 3);

    node *temp = head;
    while (true)
    {
        cout << temp->data << " ";
        temp = temp->next;
        if (temp == head)
            break;
    }

    return 0;
}