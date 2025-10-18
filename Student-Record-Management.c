#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student {
    int id;
    char name[50];
    int age;
    float marks;
};

void addStudent(FILE *fp) {
    struct Student s;
    printf("\nEnter ID: ");
    scanf("%d", &s.id);
    printf("Enter Name: ");
    getchar();
    fgets(s.name, 50, stdin);
    s.name[strcspn(s.name, "\n")] = 0;
    printf("Enter Age: ");
    scanf("%d", &s.age);
    printf("Enter Marks: ");
    scanf("%f", &s.marks);
    fwrite(&s, sizeof(s), 1, fp);
    printf("\n✅ Student record added successfully!\n");
}

void displayStudents(FILE *fp) {
    struct Student s;
    rewind(fp);
    printf("\n---- Student Records ----\n");
    while (fread(&s, sizeof(s), 1, fp) == 1) {
        printf("ID: %d\nName: %s\nAge: %d\nMarks: %.2f\n----------------\n", s.id, s.name, s.age, s.marks);
    }
}

void searchStudent(FILE *fp) {
    struct Student s;
    int id, found = 0;
    printf("\nEnter ID to search: ");
    scanf("%d", &id);
    rewind(fp);
    while (fread(&s, sizeof(s), 1, fp) == 1) {
        if (s.id == id) {
            printf("\n🎯 Student Found:\nID: %d\nName: %s\nAge: %d\nMarks: %.2f\n", s.id, s.name, s.age, s.marks);
            found = 1;
            break;
        }
    }
    if (!found)
        printf("\n❌ Student with ID %d not found!\n", id);
}

void updateStudent(FILE *fp) {
    struct Student s;
    int id, found = 0;
    long pos;
    printf("\nEnter ID to update: ");
    scanf("%d", &id);
    rewind(fp);
    while (fread(&s, sizeof(s), 1, fp) == 1) {
        if (s.id == id) {
            found = 1;
            pos = ftell(fp) - sizeof(s);
            printf("\nEnter new Name: ");
            getchar();
            fgets(s.name, 50, stdin);
            s.name[strcspn(s.name, "\n")] = 0;
            printf("Enter new Age: ");
            scanf("%d", &s.age);
            printf("Enter new Marks: ");
            scanf("%f", &s.marks);
            fseek(fp, pos, SEEK_SET);
            fwrite(&s, sizeof(s), 1, fp);
            printf("\n✅ Record updated successfully!\n");
            break;
        }
    }
    if (!found)
        printf("\n❌ Student with ID %d not found!\n", id);
}

void deleteAll(FILE *fp) {
    fclose(fp);
    fp = fopen("students.dat", "wb");
    if (fp == NULL) {
        printf("\nError deleting records.\n");
        return;
    }
    printf("\n🗑️ All student records deleted successfully!\n");
    fclose(fp);
}

int main() {
    FILE *fp;
    int choice;
    fp = fopen("students.dat", "ab+");
    if (fp == NULL) {
        printf("Error opening file!\n");
        exit(1);
    }

    while (1) {
        printf("\n===== STUDENT RECORD SYSTEM =====");
        printf("\n1. Add Student");
        printf("\n2. Display All Students");
        printf("\n3. Search Student");
        printf("\n4. Update Student");
        printf("\n5. Delete All Records");
        printf("\n6. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addStudent(fp);
                break;
            case 2:
                displayStudents(fp);
                break;
            case 3:
                searchStudent(fp);
                break;
            case 4:
                updateStudent(fp);
                break;
            case 5:
                deleteAll(fp);
                fp = fopen("students.dat", "ab+");
                break;
            case 6:
                fclose(fp);
                printf("\n👋 Exiting program...\n");
                exit(0);
            default:
                printf("\n❌ Invalid choice! Try again.\n");
        }
    }
    return 0;
}
