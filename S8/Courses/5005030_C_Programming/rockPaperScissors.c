#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
 *   This program simulates a game of Rock, Paper, Scissors between the player and the computer.
 *   @return int
 */
int main() {
    srand((unsigned)time(NULL)); // Initialize the random number generator with the current time.

    int player, computer, result;

    printf("Rock(0), Paper(1), Scissors(2)\n\n");

    do {
        printf("Your move: ");
        scanf("%d", &player);

        computer = rand() % 3; // Generate a random move for the computer (0, 1, or 2).

        printf("Computer's move: %d\n", computer);

        result = (player - computer + 3) % 3;

        switch (result) {
            case 0:
                printf("\n\nIt's a tie! Try again.\n\n");
                break;
            case 1:
                printf("\n\nYou win!\n");
                break;
            case 2:
                printf("\n\nYou lose...\n");
                break;
        }

    } while (result == 0); // Continue the game until there's a winner.

    return 0;
}
