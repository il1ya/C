/*
Что выведут приведенные далее программы в случае ввода Go west, young man!?
(В кодировке ASCII символ ! следует за символом пробела.)
*/
#include <stdio.h>
int main (void)
{
	char ch;
	scanf("%c", &ch);
	while (ch != 'g')
	{
		printf("%c", ++ch);
		scanf("%c", ch);
	}
	return 0;
}
// Hp ! xftu-! zpvo