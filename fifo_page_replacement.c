#include <stdio.h>
#include <stdbool.h>

/**
 * @brief Simulates the FIFO (First-In, First-Out) Page Replacement Algorithm.
 * * This program takes a page reference string and the capacity of page frames,
 * then simulates the FIFO replacement process, reporting hits, faults, and 
 * the final total number of page faults.
 */
int main() {
    int n;
    printf("Enter number of pages in the reference string: ");
    // Ensure the input is a positive integer for the array size
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Invalid input for number of pages.\n");
        return 1; 
    }

    int pages[n];
    printf("Enter page reference string (space-separated integers):\n");
    for (int i = 0; i < n; i++) {
        if (scanf("%d", &pages[i]) != 1) {
            printf("Invalid input for page reference string.\n");
            return 1;
        }
    }

    int capacity;
    printf("Enter capacity of page frames: ");
    if (scanf("%d", &capacity) != 1 || capacity <= 0) {
        printf("Invalid input for capacity.\n");
        return 1;
    }

    int frames[capacity];
    int index = 0; // Index to track which frame slot will be replaced next (FIFO order)
    int page_faults = 0;

    // Initialize frames to -1 (indicating an empty slot)
    for (int i = 0; i < capacity; i++) {
        frames[i] = -1;
    }

    printf("\n--- Page Replacement Process (FIFO) ---\n");

    // Iterate through the page reference string
    for (int i = 0; i < n; i++) {
        int page = pages[i];
        bool found = false;

        // 1. Check if the page is already in a frame (Page Hit)
        for (int j = 0; j < capacity; j++) {
            if (frames[j] == page) {
                found = true;
                break;
            }
        }

        if (!found) {
            // 2. Page Fault: Replace the oldest page using the 'index'
            frames[index] = page;
            
            // Move the index to the next slot in a circular fashion 
            // This is the core of the FIFO logic: the oldest is the one 
            // that has been in the frame the longest, which is what the index points to.
            index = (index + 1) % capacity;
            
            page_faults++;
            printf("Reference %d: Page %d caused a FAULT. Frames: ", i + 1, page);
        } else {
            // Page Hit
            printf("Reference %d: Page %d was a HIT. Frames: ", i + 1, page);
        }

        // Print current state of the frames
        for (int k = 0; k < capacity; k++) {
            if (frames[k] != -1) {
                printf("%d ", frames[k]);
            } else {
                printf("- ");
            }
        }
        printf("\n");
    }

    printf("\n--- Results ---\n");
    printf("Total Page Faults = %d\n", page_faults);
    printf("Total Page References = %d\n", n);

    return 0;
}