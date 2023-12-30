#include <stdio.h>
#include <limits.h>

int minArr(int *p) {
    int min = *p;
    while (*p != INT_MIN) {
        if (*p < min) {
            min = *p;
        }
        p++;
    }
    return min;
}

int maxArr(int *p) {
    int max = *p;
    while (*p != INT_MIN) {
        if (*p > max) {
            max = *p;
        }
        p++;
    }
    return max;
}

void min_maxArr(int datArr[][9], int resArr[][2], int num) {
    int i;
    for (i = 0; i < num; i++) {
        resArr[i][0] = minArr(datArr[i]);
        resArr[i][1] = maxArr(datArr[i]);
    }
}

int main(void) {
    int data[3][9] = {
        {3, 5, 7, 1, 2, 3, 4, 0, INT_MIN},
        {10, 100, 5, 1, 0, -10, 15, 9, INT_MIN},
        {0, 5, -1, -3, 8, 2, 6, -8, INT_MIN}
    };

    int result[3][2];

    min_maxArr(data, result, 3);

    int i;
    for (i = 0; i < 3; i++) {
        printf("data %d = min value: %d, max value: %d\n", i+1, result[i][0], result[i][1]);
    }

    return 0;
}
