// производит подсчет символов, слов, строк
#include <stdio.h>
#include <ctype.h> //для isspace()
#include <stdbool.h> // для bool, true, false
#define STOP '|'
int main(void)
{
	char c; // прочитанный символ
	char prev; // предыдущий прочитанный символ
	long n_chars = 0L; // количество символов
	int n_lines = 0; // количество строк
	int n_words = 0; //количество слов
	int p_lines = 0; // количество неполных строк
	bool inword = false; // == true если символ с находится внутри слова
	printf("Enter text to be analyzed (| to terminate):\r\n");
	prev = '\n'; // используется для идентификации полных строк
	while ((c = getchar()) != STOP)
	{
		n_chars++; // считать символы
		if (c == '\n')
			n_lines++; // считать строки
		if (!isspace(c) && !inword)
		{
			inword = true; // начало нового слова
			n_words++; // считать слова
		}
		if (isspace(c) && inword)
			inword = false; // достигнут конец слова
			prev = c; // сохранить значение символа
	}
	if (prev != '\n')
		p_lines = 1;
	printf("characters = %ld, words = %d, lines = %d, ", n_chars, n_words, n_lines);
	printf("partial lines = %d\r\n", p_lines);
	return 0;
}