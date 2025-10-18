/*
 Program: Tower of Hanoi using Recursion
 Problem: Solve the Tower of Hanoi problem for N disks.
 Input: 3
 Output:
 Move disk 1 from A to C
 Move disk 2 from A to B
 Move disk 1 from C to B
 Move disk 3 from A to C
 Move disk 1 from B to A
 Move disk 2 from B to C
 Move disk 1 from A to C

 Complexity: O(2^n) (since each disk move roughly doubles the work)
 Compile: gcc TowerOfHanoi.c -o TowerOfHanoi
 Run: ./TowerOfHanoi
*/

#include <stdio.h>

void towerOfHanoi(int n, char fromRod, char toRod, char auxRod) {
    if (n == 0) return;  // Base case: no disk to move
    towerOfHanoi(n - 1, fromRod, auxRod, toRod);
    printf("Move disk %d from %c to %c\n", n, fromRod, toRod);
    towerOfHanoi(n - 1, auxRod, toRod, fromRod);
}

int main() {
    int n;
    printf("Enter number of disks: ");
    scanf("%d", &n);
    printf("Steps to solve Tower of Hanoi with %d disks:\n", n);
    towerOfHanoi(n, 'A', 'C', 'B'); // Source=A, Destination=C, Auxiliary=B
    return 0;
}
