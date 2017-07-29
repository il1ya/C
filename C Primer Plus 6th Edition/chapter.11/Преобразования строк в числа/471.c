/*Стандарт ANSI С предоставляет усложненные версии этих функций: strtol() преобразует строку в значение типа long, strtoul() — типа unsigned long, а strtod() — типа double. 
Более сложный аспект упомянутых функций связан с тем, что они идентифицируют и сообщают о первом символе в строке, который не относится к числу. 
Кроме того, функции strtol() и strtoul() позволяют указывать основание системы счисления.
Давайте рассмотрим пример, в котором задействована функция strtol(). 
Ее прототип имеет следующий вид:
long strtol(const char * restrict nptr, char ** restrict endptr, int base);
Здесь nptr — указатель на строку, подлежащую преобразованию, endptr — адрес указателя, который устанавливается в адрес символа, 
прекращающего ввод числа, и base — основание системы счисления, в которой записано число. 
Это поможет прояснить пример, приведенный в листинге 11.33.*/
// Листинг 11.33. Программа strcnvt.с
/* strcnvt.c -- использование функции strtol() */
#include <stdio.h>
#include <stdlib.h>
#define LIM 30
char *s_gets(char *st, int n);
int main(void)
{
	char number[LIM];
	char *end;
	long value;
	puts("Enter a number (empty line to quit):"); // Введите число (или пустую строку для выхода из программы)
	while(s_gets(number, LIM) && number[0] != '\0')
	{
/*Функция strtol() работает с системами счисления, имеющими основание вплоть до 36, применяя в качестве цифр все буквы английского алфавита до 'z'. 
Функция strtoul() делает то же самое, но преобразует значения без знака.*/
		value = strtol(number, &end, 10);
		printf("base 10 input, base 10 output: %ld, stopped at %s (%d)\r\n", value, end, *end); // десятичный ввод, десятичный вывод: прекращен на
		value = strtol(number, &end, 16);
		printf("base 16 input, base 10 output: %ld, stopped at %s (%d)\r\n", value, end, *end); // шестнадцатеричный ввод, шестнадцатеричный вывод: прекращен на
/*Функция strtod() работает только в десятичной системе счисления, так что она принимает только два аргумента.*/
		puts("Next number:"); // Следующее число
	}
	puts("Bye!\r\n"); // Программа завершена
	return 0;
}
char *s_gets(char *st, int n)
{
	char *ret_val;
	int i = 0;
	ret_val = fgets(st, n, stdin);
	if(ret_val)
	{
		while(st[i] != '\n' && st[i] != '\0')
			i++;
		if(st[i] == '\n')
			st[i] = '\0';
		else // требуется наличие words[i] == '\0'
			while(getchar() != '\n')
				continue;
	}
	return ret_val;
}
/*Прежде всего, обратите внимание, что строка "10" преобразуется в число 10, когда base равно 10, и в 16, когда base равно 16. 
Кроме того, если end указывает на символ, то *end — это сам символ. 
Следовательно, первое преобразование завершается, когда достигнут нулевой символ, поэтому end указывает на нулевой символ. 
Таким образом, вывод end приводит к отображению пустой строки, а вывод *end с форматом %d — к отображению ASCII-кода нулевого символа.*/

/*Для второй строки ввода (в интерпретации с десятичным представлением) указатель end получает адрес символа 'а'. 
Тогда вывод указателя end приводит к отображению строки "atom", а вывод *end — к отображению ASCII-кода символа 'а'. 
Однако, как только base изменяется на 16, символ 'а' распознается как допустимая шестнадцатеричная цифра, и функция преобразует шестнадцатеричное число 1Оа в десятичное 266.*/

/*Многие реализации располагают функциями itoa() и ftoa(), предназначенными для преобразования целочисленных значений и значений с плавающей запятой в строки. 
Тем не менее, они не являются частью стандартной библиотеки С, поэтому для большей совместимости используйте вместо них sprintf().*/