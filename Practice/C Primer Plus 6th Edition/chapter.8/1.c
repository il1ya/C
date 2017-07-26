#include <stdio.h>
int main(void)
{
	char name;
	printf("Welcome sir!\r\nEnter your name:\r\n");
	scanf("%s", &name);
	switch(name)
	{
		case 'i':
		printf("Ohh sir welcom back!");
		break;
		case 'a':
		printf("WHY ARE YOU");
		break;
		default:
		printf("I do not expect you");
		break;
	}
	return 0;
}