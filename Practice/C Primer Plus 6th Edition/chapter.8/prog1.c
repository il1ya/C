/*
Напишите программу, которая подсчитывает количество символов во входных данных до достижения конца файла.
*/
#include <stdio.h>
// #include <ctype.h> // для isspace() подсчета пробельных символов
int main(void)
{
	char ch;
	int n_chars = 0;
	while((ch = getchar()) != '#' && ch != EOF)
	{
		n_chars++; // считать символы
	}
	printf("characters = %d", n_chars);
	return 0;
}