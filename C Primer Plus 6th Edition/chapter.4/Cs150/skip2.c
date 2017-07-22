#include <stdio.h> // пропускает первые два целых числа в потоке ввода
int main (void)
{
	int n;
	printf("Enter three integers:\r\n"); // Введите три целых числа:
	scanf("%*d %*d %d", &n);
	printf("The last was an integer %d\r\n", n); // Последним целым числом было
	return 0;
}