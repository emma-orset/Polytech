#include <stdio.h>
#include <stdlib.h>
#define LENGTH 10

void fillTab(int * tab){
    int i;
    int j=0;
    for(i = 0; i < LENGTH; i++){
        * tab++ = j++;
    }
}

void displayTab(int * tab){
    int i;
    for(i = 0; i< LENGTH; i++){
        printf("tab[%d] = %d\n", i, *tab++);
    }
}

int main(void){
    int tab[LENGTH];

    fillTab(tab);

    displayTab(tab);

    char c[10] = {'e', 'm', 'm', 'a', '\0'};

    printf("Length : %d\n", strlen(c) );


}
