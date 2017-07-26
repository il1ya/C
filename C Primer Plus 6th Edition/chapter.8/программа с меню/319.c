/*
Цели гладкости программы (гладкость при обработке как корректного, так и некорректного ввода) вступает в игру, когда вы решаете, 
каким образом реализовать указанный план. Например, одно из действий, которое вы можете предпринять - это исключить в части “получить вариант" неправильные ответы, 
чтобы оператору switch передавались только корректные варианты. Это предполагает представление процесса ввода в виде функции, 
которая возвращает только корректные ответы. В сочетании с циклом while и оператором switch получается следующая структура программы:
*/
// menuette.c --технология меню
#include <stdio.h>
char get_choice(void);
char get_first(void);
int get_int(void);
void count(void);
int main(void)
{
	int choice;
	void count(void);
	while((choice = get_choice()) != 'q')
	{
		switch(choice)
		{
			case 'a' : printf("Buy low, sell high.\r\n"); // покупайте дешево, продавайте дорого
			break;
			case 'b' : putchar('\a'); // ANSI
			break;
			case 'c' : count();
			break;
			default : printf("Program error!\r\n"); // Ошитбка
			break;
		}
	}
	return 0;
}
void count(void)
{
	int n, i;
	printf("Count how far? Enter an integer:\r\n"); // До какого предела вести подсчет? Введите целое число:
	n = get_int();
	for(i = 1; i <= n; i++)
		printf("%d\r\n", i);
	while(getchar() != '\n')
		continue;
}
char get_choice(void)
{
	int ch;
	printf("Enter the letter of your choice:\r\n"); // Введите букву, соответсвующую выбранному варианту:
	printf("a. advice 			b. bell\r\n");// a. совет b. звонок
	printf("c. count 			q. quit\r\n");// b. подсчет q. выход
	ch = get_first();
	while((ch < 'a' || ch > 'c') && ch != 'q')
	{
		printf("Please respond with a, b, c, or q.\r\n");// выберите a, b, c, or q.
		ch = get_first();
	}
	return ch;
}
char get_first(void)
{
	int ch;
	ch = getchar(); // читать слудующий символ
	while(getchar() != '\n')
		continue; // отбросить оставшуюся часть строки
	return ch;
}
int get_int(void)
{
	int input;
	char ch;
	while(scanf("%d", &input) != 1)
	{
		while ((ch = getchar()) != '\n')
			putchar(ch); // отбросить неправильный ввод
		printf(" is not an integer.\r\nPlease enter an ");
		printf("integer value, such as 25, -178, or 3: ");
	}
	return input;
}
