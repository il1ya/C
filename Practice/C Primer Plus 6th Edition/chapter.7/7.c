// ch07ex07.c

/* Write a program that requests the hours worked in a week & then prints the gross pay, the taxes, & the net pay. Assume the following:
a. Basic pay rate = $10.00/hr
b. Overtime (in excess of 40 hours) = time & a half
c. Tax rate: 15% of the first $300, 20% of the next $150, 25% of the rest
Use #define constants, & don't worry if the example does not conform to current tax law. */

#include <stdio.h>

#define RATE_HOUR 10
#define OVER_TIME 40
#define RATE_OVER 1.5
#define AMOUNT_01 300
#define AMOUNT_02 150
#define TAX_RATE1 0.15
#define TAX_RATE2 0.20
#define TAX_RATE3 0.25

int main(void)
{
	double gross, hours, net, taxes;
	
	printf("Enter the number of hours worked this week: ");
	scanf("%lf", &hours);
	
	if (hours <= OVER_TIME)
	{
		gross = hours * RATE_HOUR;
	}
	else
	{
		gross = OVER_TIME * RATE_HOUR + (hours - OVER_TIME) * RATE_HOUR * RATE_OVER;
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