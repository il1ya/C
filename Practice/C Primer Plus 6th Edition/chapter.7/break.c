#include <stdio.h>
int main(void)
{
	int p, q;
	printf("%d\r\n", p);
	scanf("%d", &q);
	while(q > 0)
	{
		printf("%d\r\n", p * q);
		if(q > 100)
			break; // выход из внутреннего цикла
		scanf("%d", &q);
	}
	if (q > 100)
		break; // выход из внешнего цикла
	scanf("%d", &p);
	return 0;
}