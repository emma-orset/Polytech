#include <stdio.h>

/*
 * Description: This program calculates the total points scored by two teams (Giants and Tigers)
 * in a series of games and determines the winner or if the match is a tie.
 */
int main(void) {
    int giants = 0;
    int tigers = 0;
    int numGames, game, score;

    // Prompt the user to enter the number of games played.
    printf("How many games were played?  ");
    scanf("%d", &numGames);
    printf("\n");

    for (game = 1; game <= numGames; game++) {
        // Prompt the user for the number of points scored by the Giants in each game.
        printf("Game %d - How many points for the Giants?   ", game);
        scanf("%d", &score);
        giants += score;

        // Prompt the user for the number of points scored by the Tigers in each game.
        printf("Game %d - How many points for the Tigers?   ", game);
        scanf("%d", &score);
        tigers += score;
    }

    // Calculate and print the total points for each team.
    printf("\nGiants: %d points  -  Tigers: %d points\n", giants, tigers);

    // Determine the winner or if it's a tie and print the result.
    if (giants > tigers)
        printf("Giants have won.\n");
    else if (giants < tigers)
        printf("Tigers have won.\n");
    else
        printf("It's a tie.\n");
}
