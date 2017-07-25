/*программа считывает список показаний минимальных дневных температур (по шкале Цельсия) и выводит общее количество элементов, а также процентзначений, 
меньших точки замерзания (т.е. ниже нуля по Цельсию). Для чтения значений используется функция scanf() в цикле. На каждой итерации цикла инкрементируется счетчик, 
отслеживая количество показаний. Спомощью оператора if идентифицируются значения температуры ниже нуля, ведется отдельный подсчет таких случаев. 
*/
// вычисляет процент случаев, когда температура опускается ниже нуля
#include <stdio.h>
int main(void)
{
	const int FREEZING = 0;
	float temperature;
	int cold_days = 0;
	int all_days = 0;
	printf("Enter the list of daily low temperatures.\r\n");
	printf("Use Celsius, and enter q to quit.\r\n");
	while (scanf("%f", &temperature) == 1)
	{
		all_days++;
		if (temperature < FREEZING)
			cold_days++;
	}
	if (all_days != 0)
		printf("%d days total: %.1f%% were below freezing.\r\n",
			all_days, 100.0 * (float) cold_days / all_days);
	if(all_days == 0)
		printf("No data entered!\r\n");
	return 0;
}
/*
В условии проверки цикла while значение, возвращаемое функцией scanf(), используется для завершения цикла, когда встречается нечисловое значение. 
За счет применения типа float вместо int для переменной temperature программа получает возможность принимать такие показания температуры, как -2.5 ,а также 8.
*/ 