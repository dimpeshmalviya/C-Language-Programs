// Queue Operations implemented using Linked list
/*
1.Enqueue(to Insert elements)
2.Dequeue(to delete/remove elements)
3.Peek(to diplay the topmost elemet without deleting)
4.Display(print/display all the elements in the queue)
5.IsEmpty(To check if the queue is Empty)
*/

//code
#include <stdio.h>
#include <stdlib.h>

//defining node
struct Node {
    int data;
    struct Node* next;
};

//defining queue
struct Queue {
    struct Node* front;
    struct Node* rear;
};

//creating newnode
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

//creating queue
struct Queue* createQueue() {
    struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
    q->front = q->rear = NULL;
    return q;
}

//defining isempty
int isEmpty(struct Queue* q) {
    return (q->front == NULL);
}

//Enqueue operation
void enqueue(struct Queue* q, int value) {
    struct Node* newNode = createNode(value);
    if (q->rear == NULL) {
        q->front = q->rear = newNode;
        return;
    }
    q->rear->next = newNode;
    q->rear = newNode;
}

//Dequeue operation
int dequeue(struct Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty!\n");
        return -1;
    }
    struct Node* temp = q->front;
    int data = temp->data;
    q->front = q->front->next;
    if (q->front == NULL)
        q->rear = NULL;
    free(temp);
    return data;
}

//peek operation
int front(struct Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty!\n");
        return -1;
    }
    return q->front->data;
}

//display operation
void display(struct Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty!\n");
        return;
    }
    struct Node* temp = q->front;
    printf("Queue: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

//Sample input and output
/*
int main() {
    struct Queue* q = createQueue();

    enqueue(q, 10);
    enqueue(q, 20);
    enqueue(q, 30);
    display(q);

    printf("Dequeued: %d\n", dequeue(q));
    display(q);

    printf("Front element: %d\n", front(q));

    enqueue(q, 40);
    display(q);

    while (!isEmpty(q)) {
        printf("Dequeued: %d\n", dequeue(q));
    }
    display(q);

    return 0;
}
*/