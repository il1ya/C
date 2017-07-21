/*Функция sprintf() объявлена в заголовочном файле stdio.h, а не в string.h.
Она работает подобно printf(), но осуществляет запись в строку, а не на дисплей.
Таким образом, она предоставляет способ объединения нескольких элементов в единую строку. Первый аргумент sprintf() — это адрес целевой строки. 
Остальные аргументы аналогичны аргументам в printf() — строка спецификации преобразования и список элементов, предназначенных для записи.
В листинге 11.28 функция sprintf() применяется для объединения трех элементов (двух строк и числа) в одну строку. 
Обратите внимание, что sprintf() используется так же, как это бы делалось в случае функции 
printf(), кроме того, что результирующая строка сохраняется в массиве formal, а не отображается на экране.*/
// Листинг 11.28. Программа format.c
// format.c -- форматирование строки
#include <stdio.h>
#define MAX 20
char *s_gets(char *st, int n);
int main(void)
{
	char first[MAX];
	char last[MAX];
	char formal[2 * MAX + 10];
	double prize;
	puts("Enter your first name:");
	s_gets(first, MAX);
	puts("Enter your last name:");
	s_gets(last, MAX);
	puts("Enter your prize money:");
	scanf("%lf", &prize);
	sprintf(formal, "%s, %-19s: $%6.2f\r\n", last, first, prize);
	puts(formal);
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
/*Функция sprintf() принимает входные данные и форматирует его в стандартном виде, после чего сохраняет в строку formal.*/