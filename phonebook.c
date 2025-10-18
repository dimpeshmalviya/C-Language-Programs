/*
phonebook.c
Tiny file-backed phonebook with add/list/search/delete (CSV).
Compile:
  gcc -o phonebook phonebook.c
Usage:
  ./phonebook
Menu-driven; stores entries in "phonebook.csv" in current dir.
Note: very simple CSV handling (no escaping).
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DB_FILE "phonebook.csv"
#define LINE_MAX 512

void add_entry() {
    char name[128], phone[64];
    printf("Name: ");
    if (!fgets(name, sizeof(name), stdin)) return;
    name[strcspn(name, "\n")] = 0;
    printf("Phone: ");
    if (!fgets(phone, sizeof(phone), stdin)) return;
    phone[strcspn(phone, "\n")] = 0;
    FILE *f = fopen(DB_FILE, "a");
    if (!f) { perror("fopen"); return; }
    fprintf(f, "%s,%s\n", name, phone);
    fclose(f);
    printf("Added.\n");
}

void list_entries() {
    FILE *f = fopen(DB_FILE, "r");
    if (!f) { printf("No entries.\n"); return; }
    char line[LINE_MAX];
    int i = 0;
    while (fgets(line, sizeof(line), f)) {
        char *name = strtok(line, ",\n");
        char *phone = strtok(NULL, ",\n");
        if (name && phone) {
            printf("%d: %s -> %s\n", ++i, name, phone);
        }
    }
    fclose(f);
    if (i == 0) printf("No entries.\n");
}

void search_entries() {
    char q[128];
    printf("Search name substring: ");
    if (!fgets(q, sizeof(q), stdin)) return;
    q[strcspn(q, "\n")] = 0;
    FILE *f = fopen(DB_FILE, "r");
    if (!f) { printf("No entries.\n"); return; }
    char line[LINE_MAX];
    int found = 0;
    while (fgets(line, sizeof(line), f)) {
        char tmp[LINE_MAX];
        strcpy(tmp, line);
        char *name = strtok(tmp, ",\n");
        char *phone = strtok(NULL, ",\n");
        if (name && phone && strstr(name, q)) {
            printf("%s -> %s\n", name, phone);
            found = 1;
        }
    }
    fclose(f);
    if (!found) printf("No matches.\n");
}

void delete_entry() {
    list_entries();
    printf("Enter number to delete (0 to cancel): ");
    int idx;
    if (scanf("%d", &idx) != 1) { while(getchar()!='\n'); return; }
    while (getchar() != '\n'); // clear rest
    if (idx <= 0) return;
    FILE *f = fopen(DB_FILE, "r");
    if (!f) { printf("No entries.\n"); return; }
    char lines[1024][LINE_MAX];
    int count = 0;
    while (fgets(lines[count], LINE_MAX, f)) count++;
    fclose(f);
    if (idx > count) { printf("Invalid index.\n"); return; }
    FILE *out = fopen(DB_FILE, "w");
    if (!out) { perror("fopen"); return; }
    for (int i = 0; i < count; ++i) {
        if (i == idx - 1) continue;
        fputs(lines[i], out);
    }
    fclose(out);
    printf("Deleted.\n");
}

int main(void) {
    while (1) {
        printf("\nPhonebook Menu:\n1) Add\n2) List\n3) Search\n4) Delete\n5) Exit\nChoose: ");
        int choice;
        if (scanf("%d", &choice) != 1) break;
        while (getchar() != '\n'); // consume newline
        switch (choice) {
            case 1: add_entry(); break;
            case 2: list_entries(); break;
            case 3: search_entries(); break;
            case 4: delete_entry(); break;
            case 5: printf("Bye.\n"); return 0;
            default: printf("Invalid choice.\n");
        }
    }
    return 0;
}
