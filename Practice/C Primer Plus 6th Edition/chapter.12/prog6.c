/*Напишите программу, которая генерирует 1000 случайных чисел в диапазоне от 1 до 10. 
Не сохраняйте и не выводите эти числа, а выводите лишь то, сколько раз генерировалось каждое число. 
Программа должа делать это для 10 разных начальныхи значений. 
Появляются ли числа в одинаковых количествах? 
Можете использовать функции из этой главы или функции rand() и srand() из ANSI С, которые следуют тому же формату, что и рассмотренные здесь. 
Это один из способов исследования недетерминированности конкретного генератора случайных чисел.*/
#include <stdio.h>
#include <stdlib.h>
void count(int *p);
int main(void)
{
	int nums[1000];
	int seed;
	puts("Please enter a integer value as seed, 'q' to quit");
	while(scanf("%d", &seed) == 1)
	{
		srand(seed);
		for(int i =0; i < 1000; i++)
			nums[i] = rand() % 10 + 1;
		count(nums);
		for(int j = 1; j <= 1000; j++)
		{
			if(j % 10 == 0)
				printf("last%3d\r\n", nums[j]);
			else
				printf("%3d", nums[j]);
		}
		printf("\n");
		puts("please choose another int seed, 'q' to quit.");
	}
	return 0;
}
void count(int *p)
{
	int i;
	int ten = 0;    int one = 0;
	int two = 0;	int three = 0;
	int four = 0;	int five = 0;
	int six = 0;	int seven = 0;
	int eight = 0;	int nine = 0;
	for(i = 0; i < 100; i++)
	{
		switch(p[i])
		{
			case 10: ++ten; 	break;		case 1: ++one; 		break;
			case 2: ++two; 		break;		case 3: ++three;	break;
			case 4: ++four; 	break;		case 5: ++five;		break;
			case 6: ++six; 		break;		case 7: ++seven;	break;
			case 8: ++eight; 	break;		case 9: ++nine;		break;
			default: printf("\nwrong\r\n");
		}
	}
	printf("10 -> %d\r\n1 -> %d\r\n2 -> %d\r\n3 -> %d\r\n4 -> %d\r\n5 -> %d\r\n6 -> %d\r\n7 -> %d\r\n8 -> %d\r\n9 -> %d\r\n",
		ten, one, two, three, four, five, six, seven, eight, nine);
}