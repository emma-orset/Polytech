#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct Date {
    int year;
    int month;
    int day;
};

int randNumber(int _min, int _max){
    return _min + rand() % (_max+1-_min);
}

struct Preca {
    int id;
    int amount;
    struct Date date;
    int code;
};

void printPreca(struct Preca _p){
    printf("#%d: %d, %04d/%02d/%02d, %04d\n", _p.id, _p.amount, _p.date.year, _p.date.month, _p.date.day, _p.code);
}

void makePreca(struct Preca tab[], int _size) {
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

void dumpPreca(struct Preca tab[], int _size){
    for (int i = 0; i < _size; i++){
        printPreca(tab[i]);
    }
}


int main() {
    int n;

    printf("Number of Preca cards: ");
    scanf("%d", &n);

    srand(time(NULL));

    struct Preca tab[n];

    makePreca(tab, n);

    dumpPreca(tab, n);

    return 0;
}
