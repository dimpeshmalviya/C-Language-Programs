#include <stdio.h>

int main() {
    int n, i, j;
    
    printf("How many numbers do you want to enter? ");
    scanf("%d", &n);

    int numbers[n];
    unsigned long long factorial[n]; // Store factorials

    // Input numbers
    for(i = 0; i < n; i++) {
        printf("Enter number %d: ", i + 1);
        scanf("%d", &numbers[i]);
    }

    // Calculate factorials
    for(i = 0; i < n; i++) {
        if(numbers[i] < 0) {
            factorial[i] = 0; // Factorial not defined
        } else {
            factorial[i] = 1;
            for(j = 1; j <= numbers[i]; j++) {
                factorial[i] *= j;
            }
        }
    }

    // Display results
    printf("\nFactorials:\n");
    for(i = 0; i < n; i++) {
        if(numbers[i] < 0)
            printf("Factorial of %d is not defined\n", numbers[i]);
        else
            printf("Factorial of %d is %llu\n", numbers[i], factorial[i]);
    }

    return 0;
}
