// word_ladder.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int differByOne(const char* a, const char* b) {
    int diff = 0;
    for (int i = 0; a[i] && b[i]; ++i) {
        if (a[i] != b[i]) {
            diff++;
            if (diff > 1) return 0;
        }
    }
    return diff == 1;
}

int ladderLength(char* beginWord, char* endWord, char** wordList, int wordCount) {
    // If endWord not in list, can't reach it
    int endIdx = -1;
    for (int i = 0; i < wordCount; ++i) if (strcmp(wordList[i], endWord) == 0) { endIdx = i; break; }
    if (endIdx == -1) return 0;

    // visited array
    bool* visited = (bool*)calloc(wordCount, sizeof(bool));
    // queue of indices and distances
    int* q = (int*)malloc(sizeof(int)*wordCount);
    int* dist = (int*)malloc(sizeof(int)*wordCount);
    int front = 0, back = 0;

    // Enqueue neighbors of beginWord (not in list necessarily)
    for (int i = 0; i < wordCount; ++i) {
        if (!visited[i] && (differByOne(beginWord, wordList[i]) || strcmp(beginWord, wordList[i])==0)) {
            q[back] = i; dist[back] = 2; back++;
            visited[i] = true;
            if (i == endIdx) {
                int res = dist[back-1];
                free(visited); free(q); free(dist);
                return res;
            }
        }
    }

    while (front < back) {
        int idx = q[front];
        int d = dist[front];
        front++;
        for (int i = 0; i < wordCount; ++i) {
            if (!visited[i] && differByOne(wordList[idx], wordList[i])) {
                if (i == endIdx) {
                    free(visited); free(q); free(dist);
                    return d + 1;
                }
                q[back] = i; dist[back] = d + 1; back++;
                visited[i] = true;
            }
        }
    }
    free(visited); free(q); free(dist);
    return 0;
}

int main() {
    char begin[] = "hit";
    char end[] = "cog";
    char *words[] = {"hot","dot","dog","lot","log","cog"};
    int n = sizeof(words)/sizeof(words[0]);
    int len = ladderLength(begin, end, words, n);
    printf("Length = %d\n", len); // expected 5
    return 0;
}