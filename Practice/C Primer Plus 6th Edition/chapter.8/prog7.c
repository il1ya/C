/*
Модифицируйте упражнение по программированию 8 из главы 7 так, чтобы пункты меню помечались буквами, а не цифрами; 
для прекращения ввода используйте букву q вместо цифры 5.
*/ 
#include <stdio.h>
#define OVER_TIME 40
#define RATE_OVER 1.5
#define AMOUNT_01 300
#define AMOUNT_02 150
#define TAX_RATE1 0.15
#define TAX_RATE2 0.20
#define TAX_RATE3 0.25
float SetPay(int);
int main(void)
{
	char option;
	float gross, hours, net, rate, taxes;
	printf("Enter the number corresponding to the desired pay rate or action.\n");
	printf("a) $8.75/hr\t b) $9.33/hr\t c) $10.00/hr\t d) $11.20/hr\t q) quit\n");
	scanf("%c", &option);
	if (SetPay(option)) 
		{
		rate = SetPay(option);
    	} 
		else 
		{
        return 0;
    }
	
	printf("Enter the number of hours worked this week: ");
	scanf("%lf", &hours);
	
	if (hours <= OVER_TIME)
	{
		gross = hours * rate;
	}
	else
	{
		gross = OVER_TIME * rate + (hours - OVER_TIME) * rate * RATE_OVER;
	}
	if (gross <= AMOUNT_01)
	{
		taxes = gross * TAX_RATE1;
	}
	else if (gross <= AMOUNT_01 + AMOUNT_02)
	{
		taxes = AMOUNT_01 * TAX_RATE1 + (gross - AMOUNT_01) * TAX_RATE2;
	}
	else
	{
		 taxes = AMOUNT_01 * TAX_RATE1 + AMOUNT_02 * TAX_RATE2 + (gross - AMOUNT_01 - AMOUNT_02) * TAX_RATE3;
	}
	net = gross - taxes;
 	printf("gross: $%.2f; taxes: $%.2f; net: $%.2f\n", gross, taxes, net);
	
	getch();
	return 0;
}

float SetPay(int option)
{
	switch(option)
	{
		case 'a':
			return 8.75;
		case 'b':
			return 9.33;
		case 'c':
			return 10.00;
		case 'd':
			return 11.20;
		case 'q':
			return 0;
		default:
			printf("You must enter 1 through 5.\n");
			printf("Enter the number corresponding to the desired pay rate or action.\n");
			printf("a) $8.75/hr\t b) $9.33/hr\t c) $10.00/hr\t d) $11.20/hr\t q) quit\n");
			scanf("%d", &option);
			break;
	}
}