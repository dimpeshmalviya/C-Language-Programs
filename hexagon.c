#include <stdio.h>

int main() {
    int n, i, j;
    printf("Enter size of hexagon (e.g. 4 or 5): ");
    scanf("%d", &n);

    // Upper part
    for (i = 0; i < n; i++) {
        // spaces
        for (j = 0; j < n - i - 1; j++)
            printf(" ");
        // stars
        for (j = 0; j < n + 2 * i; j++)
            printf("*");
        printf("\n");
    }

    // Lower part
    for (i = n - 2; i >= 0; i--) {
        // spaces
        for (j = 0; j < n - i - 1; j++)
            printf(" ");
        // stars
        for (j = 0; j < n + 2 * i; j++)
            printf("*");
        printf("\n");
    }

    return 0;
}
