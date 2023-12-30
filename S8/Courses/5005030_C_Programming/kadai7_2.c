#include <stdio.h>

void rotate(int *x, int *y, int *z){

    int tempx = *x;

    *x = *y;
    *y = *z;
    *z = tempx;

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
