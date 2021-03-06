/*Функции файлового ввода-вывода fprintf() и fscanf() работают аналогично printf() и scanf(), отличаясь только наличием дополнительного первого аргумента,
в котором идентифицируется подходящий файл. 
Вы уже применяли функцию fprintf(). В листинге 13.3 демонстрируется работа функций файлового ввода-вывода наряду с функцией rewind().*/
// Листинг 13.3. Программа addaword.c

/*addaword.c -- использование fprintf(), fscanf(), rewind()*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 41

int main(void)
{
	FILE *fp;
	char words[MAX];

	if((fp = fopen("wordy", "a+")) == NULL)
	{
		fprintf(stdout, "Can't open"); // Не удается открыть файл
		exit(EXIT_FALLURE);
	}
	puts("Enter words to add to the file; press the #"); // Введите слова для добавления в файл; для завершения
	puts("key at the beginning of a line to terminate."); // Введите символ # в начале строки
	while((fscanf(stdin, "%40s", words) == 1) && (words[0] != '#'))
		fprintf(fp, "%s\r\n", words);
	puts("File contents:"); // содержание файла
	rewind(fp); /*возврат в начало файла*/
	while(fscanf(fp, "%s", words) == 1)
		puts(words);
	puts("Done!"); // Готово
	if(fclose(fp) != 0)
		fprintf(stderr, "Error closing file\r\n"); // Ошибка при закрытии файла
	return 0;
}

/*Эта программа позволяет добавлять слова в файл. За счет использования режима "а+" программа может осуществлять чтение и запись в файл. 
При первом запуске она создает файл wordy и позволяет помещать в него слова по одному в строке. 
При последующем запуске программа позволяет добавлять (дописывать) слова к существующему содержимому. 
Режим добавления разрешает только дописывать данные в конец файла, но режим "а+" позволяет читать весь файл. 
Функция rewind() обеспечивает перемещение в начало файла, так что финальный цикл while может вывести содержимое файла. 
Обратите внимание, что rewind() принимает указатель файла в качестве аргумента.*/

/*$addaword
Введите слова для добавления в файл; для завершения
введите символ # в начале строки.
Один талантливый программист
#
Содержимое файла:
Один
талантливый
программист
Готово!
$ addaword
Введите слова для добавления в файл; для завершения
введите символ # в начале строки.
сумел многих
удивить
#
Содержимое файла:
Один
талантливый
программист
сумел
многих
удивить
Готово!

Как видите, fprintf() и fscanf() работают подобно функциям printf() и scanf(). В отличие от putc(), функции fprintf() и fscanf() принимают указатель
на FILE в первом, а не последнем аргументе.*/