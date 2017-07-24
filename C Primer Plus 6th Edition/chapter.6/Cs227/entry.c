/*
Эквивалентная программа do_while.c, в которой применяется цикл while, была бы несколько длиннее, как можно видеть в листинге entry.c.
*/
// цикл с предусловием
#include <stdio.h>
int main (void)
{
	const int secret_code = 13;
	int code_entered;
	printf("To enter the triskaidekaphobia therapy club,\r\n");
	printf("please enter the secret code number: ");
	scanf("%d", &code_entered);
	while (code_entered != secret_code)
	{
		printf("To enter the triskaidekaphobia therapy club,\r\n");
		printf("please enter the secret code number: ");
		scanf("%d", &code_entered);
	}
	printf("Congratulations!You are cured!\r\n");
	return 0;
}