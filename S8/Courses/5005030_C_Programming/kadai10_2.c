#include <stdio.h>
#include <ctype.h>

void strSep(const char *str1, char *str2, char *str3){
    while(*str1){
        if (isalpha(*str1) != 0){
            *str2++ = *str1++;
        }

        else if (isdigit(*str1) != 0){
            *str3++ = *str1++;
        }

        else{
            str1++;
        }
    }

    *str2 = "\0";
    *str3 = "\0";
}

int main(void) {
    char arr1[100], arr2[100], arr3[100];

    printf("Enter a string: ");
    scanf("%s", arr1);

    strSep(arr1, arr2, arr3);

    printf("\nLetters: %s", arr2);
    printf("\nNumbers: %s", arr3);

    return 0;
}
