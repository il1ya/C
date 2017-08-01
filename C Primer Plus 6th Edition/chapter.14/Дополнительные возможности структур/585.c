/*Теперь посмотрим, каким образом запрограммировать решение той же задачи с использованием структур как аргументов и возвращаемых значений. 
Во-первых, для передачи самой структуры необходимо применять артумент person, а не &person.
Тогда соответствующий формальный артумент объявляется с типом struct namect, а не указателем на этот тип. 
Во-вторых, чтобы предоставить main() значения структуры, можно возвратить саму структуру. 
В листинге 14.9 показана версия программы без указателей.*/
// Листинг 14.9. Программа names2.c
/*names2.c -- передает и возвращает структуры*/
#include <stdio.h>
#include <string.h>
/*Эта версия дает тот же самый результат, что и предыдущая, но работает по-другому.*/
#define NLEN 30
struct namect
{
	char fname[NLEN];
	char lname[NLEN];
	int letters;
};
/*Каждая из трех функций создает собственную копию структуры person, так что в программе задействованы четыре разные структуры, а не только одна.*/
struct namect getinfo(void);
struct namect makeinfo(struct namect);
void showinfo(struct namect);
char *s_gets(char *st, int n);

int main(void)
{
	struct namect person;

	person = getinfo();
	person = makeinfo(person);
	showinfo(person);

	return 0;
}

struct namect getinfo(void)
{
	struct namect temp;
	printf("Please enter your first name.\r\n");
	s_gets(temp.fname, NLEN);
	printf("Please enter your last name.\r\n");
	s_gets(temp.lname, NLEN);

	return temp;
}
/*Для примера рассмотрим функцию makeinfo(). 
В первой программе ей передавался адрес структуры person, и функция имела дело с действительными значениями person. 
Во второй версии программы создавалась новая структура по имени info.
Значения, хранящиеся в person, копировались в info, и функция работала с копией. Следовательно, подсчитанное количество букв сохранялось в info, но не в person.
Тем не менее, это исправляет механизм возврата. Строка в makeinfo()
return info;
объединяется со строкой в main()
person = makeinfo(person);
для копирования значений хранящихся внутри info, в person. Обратите внимание, что функция makeinfo() должна быть объявлена с типом struct namect,
т.к. она возвращает структуру.*/
struct namect makeinfo(struct namect info)
{
	info.letters = strlen(info.fname) + strlen(info.lname);
	return info;
}

void showinfo(struct namect info)
{
	printf("%s %s, your name contains %d letters.\r\n", info.fname, info.lname, info.letters);
}

char *s_gets(char *st, int n)
{
	char *ret_val;
	char *find;

	ret_val = fgets(st, n, stdin);
	if(ret_val)
	{
		find = strchr(st, '\n'); // поиск новой строки
		if(find)				 // если адрес не равен NULL
			*find = '\0';		 // поместить туда нулевой символ
		else
			while(getchar() != '\n')
				continue;		 // отбросить остаток строки
	}
	return ret_val;
}