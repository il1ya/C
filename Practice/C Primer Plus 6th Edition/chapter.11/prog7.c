/*7. Функция strncpy( sl, s2, n) копирует в точности n символов из строки s2 в строку sl, при необходимости усекая s2 или дополняя ее нулевыми символами.
Целевая строка может не содержать завершающего нулевого символа, если длина строки s2 равна или больше n. 
Функция возвращает строку sl. Напишите свою версию этой функции и назовите ее mystrncpy(). 
Протестируйте функцию в завершенной программе, которая использует цикл для передачи входных значений созданной функции.*/
#include <stdio.h>
#include <string.h>
#define SIZE 81
char *mystrncpy(char *target, char *sourse, int n);
int main(void)
{
	char s1[SIZE];
	char s2[SIZE];
	int n;
	for(; puts("Input s1"), gets(s1), *s1 != 'q';)
	{
		puts("Input n");
		scanf("%d", &n);
		getchar(); // to clean the '\n' after entering number n
		mystrncpy(s2, s1, n);
		printf("s1: %s\r\n", s1);
		printf("s2: %s\r\n", s2);
		continue;
	}
	puts("End of program!");
	return 0;
}
char *mystrncpy(char *target, char *sourse, int n)
{
	int len = strlen(sourse);
	int i;
	len = (n > SIZE)? SIZE: n;
	for(i = 0; i < len; i++)
		*(target + i) = *(sourse + i);
	*(target + i) = '\0';
	return target;
}