#include <stdio.h>

double calcAverage(int arr[]) {
    int sum = 0;
    int count = 0;
    while (arr[count] != -1) {
        sum += arr[count];
        count++;
    }
    return (double)sum / count;
}

int calcMax(int arr[]) {
    int max = arr[0];
    int count = 1;
    while (arr[count] != -1) {
        if (arr[count] > max) {
            max = arr[count];
        }
        count++;
    }
    return max;
}

int calcMin(int arr[]) {
    int min = arr[0];
    int count = 1;
    while (arr[count] != -1) {
        if (arr[count] < min) {
            min = arr[count];
        }
        count++;
    }
    return min;
}

void calcMaxMinAve(int arr[], int* max, int* min, double* ave) {
    *max = calcMax(arr);
    *min = calcMin(arr);
    *ave = calcAverage(arr);
}

int main(void) {
    int arr[11], i, max, min;
    double ave;

    printf("Enter scores (0-100) for up to 10 people (end at -1):\n");
    for (i = 0; i < 10; i++) {
        scanf("%d", &arr[i]);
        if (arr[i] == -1) {
            break;
        }
    }
    arr[i] = -1;

    calcMaxMinAve(arr, &max, &min, &ave);

    printf("Max score: %d\n", max);
    printf("Min score: %d\n", min);
    printf("Average: %.2f\n", ave);

    return 0;
}

