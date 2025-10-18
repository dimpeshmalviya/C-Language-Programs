#include <stdio.h>
int main()
{
    int num, reversed = 0;
    printf("Enter an integer: ");
    scanf("%d", &num);
    while (num != 0)
    {
        reversed = reversed * 10 + num % 10;
        num /= 10;
    }
    printf("Reversed number: %d\n", reversed);
    return 0;
}