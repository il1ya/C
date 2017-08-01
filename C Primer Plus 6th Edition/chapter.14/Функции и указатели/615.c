// Листинг 14.16. Программа func_ptr.c
// func_ptr.c -- использование указателей на функции

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define LEN 81

char *s_gets(char *st, int n);

char showmenu(void);

void eatline(void);				// читает до конца строки

void show(void (* fp)(char *), char *str);
/*Обратите внимание, что функции ToUpper(), ToLower(), Transpose() и Dummy() имеют тот же самый тип, поэтому все они могут быть присвоены указателю pfun.*/

void ToUpper(char *);			// преобразует строку в верхний регистр

void ToLower(char *);			// преобразует строку в нижний регистр

void Transpose(char *);			// меняет местами регистры

void Dummy(char *);				// оставляет строку неизмененной

int main(void)
{
	char line[LEN];
	char copy[LEN];
	char choice;
/*В этой программе в качестве аругмента для show() применяется pfun, но можно также указывать непосредственно любое из имен четырех функций, как в show(Transpose, сору).*/
	void (*pfun)(char *);			 // указывает на функцию, которая имеет аргумент
									// типа char * и ничего не возвращает 
	puts("Enter a string (empty line to quet):");

	while(s_gets(line, LEN) != NULL && line[0] != '\0')
	{
/*Далее, функция showmenu() спроектирована так, чтобы возвращать в программу только допустимые варианты выбора. 
Для содействия в этом применяется стандартная библиотечная функция strchr() из заголовочного файла string.h*/
		while((choice = showmenu()) != 'n')
		{
			switch(choice) // оператор switch устанавливает указатель
			{
				case 'u' : pfun = ToUpper; break;
				case 'l' : pfun = ToLower; break;
				case 't' : pfun = Transpose; break;
				case 'o' : pfun = Dummy; break;
			}
			strcpy(copy, line); // сделать копию для show()
			show(pfun, copy);	// использовать выбранную функцию
		}
		puts("Enter a string (empty line to quit):");
	}
	puts("Bye!");

	return 0;
}

char showmenu(void)
{
	char ans;
	puts("Enter menu choice:"); // Введите выбранный вариант из меню
	puts("u) uppercase 		 1) lowercase"); // нижний регистр 1) верхний регистр
	puts("t) transposed case o) original case"); // поменять местами регистры о) исходный регистр
	puts("n) next string"); // следующая строка

	ans = getchar();  	// получить ответъ
	ans = tolower(ans); // преобразовать в нижний регистр
/*Функция eatline() избавляется от оставшейся части введенной строки. 
Это полезно по двум причинам. Во-первых, при выборе действия в меню пользователь набирает букву, а затем нажимает клавишу <Enter>, что приводит к генерации символа новой строки. 
Если первым делом не избавиться от этого символа, он будет прочитан как следующий ответ. 
Во-вторых, предположим, что вместо буквы и пользователь вводит слово u uppercase целиком. 
Без функции eatline() программа трактовала бы каждый символ слова uppercase как отдельный ответ. 
Благодаря eatline(), программа обрабатывает символ и и отбрасывает оставшуюся часть строки.*/
	eatline(); 			// избавиться от оставшейся части строки
/*отражает два способа преобразования пользовательского ввода в один регистр, так что не приходится выполнять проверку для 'u' и 'U' и т.д.*/
	while(strchr("ulton", ans) == NULL)
/*Эта функция ищет местоположение первого вхождения символа ans в строке "ulton" и возвращает указатель на него. 
Если символ не найден, возвращается нулевой указатель.*/
	{
		puts("Please enter a u, l, t, o, or n:");
		ans = tolower(getchar());
		eatline();
	}
	return ans;
}


void eatline(void)
{
	while(getchar() != '\n')
		continue;
}

void ToUpper(char *str)
{
	while(*str)
	{
		*str = toupper(*str);
		str++;
	}
}

void ToLower(char *str)
{
	while(*str)
	{
		*str = tolower(*str);
		str++;
	}
}

void Transpose(char *str)
{
	while(*str)
	{
		if(islower(*str))
			*str = toupper(*str);
		else if(isupper(*str))
			*str = tolower(*str);
		str++;
	}
}

void Dummy(char *str)
{
	// оставляет строку неизмененной
}

void show(void(* fp)(char *), char *str)
{
	(*fp)(str); // применить выбранную функцию к str
	puts(str);  // отобразить результат
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