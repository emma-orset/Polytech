#include <stdio.h>

/*
 *    This program converts a year from a Japanese era to the corresponding
 *    Western (Gregorian) year and displays the result based on the user's
 *    choice of era (Showa, Heisei, Reiwa). It also checks for valid year ranges
 *    within each era.
 *
 *    @return int
 */
int main(void) {
    int year, gengou; // Variables to store the year and the era choice.

    printf("What year were you born in? "); // Prompt the user for input.
    scanf("%d", &year); // Read and store the year.

    printf("Which era?\n1=Showa\n2=Heisei\n3=Reiwa\n"); // Prompt the user to choose an era.
    scanf("%d", &gengou); // Read and store the era choice.

    switch (gengou) {
        case 1:
            if (year <= 63) {
                printf("\nOh, you were born in Showa Era at year %d!\nThen, in Western calendar, you were born in the year %d!\n", year, year + 1925);
            } else {
                printf("Too many years for Showa Era (only 63 years).\n");
            }
            break;

        case 2:
            if (year <= 30) {
                printf("\nOh, you were born in Heisei Era at year %d!\nThen, in Western calendar, you were born in the year %d!\n", year, year + 1988);
            } else {
                printf("Too many years for Heisei Era (only 30 years).\n");
            }
            break;

        case 3:
            if (year <= 5) {
                printf("\nOh, you were born in Reiwa Era at year %d!\nThen, in Western calendar, you were born in the year %d!\n", year, year + 2018);
            } else {
                printf("Too many years for Reiwa Era (only 5 years).\n");
            }
            break;

        default:
            printf("Not a good choice.\n"); // Default case for an invalid era choice.
    }
    return 0;
}
