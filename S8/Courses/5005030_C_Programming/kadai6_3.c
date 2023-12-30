#include <stdio.h>
#include <stdlib.h>

void str_rev(char *str){
    char newString[50];
    int n=1;

    for (int i = 0; i<strlen(str); i++){
        newString[i]=str[strlen(str)-n];
        n++;
    }

    printf("\n%s\n", newString);
}

int main(void){

    char str[50];

    printf("Enter a word: ");
    scanf("%s", &str);

    str_rev(str);

    return 0;
}
