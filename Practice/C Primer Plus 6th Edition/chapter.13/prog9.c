/*Модифицируйте программу в листинге 13.3, чтобы каждое слово было пронумеровано в соответствии с порядком его добавления в список, начиная с 1.
Позаботьтесь о том, чтобы при втором запуске программы новая нумерация слов начиналась с того места, где была закончена нумерация при предыдущем запуске.*/
#include <stdio.h>
#include <stdlib.h>

#define MAX 40

int main(void)
{
	FILE *fp;
	char words[MAX];
	int num = 0;

	if((fp = fopen("words", "a+")) == NULL)
	{
		fprintf(stdout, "Can't open \"words\" file.\r\n");
		exit(1);
	}
	while(fgets(words, MAX - 1, fp) != NULL)
		num++;
	puts("Enter words to add to the file: press the Enter");
	puts("key at the beginning of line to terminate.");

	while(gets(words) != NULL && words[0] != '\0')
		fprintf(fp, "%d -> %s\r\n", num, words);

	puts("File contents: ");
	rewind(fp);

	while(fgets(words, MAX, fp) != NULL)
		puts(words);

	if(fclose(fp) != 0)
		fprintf(stderr, "Error closing file\r\n");

	return 0;
}