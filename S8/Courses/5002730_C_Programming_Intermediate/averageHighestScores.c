#include <stdio.h>

/**
 * Calculate the average and find the highest score among 5 students' scores.
 * @return int
 */
int main(void) {
    int max, score[5], sum, i, j;
    double mean;

    printf("Enter scores of 5 students (between 0 and 100):\nPattern : 00 00 00 00 00\n");
    sum = 0;

    for (i = 0; i < 5; i++) {
        scanf("%d", &score[i]);
        sum = sum + score[i];
    }

    mean = (double)sum / 5;  // Calculate the average

    max = score[0];

    for (j = 1; j < 5; j++) {
        if (max < score[j]) {
            max = score[j];
        }
    }

    printf("Average is: %lf.\nBest score is: %d.", mean, max);
    return 0;
}
