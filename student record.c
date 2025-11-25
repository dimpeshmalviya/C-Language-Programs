#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student {
    int roll;
    char name[50];
    float marks;
};

// Function prototypes
void addStudent();
void displayStudents();
void searchStudent();
void updateStudent();
void deleteStudent();

int main() {
    int choice;

    while(1) {
        printf("\n\n===== STUDENT RECORD MANAGEMENT SYSTEM =====\n");
        printf("1. Add Student\n");
        printf("2. Display All Students\n");
        printf("3. Search Student\n");
        printf("4. Update Student\n");
        printf("5. Delete Student\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: addStudent(); break;
            case 2: displayStudents(); break;
            case 3: searchStudent(); break;
            case 4: updateStudent(); break;
            case 5: deleteStudent(); break;
            case 6: exit(0);
            default: printf("Invalid Choice!\n");
        }
    }
    return 0;
}

// 1. ADD STUDENT RECORD
void addStudent() {
    struct Student s;
    FILE *fp = fopen("students.dat", "ab");  // append binary

    printf("\nEnter Roll Number: ");
    scanf("%d", &s.roll);

    printf("Enter Name: ");
    scanf("%s", s.name);

    printf("Enter Marks: ");
    scanf("%f", &s.marks);

    fwrite(&s, sizeof(s), 1, fp);
    fclose(fp);

    printf("\nStudent Added Successfully!\n");
}

// 2. DISPLAY ALL STUDENT RECORDS
void displayStudents() {
    struct Student s;
    FILE *fp = fopen("students.dat", "rb");

    if(fp == NULL) {
        printf("No Records Found.\n");
        return;
    }

    printf("\n==== STUDENT LIST ====\n");
    while(fread(&s, sizeof(s), 1, fp)) {
        printf("\nRoll Number : %d", s.roll);
        printf("\nName        : %s", s.name);
        printf("\nMarks       : %.2f\n", s.marks);
    }

    fclose(fp);
}

// 3. SEARCH STUDENT BY ROLL NUMBER
void searchStudent() {
    struct Student s;
    int roll, found = 0;

    printf("\nEnter Roll Number to Search: ");
    scanf("%d", &roll);

    FILE *fp = fopen("students.dat", "rb");

    while(fread(&s, sizeof(s), 1, fp)) {
        if(s.roll == roll) {
            printf("\nRecord Found!\n");
            printf("Roll Number: %d\n", s.roll);
            printf("Name       : %s\n", s.name);
            printf("Marks      : %.2f\n", s.marks);
            found = 1;
            break;
        }
    }

    if(!found)
        printf("No Record Found for Roll Number %d\n", roll);

    fclose(fp);
}

// 4. UPDATE STUDENT RECORD
void updateStudent() {
    struct Student s;
    int roll, found = 0;

    printf("\nEnter Roll Number to Update: ");
    scanf("%d", &roll);

    FILE *fp = fopen("students.dat", "rb+");

    while(fread(&s, sizeof(s), 1, fp)) {
        if(s.roll == roll) {
            printf("\nEnter New Name: ");
            scanf("%s", s.name);

            printf("Enter New Marks: ");
            scanf("%f", &s.marks);

            fseek(fp, -sizeof(s), SEEK_CUR);
            fwrite(&s, sizeof(s), 1, fp);

            printf("Record Updated Successfully!\n");
            found = 1;
            break;
        }
    }

    if(!found)
        printf("Record Not Found!\n");

    fclose(fp);
}

// 5. DELETE A STUDENT RECORD
void deleteStudent() {
    struct Student s;
    int roll, found = 0;

    printf("\nEnter Roll Number to Delete: ");
    scanf("%d", &roll);

    FILE *fp = fopen("students.dat", "rb");
    FILE *temp = fopen("temp.dat", "wb");

    while(fread(&s, sizeof(s), 1, fp)) {
        if(s.roll != roll) {
            fwrite(&s, sizeof(s), 1, temp);
        } else {
            found = 1;
        }
    }

    fclose(fp);
    fclose(temp);

    remove("students.dat");
    rename("temp.dat", "students.dat");

    if(found)
        printf("Record Deleted Successfully!\n");
    else
        printf("Record Not Found!\n");
}
