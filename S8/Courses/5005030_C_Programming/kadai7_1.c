#include <stdio.h>

void divide_Real(double x, int *p_i, double *p_f){
    *p_i = (int)x;

    *p_f = x - *p_i;

}

int main(){

    int n;
    double x, f;

    printf("Enter a number:\n");
    scanf("%lf", &x);

    divide_Real(x,&n,&f);

    printf("Integer part: %d\nDecimal part:%f\n", n, f);

    return 0;
}
