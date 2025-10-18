#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int userChoice, computerChoice;
    char *choices[] = {"Rock", "Paper", "Scissors"};

    srand(time(0));

    printf("✊🤚✌️ Welcome to Rock-Paper-Scissors!\n");
    printf("1: Rock, 2: Paper, 3: Scissors\n");

    printf("Enter your choice: ");
    scanf("%d", &userChoice);

    if (userChoice < 1 || userChoice > 3)
    {
        printf("Invalid choice!\n");
        return 0;
    }

    computerChoice = rand() % 3 + 1;
    printf("You chose: %s\n", choices[userChoice - 1]);
    printf("Computer chose: %s\n", choices[computerChoice - 1]);

    if (userChoice == computerChoice)
        printf("🤝 It's a tie!\n");
    else if ((userChoice == 1 && computerChoice == 3) ||
             (userChoice == 2 && computerChoice == 1) ||
             (userChoice == 3 && computerChoice == 2))
        printf("🎉 You win!\n");
    else
        printf("💻 Computer wins!\n");

    return 0;
}
