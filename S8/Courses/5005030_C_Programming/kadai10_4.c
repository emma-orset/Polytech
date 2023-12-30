#include <stdio.h>

int strKeynum(const char *str, const char *key) {
    int count = 0;

    while (*str) {
        const char *str_orig = str;
        const char *key_orig = key;

        while (*str == *key && *str && *key) {
            str++;
            key++;
        }

        if (*key == '\0')
            count++;

        str = str_orig + 1;
        key = key_orig;
    }

    return count;
}

int main(void) {
    char str[100], key[100];

    printf("str: ");
    scanf("%s", str);

    printf("key: ");
    scanf("%s", key);

    int count = strKeynum(str, key);

    printf("%d key(s) found\n", count);

    return 0;
}

