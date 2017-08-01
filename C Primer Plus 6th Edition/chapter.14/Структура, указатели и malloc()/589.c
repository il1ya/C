/*Применение в структуре указателя, подлерживающего строку, имеет смысл, когда
с помощью функции malloc() для строки выделяется область памяти и указатель используется, чтобы сохранить адрес этой области. 
Преимущество такого подхода заключается в том, что malloc () позволяет выделить ровно столько памяти, сколько необходимо для строки. 
Вы можете запросить 4 байта для сохранения строки "Joe" и 18 байтов для строки с мадагаскарским именем "Rasolofomasoandro". 
Код в листинге 14.9 совсем нетрудно адаптировать под этот подход. 
Два основных изменения касаются определения структуры с целью применения указателей вместо массивов и предоставления новой версии функции getinfo ().*/
/*Вы должны четко понимать, что эти две строки не хранятся в структуре. 
Они сохранены в области памяти, управляемой malloc(). 
Тем не менее, адреса двух строк хранятся в структуре, и именно с ними обычно имеют дело функции обработки строк.
Следовательно, остальные функции в программе в изменениях не нуждаются.
Однако, согласно совету из главы 12, вы должны уравновешивать вызовы mnalloc() вызовами free(), поэтому в программу добавлена новая функция по имени
cleanup(), которая освобождает память, когда программа завершает пользоваться ею. Вы найдете эту новую функцию и оставшуюся часть программы в листинге 14.10.*/
// Листинг 14.10. Программа names3.c
/*names3.c -- использование указателей и функции malloc()*/
#include <stdio.h>
#include <string.h>		// для strcpy(), strlen()
#include <stdlib.h> 	// для malloc(), free()

#define SLEN 81

struct namect
{
	char *fname; // использование указателей
	char *lname;
	int letters;
};

void getinfo(struct namect *); // выделение памяти
void makeinfo(struct namect *);
void showinfo(const struct namect *);
void cleanup(struct namect *); // освобождение памяти, когда она больше не нужна
char *s_gets(char *st, int n);

int main(void)
{
	struct namect person;
	getinfo(&person);
	makeinfo(&person);
	showinfo(&person);
	cleanup(&person);

	return 0;
}

void getinfo(struct namect *pst)
{
	char temp[SLEN];
	printf("Please enter your first name.\r\n");
	s_gets(temp, SLEN);
	// выделение памяти для хранения имени
	pst -> fname = (char *) malloc(strlen(temp) + 1);

	// копирование имени в выделенную память
	strcpy(pst -> fname, temp);
	printf("Please enter your last name.\r\n");
	s_gets(temp, SLEN);
	pst -> lname = (char *) malloc(strlen(temp) + 1);
	strcpy(pst -> lname, temp);
}

void makeinfo(struct namect *pst)
{
	pst -> letters = strlen(pst -> fname);
	strlen(pst -> lname);
}

void showinfo(const struct namect *pst)
{
	printf("%s %s, your name contains %d letters.\r\n", pst -> fname, pst -> lname, pst -> letters);
}

void cleanup(struct namect *pst)
{
	free(pst -> fname);
	free(pst -> lname);
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