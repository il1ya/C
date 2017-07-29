/*Напишите программу, которая читает до 10 строк и или до появления EOF, в зависимости от того, что произойдет раньше. 
Функция должна предложить пользователю меню с пятью вариантами: вывод исходного списка строк, 
вывод строк согласно последовательности сопоставления ASCII, вывод строк в порядке возрастания длины, 
вывод строк в порядке возрастания длины первого слова в строке и выход из программы. 
Меню должно отображаться до тех пор, пока пользователь не выберет вариант выхода из программы. 
Программа должна действительно выполнять запрошенные действия.*/
#include <stdio.h>
#include <string.h>
#define LINE 10
#define SIZE 81
void origin_put(char *group[], int n);
void ascii_put(char *group[], int n);
void lenght_put(char *group[], int n);
void word_put(char *group[], int n);
int forst_len(char *sp);
int main(void)
{
	char strings[LINE][SIZE];
	char *ptr[LINE]; // Additional pointer to maintain original string array
	char option[SIZE];
	int line = 0;
	while(1)
	{
		puts("Please enter 10 strings shorter than 81"
			" characters and ends with EOF.");
		while(line < LINE && gets(strings[line]) != NULL && strings[line][0] != '\0')
		{
			ptr[line] = strings[line]; // copy address from strings to ptr
			line++; // total lines of strings read
		}
		do
		{
            puts("Please select an option below: ");
            puts("a) Original put out");
            puts("b) According to ascii order");
            puts("c) According to sentence length");
            puts("d) According to first word length");
            puts("e) Quit");

            gets(option); // gets an option
            switch(*option) // response cases
            {
            	case 'a': origin_put(ptr, line); break;
            	case 'b': ascii_put(ptr, line); break;
            	case 'c': lenght_put(ptr, line); break;
            	case 'd': word_put(ptr, line); break;
            	case 'e': break;
            	default: printf("No valid option selected!\r\n"
            		"Restarting procedure...\r\n");
            	continue;
            }
		}while (*option != 'e');
		break;
	}
	puts("End of program");
	return 0;
}
void origin_put(char *group[], int n)
{
	int i;
	for(i = 0; i < n; i++)
		puts(group[i]);
}
void ascii_put(char *group[], int n)
{
	int i, j, cnt;
	char *temp;
	for(i = 0; i < n - 1; i++)
		for(j = i + 1; j < n; j++)
			if(strcmp(group[i], group[j]) > 0)
			{
				temp = group[i];
				group[i] = group[j];
				group[j] = temp;
			}
			for(cnt = 0; cnt < n; cnt++)
				puts(group[cnt]);
}
void lenght_put(char * group[], int n)
{
	int i, j, cnt;
	char *temp;
	for(i = 0; i < n - 1; i++)
		for(j = i + 1; j < n; j++)
			if(strlen(group[i]) > strlen(group[j])) // wierd sizeof doesn't work here
			{
				temp = group[i];
				group[i] = group[j];
				group[j] = temp;
			}
			for(cnt = 0; cnt < n; cnt++)
				puts(group[cnt]);
}
void word_put(char *group[], int n)
{
	int i, j, cnt;
	char *temp;
	for(i = 0; i < n - 1; i++)
		for(j = i + 1; j < n; j++)
			if(first_len(group[i]) > first_len(group[j]))
			{
				temp = group[i];
				group[i] = group[j];
				group[j] = temp;
			}
			for(cnt = 0; cnt < n; cnt++)
				puts(group[cnt]);
}
int first_len(char *sp)
{
	int i;
	for(i = 0; i < strlen(sp) && *(sp + i) != ' '; i++)
		continue;
	return i;
}