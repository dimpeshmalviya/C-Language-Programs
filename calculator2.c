#include <stdio.h>
#include <stdlib.h>

int main() {
    char operator;
    double num1, num2, result;
    char choice;

    printf("=====================================\n");
    printf("      🧮 Simple Calculator App       \n");
    printf("=====================================\n");

    do {
        printf("\nEnter an operator (+, -, *, /): ");
        if (scanf(" %c", &operator) != 1) {
            printf("Invalid input. Please try again.\n");
            return 1;
        }

        printf("Enter first number: ");
        if (scanf("%lf", &num1) != 1) {
            printf("Invalid number. Please try again.\n");
            return 1;
        }

        printf("Enter second number: ");
        if (scanf("%lf", &num2) != 1) {
            printf("Invalid number. Please try again.\n");
            return 1;
        }

        switch (operator) {
            case '+':
                result = num1 + num2;
                printf("Result: %.2lf + %.2lf = %.2lf\n", num1, num2, result);
                break;
            case '-':
                result = num1 - num2;
                printf("Result: %.2lf - %.2lf = %.2lf\n", num1, num2, result);
                break;
            case '*':
                result = num1 * num2;
                printf("Result: %.2lf × %.2lf = %.2lf\n", num1, num2, result);
                break;
            case '/':
                if (num2 != 0) {
                    result = num1 / num2;
                    printf("Result: %.2lf ÷ %.2lf = %.2lf\n", num1, num2, result);
                } else {
                    printf("⚠️  Error: Division by zero is not allowed.\n");
                }
                break;
            default:
                printf("⚠️  Error: Invalid operator '%c'. Please use +, -, *, or /.\n", operator);
        }

        printf("\nDo you want to perform another calculation? (y/n): ");
        scanf(" %c", &choice);

    } while (choice == 'y' || choice == 'Y');

    printf("\nThank you for using the Calculator App! 👋\n");

    return 0;
}
