/*Программы, работающие с аргументами командной строки, полагаются на то, что пользователь помнит, как их правильно запускать. 
Перепишите программу из листинга 13.2 так, чтобы вместо использования аргументов командной строки она предлагала пользователю ввести необходимую информацию.*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LEN 40

int main(void)
{
	FILE *in, *out;
	int ch;
	char name[LEN];
	char source[LEN];
	int count = 0;

	puts("Enter file name: ");
	gets(source);
	if((in = fopen(source, "r")) == NULL)
	{
		fprintf(stderr, "I couldn't open the file\"%s\"\r\n", source);
		exit(2);
	}
	strcpy(name, source);
	strcat(name, ".red");
	if((out = fopen(name, "w")) == NULL)
	{
		fprintf(stderr, "Can't create output file.\r\n");
		exit(3);
	}
	while((ch = getc(in)) != EOF)
		if(count++ % 3 == 0)
			putc(ch, out);
	if(fclose(in) != 0 || fclose(out) != 0)
		fprintf(stderr, "Error in closing files\r\n");
	return 0;
}