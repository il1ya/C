/*В листинге 11.23 функция strcmp() используется для выяснения, когда программа должна остановить чтение ввода.*/
// Листинг 11.23. Программа quit_chk.c
// quit_chk.c -- начало некоторой программы
#include <stdio.h>
#include <string.h>
#define SIZE 80
#define LIM 10
#define STOP "quit"
char *s_gets(char *st, int n);
int main(void)
{
	char input[LIM][SIZE];
	int ct = 0;
	printf("Enter up to %d lines (type quit to quit):\r\n", LIM);
	while(ct < LIM && s_gets(input[ct], SIZE) != NULL && strcmp(input[ct], STOP) != 0)
	{
		ct++;
	}
	printf("%d strings entered\r\n", ct);
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
/*Программа завершает чтение входных данных, когда встречает символ EOF (в этом случае s_gets() возвращает NULL), при вводе слова quit или по достижении предела, указанного в LIM.
Кстати, чтение входных данных иногда удобнее прекращать путем ввода пустой строки, т.е. нажатием клавиши <Enter> или <Return>, не набирая ничего другого.
Для этого оператор цикла while можно модифицировать так:
while (ct < LIM && s_gets(input[ct], SIZE) != NULL && input[ct][O] != '\0')
Здесь input[ct] представляет собой только что введенную строку, а input[ct][0] — первый символ этой строки. 
Если пользователь вводит пустую строку, то функция s_gets() помещает в первый элемент нулевой символ, так что выражение input[ct][0] != '\0'
выполняет проверку на предмет пустой входной строки.*/