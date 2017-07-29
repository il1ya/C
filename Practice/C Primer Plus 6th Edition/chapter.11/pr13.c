/*13. Перепишите программу из листинга 11.21, используя функции из ctype.h для того, чтобы программа распознавала правильный ответ независимо от применения
пользователем прописных или строчных букв.*/
#include <stdio.h>
#include <ctype.h>
#include <string.h> // объявление strcmp()
#define ANSWER "Grant"
#define SIZE 40
char *s_gets(char *st, int n);
void ToUpper(char *str);
int main(void)
{
	char try[SIZE];
	puts("Who is buried in Grant's tomb?"); // Кто похоронен в могиле Гранта?
	s_gets(try, SIZE);
	ToUpper(try);
	while(strcmp(try, ANSWER) != 0)
	{
		puts("No, that's wrog. Try again."); // Неправильно! Попытайтесь еще раз
		s_gets(try, SIZE);
		ToUpper(try);
	}
	puts("That's right!"); // Теперь правильно!
	return 0;
}
void ToUpper(char *str)
{
	while(*str != '\0')
	{
		*str = toupper(*str);
		str++;
	}
}
char *s_gets(char *st, int n)
{
	char *ret_val;
	int i = 0;
	ret_val = fgets(st, n, stdin);
	if(ret_val)
	{
		while(st[i] != '\n' && st[i] != '\0')
			i++;
		if(st[i] == '\n')
			st[i] == '\0';
		else // требуется наличие words[i] == '\0'
			while(getchar() != '\n')
				continue;
	}
	return ret_val;
}