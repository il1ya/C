#include <stdio.h>
#define STOP 2
int main(void)
{
	char name1;
	printf("Enter ur name(Enter # to exist)\r\n");
	while((scanf("%s", &name1)) != STOP)
	{
		const char name2 = 'i';
		if(name1 == name2)
		printf("stop play and lear more C");
		else
		printf("Welcom back %s", name1);
	}
	printf("Bye bye");
	return 0;
}