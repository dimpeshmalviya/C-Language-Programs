// Insert at the end of circular linked list
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

// Naive method
node *insertAtEndNaive(node *head, int x)
{
    node *temp = new node(x);
    if (head == NULL)
    {
        temp->next = temp;
        return temp;
    }
    else
    {
        node *curr = head;
        while (curr->next != head)
            curr = curr->next;
        curr->next = temp;
        temp->next = head;
        return head;
    }
}

// Efficient method
node *insertAtEndEfficient(node *head, int x)
{
    node *temp = new node(x);
    if (head == NULL)
    {
        temp->next = temp;
        return temp;
    }
    else
    {
        temp->next = head->next;
        head->next = temp;
        int t = temp->data;
        temp->data = head->data;
        head->data = t;
        return temp;
    }
}

int main()
{
    node *head = NULL;
    head = insertAtEndNaive(head, 1);
    head = insertAtEndNaive(head, 2);
    head = insertAtEndNaive(head, 3);
    head = insertAtEndNaive(head, 4);
    head = insertAtEndNaive(head, 5);

    node *temp = head;
    do
    {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head);

    cout << endl;

    head = NULL;
    head = insertAtEndEfficient(head, 1);
    head = insertAtEndEfficient(head, 2);
    head = insertAtEndEfficient(head, 3);
    head = insertAtEndEfficient(head, 4);
    head = insertAtEndEfficient(head, 5);

    temp = head;
    do
    {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head);

    cout << endl;

    return 0;
}