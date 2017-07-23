// постфиксная и префиксная формы
#include <stdio.h>
int main (void)
{
	int a = 5, b = 5, d = 5;
	int a_post, pre_b, d_pos;

	a_post = a++; // значение a++ во время этапа присваивания
	pre_b = ++b; // значение ++b во время этапа присваивания
	
	printf("a a_post b pre_b\r\n");
	printf("%1d %5d %2d %1d\r\n", a, a_post, b, pre_b);
	return 0;
}