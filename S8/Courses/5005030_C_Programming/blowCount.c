#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

/*
 * Counts the number of blows (matching elements in different positions) between two integer arrays
 * of the same length.
 * @param arr1 The first integer array.
 * @param arr2 The second integer array.
 * @param n The length of the arrays.
 * @return int The number of blows.
 */
int countBlows(int arr1[], int arr2[], int n) {
    int blows = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i != j && arr1[i] == arr2[j]) {
                blows++;
                break; // Exit the inner loop after a blow is found.
            }
        }
    }
    return blows;
}

/*
 * Generates a random array of unique numbers, allows the user to input their own array,
 * and counts the number of blows (matching elements in different positions).
 * @return int
 */
int main(void) {
    srand(time(NULL));
    int n = 0;
    bool isIn = false;

    // Ensure the user provides a valid value for n (between 1 and 5).
    while (n <= 0 || n > 5) {
        printf("n: ");
        scanf("%d", &n);
    }

    int answer[n];
    int input[n];

    for (int i = 0; i < n; i++) {
        do {
            isIn = false;
            answer[i] = (rand() % 9) + 1;

            // Check if the generated number is already in the array.
            for (int j = 0; j < i; j++) {
                if (answer[j] == answer[i]) {
                    isIn = true;
                    break;
                }
            }
        } while (isIn);
        printf("%d ", answer[i]);
    }
    printf("\n");

    for (int i = 0; i < n; i++) {
        printf("n%d: ", i + 1);
        scanf("%d", &input[i]);
    }

    // Count blows (matching elements in different positions) and display the result.
    int blows = countBlows(answer, input, n);
    printf("Blow count = %d\n", blows);

    return 0;
}
