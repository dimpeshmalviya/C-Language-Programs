#include<stdio.h>

int main(){

    int apple, sum = 0, count = 0;
    printf("Enter the value of the Apple: ");
    scanf("%d", &apple);

    while (sum < apple){
        count++;
        sum += (12 * count * count);
    }

    printf("n: %d\n", (12 * count * count));
    printf("Sigma(%d): %d\n", (12 * count * count), sum);
    printf("Count: %d\n", count);
    printf("Perimeter: %d", (8 * count));

    return 0;
}