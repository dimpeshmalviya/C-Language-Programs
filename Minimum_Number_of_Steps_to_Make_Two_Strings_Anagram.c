/*
 * Minimum Steps to Make Two Strings Anagram
 *
 * Problem:
 * Given two strings s and t of the same length, find the minimum
 * number of character replacements required in t to make it an anagram of s.
 *
 * Approach:
 * - Count the frequency of each character (a-z) in both strings.
 * - For each character, if t has more occurrences than s,
 *   those extras must be replaced.
 * - Total replacements = sum of all positive (countT[i] - countS[i]).
 *
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */

#include <stdio.h>
#include <string.h>

int minSteps(char* s, char* t) {
    int countS[26] = {0};
    int countT[26] = {0};
    int steps = 0;

    // Count character frequencies
    for (int i = 0; s[i] != '\0'; i++) {
        countS[s[i] - 'a']++;
        countT[t[i] - 'a']++;
    }

    // Count excess characters in t
    for (int i = 0; i < 26; i++) {
        if (countT[i] > countS[i])
            steps += countT[i] - countS[i];
    }

    return steps;
}

int main() {
    // Test Case 1
    char s1[] = "bab";
    char t1[] = "aba";
    printf("Output 1: %d\n", minSteps(s1, t1)); // Expected: 1

    // Test Case 2
    char s2[] = "leetcode";
    char t2[] = "practice";
    printf("Output 2: %d\n", minSteps(s2, t2)); // Expected: 5

    // Test Case 3
    char s3[] = "anagram";
    char t3[] = "mangaar";
    printf("Output 3: %d\n", minSteps(s3, t3)); // Expected: 0

    // Test Case 4
    char s4[] = "friend";
    char t4[] = "family";
    printf("Output 4: %d\n", minSteps(s4, t4)); // Expected: 4

    return 0;
}
