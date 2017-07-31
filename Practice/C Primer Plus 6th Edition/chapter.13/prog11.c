/*
Напишите программу, которая принимает два аргумента командной строки.
Первый аргумент - это строка, а второй - имя файла. 
Программа должна искать в файле и выводить все строки, содержащие указанную. 
Поскольку задача ориентирована на строки, а не на символы, используйте функцию fgets() вместо getc(). 
Для поиска строки, содержащей заданную, применяйте функцию strstr() (кратко описанную в упражнении 7 из главы 11) из стандартной библиотеки С.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 201

int main(int argc, char *argv[])
{
	char line[MAX];
	FILE *temp;

	if(argc <= 2)
	{
		fprintf(stderr, "Usage: %s character filename\r\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	else
	{
		if((temp = fopen(argv[2], "r")) == NULL)
		{
			fprintf(stderr, "Fail to open file %s.\r\n", argv[2]);
			exit(EXIT_FAILURE);
		}

		while(fgets(line, MAX, temp) != NULL)
			if(strstr(line, argv[1]) != NULL)
				fputs(line, stdout);
			fclose(temp);
	}
	return 0;
}