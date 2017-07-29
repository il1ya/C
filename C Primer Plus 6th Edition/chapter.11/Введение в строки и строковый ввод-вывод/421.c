/* символьная строка — это массив элементов типа char с завершающим нулевым символом (\О).*/
// Листинг 11.1. Программа strings1.c
// strings1.c
#include <stdio.h>
#define MSG "I am a symbolic string constant." // Я символьная строковая константа
#define MAXLENGTH 81
int main(void)
{
// Строковый липтерал, который также называют страковай константай, представляет собой произвольную последовательность символов, помещенную в двойные кавычки.
	char words[MAXLENGTH] = "I am a string in an array."; // Я являюсь строкой, хранящейся в массиве.
	const char *ptl = "Something is pointing at me."; // Что-то указывает на меня.
	puts("\"Here are some string: \""); // двойные кавычки в строке \"
	puts(MSG);
	puts(words);
	puts(ptl);
	words[8] = 'p';
	puts(words);
	return 0;
}
/*Подобно printf(), функция puts() принадлежит семейству функций ввода-вывода stdio.h. 
Она отображает только строки и, в отличие от printf(), автоматически добавляет к выводимой строке символ новой строки.*/