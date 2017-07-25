// использование оператора contine для пропуска части цикла
#include <stdio.h>
int main(void)
{
	const float MIN = 0.0f;
	const float MAX = 100.0f;

	float score;
	float total = 0.0f;
	int n = 0;
	float min = MAX;
	float max = MIN;

	printf("Enter the first score (q to quit): ");
	while(scanf("%f", &score) == 1)
	{
		if(score < MIN || score > MAX)
		{
			printf("%0.1f is an invalid value. Try again: ", score);
			continue;
		}
		printf("Accepting %0.1f:\r\n", score);
		min = (score < min)? score: min;
		max = (score > max)? score: max;
		total += score;
		n++;
		printf("Enter next score(q to quit): ");
	}
	if (n > 0)
	{
		printf("Average of %d scores is %0.1f.\r\n", n, total / n);
		printf("Low = %0.1f, high = %0.1f\r\n", min, max);
	}
	else
		printf("No valid scores were entered.\r\n");
	return 0;
}
/*
цикл while читает входные данные до тех пор, пока не будет введено нечисловое значение. 
Оператор if внутри цикла отсеивает недопустимые значения результатов. Если вы, скажем, вводите число 188, программа сообщает о том, что оно является недопустимым. 
Затем оператор continue заставляет программу пропустить оставшуюся часть цикла, которая предназначена для обработки допустимого входного значения. 
Взамен программа начинает новую итерацию, считывая очередное входное значение.
*/ 