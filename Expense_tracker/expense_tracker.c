#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILE_PATH "expenses.csv"

void add_expense() {
    char date[32], desc[128];
    double amount;

    printf("Enter date (YYYY-MM-DD): ");
    scanf("%s", date);

    printf("Enter amount: ");
    scanf("%lf", &amount);
    getchar(); // clear newline

    printf("Enter description: ");
    fgets(desc, sizeof(desc), stdin);
    desc[strcspn(desc, "\n")] = 0;

    FILE *file = fopen(FILE_PATH, "a");
    if (!file) {
        printf("Error opening file!\n");
        return;
    }

    fprintf(file, "%s,%.2f,%s\n", date, amount, desc);
    fclose(file);
    printf("Expense added successfully!\n");
}

void view_expenses() {
    FILE *file = fopen(FILE_PATH, "r");
    if (!file) {
        printf("No expenses found.\n");
        return;
    }

    char line[256];
    double total = 0.0;

    printf("\nDate\t\tAmount\tDescription\n");
    printf("------------------------------------\n");

    while (fgets(line, sizeof(line), file)) {
        char date[32], desc[128];
        double amount;

        sscanf(line, "%[^,],%lf,%[^\n]", date, &amount, desc);
        printf("%s\t%.2f\t%s\n", date, amount, desc);
        total += amount;
    }

    printf("------------------------------------\n");
    printf("Total: %.2f\n\n", total);

    fclose(file);
}

void delete_expense() {
    char date[32];
    printf("Enter date to delete (YYYY-MM-DD): ");
    scanf("%s", date);

    FILE *file = fopen(FILE_PATH, "r");
    if (!file) {
        printf("No file found.\n");
        return;
    }

    FILE *temp = fopen("temp.csv", "w");
    char line[256];
    int removed = 0;

    while (fgets(line, sizeof(line), file)) {
        if (strncmp(line, date, strlen(date)) == 0)
            removed++;
        else
            fputs(line, temp);
    }

    fclose(file);
    fclose(temp);
    remove(FILE_PATH);
    rename("temp.csv", FILE_PATH);

    printf("Deleted %d expense(s).\n", removed);
}

int main() {
    int choice;

    while (1) {
        printf("\n1. Add Expense\n");
        printf("2. View Expenses\n");
        printf("3. Delete Expense\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();

        if (choice == 1)
            add_expense();
        else if (choice == 2)
            view_expenses();
        else if (choice == 3)
            delete_expense();
        else if (choice == 4)
            break;
        else
            printf("Invalid choice!\n");
    }

    return 0;
}