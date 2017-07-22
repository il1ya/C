#include <stdio.h> /*Поля разной ширины*/
#define PAGES 9
int main (void)
{
	printf("*%d*\r\n", PAGES);
	printf("*%2d*\r\n", PAGES);
	printf("*%10d*\r\n", PAGES);
	printf("*%-10d*\r\n", PAGES);
	return 0;
}