#include <stdio.h>

int main() {
    int arr[10] = {1,2,3,4,5,6,7,8,9,10};
    int element, found = 0;

    printf("Enter the element that you want to search: ");
    scanf("%d", &element);

    for(int i = 0; i < 10; i++) {
        if(arr[i] == element) {
            printf("Element found at position %d\n", i + 1);
            found = 1;
            break;
        }
    }

    if(!found) {
        printf("Element doesn't exist\n");
    }

    return 0;
}
