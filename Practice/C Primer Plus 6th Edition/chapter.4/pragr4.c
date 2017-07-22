#include <stdio.h>
int main (void)
{
	char name[10];
	int b;
	printf("Enter name and Enter number\r\n");
	scanf("%s %d", name, &b);
	printf("Good %s, ur number %d", name, b);
	return 0;
}