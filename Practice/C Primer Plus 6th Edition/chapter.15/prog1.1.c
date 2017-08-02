/*1. 
Напишите функцию, которая преобразует строку с двоичным представлением в числовое значение. 
Другими словами, если есть char *pbin = "01001001";
то переменную pЬin можно передать этой функции в качестве аргумента, и функция должна возвратить значение 25 типа int.*/
#include <stdio.h>
int bstoi(char *pbin);
int main(void)
{
	char *pbin = "01001001";
	printf("%s is %d\r\n", pbin, bstoi(pbin));
	return 0;
}
int bstoi(char *pbin)
{
	int dec = 0;
	while(*pbin != '\0')
		dec = (dec << 1) + *pbin++ - '0';
	return dec;
}