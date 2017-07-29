/*3. Разработайте и протестируйте функцию, которая читает первое слово из строки ввода в массив и отбрасывает остальную часть строки. 
Функция должна пропускать ведущие пробельные символы. Определите слово как последовательность символов, не содержащую символов пробела, табуляции или новой строки.
Используйте функцию getchar(), а не scanf().*/
#include <stdio.h>
//#include <stdio_ext.h>
#include <ctype.h>
/*#define WORD_SIZE = 32;
#define WORD_NUM = 128;*/
void read_first_word(char *);
int main(void)
{
	const unsigned int WORD_SIZE = 32;
    const unsigned int WORD_NUM = 128;

	char words[WORD_SIZE][WORD_NUM];
	unsigned int i = 0; n = 0;
	for(i = 0; i < WORD_NUM; i++)
	{
		read_first_word(words[i]);
		if(words[i][0] == '\0')
		{
			break;
		}
		n++;
	}
	for(i = 0; i < n; i++)
	{
		puts(words[i]);
	}
	return 0;
}
void read_first_word(char *word)
{
	char line[WORD_NUM] = {0};
	unsigned int i = 0, j = 0;
	// find the first non-space char
	while(line[i] != '\0')
	{
		if(!isspace(line[i]))
		{
			break;
		}
		i++;
	}
	if(line[i] == '\0')
	{
		word[0] = '\0';
	}
	else
	{
		while(line[i] != '\0')
		{
			if(isspace(line[i]))
			{
				word[j] = '\0';
				break;
			}
			word[j] = line[i];
			i++;
			j++;
		}
	}
	//_fpurge(stdin);
}