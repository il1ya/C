/*Напишите программу, которая ведет себя подобно модификации листинга 12.13, которая обсуждалась после представления вывода из программы, показанной в листинге 12.13. 
То есть программа должна давать вывод следующего вида:

Введите количество бросаний или q для завершения: 18
Сколько граней и сколько костей? 63
Имеем 18 бросаний 3 костей с 6 гранями.
12 10 6 9 8 14 8 15 9 14 12 17 11 7 10 13 8 14
Введите количество бросаний или q для завершения: q**/
#include <stdio.h>
#include <stdlib.h>
int rollem(int sides);
int roll_n_dice(int dice, int sides);

int main(void)
{
	int sets, sides, dice;
	puts("Enter the number of sets; enter q to quit.");
	while(scanf("%d", &sets) == 1)
	{
		puts("How may sides and how many dice?");
		scanf("%d %d", &sides, &dice);
		printf("Here are %d sets of %d %d-sided throws.\r\n", sets, dice, sides);

		for(int i = 0; i < sets; i++)
			printf("%3d", roll_n_dice(dice, sides));
	}
	return 0;
}
int rollem(int sides)
{
	int roll;
	roll = rand() % sides + 1;
	return roll;
}
int roll_n_dice(int dice, int sides)
{
	int d;
	int total = 0;
	if(sides < 2)
	{
		printf("Need at least 2 sides.\r\n");
		return -2;
	}
	if(dice < 1)
	{
		printf("Need at least 1 dice.\r\n");
		return -1;
	}
	for(d = 0; d < dice; d++)
		total += rollem(sides);
	return total;
}