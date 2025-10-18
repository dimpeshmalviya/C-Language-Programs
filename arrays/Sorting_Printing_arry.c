#include <stdio.h>

int main() {
    int arr[5];  // Declare an array of size 5
    int i;

    // Taking input from the user
    printf("Enter 5 numbers:\n");
    for(i = 0; i < 5; i++) {
        scanf("%d", &arr[i]);
    }

    // Displaying the array elements
    printf("The numbers you entered are:\n");
    for(i = 0; i < 5; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}
