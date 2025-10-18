/*
 * Number of Students Unable to Eat Lunch
 * 
 * Problem:
 * Students are in a queue and sandwiches are in a stack.
 * A student will take a sandwich only if it matches their preference.
 * Otherwise, the student goes to the back of the queue.
 * The process stops when no student in the queue wants the top sandwich.
 *
 * Approach:
 * - Count how many students want 0 and how many want 1.
 * - Go through the sandwich stack:
 *      - If the top sandwich is available (students of that type > 0), serve it.
 *      - Otherwise, break because no one else will eat.
 * - Return the remaining students.
 *
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */

#include <stdio.h>

int countStudents(int* students, int studentsSize, int* sandwiches, int sandwichesSize) {
    int count0 = 0, count1 = 0;

    // Count preferences
    for (int i = 0; i < studentsSize; i++) {
        if (students[i] == 0) count0++;
        else count1++;
    }

    // Process sandwiches
    for (int i = 0; i < sandwichesSize; i++) {
        if (sandwiches[i] == 0) {
            if (count0 > 0) count0--;
            else return count1; // nobody wants 0, remaining are 1's
        } else {
            if (count1 > 0) count1--;
            else return count0; // nobody wants 1, remaining are 0's
        }
    }

    return 0; // all students got sandwiches
}

int main() {
    // Test Case 1
    int students1[] = {1,1,0,0};
    int sandwiches1[] = {0,1,0,1};
    int n1 = sizeof(students1)/sizeof(students1[0]);
    printf("Output 1: %d\n", countStudents(students1, n1, sandwiches1, n1)); // 0

    // Test Case 2
    int students2[] = {1,1,1,0,0,1};
    int sandwiches2[] = {1,0,0,0,1,1};
    int n2 = sizeof(students2)/sizeof(students2[0]);
    printf("Output 2: %d\n", countStudents(students2, n2, sandwiches2, n2)); // 3

    return 0;
}
