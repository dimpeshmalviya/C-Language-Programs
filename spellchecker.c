#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define MAX_LEN 100

// Function to devowel a word
void devowel(const char *word, char *out) {
    int n = strlen(word);
    for (int i = 0; i < n; i++) {
        char c = tolower(word[i]);
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
            out[i] = '*';
        else
            out[i] = c;
    }
    out[n] = '\0';
}

// Function to lowercase a word
void toLowerStr(const char *src, char *dst) {
    int n = strlen(src);
    for (int i = 0; i < n; i++) {
        dst[i] = tolower(src[i]);
    }
    dst[n] = '\0';
}

// Check if string exists in list
int findExact(char words[][MAX_LEN], int size, const char *target) {
    for (int i = 0; i < size; i++) {
        if (strcmp(words[i], target) == 0)
            return i;
    }
    return -1;
}

// Check lowercase match
int findLower(char lowers[][MAX_LEN], int size, const char *target) {
    for (int i = 0; i < size; i++) {
        if (strcmp(lowers[i], target) == 0)
            return i;
    }
    return -1;
}

// Check devowel match
int findDevowel(char devs[][MAX_LEN], int size, const char *target) {
    for (int i = 0; i < size; i++) {
        if (strcmp(devs[i], target) == 0)
            return i;
    }
    return -1;
}

void spellchecker(
    char wordlist[][MAX_LEN], int wordCount,
    char queries[][MAX_LEN], int queryCount,
    char output[][MAX_LEN]
) {
    char lowers[MAX_WORDS][MAX_LEN];
    char devs[MAX_WORDS][MAX_LEN];

    // Preprocessing wordlist
    for (int i = 0; i < wordCount; i++) {
        toLowerStr(wordlist[i], lowers[i]);
        devowel(wordlist[i], devs[i]);
    }

    // Processing queries
    for (int i = 0; i < queryCount; i++) {
        char *q = queries[i];

        // 1. Exact match
        int idx = findExact(wordlist, wordCount, q);
        if (idx != -1) {
            strcpy(output[i], wordlist[idx]);
            continue;
        }

        // 2. Case-insensitive match
        char lowQ[MAX_LEN];
        toLowerStr(q, lowQ);
        idx = findLower(lowers, wordCount, lowQ);
        if (idx != -1) {
            strcpy(output[i], wordlist[idx]);
            continue;
        }

        // 3. Devowel match
        char dvQ[MAX_LEN];
        devowel(q, dvQ);
        idx = findDevowel(devs, wordCount, dvQ);
        if (idx != -1) {
            strcpy(output[i], wordlist[idx]);
            continue;
        }

        // 4. No match
        strcpy(output[i], "");
    }
}

int main() {
    // Example usage
    char wordlist[MAX_WORDS][MAX_LEN] = {"KiTe", "kite", "hare", "Hare"};
    char queries[MAX_WORDS][MAX_LEN] = {"kite", "Kite", "KiTe", "Hare", "HARE", "Hear", "hear", "keti", "keet", "keto"};
    int wordCount = 4;
    int queryCount = 10;

    char output[MAX_WORDS][MAX_LEN];

    spellchecker(wordlist, wordCount, queries, queryCount, output);

    for (int i = 0; i < queryCount; i++) {
        printf("Query: %-5s -> Result: %s\n", queries[i], output[i]);
    }

    return 0;
}
