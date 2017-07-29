/*Напишите функцию string_in(), которая принимает в качестве аргументов два указателя на строки. 
Если вторая строка содержится внутри первой, функция должна возвратить адрес, с которого начинается вторая строка в первой строке.
Например, вызов string_in("данные", "ан") возвратит адрес символа а в строке данные. 
В противном случае функция должна возвратить нулевой указатель.
Протестируйте функцию в завершенной программе, которая использует цикл для передачи входных значений созданной функции.*/
#include <stdio.h>
#include <string.h>
#define SIZE 81
char *string_in(char *ptr1, char *ptr2);
int main(void)
{
	char s1[SIZE];
	char s2[SIZE];
	char *ps;
	do{
		puts("Input s1: (enter 'q to quit)");
		gets(s1);
		puts("Input s2:");
		gets(s2);
		// ps = strstr(s1, s2); Just the same effect as this function
		ps = string_in(s1, s2);
		if(ps)
			printf("s1: %p s2 found in s1: %p\r\n", s1, ps);
		else
			puts("s2 not contained in s1.");
	}while (*s1 != 'q');
	puts("Bye!");
	return 0;
}
char *string_in(char *ptr1, char *ptr2)
{
	int i, j;
	char *res;

	for(i = 0; i < strlen(ptr1) && (*(ptr1 + i) != *ptr2); i++)
		continue;

	for(j = 0; j < strlen(ptr2); j++)
	{
		if((*(ptr1 + i + j) != *(ptr2 + j)) || (*(ptr1 + i + j) == '\0'))
		{
			puts("if");
			res = NULL;
		}
		else
		{
			puts("else");
			res = ptr1 + i;
		}
	}
	return res;
}