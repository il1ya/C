/*Напишите программу, которая принимает в качестве аргументов командной строки символ и ноль или более имен файлов. 
Если за символом не следуют аргументы, программа должна читать стандартный ввод. 
В противном случае она должна открывать каждый файл по очереди и сообщать, сколько раз в нем ветречается указанный символ. 
Вместе с результатом каждого подсчета должны быть указаны имя файла и сам символ. 
Предусмотрите средства проверки ошибок, позволяющие выяснить корректность количества аргументов и возможность открытия файлов. 
Если файл не может быть открыт, программа должна сообщать об этом факте и переходить к обработке следующего файла.*/

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	int cnt = 0;
	char ch;
	FILE *temp;

	if(argc < 2)
	{
		fprintf(stderr, "Usage: %s character filename [filename2...]\r\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	else if(argc == 2)
	{
		fprintf(stdout, "Please enter a string:\r\n");
		while((ch = getc(stdin)) != EOF)
		{
			if(ch == *argv[1])
				cnt++;
		}
		fprintf(stdout, "In your input: %c appeared %d times.\r\n", *argv[1], cnt);
	}
	else
	{
		for(int i = 2; i < argc; i++)
		{
			if((temp = fopen(argv[i], "r")) == NULL)
			{
				fprintf(stderr, "Fail to open file %s.\r\n", argv[i]);
				continue;
			}
			while((ch = getc(temp)) != EOF)
			{
				if(ch == *argv[1])
					cnt++;
			}
			fprintf(stdout, "character %c appeared %d times in file %s\r\n", *argv[1], cnt, argv[i]);
			fclose(temp);
			cnt = 0;
		}
	}
	return 0;
}