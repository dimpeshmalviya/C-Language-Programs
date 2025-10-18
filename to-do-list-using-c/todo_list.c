#include <stdio.h>
#include <string.h>

#define MAX_TASKS 100
#define MAX_LENGTH 100

int main() {
    char tasks[MAX_TASKS][MAX_LENGTH];
    int count = 0;
    int choice;

    printf("📋 Welcome to Your To-Do List App (C Language)\n");

    do {
        printf("\n===== MENU =====\n");
        printf("1️⃣ Add Task\n");
        printf("2️⃣ View All Tasks\n");
        printf("3️⃣ Remove Task\n");
        printf("4️⃣ Exit\n");
        printf("👉 Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // clear newline

        switch (choice) {
            case 1:
                if (count < MAX_TASKS) {
                    printf("✍️ Enter task: ");
                    fgets(tasks[count], MAX_LENGTH, stdin);
                    tasks[count][strcspn(tasks[count], "\n")] = 0; // remove newline
                    count++;
                    printf("✅ Task added successfully!\n");
                } else {
                    printf("❌ Task list is full!\n");
                }
                break;

            case 2:
                printf("\n📜 Your To-Do List:\n");
                if (count == 0) {
                    printf("❌ No tasks found.\n");
                } else {
                    for (int i = 0; i < count; i++) {
                        printf("%d. %s\n", i + 1, tasks[i]);
                    }
                }
                break;

            case 3:
                if (count == 0) {
                    printf("❌ No tasks to remove.\n");
                } else {
                    int index;
                    printf("🗑️ Enter task number to remove: ");
                    scanf("%d", &index);
                    if (index > 0 && index <= count) {
                        for (int i = index - 1; i < count - 1; i++) {
                            strcpy(tasks[i], tasks[i + 1]);
                        }
                        count--;
                        printf("✅ Task removed successfully!\n");
                    } else {
                        printf("❌ Invalid task number.\n");
                    }
                }
                break;

            case 4:
                printf("👋 Exiting... Have a productive day!\n");
                break;

            default:
                printf("❌ Invalid choice. Try again.\n");
        }

    } while (choice != 4);

    return 0;
}
