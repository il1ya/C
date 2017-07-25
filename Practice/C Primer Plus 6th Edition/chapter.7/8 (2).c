//ch07ex08.c

/* Modify assumption a. in exercise 7 so that the program presents a menu of pay rates from which to choose. Use a switch to select the pay rate. The beginning of a run should look something like this:
Enter the number corresponding to the desired pay rate or action:
1) $8.75/hr
2) $9.33/hr
3) $10.00/hr
4) $11.20/hr
5) quit 
If choices 1 through 4 are selected, the program should request the hours worked. The program should recycle until 5 is entered. If something other than choices 1 through 5 is entered, the program should remind the user what the proper choices are & then recycle. Use #defined constants for the various earning rates & tax rates. */

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
	int option;
	float gross, hours, net, rate, taxes;
	
	printf("Enter the number corresponding to the desired pay rate or action.\n");
	printf("1) $8.75/hr\t 2) $9.33/hr\t 3) $10.00/hr\t 4) $11.20/hr\t 5) quit\n");
	
	scanf("%d", &option);
	
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
		case 1:
			return 8.75;
		case 2:
			return 9.33;
		case 3:
			return 10.00;
		case 4:
			return 11.20;
		case 5:
			return 0;
		default:
			printf("You must enter 1 through 5.\n");
			printf("Enter the number corresponding to the desired pay rate or action.\n");
			printf("1) $8.75/hr\t 2) $9.33/hr\t 3) $10.00/hr\t 4) $11.20/hr\t 5) quit\n");
			scanf("%d", &option);
			break;
	}
}