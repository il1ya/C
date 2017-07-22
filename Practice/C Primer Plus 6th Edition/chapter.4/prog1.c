#include <stdio.h> // напишите программу, которая запрашивает имя и фамилию, а затем выводит их в формате фамилия, имя.
int main (void)
{
	char name[10];
	char lastname[10];
	printf("Please enter your first and last name\r\n");
	scanf("%s %s", name, lastname);
	printf("Welcom back %s %s", lastname, name);
	return 0;

}