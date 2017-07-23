// экспоненциальный рост
#include <stdio.h>
#define SQUARES 64 // колочество клеток шахматной доски
int main (void)
{
	const double CROP = 2E16; // мировой урожай пшеницы в зернах
	double current, total;
	int count = 1;
	printf("square    added    total "); // квадрат, добавлено, итого
	printf("percent for \r\n"); // процент от
	printf("    grains    grains    "); // зерен
	printf("global harvest\r\n"); // мирового уражая
	total = current = 1.0; // начинаем с одного зернышка
	printf("%4d %13.2e %12.2e %12.2e\r\n", count, current, total, total / CROP);
	while (count < SQUARES)
	{
		count = count + 1;
		current = 2.0 * current; // удвоить количество зерен на следующей клетке
		total = total + current; // обновить итоговую сумму
		printf("%4d %13.2e %12.2e %12.2e\r\n", count, current, total, total / CROP);
	}
	printf("That's all\r\n");
	return 0;
}