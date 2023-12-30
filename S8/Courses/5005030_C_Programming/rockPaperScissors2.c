#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
 *   This program simulates a Rock-Paper-Scissors game between the player and the computer.
 *   The first player to win 3 rounds wins the game.
 *   @return int
 */
int main() {
    srand((unsigned)time(NULL));

    int playerScore = 0, computerScore = 0;
    char playerMove, computerMove;

    printf("Let's play Rock-Paper-Scissors!\n");
    printf("First to win 3 rounds wins the game.\n\n");

    while (playerScore < 3 && computerScore < 3) {
        printf("\n\nEnter your move (R for Rock, P for Paper, S for Scissors): ");
        scanf(" %c", &playerMove);

        // Input error handling, prompt the user to try again if the input is not valid.
        while (playerMove != 'R' && playerMove != 'P' && playerMove != 'S') {
            printf("Invalid input. Please enter R, P, or S: ");
            scanf(" %c", &playerMove);
        }

        printf("\n\n");

        // Generate the computer's move.
        int computerInt = rand() % 3;
        switch (computerInt) {
            case 0:
                computerMove = 'R';
                printf("(Computer) Rock");
                break;
            case 1:
                computerMove = 'P';
                printf("(Computer) Paper");
                break;
            case 2:
                computerMove = 'S';
                printf("(Computer) Scissors");
                break;
        }

        printf(" VS ");

        if (playerMove == 'S'){
            printf("Scissors (You)");
        }
        else if (playerMove == 'P'){
            printf("Paper (You)");
        }
        else if (playerMove == 'R'){
            printf("Rock (You)");
        }

        printf("\n\n");

        // Determine the winner of the round.
        if (playerMove == computerMove) {
            printf("Tie! Play again.");
        } else if ((playerMove == 'R' && computerMove == 'S') || (playerMove == 'P' && computerMove == 'R') || (playerMove == 'S' && computerMove == 'P')) {
            printf("You win this round!");
            playerScore++;
        } else {
            printf("Computer wins this round!");
            computerScore++;
        }

        printf("\n\n");

        printf("Your score: %d    |    Computer's score: %d", playerScore, computerScore);
    }

    printf("\n\n");

    // Determine the winner of the game.
    if (playerScore > computerScore) {
        printf("Congratulations! You win the game!");
    } else {
        printf("Sorry, you lost the game. Better luck next time!");
    }

    printf("\n\n");

    printf("\nDo you want to play again? (Y/N) ");
    scanf(" %c", &playerMove);
    if (playerMove == 'Y') {
        main(); // Restart the game if the player wants to play again.
    }

    printf("\n\n");

    return 0;
}
