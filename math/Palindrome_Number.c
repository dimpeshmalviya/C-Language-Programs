#include <stdio.h>

int main() {
    int num, original, reversed = 0, digit;

    printf("Enter a number: ");
    scanf("%d", &num);

    original = num;  // store original number

    // Reverse the number
    while (num != 0) {
        digit = num % 10;         // get last digit
        reversed = reversed * 10 + digit;  // build reversed number
        num /= 10;                // remove last digit
    }

    // Check if original and reversed are same
    if (original == reversed) {
        printf("%d is a Palindromic Number.\n", original);
    } else {
        printf("%d is NOT a Palindromic Number.\n", original);
    }

    return 0;
}
