#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char password[100];
    int upper=0, lower=0, digit=0, special=0;

    printf("Enter your password: ");
    scanf("%s", password);

    for(int i=0; i<strlen(password); i++) {
        if(isupper(password[i])) upper++;
        else if(islower(password[i])) lower++;
        else if(isdigit(password[i])) digit++;
        else special++;
    }

    printf("\nPassword Strength: ");
    if(strlen(password) >= 8 && upper && lower && digit && special)
        printf("Strong 💪\n");
    else if(strlen(password) >= 6 && (upper || lower) && digit)
        printf("Medium 😐\n");
    else
        printf("Weak 😢\n");

    return 0;
}
