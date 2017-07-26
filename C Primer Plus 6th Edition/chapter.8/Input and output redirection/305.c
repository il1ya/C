/*
Если перенаправление не работает, можете попытаться заставить программу открыть файл напрямую. В листинге 8.3 показан пример с минимальными пояснениями.
*/
//file_eof.c -- открывает файл и отображает его содержимое

#include <stdio.h>
#include <stdlib.h> // для функии exit()
int main(void)
{
	int ch;
	FILE * fp;
	char fname[50]; // для хранения имени файла
	printf("Enter the name of the file: ");
	scanf("%s", fname);
	fp = fopen(fname, "r"); // открыть файл для чтения
	if(fp == NULL) // попытка завершилась неудачей
	{
		printf("Failed to open file. Bye\r\n");
		exit(1); // выйти из программы
	}
	// функция getc(fp) получает символ из открытого файла
	while((ch = getc(fp)) != EOF)
		putchar(ch);
	fclose(fp); // закрыть файл
	return 0;
}
