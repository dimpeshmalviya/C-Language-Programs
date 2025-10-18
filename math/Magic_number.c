#include <stdio.h>

/*
 * Function: isMagicNumber
 * -----------------------
 * Checks whether n is a magic number.
 * A magic number is defined as a number which, when you repeatedly sum its digits until 
 * a single digit remains, results in a 1.
 *
 * n: The number to check
 *
 * Returns: 1 if n is a magic number, 0 otherwise
 *
 * Example:
 * isMagicNumber(19); // returns 1 (since 1 + 9 = 10, 1 + 0 = 1)
 * isMagicNumber(123); // returns 0 (since 1 + 2 + 3 = 6)
 */
int isMagicNumber(int n) {
    // Reduce n to a single digit by repeatedly summing its digits
    while (n > 9) {
        int sum = 0;
        while (n > 0) {
            sum += n % 10; // Add last digit
            n /= 10;       // Remove last digit
        }
        n = sum;           // Replace n with the sum
    }
    // If single digit is 1, number is magic
    return (n == 1) ? 1 : 0;
}

/*
 * Function: printMagicCheck
 * ------------------------
 * Prints whether the provided number is magic, for demonstration.
 *
 * n: Number to check
 */
void printMagicCheck(int n) {
    if (isMagicNumber(n))
        printf("%d is a magic number.\n", n);
    else
        printf("%d is NOT a magic number.\n", n);
}

int main() {
    // Sample usage for demonstration
    int test_num1 = 19, test_num2 = 123, test_num3 = 1001;
    printMagicCheck(test_num1); // Output: 19 is a magic number.
    printMagicCheck(test_num2); // Output: 123 is NOT a magic number.
    printMagicCheck(test_num3); // Output: 1001 is a magic number.

    return 0;
}
