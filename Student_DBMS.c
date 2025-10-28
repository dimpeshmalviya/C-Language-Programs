#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

char name[MAX][50], roll[MAX][20], course[MAX][50], sem[MAX][20];
char contact[MAX][20], cgpa[MAX][10], fees[MAX][10];
int total = 0;

void enter() {
    int ch;
    printf("How many students do you want to enter? ");
    scanf("%d", &ch);

    for (int i = total; i < total + ch; i++) {
        printf("\nEnter data of student %d\n", i + 1);

        printf("Enter name: ");
        scanf("%s", name[i]);

        printf("Enter roll no: ");
        scanf("%s", roll[i]);

        printf("Enter course: ");
        scanf("%s", course[i]);

        printf("Enter semester: ");
        scanf("%s", sem[i]);

        printf("Enter contact: ");
        scanf("%s", contact[i]);

        printf("Enter CGPA: ");
        scanf("%s", cgpa[i]);

        printf("Enter fees due (0 if completed): ");
        scanf("%s", fees[i]);
    }

    total += ch;
}

void show() {
    if (total == 0) {
        printf("No data entered yet.\n");
        return;
    }

    for (int i = 0; i < total; i++) {
        printf("\nData of Student %d\n", i + 1);
        printf("Name: %s\n", name[i]);
        printf("Roll No: %s\n", roll[i]);
        printf("Course: %s\n", course[i]);
        printf("Semester: %s\n", sem[i]);
        printf("Contact: %s\n", contact[i]);
        printf("CGPA: %s\n", cgpa[i]);

        if (strcmp(fees[i], "0") == 0)
            printf("Fee Payment Status: Completed\n");
        else
            printf("Fee Due: %s\n", fees[i]);
    }
}

void search() {
    if (total == 0) {
        printf("No data entered yet.\n");
        return;
    }

    char rollno[20];
    printf("Enter roll number to search: ");
    scanf("%s", rollno);

    for (int i = 0; i < total; i++) {
        if (strcmp(rollno, roll[i]) == 0) {
            printf("\nRecord Found:\n");
            printf("Name: %s\n", name[i]);
            printf("Roll No: %s\n", roll[i]);
            printf("Course: %s\n", course[i]);
            printf("Semester: %s\n", sem[i]);
            printf("Contact: %s\n", contact[i]);
            printf("CGPA: %s\n", cgpa[i]);
            if (strcmp(fees[i], "0") == 0)
                printf("Fee Payment Status: Completed\n");
            else
                printf("Fee Due: %s\n", fees[i]);
            return;
        }
    }

    printf("Record not found.\n");
}

void update() {
    if (total == 0) {
        printf("No data entered yet.\n");
        return;
    }

    char rollno[20];
    printf("Enter roll number to update: ");
    scanf("%s", rollno);

    for (int i = 0; i < total; i++) {
        if (strcmp(rollno, roll[i]) == 0) {
            printf("\nPrevious Data:\n");
            printf("Name: %s\n", name[i]);
            printf("Roll No: %s\n", roll[i]);
            printf("Course: %s\n", course[i]);
            printf("Semester: %s\n", sem[i]);
            printf("Contact: %s\n", contact[i]);
            printf("CGPA: %s\n", cgpa[i]);
            printf("Fees: %s\n", fees[i]);

            printf("\nEnter new data:\n");
            printf("Enter name: ");
            scanf("%s", name[i]);
            printf("Enter roll no: ");
            scanf("%s", roll[i]);
            printf("Enter course: ");
            scanf("%s", course[i]);
            printf("Enter semester: ");
            scanf("%s", sem[i]);
            printf("Enter contact: ");
            scanf("%s", contact[i]);
            printf("Enter CGPA: ");
            scanf("%s", cgpa[i]);
            printf("Enter fees due (0 if completed): ");
            scanf("%s", fees[i]);

            printf("Record updated successfully.\n");
            return;
        }
    }

    printf("Record not found.\n");
}

void deleteRecord() {
    if (total == 0) {
        printf("No data entered yet.\n");
        return;
    }

    int choice;
    printf("Press 1 to delete all records\n");
    printf("Press 2 to delete specific record\n");
    scanf("%d", &choice);

    if (choice == 1) {
        total = 0;
        printf("All records deleted.\n");
    } else if (choice == 2) {
        char rollno[20];
        printf("Enter roll number to delete: ");
        scanf("%s", rollno);

        for (int i = 0; i < total; i++) {
            if (strcmp(rollno, roll[i]) == 0) {
                for (int j = i; j < total - 1; j++) {
                    strcpy(name[j], name[j + 1]);
                    strcpy(roll[j], roll[j + 1]);
                    strcpy(course[j], course[j + 1]);
                    strcpy(sem[j], sem[j + 1]);
                    strcpy(contact[j], contact[j + 1]);
                    strcpy(cgpa[j], cgpa[j + 1]);
                    strcpy(fees[j], fees[j + 1]);
                }
                total--;
                printf("Record deleted successfully.\n");
                return;
            }
        }

        printf("Record not found.\n");
    } else {
        printf("Invalid choice.\n");
    }
}

int main() {
    int choice;

    while (1) {
        printf("\n1. Enter Data\n");
        printf("2. Show Data\n");
        printf("3. Search Data\n");
        printf("4. Update Data\n");
        printf("5. Delete Data\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                enter();
                break;
            case 2:
                show();
                break;
            case 3:
                search();
                break;
            case 4:
                update();
                break;
            case 5:
                deleteRecord();
                break;
            case 6:
                exit(0);
            default:
                printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}
