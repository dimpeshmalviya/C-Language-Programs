//Segregate even and odd nodes of a linked list
#include<iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = nullptr;
    }
};

class LinkedList {
public:
    Node* head;

    LinkedList() {
        head = nullptr;
    }

    void append(int value) {
        Node* newNode = new Node(value);
        if (head == nullptr) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    void segregateEvenOdd() {
        Node* evenHead = nullptr;
        Node* oddHead = nullptr;
        Node* evenTail = nullptr;
        Node* oddTail = nullptr;

        Node* temp = head;
        while (temp != nullptr) {
            if (temp->data % 2 == 0) {
                if (evenHead == nullptr) {
                    evenHead = temp;
                    evenTail = temp;
                } else {
                    evenTail->next = temp;
                    evenTail = temp;
                }
            } else {
                if (oddHead == nullptr) {
                    oddHead = temp;
                    oddTail = temp;
                } else {
                    oddTail->next = temp;
                    oddTail = temp;
                }
            }
            temp = temp->next;
        }

        if (evenHead == nullptr) {
            head = oddHead;
        } else {
            head = evenHead;
            evenTail->next = oddHead;
        }
        if (oddTail != nullptr) {
            oddTail->next = nullptr;
        }
    }

    void printList() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    LinkedList list;
    list.append(1);
    list.append(2);
    list.append(3);
    list.append(4);
    list.append(5);
    list.append(6);

    cout << "Original List: ";
    list.printList();

    list.segregateEvenOdd();

    cout << "Segregated List: ";
    list.printList();

    return 0;
}