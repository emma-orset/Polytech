#include <stdio.h>

/*
 *    Calculate the length of the longest consecutive run of 1s in an array.
 *    @param tab An array of integers.
 *    @param n The number of elements in the array.
 *    @return The length of the longest consecutive run of 1s.
 */
int ckLongestRun(int tab[20], int n) {
    int res = 0;       // Initialize the result to 0.
    int numOf1 = 0;    // Initialize the count of consecutive 1s to 0.

    for (int i = 0; i < n; i++) {
        if (tab[i] == 1) {
            numOf1++;   // Increment the count of consecutive 1s.
        } else if (tab[i] == 0) {
            if (numOf1 > res) {
                res = numOf1;  // Update the result if the current run is longer.
            }
            numOf1 = 0;       // Reset the count of consecutive 1s.
        }
    }

    if (numOf1 > res) {
        res = numOf1;  // Check if the last run is the longest.
    }

    return res;
}

/*
 *    Main function to input binary values, display the array, and find the longest run of consecutive 1s.
 *    @return 0 indicating successful execution.
 */
int main() {
    int tab[20];  // Array to store binary values.
    int bin = 0;
    int n = 0;    // Number of elements in the array.

    printf("\nWrite 0 or 1, finish with -1:\n");

    while (bin != -1 && n < 20) {
        scanf("%d", &bin);
        if (bin == 1 || bin == 0) {
            tab[n] = bin;  // Store valid binary values in the array.
            n++;
        }
    }

    printf("\n\n\n");
    for (int i = 0; i < n; i++) {
        printf("%d,", tab[i]);  // Display the entered binary values.
    }

    printf("\n\nLongest number of consecutive 1s: %d\n\n", ckLongestRun(tab, n));  // Display the result.

    return 0;
}
