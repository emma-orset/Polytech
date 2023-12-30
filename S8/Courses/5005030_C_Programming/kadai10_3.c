#include <stdio.h>

void strMix(const char *str1, const char *str2, char *str3){

    while (*str1 || *str2) {
        if (*str1) {
            *str3 = *str1;
            str1++;
            str3++;
        }
        if (*str2) {
            *str3 = *str2;
            str2++;
            str3++;
        }
    }

    *str3 = '\0';
}

int main(void) {
    char arr1[50], arr2[50], arr3[102];

    printf("arr1: ");
    scanf("%s", arr1);

    printf("arr2: ");
    scanf("%s", arr2);

    strMix(arr1, arr2, arr3);

    printf("\narr3: %s", arr3);

    return 0;
}
