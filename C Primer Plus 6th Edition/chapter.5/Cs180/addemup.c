// пять видов операторов
#include <stdio.h>
int main (void)							/* ниходит сумму первых 20 целых чисел */
{
	int count, sum;						/* оператор объявления     */

	count = 0;							/* оператор присваивания   */
	sum = 0;
	while (count++ < 20)				/* операторов  			   */
	{
		sum = sum + count;				/*         while		   */
		printf("sum = %d\r\n", sum);	/* оператор вызова функции */
	}
	return 0;
}