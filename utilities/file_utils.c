/*
 * File I/O Utilities Module
 *
 * This program provides a set of utility functions for common file operations in C.
 * It includes reading, writing, appending, counting statistics, copying, and searching in text files.
 * The program is menu-driven for easy testing and demonstration.
 *
 * Features:
 * - Read text files line by line and display content.
 * - Write new data to a file (overwrites existing content).
 * - Append data to an existing file.
 * - Count words, lines, and characters in a file.
 * - Copy content from one file to another.
 * - Search for a specific word or phrase in a file.
 *
 * Compile: gcc -std=c11 -Wall -Wextra -o file_utils utilities/file_utils.c
 * Run: ./file_utils
 *
 * Example Usage:
 * 1. Choose option 1, enter filename "sample.txt" (assuming it exists), it will display contents.
 * 2. Choose option 2, enter filename "newfile.txt", enter data "Hello World", creates/overwrites file.
 * 3. Choose option 4, enter filename "sample.txt", outputs counts like Lines: 5, Words: 20, Characters: 100.
 * 4. Choose option 6, enter filename "sample.txt", enter word "hello", shows lines containing it.
 *
 * Note: All operations assume text files. Error handling for file not found or permissions.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE 1024

// Function to read and display file content line by line
void read_file(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        printf("Error: Cannot open file %s for reading.\n", filename);
        return;
    }
    printf("Contents of %s:\n", filename);
    char line[MAX_LINE];
    while (fgets(line, sizeof(line), file)) {
        printf("%s", line);
    }
    fclose(file);
}

// Function to write new data to file (overwrites)
void write_file(const char *filename, const char *data) {
    FILE *file = fopen(filename, "w");
    if (!file) {
        printf("Error: Cannot open file %s for writing.\n", filename);
        return;
    }
    fprintf(file, "%s", data);
    fclose(file);
    printf("Data written to %s successfully.\n", filename);
}

// Function to append data to file
void append_file(const char *filename, const char *data) {
    FILE *file = fopen(filename, "a");
    if (!file) {
        printf("Error: Cannot open file %s for appending.\n", filename);
        return;
    }
    fprintf(file, "%s", data);
    fclose(file);
    printf("Data appended to %s successfully.\n", filename);
}

// Function to count lines, words, characters
void count_stats(const char *filename, int *lines, int *words, int *chars) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        printf("Error: Cannot open file %s for reading.\n", filename);
        return;
    }
    *lines = 0;
    *words = 0;
    *chars = 0;
    char line[MAX_LINE];
    int in_word = 0;
    while (fgets(line, sizeof(line), file)) {
        (*lines)++;
        for (char *p = line; *p; p++) {
            (*chars)++;
            if (isspace(*p)) {
                if (in_word) {
                    (*words)++;
                    in_word = 0;
                }
            } else {
                in_word = 1;
            }
        }
    }
    if (in_word) (*words)++; // last word if no trailing space
    fclose(file);
}

// Function to copy file content
void copy_file(const char *src, const char *dest) {
    FILE *src_file = fopen(src, "r");
    if (!src_file) {
        printf("Error: Cannot open source file %s.\n", src);
        return;
    }
    FILE *dest_file = fopen(dest, "w");
    if (!dest_file) {
        printf("Error: Cannot open destination file %s.\n", dest);
        fclose(src_file);
        return;
    }
    char buffer[MAX_LINE];
    size_t bytes;
    while ((bytes = fread(buffer, 1, sizeof(buffer), src_file)) > 0) {
        fwrite(buffer, 1, bytes, dest_file);
    }
    fclose(src_file);
    fclose(dest_file);
    printf("File copied from %s to %s successfully.\n", src, dest);
}

// Function to search for word in file
void search_word(const char *filename, const char *word) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        printf("Error: Cannot open file %s for reading.\n", filename);
        return;
    }
    printf("Searching for '%s' in %s:\n", word, filename);
    char line[MAX_LINE];
    int line_num = 0;
    int found = 0;
    while (fgets(line, sizeof(line), file)) {
        line_num++;
        if (strstr(line, word)) {
            printf("Line %d: %s", line_num, line);
            found = 1;
        }
    }
    if (!found) {
        printf("Word '%s' not found in the file.\n", word);
    }
    fclose(file);
}

int main() {
    int choice;
    char filename[256], data[1024], word[256], src[256], dest[256];
    int lines, words, chars;

    while (1) {
        printf("\nFile I/O Utilities Menu:\n");
        printf("1. Read file\n");
        printf("2. Write to file\n");
        printf("3. Append to file\n");
        printf("4. Count lines, words, characters\n");
        printf("5. Copy file\n");
        printf("6. Search word in file\n");
        printf("7. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        getchar(); // consume newline

        switch (choice) {
            case 1:
                printf("Enter filename: ");
                fgets(filename, sizeof(filename), stdin);
                filename[strcspn(filename, "\n")] = 0;
                read_file(filename);
                break;
            case 2:
                printf("Enter filename: ");
                fgets(filename, sizeof(filename), stdin);
                filename[strcspn(filename, "\n")] = 0;
                printf("Enter data to write: ");
                fgets(data, sizeof(data), stdin);
                write_file(filename, data);
                break;
            case 3:
                printf("Enter filename: ");
                fgets(filename, sizeof(filename), stdin);
                filename[strcspn(filename, "\n")] = 0;
                printf("Enter data to append: ");
                fgets(data, sizeof(data), stdin);
                append_file(filename, data);
                break;
            case 4:
                printf("Enter filename: ");
                fgets(filename, sizeof(filename), stdin);
                filename[strcspn(filename, "\n")] = 0;
                count_stats(filename, &lines, &words, &chars);
                printf("Lines: %d, Words: %d, Characters: %d\n", lines, words, chars);
                break;
            case 5:
                printf("Enter source filename: ");
                fgets(src, sizeof(src), stdin);
                src[strcspn(src, "\n")] = 0;
                printf("Enter destination filename: ");
                fgets(dest, sizeof(dest), stdin);
                dest[strcspn(dest, "\n")] = 0;
                copy_file(src, dest);
                break;
            case 6:
                printf("Enter filename: ");
                fgets(filename, sizeof(filename), stdin);
                filename[strcspn(filename, "\n")] = 0;
                printf("Enter word to search: ");
                fgets(word, sizeof(word), stdin);
                word[strcspn(word, "\n")] = 0;
                search_word(filename, word);
                break;
            case 7:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice. Try again.\n");
        }
    }
    return 0;
}
