#include <stdio.h>
const int S_PER_M = 60;				// количество секунд в минуте
const int S_PER_H = 3600;			// количество секунд в часе
const double M_PER_K = 0.62137;		// количество миль в километре 
int main (void)
{
	double distk, distm; // дистанция пробега в километрах и милях
	double rate;		 // средняя скорость в милях в час
	int min, sec;       // время пробега в минутах и секундах
	int time;			// время пробега только в секундах
	double mtime;		// время пробега одной мили в секундах
	int mmin, msec;		// время пробега одной мили в минутах и секундах
	printf("This program converts your time for a metric race\r\n"); // Эта программа преобразует время пробега дистанции в метрической системе
	printf("to a time for running a mile and to your average\r\n"); // во время пробега одной мили и вычисляет вашу среднюю
	printf("speed in miles per hour.\r\n"); // скорость в милях в час
	printf("Please enter, in kilometers, the distance run.\r\n"); // Введите дистанцию пробега в километрах
	scanf("%lf", &distk);  // lf для типа double
	printf("Next enter the time in minutes and seconds.\r\n");	// Введите время в минутах и секундах
	printf("Begin by entering the minutes.\r\n");	// Начните с ввода минут
	scanf("%d", &min);
	printf("Now enter the seconds.\r\n"); // Теперь введите секунды
	scanf("%d", &sec);
	// переводит время в секунды
	time = S_PER_M * min + sec;
	// переводит километры в мили
	distm = M_PER_K * distk;
	// умножение миль в секунду на количество секунд в часе дает количество миль в час
	rate = distm / time * S_PER_H;
	// деление времени на расстояние дает время пробега одной мили
	mtime = (double) time / distm;
	mmin = (int) mtime / S_PER_M; // вычисление полного количества минут
	msec = (int) mtime % S_PER_M; // вычисление остатка в секундах
	printf("You ran %1.2f km (%1.2f miles) in %d min, %d sec.\r\n", distk, distm, min, sec);
	printf("That pace corresponds to running a mile in %d min, ", mmin); // Такая скорость соотвествует пробегу одной мили за
	printf("%d sec.\r\nYour average speed was %1.2f mph.\r\n", msec, rate); // Ваша средняя скорость составила миль в секунду
	return 0;

}