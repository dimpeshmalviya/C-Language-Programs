#include <stdio.h>
#include <math.h>

// Function to check if a number is an Armstrong number
// An Armstrong number is an n-digit number that is equal to
// the sum of its digits each raised to the power n.
//
// Example: For 153 -> 1^3 + 5^3 + 3^3 = 153

int main() {
    int number, originalNumber, result = 0, n = 0, remainder;

    // Example input:
    // Enter a number: 153

    printf("Enter a number: ");
    scanf("%d", &number);

    originalNumber = number;

    // Find the number of digits (n)
    while (originalNumber != 0) {
        originalNumber /= 10;
        ++n;
    }

    originalNumber = number;

    // Calculate the sum of digits raised to the power n
    while (originalNumber != 0) {
        remainder = originalNumber % 10;
        result += (int)pow(remainder, n);
        originalNumber /= 10;
    }

    // Check if the number is an Armstrong number
    if (result == number)
        printf("%d is an Armstrong number.\n", number);
    else
        printf("%d is not an Armstrong number.\n", number);

    return 0;
}

/*
Sample input/output:

Enter a number: 153
153 is an Armstrong number.

Enter a number: 123
123 is not an Armstrong number.
*/
