#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int id;
    char name[50];
    int age;
    float marks;
} Student;

void addRecord() {
    FILE *f = fopen("students.dat", "ab");
    if (!f) {
        printf("Unable to open file!\n");
        return;
    }

    Student s;
    printf("Enter ID: ");
    scanf("%d", &s.id);
    getchar(); // clear newline
    printf("Enter Name: ");
    fgets(s.name, sizeof(s.name), stdin);
    s.name[strcspn(s.name, "\n")] = 0; // remove newline
    printf("Enter Age: ");
    scanf("%d", &s.age);
    printf("Enter Marks: ");
    scanf("%f", &s.marks);

    fwrite(&s, sizeof(Student), 1, f);
    fclose(f);
    printf("Record added successfully.\n");
}

void displayRecords() {
    FILE *f = fopen("students.dat", "rb");
    if (!f) {
        printf("No records found.\n");
        return;
    }

    Student s;
    printf("\n--- Student Records ---\n");
    while (fread(&s, sizeof(Student), 1, f)) {
        printf("ID: %d | Name: %s | Age: %d | Marks: %.2f\n", s.id, s.name, s.age, s.marks);
    }
    fclose(f);
}

void searchRecord() {
    FILE *f = fopen("students.dat", "rb");
    if (!f) {
        printf("No records found.\n");
        return;
    }

    int id;
    printf("Enter ID to search: ");
    scanf("%d", &id);

    Student s;
    int found = 0;
    while (fread(&s, sizeof(Student), 1, f)) {
        if (s.id == id) {
            printf("ID: %d | Name: %s | Age: %d | Marks: %.2f\n", s.id, s.name, s.age, s.marks);
            found = 1;
            break;
        }
    }
    if (!found) printf("Record not found.\n");
    fclose(f);
}

void deleteRecord() {
    FILE *f = fopen("students.dat", "rb");
    if (!f) {
        printf("No records found.\n");
        return;
    }

    int id;
    printf("Enter ID to delete: ");
    scanf("%d", &id);

    FILE *temp = fopen("temp.dat", "wb");
    Student s;
    int found = 0;

    while (fread(&s, sizeof(Student), 1, f)) {
        if (s.id != id) {
            fwrite(&s, sizeof(Student), 1, temp);
        } else {
            found = 1;
        }
    }

    fclose(f);
    fclose(temp);

    remove("students.dat");
    rename("temp.dat", "students.dat");

    if (found)
        printf("Record deleted successfully.\n");
    else
        printf("Record not found.\n");
}

int main() {
    int choice;
    do {
        printf("\n--- Student Records Management ---\n");
        printf("1. Add Record\n2. Display Records\n3. Search Record\n4. Delete Record\n5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: addRecord(); break;
            case 2: displayRecords(); break;
            case 3: searchRecord(); break;
            case 4: deleteRecord(); break;
            case 5: printf("Exiting...\n"); break;
            default: printf("Invalid choice!\n");
        }
    } while(choice != 5);

    return 0;
}
