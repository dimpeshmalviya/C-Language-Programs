#include <stdio.h>
#include <string.h>

// Structure to store student details
struct Student {
    char name[50];
    int roll;
    float marks[5];
    float average;
    char grade;
};

// Function to calculate grade
char calculateGrade(float avg) {
    if (avg >= 90) return 'A';
    else if (avg >= 75) return 'B';
    else if (avg >= 60) return 'C';
    else if (avg >= 40) return 'D';
    else return 'F';
}

int main() {
    struct Student students[50];
    int n, i, j;

    printf("Enter number of students: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("\nEnter details for student %d\n", i + 1);
        printf("Name: ");
        scanf("%s", students[i].name);
        printf("Roll No: ");
        scanf("%d", &students[i].roll);

        float sum = 0;
        for (j = 0; j < 5; j++) {
            printf("Enter marks of subject %d: ", j + 1);
            scanf("%f", &students[i].marks[j]);
            sum += students[i].marks[j];
        }

        students[i].average = sum / 5.0;
        students[i].grade = calculateGrade(students[i].average);
    }

    printf("\n--- Student Report ---\n");
    for (i = 0; i < n; i++) {
        printf("\nName: %s", students[i].name);
        printf("\nRoll No: %d", students[i].roll);
        printf("\nAverage Marks: %.2f", students[i].average);
        printf("\nGrade: %c\n", students[i].grade);
    }

    return 0;
}
