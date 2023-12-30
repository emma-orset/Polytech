#include <stdio.h>
#include <string.h>

char *dicSearch(char *dic[], int n, char *key) {
    for (int i = 0; i < n; i++) {
        if (strcmp(dic[i], key) == 0) {
            return dic[i];
    }
    return NULL;

int main() {
    char *dic[7] = {
        "sunday", "monday", "tuesday", "wednesday",
        "thursday", "friday", "saturday"
    };

    char key[100];

    while (1) {
        printf("key: ");
        scanf("%s", key);

        if (strcmp(key, "XXXXX") == 0) {
            break;
        }

        char *result = dicSearch(dic, 7, key);
        if (result != NULL) {
            printf("Exists\n");
        } else {
            printf("Does not exist\n");
        }
    }

    return 0;
}
