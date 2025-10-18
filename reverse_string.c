/*
reverse_string.c
Read a line and print its reverse (preserving newline handling).

Compile:
  gcc -o reverse_string reverse_string.c

Usage:
  ./reverse_string
  Enter text: Hello world
  Reversed: dlrow olleH
*/
#include <stdio.h>
#include <string.h>

int main(void) {
    char buf[1024];
    printf("Enter text: ");
    if (!fgets(buf, sizeof(buf), stdin)) return 1;
    size_t len = strlen(buf);
    if (len > 0 && buf[len-1] == '\n') {
        buf[--len] = '\0';
    }
    for (size_t i = 0; i < len / 2; ++i) {
        char t = buf[i];
        buf[i] = buf[len - 1 - i];
        buf[len - 1 - i] = t;
    }
    printf("Reversed: %s\n", buf);
    return 0;
}
