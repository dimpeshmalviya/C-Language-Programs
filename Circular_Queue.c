#include <stdio.h>
#include <stdlib.h>

#define SIZE 5  // maximum size of the circular queue

int queue[SIZE];
int front = -1, rear = -1;

// Function to check if queue is full
int isFull() {
    return (front == 0 && rear == SIZE - 1) || (rear + 1 == front);
}

// Function to check if queue is empty
int isEmpty() {
    return (front == -1);
}

// Function to insert (enqueue) an element
void enqueue(int value) {
    if (isFull()) {
        printf("Queue is full! (Overflow)\n");
    } else {
        if (front == -1)  // first element
            front = 0;
        rear = (rear + 1) % SIZE;  // circular increment
        queue[rear] = value;
        printf("Inserted %d into the queue.\n", value);
    }
}

// Function to delete (dequeue) an element
void dequeue() {
    if (isEmpty()) {
        printf("Queue is empty! (Underflow)\n");
    } else {
        printf("Deleted %d from the queue.\n", queue[front]);
        if (front == rear) {
            // Only one element was present
            front = rear = -1;
        } else {
            front = (front + 1) % SIZE;  // circular increment
        }
    }
}

// Function to display the queue
void display() {
    if (isEmpty()) {
        printf("Queue is empty.\n");
    } else {
        printf("Queue elements are: ");
        int i = front;
        while (1) {
            printf("%d ", queue[i]);
            if (i == rear)
                break;
            i = (i + 1) % SIZE;
        }
        printf("\n");
    }
}

int main() {
    int choice, value;

    while (1) {
        printf("\n--- Circular Queue Menu ---\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                enqueue(value);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}
