#include <stdio.h>
#include <math.h>

/*
 *    This program calculates parking fees based on the number of minutes
 *    the user has parked. If the time is between 2 and 600 minutes, a fee
 *    of 100 yen per hour is applied.
 *
 *    @return int
 */
int main(void) {
    int time; // Variable to store the number of minutes parked.

    printf("How many minutes have you parked? "); // Prompt the user for input.
    scanf("%d", &time); // Save the user-entered parking time in the 'time' variable.

    if (time > 2 && time < 600) {
        // Calculate parking fee for times between 2 and 600 minutes, rounding up to the next hour.
        printf("The parking fee is %d yen.\n", ((int)floor(time / 60) + 1) * 100);
    } else if (time >= 600) {
        printf("Parking fees are 1,000 yen.\n"); // Parking fee for times of 600 minutes or more.
    } else {
        printf("Parking fees are 0 yen.\n"); // No parking fee for times less than or equal to 2 minutes.
    }

    return 0;
}
