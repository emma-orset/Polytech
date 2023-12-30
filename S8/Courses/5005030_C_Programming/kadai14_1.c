#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    int year;
    int month;
    int day;
}Date;

typedef struct {
    int id;
    int amount;
    Date date;
    int code;

}Preca;

int randNumber(){
    return (rand() % 9999) + 1;
}

void initPreca(Preca * _p ){
    _p->id = 1;
    _p->amount = 1000;
    _p->date.day = 31;
    _p->date.month = 3;
    _p->date.year = 2025;
    _p->code = randNumber();
}


void printPreca(Preca _p){
    printf("#%d: %d, %04d/%02d/%02d, %04d\n", _p.id,_p.amount, _p.date.year, _p.date.month, _p.date.day, _p.code);
}

int main() {
    srand(time(NULL));

    Preca c1;
    initPreca(&c1);
    printPreca(c1);
    return 0;
}

