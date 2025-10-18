#include <stdio.h>

char calculateGrade(float percentage) {
    if (percentage >= 90)
        return 'A';
    else if (percentage >= 75)
        return 'B';
    else if (percentage >= 60)
        return 'C';
    else if (percentage >= 50)
        return 'D';
    else
        return 'F';
}

int main() {
    int n, i;
    printf("===== Student Grade Analyzer =====\n");
    printf("Enter number of subjects: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Invalid number of subjects.\n");
        return 1;
    }

    float marks[n], total = 0;
    for (i = 0; i < n; i++) {
        printf("Enter marks for subject %d: ", i + 1);
        scanf("%f", &marks[i]);
        total += marks[i];
    }

    float average = total / n;
    float percentage = average; // assuming marks are out of 100
    char grade = calculateGrade(percentage);

    printf("\nTotal Marks: %.2f\n", total);
    printf("Average Marks: %.2f\n", average);
    printf("Percentage: %.2f%%\n", percentage);
    printf("Grade: %c\n", grade);

    return 0;
}
