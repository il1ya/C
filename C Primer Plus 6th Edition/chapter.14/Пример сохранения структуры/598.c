/*
Чтобы продемонстрировать использование этих функций в программе, мы модифицировали код из листинга 14.2, чтобы сведения о книгах сохранялись в файле по имени book.dat. 
Если файл уже существует, программа отображает его текущее содержимое и затем позволяет добавить в файл новые данные. 
Новая версия программы показана в листинге 14.14. (Если вы имеете дело с Borland C/C++, ознакомьтесь с врезкой "Borland С и плавающая запятая" ранее в главе.)*/
// Листинг 14.14. Программа booksave.с

/*booksave.c -- сохранение содержимого структуры в файле*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXTITL 40
#define MAXAULT 40
#define MAXBKS 10 			/*максимальное количество книг*/

char *s_gets(char *st, int n);

struct book 			/*определение шаблона book*/
{
	char title[MAXTITL];
	char author[MAXAULT];
	float value;
};

int main(void)
{
	struct book library[MAXBKS]; /*массив структур*/
	int count = 0;
	int index, filecount;
	FILE *pbooks;
	int size = sizeof (struct book);
/*Для начала файл открывается в режиме "а+Ь". Часть а+ позволяет программе читать весь файл и добавлять данные в конец файла. 
Часть Ь - это принятый в ANSI способ для сообщения о том, что программа будет применять двоичный файловый формат.*/
	if((pbooks = fopen("book.dat", "a+b")) == NULL)
	{
		fputs("Can't open book.dat file\r\n", stderr); // Не удается открыть файл 
		exit(1);
	}
/*Вызов rewind() обеспечивает установку указателя позиции в файле на начало файла, приводя его в состояние готовности к первому чтению.*/
	rewind(pbooks);					/*переход в начало файла*/
/*Первый цикл while читает одну структуру за раз в массив структур, останавливаясь при заполнении этого массива либо при исчерпании данных в файле.*/
	while(count < MAXBKS && fread(&library[count], size, 1, pbooks) == 1)
	{
		if(count == 0)
			puts("Current contents of book.dat:"); // Текущуу содержимое файла
		printf("%s by %s: $%.2f\r\n", library[count].title, library[count].author, library[count].value);
		count++;
	}
/*Переменная filecount отслуживает количество прочитанных структур.*/
	filecount = count;
	if(count == MAXBKS)
	{
		fputs("The book.dat file is full.", stderr);
		exit(2);
	}

	puts("Please add new book titles."); // Введите название новых книг.
	puts("Press [enter] at the start of a line to stop."); // Нажмите в начале строки, чтобы закончить ввод
/*Следующий цикл while запрашивает и получает пользовательский ввод. 
Как и в листинге 14.2, этот цикл прекращается, когда массив заполнен или пользователь нажал клавишу <Enter> в начале строки. 
Обратите внимание, что переменная count начинается со значения, которое она получила по окончании предыдущего цикла. 
Это приводит к добавлению новых записей в конец массива.*/
	while(count < MAXBKS && s_gets(library[count].title, MAXTITL) != NULL && library[count].title[0] != '\0')
	{
		puts("Now enter the author."); // Теперь введите имя автора
		s_gets(library[count].author, MAXAULT);
		puts("Now enter the value."); // Теперь введите цену книги
		scanf("%f", &library[count++].value);
		while(getchar() != '\n')
			continue; 				/*очистить входную строку*/
		if(count < MAXBKS)
			puts("Enter the next title."); // Введите название следующей книги
	}

	if(count > 0)
	{
		puts("Here is the list of your books:"); // Каталог ваших книг
/*Затем в цикле for выводятся данные, полученные из файла и от пользователя. 
Так как файл был открыт в режиме добавления, новые записи присоединяются к существующему содержимому.*/
		for(index = 0; index < count; index++)
			printf("%s by %s: $%.2f\r\n", library[index].title, library[index].author, library[index].value);
/*Выражение &library[filecount] — это адрес первой новой структуры в массиве, поэтому копирование начинается с этой точки.*/
		fwrite(&library[filecount], size, count - filecount, pbooks);
	}
	else
		puts("No books? Too bad.\r\n"); // Вообще нет книг? Очень плохо

	puts("Bye.\r\n"); // Программа завершена
	fclose(pbooks);

	return 0;
}

char *s_gets(char *st, int n)
{
	char *ret_val;
	char *find;

	ret_val = fgets(st, n, stdin);
	if(ret_val)
	{
		find = strchr(st, '\n'); // поиск новой строки
		if(find) // если адрес не равен NULL
			*find = '\0'; // поместить туда нулевой символ
		else
			while(getchar() != '\n')
				continue; // отбросить остаток строки
	}
	return ret_val;
}