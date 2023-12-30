#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    int year;
    int month;
    int day;
}Date;

int randNumber(int _min, int _max){
    return _min + rand() % (_max+1-_min);
}

typedef struct {
    int id;
    int amount;
    Date date;
    int code;
}Preca;

void printPreca(Preca _p){
    printf("#%d: %d, %04d/%02d/%02d, %04d\n", _p.id, _p.amount, _p.date.year, _p.date.month, _p.date.day, _p.code);
}

void makePreca(Preca tab[], int _size) {
    for (int i = 0; i < _size; i++) {
        tab[i].id = i + 1;
        tab[i].amount = randNumber(0, 100000000000000);

        int year = randNumber(1900, 2023);
        tab[i].date.year = year;

        int month = randNumber(1, 12);
        tab[i].date.month = month;

        int day;

        if (month == 4 || month == 6 || month == 9 || month == 11)
            day = randNumber(1, 30);

        else if(month == 2){
            if (year % 4 == 0)
                day = randNumber(1, 28);
            else
                day = randNumber(1, 29);
        }
        else
            day = randNumber(1, 31);

        tab[i].date.day = day;

        int code;
        int isDuplicate = 0;

        do {
            code = randNumber(0, 9999);
            for (int j = 0; j < i; j++) {
                if (tab[j].code == code) {
                    isDuplicate = 1;
                    break;
                }
            }
        } while (isDuplicate);

        tab[i].code = code;
    }
}

void dumpPreca(Preca tab[], int _size){
    for (int i = 0; i < _size; i++){
        printPreca(tab[i]);
    }
}

int payPreca(Preca tab[], int _size){
    int id, code, amount;
    printf("Payment Process\n");
    printf("ID: ");
    scanf("%d", &id);
    printf("Security Code: ");
    scanf("%d", &code);
    printf("Amount: ");
    scanf("%d", &amount);

    for (int i = 0; i < _size; i++){
        if (tab[i].id == id && tab[i].code == code){
            if (tab[i].amount >= amount){
                tab[i].amount -= amount;
                printf("Balance: %d yen\n", tab[i].amount);
                return id;
            } else {
                printf("Insufficient Balance\n");
                return -1;
            }
        }
    }

    printf("Payment Failed\n");
    return -1;
}

int main() {
    int n;

    printf("Number of Preca cards: ");
    scanf("%d", &n);

    srand(time(NULL));

    Preca tab[n];

    makePreca(tab, n);

    dumpPreca(tab, n);

    int paymentResult = payPreca(tab, n);

    if (paymentResult != -1) {
        printf("#%d: %d, %04d/%02d/%02d, %04d\n", tab[paymentResult - 1].id, tab[paymentResult - 1].amount, tab[paymentResult - 1].date.year, tab[paymentResult - 1].date.month, tab[paymentResult - 1].date.day, tab[paymentResult - 1].code);
    }

    return 0;
}
