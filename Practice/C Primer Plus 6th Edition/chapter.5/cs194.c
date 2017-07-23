#include <stdio.h>
#define FORMAT "%s! C is cool!\r\n"
int main (void)
{
	int num = 10;
	printf(FORMAT, FORMAT);
	printf("%d\r\n", ++num);
	printf("%d\r\n", num++);
	printf("%d\r\n", num--);
	printf("%d\r\n", num);
	return 0;
}