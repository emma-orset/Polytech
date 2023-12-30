#include <stdio.h>

/*
 *    This program converts a year from the Heisei era to the corresponding
 *    Western (Gregorian) year.
 *
 *    @return int
 */
int main(void) {
    int year; // Variable to store the year in the Heisei era.

    printf("In which year of Heisei era were you born?\n"); // Prompt the user for input.
    scanf("%d", &year); // Read the year in Heisei era from the user.

    printf("So your occidental year birth is %i.\n", year + 1989); // Calculate and display the corresponding Western year.

    return 0;
}
