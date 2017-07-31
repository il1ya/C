/*1. Модифицируйте программу в листинге 13.1, чтобы она предлагала пользователю ввести имя файла и читала его ответ вместе использования аргументов командной строки.*/
#include <stdio.h>
#include <stdlib.h> // прототип exit()
int main()
{
	char name[25];
	char surname[25];
	puts("Enter your a name");
	scanf("%s", name);
	printf("%s enter your surname\r\n", name);
	scanf("%s", surname);
	printf("%s %s", name, surname);
	return 0;
}