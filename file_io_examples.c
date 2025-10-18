/*
 * file_io_examples.c
 * Demonstrates basic file read/write in C.
 * Creates (or overwrites) "sample_output.txt", writes sample lines,
 * then reopens and reads them back to stdout.
 * Compile: gcc -std=c11 -Wall -Wextra -o file_io_examples file_io_examples.c
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
    const char *filename = "sample_output.txt";
    FILE *f = fopen(filename, "w");
    if (!f) {
        perror("fopen for write");
        return EXIT_FAILURE;
    }

    fprintf(f, "Hello from file_io_examples!\n");
    fprintf(f, "This file was written by a C program.\n");
    fclose(f);

    f = fopen(filename, "r");
    if (!f) {
        perror("fopen for read");
        return EXIT_FAILURE;
    }

    printf("Contents of %s:\n", filename);
    char buffer[256];
    while (fgets(buffer, sizeof(buffer), f)) {
        fputs(buffer, stdout);
    }
    fclose(f);

    return EXIT_SUCCESS;
}
