#include <stdio.h>
int main (void)
{
	char name[1];
	printf("Enter your name:\r\n");
	scanf("%s", name);
	printf("Hello %s", name);
	return 0;
}