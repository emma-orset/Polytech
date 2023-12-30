#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

/*
 * Generates an array of unique random numbers within a specified range (1 to 9).
 * The user specifies the number of elements in the array (n), and the array is
 * populated with unique random numbers.
 * @return int
 */
int main(void) {
    srand(time(NULL));
    int n = 0, nb;
    bool isIn = false;

    // Ensure the user provides a valid value for n (between 1 and 5).
    while (n <= 0 || n > 5) {
        printf("n: ");
        scanf("%d", &n);
    }

    int arr[n];

    for (int i = 0; i < n; i++) {
        do {
            isIn = false;
            nb = (rand() % 9) + 1;

            // Check if the generated number is already in the array.
            for (int j = 0; j < i; j++) {
                if (arr[j] == nb) {
                    isIn = true;
                    break; // Exit the loop early if a match is found.
                }
            }
        } while (isIn);

        arr[i] = nb;
    }

    // Print the generated unique numbers in the array.
    for (int i = 0; i < n; i++) {
        printf("%2d", arr[i]);
    }

    return 0;
}
