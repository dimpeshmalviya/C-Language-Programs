#include <stdio.h>
#include <stdlib.h>

struct Queue{
    int size;
    int front;
    int rear;
    int *arr;
};

int isFull(struct Queue *q){
    return q->rear == q->size-1;
}

int isEmpty(struct Queue *q){
    return q->front == -1 || q->front > q->rear;
}

int peekFront(struct Queue *q){
	if(isEmpty(q)){
		return -1;
	}
	return q->arr[q->front];
}

int searchElem(struct Queue *q, int val){
    if(isEmpty(q)){
        printf("Queue is empty!\n");
        return -1;
    }
	int i=0;
    for(i = q->front; i <= q->rear; i++){
        if(q->arr[i] == val){
            printf("\nElement %d found at index %d\n", val, i);
            return i;
        }
    }

    printf("\nElement %d not found in the queue!\n", val);
    return -1;
}


void enqueue(struct Queue *q, int val){
    if(isFull(q)){
        printf("Queue Overflow! Cannot insert %d\n", val);
    } else {
        if(q->front == -1) q->front = 0;
        q->rear++;
        q->arr[q->rear] = val;
        printf("Element enqueued -> %d\n", val);
    }
}

int dequeue(struct Queue *q){
    if(isEmpty(q)){
        printf("Queue is Empty!\n");
        return -1;
    }
    int num = q->arr[q->front];
    q->front++;
    return num;
}

void displayQueue(struct Queue *q){
    if(isEmpty(q)){
        printf("No elements to display!\n");
        return;
    }
    printf("Queue Elements: ");
    int i=0;
    for(i = q->front; i <= q->rear; i++){
        printf("%d ", q->arr[i]);
    }
    printf("\n");
}

void ReverseQueue(struct Queue *q){
	if(isEmpty(q)) return;
	int data = dequeue(q);
	ReverseQueue(q);
	enqueue(q,data);
}

int main(){
    struct Queue q;
    q.size = 10;
    q.front = q.rear = -1;
    q.arr = (int *)malloc(q.size * sizeof(int));

    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);
    displayQueue(&q);

    printf("Dequeued: %d\n", dequeue(&q));
    displayQueue(&q);

    enqueue(&q, 40);
    displayQueue(&q);
    
    enqueue(&q, 100);
    displayQueue(&q);
    
    printf("\nPeek element is: %d",peekFront(&q));
	searchElem(&q, 100);
	
	ReverseQueue(&q);
	displayQueue(&q);
    free(q.arr);
    return 0;
}

