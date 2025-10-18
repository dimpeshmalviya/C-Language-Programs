/*
Program Name: Sum and Average of 2D Array
Problem Statement:
Write a C program to input a 2D array of size M×N and calculate the sum and average of all elements.

Example:
Input:
Enter rows and columns: 2 3
Enter values:
1 2 3
4 5 6

Output:
Sum of all elements: 21
Average of all elements: 3.5

Compilation Command:
gcc sum_average_2d.c -o sum_average_2d

Time Complexity: O(M*N)
Space Complexity: O(M*N)
*/

#include <stdio.h>

int main() {
    int n, m;
    int sum = 0;
    
    printf("Enter number of rows and columns: ");
    scanf("%d%d", &n, &m);

    int x[n][m];
    printf("Enter values:\n");

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &x[i][j]);
            sum += x[i][j];
        }
    }

    printf("Sum of all elements: %d\n", sum);
    printf("Average of all elements: %.2f\n", (float)sum / (m * n));

    return 0;
}
