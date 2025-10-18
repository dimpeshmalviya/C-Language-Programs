#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Queue {
    struct Node* front;
    struct Node* rear;
};

int isEmpty(struct Queue* q){
    return (q->front == NULL);
}

void enqueue(struct Queue* q, int data){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    if(isEmpty(q)){
        q->front = q->rear = newNode;
    } else {
        q->rear->next = newNode;
        q->rear = newNode;
    }
}

int dequeue(struct Queue* q){
    if(isEmpty(q)){
        printf("Queue Underflow\n");
        return -1; 
    }
    struct Node* temp = q->front;
    int y = temp->data;
    q->front = q->front->next;
    
    if(q->front == NULL)  
        q->rear = NULL;

    free(temp);
    return y;
}

int getSize(struct Queue *q){
	struct Node* temp = q->front;
	int count = 0;
	while(temp != NULL){
		temp = temp->next;
		count++;
	}
	return count;
}


int main(){
    struct Queue q;
    q.front = q.rear = NULL;

    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);

    printf("Front: %d\n", q.front->data);
    printf("Rear: %d\n", q.rear->data);
    
    printf("\nAfter dequeue %d:",dequeue(&q));
    
    printf("\nFront: %d\n", q.front->data);
    printf("Rear: %d\n", q.rear->data);
	enqueue(&q, 40);
	printf("\nTotal Elements: %d", getSize(&q));
    return 0;
}

