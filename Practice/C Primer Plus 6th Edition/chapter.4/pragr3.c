#include <stdio.h>
int main (void)
{
	char name[10];
	printf("Enter your name ");
	scanf("%s", name);
	printf("Welcom back %s Nice to see you again %s", name, name);
	return 0;
}