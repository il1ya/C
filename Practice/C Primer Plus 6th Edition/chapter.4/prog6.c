/* Напишите программу, которая запрашивает имя пользователя и его фамилию. Сделайте так, чтобы она выводила введенные имена в одной строке и
количество символов в каждом слове в следующей строке. Выровняйте каждое количество символов по окончанию соотвествующего имени */
#include <stdio.h>
#include <string.h>
#define WEL "Welcom back"
int main (void)
{
	char name[10];
	char secondname[10];
	printf("%s, Enter ur name and second name", WEL);
	scanf("%s %s", name, secondname);
	printf("%s,\r\n%s %s\r\n", WEL, name, secondname);
	printf("%d %5d\r\n", strlen(name), strlen(secondname));
	printf("%5d %9d", strlen(name), strlen(secondname));
	return 0;
}
