/*
=============================================
🎮 PROGRAM NAME: Hangman Game in C
=============================================

🎯 PROBLEM STATEMENT:
Create a console-based Hangman game where a random word is chosen
and the player must guess it one letter at a time. For each incorrect
guess, a part of the hangman is drawn. The game ends when the player
guesses the word or runs out of attempts.

📥 INPUT / 📤 OUTPUT EXAMPLES:

Example 1:
-----------
Input:
  Guess a letter: a
  Guess a letter: e
  Guess a letter: t
Output:
  Word: _ A _ E _
  You win! The word was TABLE.

Example 2:
-----------
Input:
  Guess a letter: z
  Guess a letter: q
  Guess a letter: x
Output:
  You lost! The word was TRAIN.

⚙️ FEATURES:
  ✅ Random word selection
  ✅ Tracks correct & wrong guesses
  ✅ Limited attempts (6 by default)
  ✅ ASCII hangman stages
  ✅ Colored output for better UX
  ✅ Option to replay

⏱️ TIME COMPLEXITY:
  O(n) per round (n = word length)

📚 AUTHOR:
  Rik Maity (2025)
=============================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ATTEMPTS 6
#define MAX_WORD_LEN 30

#define RED     "\x1b[31m"
#define GREEN   "\x1b[32m"
#define YELLOW  "\x1b[33m"
#define BLUE    "\x1b[34m"
#define CYAN    "\x1b[36m"
#define RESET   "\x1b[0m"

// Function declarations
void displayHangman(int attempts);
void displayWord(const char *word, const int *guessed);
int isWordGuessed(const int *guessed, int length);
void clearScreen();
void playGame();
void delay(int milliseconds);

const char *wordList[] = {
    "APPLE", "TRAIN", "HOUSE", "GARDEN", "HANGMAN",
    "ELEPHANT", "COMPUTER", "PYTHON", "PROGRAM", "COLLEGE",
    "OCEAN", "FRIEND", "TABLE", "MOUNTAIN", "MUSIC"
};

// Clears screen for clean UI
void clearScreen() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

// Small delay for smooth visuals
void delay(int milliseconds) {
    clock_t start_time = clock();
    while (clock() < start_time + milliseconds * CLOCKS_PER_SEC / 1000);
}

// Displays ASCII hangman based on attempts left
void displayHangman(int attempts) {
    const char *stages[] = {
        "  _______\n |       |\n |       O\n |      /|\\\n |      / \\\n_|_\n",
        "  _______\n |       |\n |       O\n |      /|\\\n |      /\n_|_\n",
        "  _______\n |       |\n |       O\n |      /|\\\n |\n_|_\n",
        "  _______\n |       |\n |       O\n |      /|\n |\n_|_\n",
        "  _______\n |       |\n |       O\n |       |\n |\n_|_\n",
        "  _______\n |       |\n |       O\n |\n |\n_|_\n",
        "  _______\n |       |\n |\n |\n |\n_|_\n"
    };
    printf(RED "%s" RESET, stages[attempts]);
}

// Shows current word progress
void displayWord(const char *word, const int *guessed) {
    printf("\nWord: ");
    for (int i = 0; word[i] != '\0'; i++) {
        if (guessed[i])
            printf(GREEN "%c " RESET, word[i]);
        else
            printf("_ ");
    }
    printf("\n");
}

// Checks if all letters are guessed
int isWordGuessed(const int *guessed, int length) {
    for (int i = 0; i < length; i++) {
        if (!guessed[i]) return 0;
    }
    return 1;
}

// Main game logic
void playGame() {
    srand(time(0));
    const char *word = wordList[rand() % (sizeof(wordList) / sizeof(wordList[0]))];
    int length = strlen(word);
    int guessed[length];
    memset(guessed, 0, sizeof(guessed));

    char usedLetters[26] = {0};
    int usedCount = 0;
    int wrongAttempts = 0;
    char guess;

    while (wrongAttempts < MAX_ATTEMPTS) {
        clearScreen();
        printf(YELLOW "=====================================\n" RESET);
        printf(BLUE "          HANGMAN GAME (C)          \n" RESET);
        printf(YELLOW "=====================================\n" RESET);
        displayHangman(MAX_ATTEMPTS - wrongAttempts);
        displayWord(word, guessed);

        printf("\nUsed letters: ");
        for (int i = 0; i < usedCount; i++) printf("%c ", usedLetters[i]);
        printf("\nAttempts left: %d\n", MAX_ATTEMPTS - wrongAttempts);

        printf("\nEnter your guess (A-Z): ");
        scanf(" %c", &guess);
        guess = toupper(guess);

        // Check if already used
        int alreadyUsed = 0;
        for (int i = 0; i < usedCount; i++) {
            if (usedLetters[i] == guess) {
                alreadyUsed = 1;
                break;
            }
        }
        if (alreadyUsed) {
            printf(YELLOW "You already guessed '%c'! Try a different letter.\n" RESET, guess);
            delay(1000);
            continue;
        }

        usedLetters[usedCount++] = guess;
        int correct = 0;
        for (int i = 0; i < length; i++) {
            if (word[i] == guess) {
                guessed[i] = 1;
                correct = 1;
            }
        }

        if (correct) {
            printf(GREEN "\nCorrect guess!\n" RESET);
        } else {
            printf(RED "\nWrong guess!\n" RESET);
            wrongAttempts++;
        }

        delay(800);

        if (isWordGuessed(guessed, length)) {
            clearScreen();
            printf(GREEN "\n🎉 You Win! The word was: %s\n" RESET, word);
            return;
        }
    }

    clearScreen();
    displayHangman(0);
    printf(RED "\n💀 You Lost! The word was: %s\n" RESET, word);
}

int main() {
    char playAgain;
    do {
        clearScreen();
        playGame();
        printf("\nWould you like to play again? (y/n): ");
        scanf(" %c", &playAgain);
    } while (playAgain == 'y' || playAgain == 'Y');

    printf(YELLOW "\nThanks for playing Hangman! Goodbye!\n" RESET);
    return 0;
}
