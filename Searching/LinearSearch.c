/*n Linear Search, 
we iterate over all the elements of the array and check 
if it the current element is equal to the target element. 
If we find any element to be equal to the target element, 
then return the index of the current element. Otherwise, 
if no element is equal to the target element, then return 
 not found. Linear search is also known as sequential search.

*/
#include <stdio.h>

int linearSearch(int* arr, int n, int key) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == key) {
            return i;
        }
    }
    return -1;
}

int main() {
    int arr[] = { 10, 50, 30, 70, 80, 60, 20, 90, 40 };
    int n = sizeof(arr) / sizeof(arr[0]);
    int key;

    
    printf("Enter  number to search : ");
    scanf("%d", &key);

    int i = linearSearch(arr, n, key);

    if (i == -1)
        printf("Key %d Not Found\n", key);
    else
        printf("Key %d Found at Index: %d\n", key, i);

    return 0;
}