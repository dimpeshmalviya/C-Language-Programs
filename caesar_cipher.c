/*
caesar_cipher.c
Simple Caesar cipher encoder/decoder for ASCII letters.
Compile:
  gcc -o caesar_cipher caesar_cipher.c
Usage:
  ./caesar_cipher encode 3 "Hello, World!"
  ./caesar_cipher decode 3 "Khoor, Zruog!"
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void caesar(char *s, int shift) {
    for (; *s; ++s) {
        if (isupper((unsigned char)*s)) {
            *s = (char)('A' + ( (*s - 'A' + shift + 26) % 26 ));
        } else if (islower((unsigned char)*s)) {
            *s = (char)('a' + ( (*s - 'a' + shift + 26) % 26 ));
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc < 4) {
        fprintf(stderr, "Usage: %s <encode|decode> <shift> <text>\n", argv[0]);
        return 1;
    }
    int shift = atoi(argv[2]);
    if (strcmp(argv[1], "decode") == 0) shift = -shift;
    /* join remaining arguments into one string */
    size_t len = 0;
    for (int i = 3; i < argc; ++i) len += strlen(argv[i]) + 1;
    char *text = malloc(len+1);
    if (!text) return 1;
    text[0] = '\0';
    for (int i = 3; i < argc; ++i) {
        strcat(text, argv[i]);
        if (i + 1 < argc) strcat(text, " ");
    }
    caesar(text, shift);
    printf("%s\n", text);
    free(text);
    return 0;
}
