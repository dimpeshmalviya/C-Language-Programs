/*
?? Odd or Even Game in C
--------------------------------------------
Author: Your Name
Repository: C Language Programs — Hacktoberfest 2025

?? Description:
A simple interactive game where the player chooses
either "Odd" or "Even", selects a number, and plays
against the computer. The sum of the two numbers
determines the winner.

?? Features:
- Takes user input for choice and number
- Generates a random number for the computer
- Declares the winner based on the sum
- Option to play again
- Beginner-friendly and educational

?? Time Complexity: O(1)
?? Space Complexity: O(1)
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int user_choice, user_num, comp_num, sum;
    char play_again;

    // Seed random number generator
    srand(time(0));

    printf("?? Welcome to the Odd or Even Game! ??\n");

    do {
        // Get user's choice
        printf("\nChoose your side:\n");
        printf("Enter 1 for Odd or 0 for Even: ");
        scanf("%d", &user_choice);

        // Validate input
        if (user_choice != 0 && user_choice != 1) {
            printf("Invalid choice! Please enter 1 for Odd or 0 for Even.\n");
            continue;
        }

        // Get user's number
        printf("Enter your number (1–10): ");
        scanf("%d", &user_num);

        if (user_num < 1 || user_num > 10) {
            printf("Invalid number! Please choose between 1 and 10.\n");
            continue;
        }

        // Generate computer’s random number (1–10)
        comp_num = (rand() % 10) + 1;
        printf("Computer chose: %d\n", comp_num);

        // Calculate the sum
        sum = user_num + comp_num;
        printf("Sum = %d ? ", sum);

        // Determine and display result
        if (sum % 2 == 0) {
            printf("It's Even!\n");
            if (user_choice == 0)
                printf("?? You win!\n");
            else
                printf("?? Computer wins!\n");
        } else {
            printf("It's Odd!\n");
            if (user_choice == 1)
                printf("?? You win!\n");
            else
                printf("?? Computer wins!\n");
        }

        // Ask to play again
        printf("\nDo you want to play again? (y/n): ");
        scanf(" %c", &play_again);

    } while (play_again == 'y' || play_again == 'Y');

    printf("\nThanks for playing! ??\n");
    return 0;
}
