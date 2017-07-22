#include <stdio.h>
int main (void)
{
	int age;
	char name[50];
	printf("Enter your name. ");
	scanf("%s", name);
	printf("Good, %s, and how old are you?", name);
	scanf("%d", &age);
	printf("Really, %s! You must be at least, %d\r\n", name, age);
	return 0;
}