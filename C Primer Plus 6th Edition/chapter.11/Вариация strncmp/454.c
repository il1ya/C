/*Функция strcmp() сравнивает строки до тех пор, пока не найдет пару соответствующих символов, которые отличаются друг от друга, 
и этот поиск может продолжаться вплоть до достижения конца одной из строк. 
Функция strcmp() сравнивает строки до тех пор, пока не обнаружит в них различия либо пока не сравнит количество символов в обеих строках, указанное в третьем аргументе. 
Например, если необходимо найти строки, начинающиеся с "астро", то поиск можно было бы ограничить первыми пятью символами. 
В листинге 11.24 показано, как это сделать.*/
// Листинг 11.24. Программа starsrch.c
// starsrch.c -- использование функции strncmp()
#include <stdio.h>
#include <string.h>
#define LISTSIZE 6
int main(void)
{
	const char *list[LISTSIZE] = 
	{ 
	"astronomy", "astounding",
	"astrophysics", "ostracize",
	"asterism", "astrophobia"
	};
	int count = 0;
	int i;
	for(i = 0; i < LISTSIZE; i++)
		if(strncmp(list[i], "astro", 5) == 0)
		{
			printf("Found: %s\r\n", list[i]);
			count++;
		}
		printf("The list contained %d words beginning" // Количество слов в списке, начинающихся с астро
			" with astro.\r\n", count);
		return 0;
}