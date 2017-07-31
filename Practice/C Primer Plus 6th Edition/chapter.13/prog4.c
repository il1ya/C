/*Напишите программу, которая последовательно отображает на экране содержимое всех файлов, перечисленных в командной строке. 
Для управления циклом используйте argc.*/
#include <stdio.h>
#include <stdlib.h>

#define LEN 256

int main(int argc, char *argv[])
{
	FILE *fp;
	char temp[LEN];
	int i;
	if(argc < 2)
	{
		fprintf(stderr, "Usage: %s filename.\r\n", argv[0]);
		exit(1);
	}

	for(i = 1; i < argc; i++)
	{
		if((fp = fopen(argv[i], "r")) == NULL)
		{
			fprintf(stderr, "Can't open file %s.\r\n", argv[i]);
			exit(1);
		}
		while(fgets(temp, LEN, fp) != NULL)
			fputs(temp, stdout);
		fclose(fp);
	}
	putchar('\n');
	printf("%d file printed.\r\n", i);
	return 0;
}