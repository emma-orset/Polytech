#include <stdio.h>
#include <stdlib.h>
#include <math.h>  // Include the math library for the ceil function.

/*
 *    Calculate the price based on the given time.
 *    @param time The time in minutes.
 *    @return The calculated price.
 */
int calc(int time) {
    int res = 0;

    if (time > 0 && time <= 60) {
        res = 300;  // Base price for the first hour.
    } else if (time > 60) {
        time = time - 60;
        int r = ceil(time / 30.0);  // Calculate additional half-hour increments.
        res = 300 + r * 100;  // Base price plus additional half-hour increments.
    } else {
        res = 0;  // Invalid input, set the result to 0.
    }

    return res;
}

/*
 *    Main function to input the time and calculate the price.
 *    @return 0 indicating successful execution.
 */
int main() {
    int time;

    printf("\nTime: ");
    scanf("%d", &time);

    printf("\nPrice: %d\n", calc(time));  // Display the calculated price.

    return 0;
}
