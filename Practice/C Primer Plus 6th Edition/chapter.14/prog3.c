/*3. Измените программу из листинга 14.2, чтобы она сначала выводила описания
книг в том порядке, в каком они вводились, затем в алфавитном порядке по названиям и, наконец, в порядке возрастания цены.*/
#include <stdio.h>
#include <string.h>

#define MAXTITL 40
#define MAXAULT 40
#define MAXBKS 100 				/*максимальное количество книг*/

struct book /*шаблон структуры: дескриптором является book*/
{
	char title[MAXTITL];
	char author[MAXAULT];
	float value;
}; /*конец шаблона структуры*/

void alphabet(struct book *ptrs[], int n);
void mintomax(struct book *ptrs[], int n);
void test(struct book *ptrs[], int n);


int main(void)
{ 
/*	Объявление массива структур.
Здесь library объявляется как массив, содержащий MAXBKS элементов. Каждый элемент этого массива является структурой типа book. 
Таким образом, library[0] — одна структура типа book, library[1] — вторая структура типа book и т.д.*/
	struct book library[MAXBKS];     /*массив структур типа book*/
	int count = 0;
	int index;

	printf("Please enter the book title.\r\n"); // Введите название книги
	printf("Press [enter] at the start of a line to stop.\r\n"); // Нажмите [] в начале строки, чтобы закончить ввод.
/*Основное отличие этой программы от первой заключается в том, что в ней включен цикл для чтения множества записей. Цикл начинается со следующего условия while:*/
	while(count < MAXBKS && gets(library[count].title) != NULL && library[count].title[0] != '\0')
/*Выражение s_gets(library[count].title, MAXTITL) читает строку для названия книги; это выражение принимает значение NULL, 
если функция s_gets() пытается прочитать символ, следующий за концом файла.	*/	

/*Выражение library[count].title[0] != '\0' проверяет, не является ли первый символ строки нулевым (т.е. не пустая ли строка).
Если пользователь нажимает клавишу <Enter> в начале строки, передатся пустая строка и цикл завершается.*/
	{
		printf("Now enter the author.\r\n"); // Теперь введите ФИО автора.
		gets(library[count].author);
		printf("Now enter the value.\r\n"); // Теперь введите цену.
		scanf("%f", &library[count++].value);
		while(getchar() != '\n')
			continue; /*очистить входную строку*/
		if(count < MAXBKS)
			printf("Enter the next title.\r\n");
	}

	struct book *stp[count];
	for(int i = 0; i< count; i++)
		stp[i] = &library[i];

	if(count > 0)
	{
		printf("Here is the list of your books:\r\n");
		for(index = 0; index < count; index++)
			printf("%s by %s: $%.2f\r\n", library[index].title, library[index].author, library[index].value);
		puts("In alphabetical order: ");
		alphabet(stp, count);
		puts("In value order: ");
		mintomax(stp, count);
	}
	else
		printf("No books? Too bad.\r\n");
	return 0;
}

void alphabet(struct book *ptrs[], int n)
{
	struct book *temp;
	int top, seek;
	for(top = 0; top < n - 1; top++)
		for(seek = top + 1; seek < n; seek++)
		{
			if(strcmp(ptrs[top] -> title, ptrs[seek] -> title) > 0)
			{
				temp = ptrs[top];
				ptrs[top] = ptrs[seek];
				ptrs[seek] = temp;
			}
		}
}

void mintomax(struct book *ptrs[], int n)
{
	struct book *temp;
	int seek, top;
	for(top = 0; top < n - 1; top++)
		for(seek = top + 1; seek < n; seek++)
		{
			if(ptrs[top] -> value > ptrs[seek] -> value)
			{
				temp = ptrs[top];
				ptrs[top] = ptrs[seek];
				ptrs[seek] = temp;
			}
		}
}