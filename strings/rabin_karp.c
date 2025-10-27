/*
 * Program: Rabin-Karp String Matching Algorithm
 * 
 * Problem Statement:
 * Implement the Rabin-Karp algorithm to find all occurrences of a pattern
 * in a text string using rolling hash technique.
 * 
 * Input/Output Example:
 * Enter text: abcdabcabc
 * Enter pattern: abc
 * Pattern found at positions: 0 4 7
 * 
 * Time Complexity: O(n + m) average case, O(nm) worst case
 * Space Complexity: O(1)
 * 
 * Compile: gcc rabin_karp.c -o rabin_karp
 * Run: ./rabin_karp
 */

#include <stdio.h>
#include <string.h>

#define BASE 256  // Base for hash calculation
#define MOD 1000000007  // Large prime number for modulo operation

// Function to calculate hash value for a string
long long calculateHash(const char* str, int len) {
    long long hash = 0;
    for (int i = 0; i < len; i++) {
        hash = (hash * BASE + str[i]) % MOD;
    }
    return hash;
}

// Function to calculate (base^exp) % mod efficiently
long long power(long long base, int exp, long long mod) {
    long long result = 1;
    base = base % mod;
    while (exp > 0) {
        if (exp % 2 == 1) {
            result = (result * base) % mod;
        }
        exp = exp >> 1;
        base = (base * base) % mod;
    }
    return result;
}

// Rabin-Karp string matching algorithm
void rabinKarp(const char* text, const char* pattern) {
    int textLen = strlen(text);
    int patternLen = strlen(pattern);
    
    if (patternLen > textLen) {
        printf("Pattern not found (pattern longer than text)\n");
        return;
    }
    
    // Calculate hash of pattern
    long long patternHash = calculateHash(pattern, patternLen);
    
    // Calculate hash of first window of text
    long long textHash = calculateHash(text, patternLen);
    
    // Calculate BASE^(patternLen-1) for rolling hash
    long long h = power(BASE, patternLen - 1, MOD);
    
    int found = 0;
    
    // Check first window
    if (patternHash == textHash) {
        // Verify by character comparison
        int match = 1;
        for (int i = 0; i < patternLen; i++) {
            if (text[i] != pattern[i]) {
                match = 0;
                break;
            }
        }
        if (match) {
            printf("%d ", 0);
            found = 1;
        }
    }
    
    // Slide the pattern over text one by one
    for (int i = 1; i <= textLen - patternLen; i++) {
        // Calculate rolling hash: remove leading digit, add trailing digit
        textHash = (BASE * (textHash - text[i-1] * h) + text[i + patternLen - 1]) % MOD;
        
        // Handle negative values
        if (textHash < 0) {
            textHash += MOD;
        }
        
        // If hash values match, check characters one by one
        if (patternHash == textHash) {
            int match = 1;
            for (int j = 0; j < patternLen; j++) {
                if (text[i + j] != pattern[j]) {
                    match = 0;
                    break;
                }
            }
            if (match) {
                printf("%d ", i);
                found = 1;
            }
        }
    }
    
    if (!found) {
        printf("Pattern not found");
    }
    printf("\n");
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
    rabinKarp(text, pattern);
    
    return 0;
}
