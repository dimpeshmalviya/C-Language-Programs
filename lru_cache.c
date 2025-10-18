#include <stdio.h>
#define CAPACITY 2
int keys[CAPACITY];
int values[CAPACITY];
int recent[CAPACITY]; // 0 = least recently used
void moveToRecent(int index) {
    for (int i = 0; i < CAPACITY; i++)
        if (recent[i] > recent[index])
            recent[i]--;
    recent[index] = CAPACITY - 1;
}
int get(int key) {
    for (int i = 0; i < CAPACITY; i++) {
        if (keys[i] == key) {
            moveToRecent(i);
            return values[i];
        }
    }return -1;
}
void put(int key, int value) {
    for (int i = 0; i < CAPACITY; i++) {
        if (keys[i] == key) {
            values[i] = value;
            moveToRecent(i);
            return;
        }
    }
    int lru = 0;
    for (int i = 0; i < CAPACITY; i++)
        if (recent[i] == 0) { lru = i; break; }
    keys[lru] = key;
    values[lru] = value;
    moveToRecent(lru);
}
int main() {
    for (int i = 0; i < CAPACITY; i++) recent[i] = i; // init
put(1, 1);
    put(2, 2);
    printf("%d\n", get(1)); // returns 1
    put(3, 3);              // removes key 2
    printf("%d\n", get(2)); // returns -1

    return 0;
}