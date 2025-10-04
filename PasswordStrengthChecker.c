#include <stdio.h>
#include <string.h>
#include <ctype.h>

int checkPasswordStrength(char password[]) {
    int length = strlen(password);
    int hasLower = 0, hasUpper = 0, hasDigit = 0, hasSpecial = 0;

    for (int i = 0; i < length; i++) {
        if (islower(password[i]))
            hasLower = 1;
        else if (isupper(password[i]))
            hasUpper = 1;
        else if (isdigit(password[i]))
            hasDigit = 1;
        else
            hasSpecial = 1; // any non-alphanumeric char
    }

    int score = 0;

    if (length >= 8) score++;
    if (hasLower) score++;
    if (hasUpper) score++;
    if (hasDigit) score++;
    if (hasSpecial) score++;

    return score;
}

int main() {
    char password[100];

    printf("Enter your password: ");
    scanf("%99s", password);

    int strength = checkPasswordStrength(password);

    printf("\nPassword Strength: ");
    if (strength <= 2)
        printf("Weak\n");
    else if (strength == 3 || strength == 4)
        printf("Moderate\n");
    else if (strength == 5)
        printf("Strong\n");

    return 0;
}
