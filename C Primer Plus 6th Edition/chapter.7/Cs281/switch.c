#include <stdio.h>
int main(void)
{
	int choice;
	printf("Enter:\r\n");
	while((scanf("%d", &choice)) == 1)
	{
		switch(choice)
		{
			case 1 :
			case 2 : printf("Darn tootin!\r\n"); break;
			case 3 : printf("Quite right!\r\n");
			case 4 : printf("Good show!\r\n"); break;
			default : printf("Have a nice day.\r\n");
		}
	}
	return 0;
}