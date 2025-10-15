#include <stdio.h>

int main() {
    double num1, num2, result;
    char op;

    printf("Simple Calculator\n");
    printf("-----------------\n");

    printf("Enter first number: ");
    scanf("%lf", &num1);

    printf("Enter operator (+, -, *, /): ");
    scanf(" %c", &op); // Note the space before %c to ignore any leftover newline

    printf("Enter second number: ");
    scanf("%lf", &num2);

    // Logic for calculator
    if (op == '+') {
        result = num1 + num2;
    } 
    else if (op == '-') {
        result = num1 - num2;
    } 
    else if (op == '*') {
        result = num1 * num2;
    } 
    else if (op == '/') {
        if (num2 != 0)
            result = num1 / num2;
        else {
            printf("Error: Division by zero is not allowed.\n");
            return 1; // Exit the program
        }
    } 
    else {
        printf("Invalid operator!\n");
        return 1;
    }

    printf("Result: %.2lf\n", result);
    return 0;
}
