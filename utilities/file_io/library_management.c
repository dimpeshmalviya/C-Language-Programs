#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int id;
    char title[100];
    char author[50];
} Book;

void addBook() {
    FILE *f = fopen("library.dat", "ab");
    if (!f) {
        printf("Unable to open file!\n");
        return;
    }

    Book b;
    printf("Enter Book ID: ");
    scanf("%d", &b.id);
    getchar(); // clear newline
    printf("Enter Title: ");
    fgets(b.title, sizeof(b.title), stdin);
    b.title[strcspn(b.title, "\n")] = 0; // remove newline
    printf("Enter Author: ");
    fgets(b.author, sizeof(b.author), stdin);
    b.author[strcspn(b.author, "\n")] = 0;

    fwrite(&b, sizeof(Book), 1, f);
    fclose(f);
    printf("✅ Book added successfully!\n");
}

void displayBooks() {
    FILE *f = fopen("library.dat", "rb");
    if (!f) {
        printf("No books found.\n");
        return;
    }

    Book b;
    printf("\n--- Library Books ---\n");
    while (fread(&b, sizeof(Book), 1, f)) {
        printf("ID: %d | Title: %s | Author: %s\n", b.id, b.title, b.author);
    }
    fclose(f);
}

void searchBook() {
    FILE *f = fopen("library.dat", "rb");
    if (!f) {
        printf("No books found.\n");
        return;
    }

    int id;
    printf("Enter Book ID to search: ");
    scanf("%d", &id);

    Book b;
    int found = 0;
    while (fread(&b, sizeof(Book), 1, f)) {
        if (b.id == id) {
            printf("ID: %d | Title: %s | Author: %s\n", b.id, b.title, b.author);
            found = 1;
            break;
        }
    }

    if (!found)
        printf("Book not found.\n");

    fclose(f);
}

void deleteBook() {
    FILE *f = fopen("library.dat", "rb");
    if (!f) {
        printf("No books found.\n");
        return;
    }

    int id;
    printf("Enter Book ID to delete: ");
    scanf("%d", &id);

    FILE *temp = fopen("temp.dat", "wb");
    Book b;
    int found = 0;

    while (fread(&b, sizeof(Book), 1, f)) {
        if (b.id != id) {
            fwrite(&b, sizeof(Book), 1, temp);
        } else {
            found = 1;
        }
    }

    fclose(f);
    fclose(temp);

    remove("library.dat");
    rename("temp.dat", "library.dat");

    if (found)
        printf("✅ Book deleted successfully!\n");
    else
        printf("Book not found.\n");
}

int main() {
    int choice;
    do {
        printf("\n====== Library Management System ======\n");
        printf("1. Add Book\n2. Display Books\n3. Search Book\n4. Delete Book\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: addBook(); break;
            case 2: displayBooks(); break;
            case 3: searchBook(); break;
            case 4: deleteBook(); break;
            case 5: printf("Exiting...\n"); break;
            default: printf("Invalid choice!\n");
        }
    } while(choice != 5);

    return 0;
}
