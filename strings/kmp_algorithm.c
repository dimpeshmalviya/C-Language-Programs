/*
 * Program: Knuth-Morris-Pratt (KMP) String Matching Algorithm
 * 
 * Problem Statement:
 * Implement the KMP algorithm to find all occurrences of a pattern
 * in a text string using the failure function (LPS array).
 * 
 * Input/Output Example:
 * Enter text: abcdabcabc
 * Enter pattern: abc
 * Pattern found at positions: 0 4 7
 * 
 * Time Complexity: O(n + m) where n = text length, m = pattern length
 * Space Complexity: O(m) for the failure function
 * 
 * Compile: gcc kmp_algorithm.c -o kmp_algorithm
 * Run: ./kmp_algorithm
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Function to compute the failure function (LPS array)
void computeFailureFunction(const char* pattern, int* lps) {
    int patternLen = strlen(pattern);
    int len = 0;  // Length of the previous longest prefix suffix
    int i = 1;
    
    lps[0] = 0;  // First element is always 0
    
    // Fill lps[i] for i = 1 to patternLen-1
    while (i < patternLen) {
        if (pattern[i] == pattern[len]) {
            len++;
            lps[i] = len;
            i++;
        } else {
            if (len != 0) {
                // This is tricky. Consider the example:
                // AAACAAAA and i = 7. The idea is similar to search step.
                len = lps[len - 1];
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }
}

// KMP string matching algorithm
void kmpSearch(const char* text, const char* pattern) {
    int textLen = strlen(text);
    int patternLen = strlen(pattern);
    
    if (patternLen > textLen) {
        printf("Pattern not found (pattern longer than text)\n");
        return;
    }
    
    // Create LPS array
    int* lps = (int*)malloc(patternLen * sizeof(int));
    if (lps == NULL) {
        printf("Memory allocation failed\n");
        return;
    }
    
    // Preprocess the pattern
    computeFailureFunction(pattern, lps);
    
    int i = 0;  // Index for text
    int j = 0;  // Index for pattern
    int found = 0;
    
    while (i < textLen) {
        if (pattern[j] == text[i]) {
            i++;
            j++;
        }
        
        if (j == patternLen) {
            printf("%d ", i - j);
            found = 1;
            j = lps[j - 1];  // Look for next match
        } else if (i < textLen && pattern[j] != text[i]) {
            if (j != 0) {
                j = lps[j - 1];
            } else {
                i++;
            }
        }
    }
    
    if (!found) {
        printf("Pattern not found");
    }
    printf("\n");
    
    free(lps);
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
    kmpSearch(text, pattern);
    
    return 0;
}
