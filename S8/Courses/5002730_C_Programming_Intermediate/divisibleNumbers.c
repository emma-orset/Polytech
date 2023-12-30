#include <stdio.h>

/*
 * Description: This program calculates and prints numbers that are divisible by specific pairs of numbers
 * within certain ranges.
 */
void main() {

    int num;

    // Loop to find and print numbers that are divisible by 7 and 9 within the range 1 to 100.
    for (num = 1; num <= 100; num++) {

        if (num % 7 == 0 && num % 9 == 0) {
            printf("%d ", num);
        }
    }

    printf("\n\n");

    // Loop to find and print numbers that are divisible by 3 and 5 within the range 1 to 100.
    for (num = 1; num <= 100; num++) {

        if (num % 3 == 0 && num % 5 == 0) {
            printf("%d ", num);
        }
    }

    printf("\n\n");

    // Loop to find and print numbers that are divisible by 7 and 9 within the range 1 to 1000.
    for (num = 1; num <= 1000; num++) {

        if (num % 7 == 0 && num % 9 == 0) {
            printf("%d ", num);
        }
    }

    printf("\n\n");
}
