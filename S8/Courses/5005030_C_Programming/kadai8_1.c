#include <stdio.h>

void print_array(int *p){
    while (*p != -1){
        printf("%d ", *p);
        p++;
    }
    printf("\n");
}

int main(void) {
    int arr[] = {12, 7, 33, 9, 15, 28, 11, 5, 38, 25, -1};

    print_array(&arr[0]);
    print_array(arr);

    return 0;
}
