/*4. Напишите программу, которая создает шаблон структуры с двумя членами в соответствии со следующими критериями.
а. Первым членом является номер карточки социального страхования. 
Второй член — это структура, состоящая из трех членов. 
Ее первый член содержит имя, второй член — отчество и третий член — фамилию. 
Создайте и инициализируйте массив из пяти таких структур. 
Программа должна выводить данные в следующем формате:
Dribble, Flossie М. — 302039823
Выводиться должна только начальная буква отчества, за которой следует точка.
Разумеется, если этот член пуст, не должен выводиться ни инициал, ни точка.
Напишите функцию, которая выполняет такой вывод, передайте рассматриваемую структуру этой функции.
б. Модифицируйте часть 
а) так, чтобы вместо адреса передавалась сама структура.*/

#include <stdio.h>
#define NAME 45

struct name
{
	char name[NAME];
	char patronymic[NAME];
	char surname[NAME];
};

struct social 
{
	long serial;
	struct name person;
};

void display(struct social *);
int main(void)
{
	struct social *ps;
	struct social people[] =
	{
		{ 77777777, {"Skvortsov", "Alexsandor", "Illya"}},
		{ 55555555, {"Freecss", "", "Gon"}},
		{ 44444444, {"von Einzbern", .surname = "Illyasviel"}},
		{ 33333333, {"Takashi", "", "Natsume"}},
		{ 22222222, {"Sakata", "", "Gintoki"}}
	};
	ps = people;
	display(ps);
	return 0;
}

void display(struct social *p)
{
	for(int i = 0; i < 5; i++)
	{
		if((p + i) -> person.patronymic[0] != '\0')
			printf("type: %s, %s %s. - %d\r\n", (p + i) -> person.name, (p + i) -> person.surname, (p + i) -> person.patronymic, (p + i) -> serial);
		else
			printf("type%d: %s, %s - %d\r\n", i, (p + i) -> person.name, (p + i) -> person.surname, (p + i) -> person.patronymic, (p + i) -> serial);
	}
}