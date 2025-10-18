#include <stdio.h>

int main() {
    int numbers[5];
    int sum = 0;
    float average;

    // Input elements
    printf("Enter 5 numbers:\n");
    for (int i = 0; i < 5; i++) {
        printf("Number %d: ", i + 1);
        scanf("%d", &numbers[i]);
        sum += numbers[i];
    }

    // Calculate average
    average = sum / 5.0;

    // Output results
    printf("\nSum = %d\n", sum);
    printf("Average = %.2f\n", average);

    return 0;
}
