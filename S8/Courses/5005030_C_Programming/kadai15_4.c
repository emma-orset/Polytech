#include <stdio.h>
#include <string.h>

#define MAX_LINE_LENGTH 256

void compareAndDisplay(FILE *file1, FILE *file2) {
    char line1[MAX_LINE_LENGTH];
    char line2[MAX_LINE_LENGTH];
    int lineNum = 1;
    int file1End = 0, file2End = 0;

    while (!file1End || !file2End) {
        if (!fgets(line1, sizeof(line1), file1)) {
            file1End = 1;
        }
        if (!fgets(line2, sizeof(line2), file2)) {
            file2End = 1;
        }

        if (!file1End && !file2End && strcmp(line1, line2) != 0) {
            printf("\n-- file1.txt\n%d: %s", lineNum, line1);
            printf("\n-- file2.txt\n%d: %s", lineNum, line2);
        } else if (!file1End && file2End) {
            printf("\n-- file1.txt\n%d: %s", lineNum, line1);
        } else if (file1End && !file2End) {
            printf("-- file2.txt\n%d: %s", lineNum, line2);
        }
        lineNum++;
    }
}


int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Arguments missing.\n");
        return 1;
    }

    char *file1Name = argv[1];
    char *file2Name = argv[2];

    FILE *file1 = fopen(file1Name, "r");
    if (file1 == NULL) {
        printf("%s isn't a file.\n", file1Name);
        return 1;
    }

    FILE *file2 = fopen(file2Name, "r");
    if (file2 == NULL) {
        fclose(file1);
        printf("%s isn't a file.\n", file2Name);
        return 1;
    }

    compareAndDisplay(file1, file2);

    fclose(file1);
    fclose(file2);

    return 0;
}

