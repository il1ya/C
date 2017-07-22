/* напишите программу, которая запрашивает рост в дюймах и имя, после чего отображает полученную информацию в следующей форме
используйте тип float, а также операцию деления /. Если хотите, можете запрашивать рост в сантиметрах и отображать его в метрах */
#include <stdio.h>
#define M 100
int main (void)
{
	float height;
	char name[10];
	float division;
	printf("Please, enter your height and your name\r\n");
	scanf("%f %s", &height, name);
	division = height / M;
	printf("Welcome! %s, your growth is m %.2f centimeters\r\n", name, division);
	return 0;
}