/*
anagram_checker.c
Check whether two input strings are anagrams of each other.
- Ignores non-alphanumeric characters and case.
- Uses a fixed 256-byte frequency table for simplicity.

Compile:
  gcc -o anagram_checker anagram_checker.c

Usage:
  ./anagram_checker
  Enter first string: Silent
  Enter second string: Listen
  Result: Anagrams

This program is small, easy to read, and not present in the repo snippet you supplied.
*/
#include <stdio.h>
#include <string.h>
#include <ctype.h>

void normalize_and_count(const char *s, int freq[256]) {
    for (; *s; ++s) {
        unsigned char c = (unsigned char)*s;
        if (isalnum(c)) {
            unsigned char lower = (unsigned char)tolower(c);
            freq[lower]++;
        }
    }
}

int main(void) {
    char a[1024], b[1024];
    printf("Enter first string: ");
    if (!fgets(a, sizeof(a), stdin)) return 1;
    printf("Enter second string: ");
    if (!fgets(b, sizeof(b), stdin)) return 1;

    // Remove trailing newlines
    a[strcspn(a, "\n")] = '\0';
    b[strcspn(b, "\n")] = '\0';

    int freq[256] = {0};
    normalize_and_count(a, freq);
    // decrement with second string
    for (const char *s = b; *s; ++s) {
        unsigned char c = (unsigned char)*s;
        if (isalnum(c)) {
            unsigned char lower = (unsigned char)tolower(c);
            freq[lower]--;
        }
    }

    // check all zero
    for (int i = 0; i < 256; ++i) {
        if (freq[i] != 0) {
            printf("Result: Not anagrams\n");
            return 0;
        }
    }
    printf("Result: Anagrams\n");
    return 0;
}
