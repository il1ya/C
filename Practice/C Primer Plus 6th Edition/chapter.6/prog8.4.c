/*
Что выведут приведенные далее программы в случае ввода Go west, young man!?
(В кодировке ASCII символ ! следует за символом пробела.)
*/
#include <stdio.h>
int main (void)
{
	char ch;
	scanf("%c", &ch);
	for (ch = '$'; ch != 'g'; scanf("%c", &ch))
		printf("%c", ch);
	return 0;
}
// $о west, youn