#include <stdio.h>

/*
 *    This program converts a year from the Japanese era to the corresponding
 *    Western (Gregorian) year and checks if it's within the Heisei Era or not.
 *
 *    @return int
 */
int main(void) {
    int year; // Variable to store the year in the Japanese era.

    printf("In which Japanese year were you born?\n"); // Prompt the user for input.
    scanf("%d", &year); // Read the year in the Japanese era from the user.

    if (year <= 30) {
        printf("You were born in Heisei Era! Your occidental year birth is %i.\n", year + 1989);
    } else {
        printf("Heisei Era stops at year 30; next is Reiwa Era.\n");
    }

    return 0;
}
