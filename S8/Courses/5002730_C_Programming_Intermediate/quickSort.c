#include<stdio.h>
#define NUM 20 /* Number of data */

/**
 * Swap two integer values.
 * @param a Pointer to the first integer.
 * @param b Pointer to the second integer.
 * @return void
 */
void swap(int *a, int *b) {
    int tmp;
    tmp = *b;
    *b = *a;
    *a = tmp;
}

/**
 * Perform quicksort on an integer array.
 * @param a The array to be sorted.
 * @param left The left index of the array or subarray to be sorted.
 * @param right The right index of the array or subarray to be sorted.
 * @return void
 */
void quickSort(int a[], int left, int right) {
    int pivot;
    int i, j;

    if(left >= right) { /* If the range to be sorted is 1 or less */
        return;
    }

    pivot = (a[left] + a[right]) / 2; /* Determine the pivot value */
    i = left;
    j = right;

    /* Partition the array into two parts:
       - Elements less than the pivot on the left
       - Elements greater than the pivot on the right
    */
    while(1) {
        while (a[i] < pivot) {
            i++;
        }

        while (a[j] > pivot) {
            j--;
        }

        /* If i >= j, it means that elements less than or equal to the pivot
           are on the left side, and elements greater than or equal to the pivot
           are on the right side */
        if (i >= j) {
            break;
        }

        swap(&(a[i]), &(a[j])); /* Swap the two elements */
        i++;
        j--;
    }

    /* Recursively sort the two partitions */
    quickSort(a, left, i - 1); /* Sort the left partition */
    quickSort(a, j + 1, right); /* Sort the right partition */
}

/**
 * Initialize an integer array with predefined values.
 * @param a The array to be initialized.
 * @return void
 */
void initArray(int a[]) {
    a[0] = 7;
    a[1] = 20;
    a[2] = 15;
    a[3] = 8;
    a[4] = 3;
    a[5] = 14;
    a[6] = 6;
    a[7] = 1;
    a[8] = 18;
    a[9] = 13;
    a[10] = 10;
    a[11] = 19;
    a[12] = 11;
    a[13] = 2;
    a[14] = 5;
    a[15] = 17;
    a[16] = 4;
    a[17] = 9;
    a[18] = 16;
    a[19] = 12;
}

/**
 * Print the elements of an integer array.
 * @param a The array to be printed.
 * @param num The number of elements in the array.
 * @return void
 */
void printArray(int a[], int num) {
    int i;
    for (i = 0; i < num; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

/**
 * Main function to demonstrate quicksort on an array.
 * @return int
 */
int main(void) {
    int array[NUM];
    initArray(array); /* Initialize the array */
    printf("Original Array:\n");
    printArray(array, NUM); /* Display the array before sorting */
    quickSort(array, 0, NUM-1); /* Perform quicksort */
    printf("Sorted Array:\n");
    printArray(array, NUM); /* Display the array after sorting */
    return 0;
}
