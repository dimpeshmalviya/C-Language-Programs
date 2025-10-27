/*
 * Program: Boyer-Moore String Matching Algorithm
 * 
 * Problem Statement:
 * Implement the Boyer-Moore algorithm to find all occurrences of a pattern
 * in a text string using bad character and good suffix heuristics.
 * 
 * Input/Output Example:
 * Enter text: abcdabcabc
 * Enter pattern: abc
 * Pattern found at positions: 0 4 7
 * 
 * Time Complexity: O(n/m) best case, O(nm) worst case
 * Space Complexity: O(σ) where σ is the alphabet size
 * 
 * Compile: gcc boyer_moore.c -o boyer_moore
 * Run: ./boyer_moore
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define ALPHABET_SIZE 256

// Function to create bad character table
void createBadCharTable(const char* pattern, int patternLen, int badChar[ALPHABET_SIZE]) {
    // Initialize all occurrences as -1
    for (int i = 0; i < ALPHABET_SIZE; i++) {
        badChar[i] = -1;
    }
    
    // Fill the actual value of last occurrence of a character
    for (int i = 0; i < patternLen; i++) {
        badChar[(int)pattern[i]] = i;
    }
}

// Function to create good suffix table (simplified version)
void createGoodSuffixTable(const char* pattern, int patternLen, int* goodSuffix) {
    int* suffix = (int*)malloc(patternLen * sizeof(int));
    if (suffix == NULL) {
        printf("Memory allocation failed\n");
        return;
    }
    
    // Initialize suffix array
    for (int i = 0; i < patternLen; i++) {
        suffix[i] = 0;
        goodSuffix[i] = patternLen;
    }
    
    // Fill suffix array
    for (int i = patternLen - 2; i >= 0; i--) {
        int j = i;
        while (j >= 0 && pattern[j] == pattern[patternLen - 1 - i + j]) {
            j--;
        }
        suffix[i] = i - j;
    }
    
    // Fill good suffix table
    for (int i = 0; i < patternLen - 1; i++) {
        if (suffix[i] != 0) {
            goodSuffix[patternLen - 1 - suffix[i]] = patternLen - 1 - i;
        }
    }
    
    free(suffix);
}

// Boyer-Moore string matching algorithm
void boyerMooreSearch(const char* text, const char* pattern) {
    int textLen = strlen(text);
    int patternLen = strlen(pattern);
    
    if (patternLen > textLen) {
        printf("Pattern not found (pattern longer than text)\n");
        return;
    }
    
    // Create bad character table
    int badChar[ALPHABET_SIZE];
    createBadCharTable(pattern, patternLen, badChar);
    
    // Create good suffix table
    int* goodSuffix = (int*)malloc(patternLen * sizeof(int));
    if (goodSuffix == NULL) {
        printf("Memory allocation failed\n");
        return;
    }
    createGoodSuffixTable(pattern, patternLen, goodSuffix);
    
    int s = 0;  // Shift of the pattern with respect to text
    int found = 0;
    
    while (s <= (textLen - patternLen)) {
        int j = patternLen - 1;
        
        // Keep reducing index j of pattern while characters of pattern
        // and text are matching at this shift s
        while (j >= 0 && pattern[j] == text[s + j]) {
            j--;
        }
        
        // If the pattern is present at current shift, then j will become -1
        if (j < 0) {
            printf("%d ", s);
            found = 1;
            
            // Shift the pattern so that the next character in text
            // aligns with the last occurrence of it in pattern.
            s += (s + patternLen < textLen) ? 
                 patternLen - badChar[(int)text[s + patternLen]] : 1;
        } else {
            // Shift the pattern so that the bad character in text
            // aligns with the last occurrence of it in pattern.
            int badCharShift = j - badChar[(int)text[s + j]];
            int goodSuffixShift = goodSuffix[j];
            
            s += (badCharShift > goodSuffixShift) ? badCharShift : goodSuffixShift;
        }
    }
    
    if (!found) {
        printf("Pattern not found");
    }
    printf("\n");
    
    free(goodSuffix);
}

int main() {
    char text[1000];
    char pattern[100];
    
    printf("Enter text: ");
    if (fgets(text, sizeof(text), stdin) == NULL) {
        printf("Error reading input\n");
        return 1;
    }
    
    // Remove newline character if present
    text[strcspn(text, "\n")] = 0;
    
    printf("Enter pattern: ");
    if (fgets(pattern, sizeof(pattern), stdin) == NULL) {
        printf("Error reading input\n");
        return 1;
    }
    
    // Remove newline character if present
    pattern[strcspn(pattern, "\n")] = 0;
    
    printf("Pattern found at positions: ");
    boyerMooreSearch(text, pattern);
    
    return 0;
}
