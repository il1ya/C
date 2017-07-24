// ch06ex16.c

/* Daphne invests $100 at 10% simple interest. (That is, every year, the investment earns an interest equal to 10% of the original investment.) Deirdre invests $100 at 5% interest compounded annually. (That is, interest is 5% of the current balance, including previous addition of interest.) Write a program that finds how many years it takes for the value of Deirdre's investment to exceed the value of Daphne's investment. Also show the two values at the same time. */

#include <stdio.h>

int main(void)
{
    float initDaphne = 100, initDeirdre = 100;
    float rateDaphne = 0.1, rateDeirdre = 0.05;
    float sumDaphne = initDaphne, sumDeirdre = initDeirdre;

    int year = 0;
    
    while (sumDaphne >= sumDeirdre)
    {
        sumDaphne = sumDaphne + initDaphne * rateDaphne;
        sumDeirdre = sumDeirdre + sumDaphne * rateDeirdre;
        year++;
    }

    printf("Deirdre's investment will exceed Daphne's after %d years.", year);

    getch();
    return 0;
}