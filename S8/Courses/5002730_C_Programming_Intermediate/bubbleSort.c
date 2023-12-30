#include <stdio.h>

/**
 * Sort an array of 5 numbers in ascending order using the Bubble Sort algorithm.
 * @return int
 */
int main(void) {
    int i, j;
    int array[5];
    int tmp;

    // Prompt the user to enter 5 numbers
    printf("Enter 5 numbers:\n");

    for (i = 0; i < 5; i++) {
        scanf("%d", &array[i]);
    }

    // Bubble Sort algorithm to sort the array in ascending order
    for (j = 4; j >= 0; j--) {
        for (i = 0; i < j; i++) {
            if (array[i] > array[i + 1]) {
                // Swap elements if they are in the wrong order
                tmp = array[i + 1];
                array[i + 1] = array[i];
                array[i] = tmp;
            }
        }
    }

    // Print the sorted array
    printf("Sorted array in ascending order: ");
    for (i = 0; i < 5; i++) {
        printf("%d ", array[i]);
    }

    return 0;
}
