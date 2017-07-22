#include <stdio.h>
#define  PRAISE "You are an outstanding personality!"
int main (void)
{
	char name[40];
	printf("What is your name ");
	scanf("%s", name);
	printf("Hello %s. %s\r\n", name, PRAISE);
	return 0;
}