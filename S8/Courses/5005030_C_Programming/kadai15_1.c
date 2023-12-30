#include <stdio.h>
#include <stdlib.h>
#include <string.h>

double fsum(int argc, char *argv[]){
    int i;
    double result = 0;
    char *ptr;

    for(i = 1; i < argc; i++){
        result += strtod(argv[i], &ptr);
    }

    return result;
}


int main(int argc, char *argv[]){

    double sum = fsum(argc, argv);

    if (argc == 1){
        printf("Error : enter some numbers.\n");
        return 1;
    }

    printf("sum = %.2f\n", sum);
    printf("ave = %.2f\n\n", sum/(argc-1));

    return 0;

}
