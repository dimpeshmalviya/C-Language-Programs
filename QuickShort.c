/*
The basic idea behind QuickSort is to select a pivot element
 from the array and partition the other elements into two sub-arrays
  according to whether they are less than or greater than the pivot. 
  The sub-arrays are then sorted recursively. This process of partitioning
   and sorting continues until the entire array is sorted.
*/


#include <stdio.h>
#include <stdlib.h>

int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int main() {
    int arr[] = { 4, 2, 5, 3, 1 };
    int n = sizeof(arr) / sizeof(arr[0]);

    qsort(arr, n, sizeof(int), compare);

    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}