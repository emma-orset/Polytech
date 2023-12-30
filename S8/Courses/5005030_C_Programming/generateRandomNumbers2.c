#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

/*
 * Generates an array of random numbers, allows the user to input a number to check
 * if it's in the array, and displays the result.
 * @return int
 */
int main(void) {
    srand(time(NULL));
    int n = 0, nb, test;
    bool isIn = false;

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

    printf("\nWhich number do you want to try?\n");
    scanf("%d", &test);

    // Check if the test number is in the array.
    for (int i = 0; i < n; i++) {
        if (arr[i] == test) {
            isIn = true;
        }
    }

    // Display whether the test number is in the array or not.
    isIn ? printf("\n%d is in the tab!\n", test) : printf("\n%d isn't in the tab...\n", test);

    return 0;
}
