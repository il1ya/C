/*Напишите программу, открывающую текстовый файл, имя которого получается интерактивно. 
Организуйте цикл, который предлагает пользователю ввести позицию файле. Затем программа должна вывести часть файла, начиная с этой
позиции и заканчивая следующим символом новой строки. 
Цикл ввода должен завершаться при вводе отрицательного дли нечислового значения.*/

#include <stdio.h>
#include <stdlib.h>

#define LEN 80

int main(void)
{
	FILE *fptr;
	char name[LEN];
	char ch;
	long pos;
	puts("Enter a file name:");
	gets(name);
	if((fptr = fopen(name, "r")) == NULL)
	{
		fprintf(stderr, "Fail to read file %s.\r\n", name);
		exit(EXIT_FAILURE);
	}
	puts("Enter an long number as an starting position:");
	while(scanf("%ld", &pos) == 1)
	{
		if(fseek(fptr, pos, SEEK_SET) != 0)
		{
			fprintf(stderr, "Moving out of boundry.\r\n");
			break;
		}
		for(int i = 0; (ch = getc(fptr)) != EOF; i++)
			putchar(ch);

		rewind(fptr);
		putchar('\n');
		puts("Enter another long number, non numeric input to quit:");
	}
	puts("Bye!");
	return 0;
}