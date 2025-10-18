/*
decimal_to_binary.c
Convert a non-negative integer to binary (prints bits).
Compile:
  gcc -o decimal_to_binary decimal_to_binary.c
Usage:
  ./decimal_to_binary 37
  Output:
  100101
*/
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <non-negative-integer>\n", argv[0]);
        return 1;
    }
    unsigned long n = strtoul(argv[1], NULL, 10);
    if (n == 0) {
        printf("0\n");
        return 0;
    }
    char buf[64];
    int pos = 0;
    while (n > 0) {
        buf[pos++] = (n & 1) ? '1' : '0';
        n >>= 1;
    }
    for (int i = pos - 1; i >= 0; --i) putchar(buf[i]);
    putchar('\n');
    return 0;
}
