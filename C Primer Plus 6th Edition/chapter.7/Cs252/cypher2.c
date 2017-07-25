#include <stdio.h> // вносит изменения во входные данные, сохраняя пробелы
#define SPACE ' '  // кавычка, пробел, кавычка
int main (void)
{
	char ch;
	while ((ch = getchar()) != '\n') // пока не встретится конец строки
		{
			if (ch == SPACE) // оставить пробел нетронутым
				putchar(ch); // символ не меняется
			else
				putchar(ch + 1); // изменить другие символы
			ch = getchar(); //получить следующий символ
		}
		putchar (ch);
		return 0;
}