/*
Напишите программу, которая читает ввод как поток символов, пока не встретит EOF. 
Программа должна сообщать среднее количество букв в словах. Не считайте пробельные символы в словах буквами. 
На самом деле, также не должны учитываться и знаки препинания, но в данном упражнении об этом можно не беспокоиться. 
(Для учета знаков препинания можно воспользоваться функцией ispunct() из семейства ctype.h.)
*/
#include <stdio.h>
#include <ctype.h>
int main(void)
{
	char ch;
	int punctuation = 0;
	int n_lines = 0;
	int n_chars = 0;
	int n_other = 0;
	printf("Enter characters\r\n");
	while((ch = getchar()) != EOF && ch != '#')
	{
		if(ispunct(ch))	// символ знаков препинания
		punctuation++;
		if(isupper(ch)) // Символ верхнего регистра
		n_lines++; // считать строки
		else if(islower(ch)) // Символ нижнего регистра
		n_chars++; // считать символы
		else
		n_other++; // считать другое
	}
	printf("punctuation = %d|\r\nlines = %d|\r\ncharacters = %d|\r\nother = %d\r\n", punctuation, n_lines, n_chars, n_other);
	return 0;
}