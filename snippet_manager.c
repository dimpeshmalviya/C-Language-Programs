#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILE_NAME "snippets.dat"
#define MAX_NAME 50
#define MAX_LANG 20
#define MAX_TAG 30
#define MAX_CODE 1024

typedef struct {
    char name[MAX_NAME];
    char language[MAX_LANG];
    char tag[MAX_TAG];
    char code[MAX_CODE];
} Snippet;

void addSnippet() {
    Snippet s;
    FILE *fp = fopen(FILE_NAME, "ab");
    if (!fp) {
        printf("Error opening file.\n");
        return;
    }

    printf("Enter snippet name: ");
    fgets(s.name, MAX_NAME, stdin); s.name[strcspn(s.name, "\n")] = 0;

    printf("Enter language: ");
    fgets(s.language, MAX_LANG, stdin); s.language[strcspn(s.language, "\n")] = 0;

    printf("Enter tag: ");
    fgets(s.tag, MAX_TAG, stdin); s.tag[strcspn(s.tag, "\n")] = 0;

    printf("Enter code (single line, max 1024 chars): ");
    fgets(s.code, MAX_CODE, stdin); s.code[strcspn(s.code, "\n")] = 0;

    fwrite(&s, sizeof(Snippet), 1, fp);
    fclose(fp);
    printf("Snippet added successfully!\n");
}

void listSnippets() {
    FILE *fp = fopen(FILE_NAME, "rb");
    if (!fp) {
        printf("No snippets found.\n");
        return;
    }

    Snippet s;
    int count = 0;
    while (fread(&s, sizeof(Snippet), 1, fp)) {
        printf("\n[%d] %s | %s | %s\nCode: %s\n", ++count, s.name, s.language, s.tag, s.code);
    }

    if (count == 0) printf("No snippets available.\n");
    fclose(fp);
}

void searchSnippets() {
    char keyword[MAX_TAG];
    printf("Enter keyword to search (name/language/tag/code): ");
    fgets(keyword, MAX_TAG, stdin); keyword[strcspn(keyword, "\n")] = 0;

    FILE *fp = fopen(FILE_NAME, "rb");
    if (!fp) {
        printf("No snippets found.\n");
        return;
    }

    Snippet s;
    int found = 0;
    while (fread(&s, sizeof(Snippet), 1, fp)) {
        if (strstr(s.name, keyword) || strstr(s.language, keyword) || strstr(s.tag, keyword) || strstr(s.code, keyword)) {
            printf("\nName: %s | Language: %s | Tag: %s\nCode: %s\n", s.name, s.language, s.tag, s.code);
            found = 1;
        }
    }

    if (!found) printf("No matching snippets found.\n");
    fclose(fp);
}

void deleteSnippet() {
    char name[MAX_NAME];
    printf("Enter snippet name to delete: ");
    fgets(name, MAX_NAME, stdin); name[strcspn(name, "\n")] = 0;

    FILE *fp = fopen(FILE_NAME, "rb");
    FILE *temp = fopen("temp.dat", "wb");
    if (!fp || !temp) {
        printf("Error opening file.\n");
        return;
    }

    Snippet s;
    int deleted = 0;
    while (fread(&s, sizeof(Snippet), 1, fp)) {
        if (strcmp(s.name, name) != 0) {
            fwrite(&s, sizeof(Snippet), 1, temp);
        } else {
            deleted = 1;
        }
    }

    fclose(fp);
    fclose(temp);
    remove(FILE_NAME);
    rename("temp.dat", FILE_NAME);

    if (deleted) printf("Snippet deleted successfully!\n");
    else printf("Snippet not found.\n");
}

int main() {
    int choice;
    while (1) {
        printf("\n=== Code Snippet Manager ===\n");
        printf("1. Add Snippet\n2. List Snippets\n3. Search Snippets\n4. Delete Snippet\n5. Exit\n");
        printf("Enter choice: ");
        if (scanf("%d", &choice) != 1) {
            while (getchar() != '\n'); 
            continue;
        }
        getchar();

        switch (choice) {
            case 1: addSnippet(); break;
            case 2: listSnippets(); break;
            case 3: searchSnippets(); break;
            case 4: deleteSnippet(); break;
            case 5: exit(0);
            default: printf("Invalid choice!\n");
        }
    }
    return 0;
}
