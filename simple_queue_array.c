/*
simple_queue_array.c
A tiny demonstration of a fixed-size circular queue (enqueue, dequeue, peek).

Compile:
  gcc -o simple_queue_array simple_queue_array.c

Usage:
  ./simple_queue_array
  Commands:
    1 <x>  -> enqueue x
    2      -> dequeue
    3      -> peek
    4      -> exit
*/
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    const int CAP = 8;
    int q[8];
    int head = 0, tail = 0, size = 0;
    printf("Queue demo (capacity %d).\n", CAP);
    printf("Commands: 1 x (enqueue), 2 (dequeue), 3 (peek), 4 (exit)\n");
    while (1) {
        int cmd;
        if (scanf("%d", &cmd) != 1) break;
        if (cmd == 1) {
            int x; if (scanf("%d", &x) != 1) break;
            if (size == CAP) {
                printf("Queue full\n");
            } else {
                q[tail] = x;
                tail = (tail + 1) % CAP;
                size++;
                printf("Enqueued %d\n", x);
            }
        } else if (cmd == 2) {
            if (size == 0) printf("Queue empty\n");
            else {
                int v = q[head];
                head = (head + 1) % CAP;
                size--;
                printf("Dequeued %d\n", v);
            }
        } else if (cmd == 3) {
            if (size == 0) printf("Queue empty\n");
            else printf("Front: %d\n", q[head]);
        } else if (cmd == 4) {
            printf("Exit\n"); break;
        } else {
            printf("Unknown command\n");
        }
    }
    return 0;
}
