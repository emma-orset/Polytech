#include <stdio.h>


int chrCount(const char *p,const char c){
    int res = 0;
    while(*p++){
        if (*p == c){
            res++;
        }

    }
    return res;
}

int main(void) {
    char c[2], str[100];

    printf("Enter a word: ");
    scanf("%s", str);

    printf("\nEnter a letter: ");
    scanf("%s", c);

    printf("\nResult: %d",chrCount(str, c[0]));


    return 0;
}
