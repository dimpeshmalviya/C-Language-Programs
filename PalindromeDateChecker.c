#include <stdio.h>

int isPalindrome(int num) {
    int reversed = 0, original = num;
    while(num > 0) {
        reversed = reversed * 10 + (num % 10);
        num /= 10;
    }
    return reversed == original;
}

int main() {
    int date;
    printf("Enter date in YYYYMMDD format: ");
    scanf("%d", &date);

    if(isPalindrome(date))
        printf("Wow! The date is a palindrome 📅✨\n");
    else
        printf("Not a palindrome date.\n");

    return 0;
}
