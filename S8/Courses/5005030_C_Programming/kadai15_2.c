#include <stdio.h>
#include <string.h>

#define MAX_BUFFER_SIZE 256

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Arguments missing, please enter: %s <stringToSearch> <filename>\n", argv[0]);
        return 1;
    }

    FILE *filep = fopen(argv[2], "r");

    if (filep == NULL) {
        printf("Wrong file\n");
        return 1;
    }

    char line[MAX_BUFFER_SIZE];
    int lineNum = 1;

    printf("\n");
    while (fgets(line, MAX_BUFFER_SIZE, filep) != NULL) {
        if (strstr(line, argv[1]) != NULL) {
            printf("%d: %s", lineNum, line);
        }
        lineNum++;
    }
    printf("\n");

    fclose(filep);

    return 0;
}
