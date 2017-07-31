/*
7. Напишите программу, которая открывает два файла. Получать имена файлов можно либо через командную строку, либо предложив пользователю ввести их.
а. Сделайте так, чтобы эта программа выводила строку 1 первого файла, строку 1 второго файла, строку 2 первого файла, строку 2 второго файла и т.д., 
пока не будет выведена последняя строка более длинного (по количеству строк) файла.
б. Модифицируйте программу так, чтобы строки с одним и тем ж е номером вы водились в одной экранной строке.
*/
#include <stdio.h>
#include <stdlib.h>

#define LEN 80
#define BUF 1024

int main(void)
{
	FILE *fp1, *fp2;
	char *E1, *E2;
	char file1[LEN];
	char file2[LEN];
	char temp1[BUF];
	char temp2[BUF];

	puts("Enter the two files' name:('0 0' to quit)");
	while(scanf("%s %s", file1, file2) == 2)
	{
		if((fp1 = fopen(file1, "r")) == NULL || (fp2 = fopen(file2, "r")) == NULL)
		{
			printf("Reading file %s or %s failed.\r\n", file1, file2);
			exit(EXIT_FAILURE);
		}

		E1 = fgets(temp1, BUF, fp1);
		E2 = fgets(temp2, BUF, fp2);

		while(E1 != NULL || E2 != NULL)
		{
			if(E1 != NULL)
				fputs(temp1, stdout);
			if(E2 != NULL)
				fputs(temp2, stdout);

			E1 = fgets(temp1, BUF, fp1);
			E2 = fgets(temp2, BUF, fp2);
			// printf("E2: %p fp2: %p\r\n", E2, fp2);
		}
		putchar('\n');
		if(fclose(fp1) != 0 || fclose(fp2) != 0)
			printf("Error in closing file %s or %s.\r\n", file1, file2);
		puts("Enter another pair or files: ('0 0' to quit)");
	}
	printf("Successfully done.\r\n");
	return 0;
}