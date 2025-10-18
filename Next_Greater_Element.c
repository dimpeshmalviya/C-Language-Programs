#include <stdio.h>
#include <stdlib.h>

int main() {
    int arr[] = {4, 5, 2, 25};
    int n = sizeof(arr)/sizeof(arr[0]);
    int res[n], stack[n], top = -1;

    for (int i = n-1; i >= 0; i--) {
        while (top >= 0 && stack[top] <= arr[i]) top--;  // pop smaller elements
        res[i] = (top == -1) ? -1 : stack[top];
        stack[++top] = arr[i];  // push current element
    }

    for (int i = 0; i < n; i++) printf("%d ", res[i]);
}
