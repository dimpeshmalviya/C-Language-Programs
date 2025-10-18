#include <stdio.h>

int main() {
    int rows;

    // Ask user for number of rows
    printf("Enter number of rows: ");
    scanf("%d", &rows);

    // Outer loop for each row
    for (int i = 1; i <= rows; i++) {

        // Print spaces to center the pyramid
        for (int space = i; space < rows; space++) {
            printf(" ");
        }

        // Print increasing numbers (1 to i)
        for (int num = 1; num <= i; num++) {
            printf("%d", num);
        }

        // Print decreasing numbers (i-1 down to 1)
        for (int num = i - 1; num >= 1; num--) {
            printf("%d", num);
        }

        // Move to next line
        printf("\n");
    }

    return 0;
}
