/*
Program name: Queue using Array
Problem statement: Implement a queue data structure using an array in C.
Input / Output examples:
Queue operations:
1. Enqueue 10
2. Enqueue 20
3. Dequeue (returns 10)
4. Enqueue 30
5. Front (returns 20)
6. Dequeue (returns 20)
7. IsEmpty (returns false)
Complexity:
Enqueue: O(1) (amortized)
Dequeue: O(1) (amortized)
Front: O(1)
IsEmpty: O(1)
IsFull: O(1)
*/

#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 5 // Maximum size of the queue

int queue[MAX_SIZE];
int front = -1, rear = -1;

// Function to check if the queue is empty
int isEmpty() {
    return front == -1;
}

// Function to check if the queue is full
int isFull() {
    return (rear + 1) % MAX_SIZE == front;
}

// Function to add an element to the queue (Enqueue)
void enqueue(int value) {
    if (isFull()) {
        printf("Queue is full! Cannot enqueue %d\n", value);
    } else {
        if (isEmpty()) {
            front = 0;
        }
        rear = (rear + 1) % MAX_SIZE;
        queue[rear] = value;
        printf("%d enqueued to queue.\n", value);
    }
}

// Function to remove an element from the queue (Dequeue)
int dequeue() {
    int value;
    if (isEmpty()) {
        printf("Queue is empty! Cannot dequeue.\n");
        return -1; // Indicate error or empty queue
    } else {
        value = queue[front];
        if (front == rear) { // Last element in queue
            front = -1;
            rear = -1;
        } else {
            front = (front + 1) % MAX_SIZE;
        }
        printf("%d dequeued from queue.\n", value);
        return value;
    }
}

// Function to get the front element of the queue
int peek() {
    if (isEmpty()) {
        printf("Queue is empty! No front element.\n");
        return -1; // Indicate error or empty queue
    } else {
        return queue[front];
    }
}

// Function to display the elements of the queue
void display() {
    if (isEmpty()) {
        printf("Queue is empty.\n");
    } else {
        printf("Queue elements: ");
        int i = front;
        while (i != rear) {
            printf("%d ", queue[i]);
            i = (i + 1) % MAX_SIZE;
        }
        printf("%d\n", queue[rear]);
    }
}

int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    enqueue(50);
    enqueue(60); // This should show queue full

    display();

    dequeue();
    dequeue();

    display();

    printf("Front element is: %d\n", peek());

    enqueue(70);
    display();

    return 0;
}