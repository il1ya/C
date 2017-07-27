/* Напишите функцию по имени chline (ch, i, j), которая выводит требуемый символ в столбцах с i по j. 
Протестируйте эту функцию с помощью простого драйвера. */
#include <stdio.h>
int main(void)
{
	char ch;
	int i, j;
	printf("Enter your character: (# to exit)");
	while((ch = getchar()) != '#')
	while(scanf("%d %d", &i, &j))
	return 0;
}

/*
#include <stdio.h>
#define CH 'ch'
#define I 'i'
#define J 'j'
void chline(char, char);
int main(void)
{
	for(char a = 'i'; a <= J; a++)
	{
		
		printf("%c\r\n", a);
	}
	chline(I, J);
	return 0;
}

void chline(char i, char j)
{
	char a;
	for(a = I; a < J; a++)
}
*/