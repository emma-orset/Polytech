#include <stdio.h>
#include <limits.h>

int arr[] = {3, 4, -3, 2, 0, -4, -9, 7, -8, -6, 3, 4, INT_MIN};
/* int arr[] = {-2,9,0,-1,-2,-3,4,5,9,-6,INT_MIN}; */

int *findNeg(int *ptr) {
    while (*ptr >= 0) {
        ptr++;
    }
    return ptr;
}

int main(void) {
    int *p, *next;

    p = arr;
    while (1) {
        next = findNeg(p);
        if (*next == INT_MIN) {
            break;
        }
        printf("There is a negative number at position %d, the number is: %d \n", (int)(next-arr), *next);
        p = next + 1;

    }
    return 0;
}
