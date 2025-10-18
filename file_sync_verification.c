#include <stdio.h>

int exists(int arr[], int n, int val) {
    for (int i = 0; i < n; i++)
        if (arr[i] == val)
            return 1;
    return 0;
}

int main() {
    int serverA[] = {123, 456, 789, 101};
    int serverB[] = {123, 789, 101, 999};
    int nA = 4, nB = 4;

    printf("Missing/Changed: [");
    int first = 1;

    for (int i = 0; i < nA; i++)
        if (!exists(serverB, nB, serverA[i])) {
            if (!first) printf(", ");
            printf("%d", serverA[i]);
            first = 0;
        }

    for (int i = 0; i < nB; i++)
        if (!exists(serverA, nA, serverB[i])) {
            if (!first) printf(", ");
            printf("%d", serverB[i]);
            first = 0;
        }

    printf("]\n");
    return 0;
}