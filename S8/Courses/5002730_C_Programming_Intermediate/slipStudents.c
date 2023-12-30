#include <stdio.h>

/*
 * This program prompts the user to enter 10 student identifiers and
 * then separates them into two teams: Team A (even numbers) and Team B
 * (odd numbers).
 *
 * @return int
 */
int main(void) {
    int num[10]; // An array to store 10 student identifiers.
    int i;

    printf("Enter 10 student identifiers:\n"); // Prompt the user for input.
    for (i = 0; i < 10; i++) {
        scanf("%d", &num[i]); // Read student identifiers from the user.
    }

    printf("\nTeam A (even numbers):\n");
    for (i = 0; i < 10; i++) {
        if (num[i] % 2 == 0) {
            printf("%d\n", num[i]); // Display even student identifiers for Team A.
        }
    }

    printf("\nTeam B (odd numbers):\n");
    for (i = 0; i < 10; i++) {
        if (num[i] % 2 != 0) {
            printf("%d\n", num[i]); // Display odd student identifiers for Team B.
        }
    }
}
