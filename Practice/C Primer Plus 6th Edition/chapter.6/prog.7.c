#include <stdio.h>
int main (void)
{
	int i = 0;
	while (++i < 4)
		printf("Hi! ");
	do
		printf("Bye! ");
	while (i++ < 8);
	return 0;
}
// Программа выведет следующую строку: Hi! Hi! Hi! Вуе! Вуе! Вуе! Вуе! Вуе!