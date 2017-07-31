/*Напишите программу копирования файлов, которая предлагает пользователю ввести имя текстового файла, выступающего в роли исходного, и имя выходного файла. 
Программа должна использовать функцию toupper() из ctype.h для перевода текста в верхний регистр во время его записи в выходной файл.
Применяйте стандартный ввод-вывод и текстовый режим.*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define LEN 80

int main(void)
{
	FILE *source, *destin;
	char src[LEN];
	char des[LEN];
	char temp;
	int cnt;

	puts("Enter \"source file -> destination file\":");
	cnt = scanf("%s -> %s", src, des);
	if((source = fopen(src, "r")) == NULL)
	{
		fprintf(stderr, "Fail to open %s\r\n", src);
		exit(EXIT_FAILURE);
	}
	if((destin = fopen(des, "w")) == NULL)
	{
		fprintf(stderr, "Fail to open %s\r\n", des);
		exit(EXIT_FAILURE);
	}

	while((temp = getc(source)) != EOF)
		putc(toupper(temp), destin);
	if(ferror(source) != 0)
		fprintf(stderr, "Error in reading %s\r\n", src);
	if(ferror(destin) != 0)
		fprintf(stderr, "Error in writing %s\r\n", des);
	fclose(source);
	fclose(destin);
	printf("Done!\r\n");
	return 0;
}