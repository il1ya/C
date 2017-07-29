/*Предположим, что требуется сравнить введенный кем-то ответ со строкой, хранящейся в памяти, как показано в листинге 11.20.*/
// Листинг 11.20. Программа nogo.c
// nogo.c -- будет ли это работать?
#include <stdio.h>
#define ANSWER "Grant"
#define SIZE 40
char *s_gets(char *st, int n);
int main(void)
{
	char try[SIZE];
	puts("Who is buried in Grant's tomb?"); // Кто похоронен в могиле Гранта?
	s_gets(try, SIZE);
	while(try != ANSWER)
	{
		puts("No, that's wrog. Try again."); // Неправильно! Попытайтесь еще раз
		s_gets(try, SIZE);
	}
	puts("That's right!"); // Теперь правильно!
	return 0;
}
char *s_gets(char *st, int n)
{
	char *ret_val;
	int i = 0;
	ret_val = fgets(st, n, stdin);
	if(ret_val)
	{
		while(st[i] != '\n' && st[i] != '\0')
			i++;
		if(st[i] == '\n')
			st[i] == '\0';
		else // требуется наличие words[i] == '\0'
			while(getchar() != '\n')
				continue;
	}
	return ret_val;
}
/*Как бы симпатично не выглядела эта программа, работает она некорректно. В действительности ANSWER и try являются указателями, так что сравнение 
try ! = ANSWER не проверяет, совпадают ли две строки. Вместо этого оно проверяет, имеют ли указанные две строки один и тот же адрес. 
Поскольку ANSWER и try хранятся в разных ячейках памяти, их адреса никогда не будут совпадать, и пользователь каждый раз получает сообщение о том, что введенный им ответ неправилен. 
Такие программы часто сбивают польаователей с толку.*/