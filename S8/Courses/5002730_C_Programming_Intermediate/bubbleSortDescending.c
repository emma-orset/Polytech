#include <stdio.h>

/**
 * Sort an array of integers in descending order using the Bubble Sort algorithm.
 * @return int
 */
int main(void) {
    int i, j;
    int array[5] = {7, 1, 3, 8, 5}; // Initialize an array of integers with 5 elements

    int tmp; // Declare a temporary integer variable for swapping elements

    // Outer loop: Iterate from the last element to the first
    for (j = 4; j >= 0; j--) {
        // Inner loop: Iterate from the first element to one less than the outer loop index
        for (i = 0; i < j; i++) {
            // If adjacent elements are not in order, swap them
            if (array[i] > array[i + 1]) {
                tmp = array[i + 1];
                array[i + 1] = array[i];
                array[i] = tmp;
            }
        }
    }

    // Print the sorted array in descending order
    for (i = 4; i >= 0; i--) {
        printf("%2d", array[i]); // Print each element with a format specifier for minimum width
    }

    return 0; // Return 0 to indicate successful execution
}
