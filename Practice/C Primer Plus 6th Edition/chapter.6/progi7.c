#include <stdio.h>
#include <string.h>
int main(void)
{
	const int SIZE = 25;
	char name, world[SIZE];
	int sizel = sizeof world;
	int stri = strlen(world);
	printf("Enter your world ");
	scanf("%s", world);
	for(name = stri; name >= 0; name--)
	{
		printf("%c", world[name]);
	}
	return 0;
}