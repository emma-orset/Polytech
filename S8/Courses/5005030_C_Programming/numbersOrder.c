#include <stdio.h>
#include <stdlib.h>

/*
 *   This program compares three input numbers and determines whether they are in ascending, descending, or neither order.
 *   @return int
 */
int main() {
    double a, b, c; // Stores three input numbers.

    printf("Enter 3 numbers:\n");
    scanf("%lf %lf %lf", &a, &b, &c);

    if (a <= b && b <= c) {
        printf("\nWell done, it's in ascending order!");
    }
    else if (a >= b && b >= c) {
        printf("\nCongratulations, it's in descending order!");
    }
    else {
        printf("\nOh, too bad, it's not in the right order...");
    }

    return 0;
}
