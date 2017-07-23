#include <stdio.h>
#define MAX 10
int main (void)
{
	int count = MAX + 1;
	while (--count > 0)
	{
		printf("%d bottles of spring water on the shelf," 
		" %d bottles of spring water!\r\n", count, count); // бутылок родниковой воды на полке, бутылок родниковой воды!
		printf("Take one of them and let the circle,\r\n"); // Возьмите одну из них и пустите по кругу,
		printf(" %d bottles of spring water!\r\n", count - 1); // бутылок родниковой воды!
	}
	return 0;
}