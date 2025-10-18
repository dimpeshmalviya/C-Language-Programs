#include <stdio.h>
#include <string.h>

#define MAX_WORDS 100
#define MAX_LEN 50

void suggestWords(char words[][MAX_LEN], int n, char prefix[]) {
    printf("Suggestions for \"%s\": [", prefix);
    int found = 0;
    for (int i = 0; i < n; i++) {
        if (strncmp(words[i], prefix, strlen(prefix)) == 0) {
            if (found) printf(", ");
            printf("\"%s\"", words[i]);
            found = 1;
        }
    }
    if (!found)
        printf("No matches");
    printf("]\n");
}

int main() {
    char words[][MAX_LEN] = {"code", "coder", "coding", "coffee", "cool"};
    int n = 5;
    char prefix[MAX_LEN] = "co";

    suggestWords(words, n, prefix);
    return 0;
}