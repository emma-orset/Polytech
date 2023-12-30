#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
 * Generates an array of random numbers and prints them.
 * The user specifies the number of elements in the array (n) and the numbers are
 * randomly generated and printed.
 * @return int
 */
int main(void) {
    srand(time(NULL));
    int n = 0, nb;

    // Ensure the user provides a valid value for n (between 1 and 5).
    while (n <= 0 || n > 5) {
        printf("n: ");
        scanf("%d", &n);
    }

    int arr[n];

    // Generate and populate the array with random numbers.
    for (int i = 0; i < n; i++) {
        nb = (rand() % 9) + 1;
        arr[i] = nb;
    }

    // Print the generated numbers in the array.
    for (int i = 0; i < n; i++) {
        printf("%2d", arr[i]);
    }

    return 0;
}
