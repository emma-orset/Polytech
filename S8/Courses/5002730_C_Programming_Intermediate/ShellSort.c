#include <stdio.h>

/**
 * This code demonstrates the Shell Sort algorithm to sort an array of integers in ascending order.
 *
 * @param a The array to be sorted.
 * @param n The number of elements in the array.
 */
void ShellSort(int *a, int n) {
    int h, c = 0;
    int t, j, i = 0;
    h = 4;

    // Print the elements of the array before sorting
    printf("---Before---\n");
    for (c = 0; c < n; c++) {
        printf("%3d", a[c]);
    }

    // Shell Sort algorithm
    while (h >= 1) {
        for (i = h; i < n; i++) {
            t = a[i];

            // Insertion sort within specific gaps
            for (j = i - h; j >= 0; j = j - h) {
                if (t < a[j]) {
                    a[j + h] = a[j];
                } else {
                    break;
                }
            }

            a[j + h] = t;
        }

        h /= 3;
    }

    // Print the elements of the array after sorting
    printf("\n\n---After---\n");
    for (c = 0; c < n; c++) {
        printf("%3d", a[c]);
    }
    printf("\n");
}

int main() {
    // Input array
    int a[] = {9, 20, 13, 18, 6, 5, 17, 12, 8, 10, 16, 1, 15, 3, 11, 7, 4, 14, 2, 19};

    // Call ShellSort function to sort the array
    ShellSort(a, 20);

    return 0;
}
