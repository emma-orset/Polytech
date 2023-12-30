#include <stdio.h>

void print_array(int *p){
    while (*p != 0){
        printf("%d ", *p);
        p++;
    }
    printf("\n");
}

void calcOdd(int *p, int *p_oddNum, int *p_oddSum){
    while(*p != 0){
        if (*p%2 != 0){
            *p_oddNum += 1;
            if(*p>0){
                *p_oddSum += *p;
            }
        }
        p++;
    }

    printf("Number of odd numbers: %d\n", *p_oddNum);
    printf("Sum of positive odd numbers: %d\n", *p_oddSum);
}

int main(void) {
    int arr[] = {1,2,3,4,5,-3,-2,-1,0};
    int a=0, b=0;
    print_array(arr);

    calcOdd(arr, &a, &b);

    return 0;
}
