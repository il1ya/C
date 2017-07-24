/*
Что выведут приведенные далее программы в случае ввода Go west, young man!?
(В кодировке ASCII символ ! следует за символом пробела.)
*/
#include <stdio.h>
int main (void)
{
	char ch;
	do 
	{
		scanf("%c", &ch);
		printf("%c", ch);
	} while (ch != 'g');
	return 0;
}
// Go west, young