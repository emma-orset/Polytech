#include <stdio.h>

/*
 * Description: This program finds and prints numbers within a specified range that are divisible by two user-defined numbers.
 */
void main() {

    int num, i, a, b;

    // Prompt the user to enter the upper limit of the range.
    printf("Range: 1 ~ ?: ");
    scanf("%d", &i);

    // Prompt the user to enter two numbers (separated by space) for finding multiples.
    printf("\nEnter 2 numbers (separated by space) for multiples: ");
    scanf("%d %d", &a, &b);

    // Loop through the range from 1 to the specified upper limit and find multiples of both 'a' and 'b'.
    for (num = 1; num <= i; num++) {

        if (num % a == 0 && num % b == 0) {
            printf("%d ", num);
        }
    }

    printf("\n\n");
}
