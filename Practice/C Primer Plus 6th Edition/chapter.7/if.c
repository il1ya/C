#include <stdio.h>
int main(void)
{
	int number;
	printf("Enter your turn\r\n");
	scanf("%d", &number);
	if (number > 6)
	{
		if (number < 12)
			printf("You're close!\r\n");
	}
	else
		printf("Sorry, you lose a turn!\r\n");
	return 0;
}