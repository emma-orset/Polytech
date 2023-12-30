#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

/*
 * Counts the number of hits (matching elements) between two integer arrays of the same length.
 * @param arr1 The first integer array.
 * @param arr2 The second integer array.
 * @param n The length of the arrays.
 * @return int The number of hits.
 */
int countHits(int arr1[], int arr2[], int n) {
    int hits = 0;
    for (int i = 0; i < n; i++) {
        if (arr1[i] == arr2[i]) {
            hits++;
        }
    }
    return hits;
}

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
                break;
            }
        }
    }
    return blows;
}

/*
 * Checks if a value is unique in an array.
 * @param arr The integer array to check.
 * @param n The length of the array.
 * @param val The value to check for uniqueness.
 * @return bool Returns true if the value is unique, false otherwise.
 */
bool isUnique(int arr[], int n, int val) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == val) {
            return false;
        }
    }
    return true;
}

/*
 * Generates an array of random unique numbers within a specified range (1 to 9).
 * @param arr The array to be populated with unique random numbers.
 * @param n The length of the array.
 */
void generateRandomNumbers(int arr[], int n) {
    bool isIn = false;
    for (int i = 0; i < n; i++) {
        do {
            isIn = false;
            arr[i] = (rand() % 9) + 1;
            for (int j = 0; j < i; j++) {
                if (arr[j] == arr[i]) {
                    isIn = true;
                    break;
                }
            }
        } while (isIn);
        //printf("%d ", arr[i]);
    }
    printf("\n");
}

/*
 * Implements a guessing game where the user attempts to guess a sequence of numbers.
 * The game counts hits (matching elements in the same position) and blows (matching elements
 * in different positions).
 * @return int
 */
int main(void) {
    srand(time(NULL));
    int n = 0;
    int tries = 1;
    bool playAgain = true;

    // Ensure the user provides a valid value for n (between 1 and 5).
    while (n <= 0 || n > 5) {
        printf("n: ");
        scanf("%d", &n);
    }

    int answer[n];
    int input[n];

    generateRandomNumbers(answer, n);

    while (playAgain) {
        printf("Attempt %d:\n");
        for (int i = 0; i < n; i++) {
            printf("n%d: ", i + 1);
            scanf("%d", &input[i]);
        }

        int hits = countHits(answer, input, n);
        int blows = countBlows(answer, input, n);

        if (hits == n) {
            printf("Correct! (%d tries)\n", tries);
            playAgain = false;
        } else {
            printf("Incorrect: Hit count = %d, Blow count = %d\n", hits, blows);
            tries++;
            printf("Continue? (1: Yes, 2: No): ");
            int choice;
            scanf("%d", &choice);
            playAgain = (choice == 1);
        }
    }

    return 0;
}
