#include <stdio.h>

void swap(int *nx, int *ny) {
    int temp = *nx;
    *nx = *ny;
    *ny = temp;
}

void rotate(int *x, int *y, int *z){
    swap(x,y);
    swap(z,y);

}

int main(){
    int n1=1,n2=2,n3=3;

    printf("Input\nn1:");
    scanf("%d", &n1);

    printf("n2:");
    scanf("%d", &n2);
    printf("n3:");
    scanf("%d", &n3);

    rotate(&n1,&n2,&n3);

    printf("\nOutput\nn1:%d\nn2:%d\nn3:%d\n", n1, n2, n3);

    return 0;
}
