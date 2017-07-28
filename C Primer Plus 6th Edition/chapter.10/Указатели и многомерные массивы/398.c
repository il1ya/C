// zippol.c -- информация о массиве zippo
#include <stdio.h>
int main(void)
{
	int zippo[4][2] = { {2,4}, {6,8}, {1,3}, {5,7} };
	printf(" zippo = %p, zippo + 1 = %p\r\n", zippo, zippo + 1);
	printf("zippo[0] = %p, zippo[0] + 1 = %p\r\n", zippo[0], zippo[0] + 1);
	printf(" *zippo = %p, *zippo + 1 = %p\r\n", *zippo, *zippo + 1);
	printf("zippo[0][0] = %d\r\n", zippo[0][0]);
	printf(" *zippo[0] = %d\r\n", *zippo[0]);
	printf("	**zippo = %d\r\n", **zippo);
	printf("	 zippo[2][1] = %d\r\n", zippo[2][1]);
	printf("*(*(zippo + 2) + 1) = %d\r\n", *(*(zippo + 2) + 1));
	return 0;
}