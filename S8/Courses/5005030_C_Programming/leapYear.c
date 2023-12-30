#include <stdio.h>
#include <stdlib.h>

/*
 *   This program finds and counts leap years within a specified range of years.
 *   @return int
 */
int main() {
    int start_year; // Stores the start year.
    int end_year; // Stores the end year.

    printf("Input start year: ");
    scanf("%d", &start_year);

    printf("\nInput end year: ");
    scanf("%d", &end_year);

    int nb = 0; // Stores the number of leap years found.

    printf("\nHere are leap years between %d and %d :\n\n", start_year, end_year);

    for (int i = start_year; i <= end_year; i++) {
        if (i % 4 == 0) {
            if (i % 100 == 0) {
                if (i % 400 == 0) {
                    printf("%d\n", i); // Print the leap year.
                    nb++;
                }
            } else {
                printf("%d\n", i); // Print the leap year.
                nb++;
            }
        }
    }

    printf("\n\nThere are %d leap years.", nb);

    return 0;
}
