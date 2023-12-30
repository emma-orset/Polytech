#include <stdio.h>

/**
 * Swap two elements in an integer array.
 * @param arr The integer array.
 * @param index1 The index of the first element to swap.
 * @param index2 The index of the second element to swap.
 * @return void
 */
void swapElements(int arr[], int index1, int index2) {
    int tmp = arr[index1];
    arr[index1] = arr[index2];
    arr[index2] = tmp;
}

/**
 * Main function to demonstrate swapping elements in an array.
 * @return int
 */
int main(void) {
    int array[5] = {9, 7, 4, 1, 3};
    int i, tmp;

    printf("Original Array:\n");
    for (i = 0; i < 5; i++) {
        printf("%2d", array[i]);
    }

    // Swap elements at index 1 and 2
    tmp = array[1];
    array[1] = array[2];
    array[2] = tmp;

    printf("\n== After Swapping ==\n");

    for (i = 0; i < 5; i++) {
        printf("%2d", array[i]);
    }
    printf("\n");

    return 0;
}
