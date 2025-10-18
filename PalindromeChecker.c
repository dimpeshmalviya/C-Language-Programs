#include <stdio.h>
#include <string.h>
#include <stdbool.h> // Include for using the bool type (true/false)
#include <ctype.h>   // Include for tolower() function

/**
 * @brief Checks if a given string is a palindrome.
 * * A palindrome is a word that reads the same forwards and backwards.
 * This function uses a two-pointer approach to check for palindromes.
 * It is case-insensitive, meaning "Racecar" is treated as a palindrome.
 * * @param str The input string to check.
 * @return true if the string is a palindrome, false otherwise.
 */
bool isPalindrome(char str[]) {
    int left = 0;
    int right = strlen(str) - 1;

    // Loop until the two pointers meet in the middle
    while (left < right) {
        // Compare characters from both ends, ignoring case
        if (tolower(str[left]) != tolower(str[right])) {
            return false; // If characters don't match, it's not a palindrome
        }
        // Move pointers inward
        left++;
        right--;
    }

    // If the loop completes, all characters matched
    return true;
}

int main() {
    // Define a buffer to store the user's input string
    char inputString[100];

    // Prompt the user to enter a string
    printf("Enter a word to check if it's a palindrome: ");
    
    // Read the string from the user.
    // scanf is used here for simplicity in a beginner example.
    scanf("%s", inputString);

    // Call the isPalindrome function and check the result
    if (isPalindrome(inputString)) {
        printf("'%s' is a palindrome.\n", inputString);
    } else {
        printf("'%s' is not a palindrome.\n", inputString);
    }

    return 0;
}