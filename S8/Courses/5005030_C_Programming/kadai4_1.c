#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROW 9
#define COL 9

void initialize(int nums[][COL]) {
    srand((unsigned)time(NULL));
    for(int i=0; i<ROW; i++) {
        for(int j=0; j<COL; j++) {
            nums[i][j] = rand() % 10000; // 0000~9999
        }
    }
}

void print_table(int nums[][COL]) {
    printf(" |   1|   2|   3|   4|   5|   6|   7|   8|   9|\n");
    printf("-+----+----+----+----+----+----+----+----+----+\n");
    for(int i=0; i<ROW; i++) {
        printf("%d|", i+1);
        for(int j=0; j<COL; j++) {
            printf("%04d|", nums[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int nums[ROW][COL];
    initialize(nums);
    print_table(nums);

    int row, col;
    printf("Row? :");
    scanf("%d", &row);
    printf("Column? :");
    scanf("%d", &col);

    printf("Pin code: %04d\n", nums[row-1][col-1]);

    return 0;
}
