/*
 * Number Guessing Game
 * --------------------
 * The program generates a random number between 1 and 100.
 * The player has 7 attempts to guess the number.
 * After each guess, the program tells if the guess is too high,
 * too low, or close (within 5 numbers).
 * If the player guesses correctly, they win.
 * If they use all attempts without guessing, the number is revealed.
 *
 * Author: Your Name
 * Date: 2025-10-14
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int target, guess, attempts = 7;

    srand(time(NULL));
    target = rand() % 100 + 1;

    printf("Welcome to the Number Guessing Game!\n");
    printf("I have picked a number between 1 and 100.\n");
    printf("You have %d attempts to guess it.\n\n", attempts);

    for (int i = 1; i <= attempts; i++) {
        printf("Attempt %d: Enter your guess: ", i);
        scanf("%d", &guess);

        if (guess == target) {
            printf("Congratulations! You guessed the number!\n");
            return 0;
        } else if (abs(guess - target) <= 5) {
            if (guess < target)
                printf("Close! Your guess is a bit low.\n");
            else
                printf("Close! Your guess is a bit high.\n");
        } else if (guess < target) {
            printf("Too low.\n");
        } else {
            printf("Too high.\n");
        }
    }

    printf("\nSorry, you ran out of attempts. The number was %d.\n", target);
    return 0;
}
