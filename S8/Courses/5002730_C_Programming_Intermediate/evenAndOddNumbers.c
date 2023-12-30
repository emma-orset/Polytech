#include <stdio.h>
#include <stdlib.h>

/**
 * Classify and display numbers as even or odd in a given range.
 * @return void
 */
int main() {
    int a;  // Variable to store the upper limit of the range
    int i;  // Loop counter variable

    // Prompt the user to enter the upper limit of the range
    printf("a=");
    scanf("%d", &a);

    // Loop through numbers from 1 to 'a'
    for (i = 1; i <= a; i++) {
        if (i % 2 == 0) {
            // Check if 'i' is even and display it accordingly
            printf("%d is an even number.\n", i);
        } else {
            // 'i' is not even, so it's classified as a odd number
            printf("%d is a odd number.\n", i);
        }
    }

    printf("\n");

    return 0;
}

