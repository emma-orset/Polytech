#include <stdio.h>

void split_arr(int *arr1, int *arr2, int *arr3){
    int i = 0;

    while (*arr1 != -1){
        if (i%2 != 1){
            *arr2 = *arr1;
            arr2++;
        }
        else{
            *arr3 = *arr1;
            arr3++;
        }

        arr1++;
        i++;

    }

    *arr2 = -1;
    *arr3 = -1;
}

void print_array(int *p){
    while (*p != -1){
        printf("%d ", *p);
        p++;
    }
    printf("\n");
}

int main(void) {
    int arr[] = {12, 7, 33, 9, 15, 28, 11, 5, 38, 25, -1};
    int a[10], b[10];

    split_arr(arr, a, b);

    print_array(a);
    print_array(b);

    return 0;
}
