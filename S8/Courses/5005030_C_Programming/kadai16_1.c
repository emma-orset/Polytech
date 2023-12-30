#include <stdio.h>

// Function to read the current amount of money from the file (load function)
int loadMoney() {
    FILE *file = fopen("kadai16_1_money.txt", "r");
    int money = 0;
    if (file != NULL) {
        fscanf(file, "%d", &money);
        fclose(file);
    }
    return money;
}

void saveMoney(int money) {
    FILE *file = fopen("kadai16_1_money.txt", "w");
    if (file != NULL) {
        fprintf(file, "%d", money);
        fclose(file);
    }
}

int main() {
    int previousMoney = loadMoney();

    printf("Previous amount of money: %d yen\n", previousMoney);

    int income, expenses;
    printf("-----\nToday's income: ");
    scanf("%d", &income);
    printf("Today's expenses: ");
    scanf("%d", &expenses);

    int currentMoney = previousMoney + income - expenses;

    printf("-----\nCurrent amount of money: %d yen\n", currentMoney);

    saveMoney(currentMoney);

    return 0;
}
