/*б. Модифицируйте часть 
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

void display(struct social one[5]);
int main(void)
{
	struct social *ps;
	struct social people[5] =
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

void display(struct social one[5])
{
	for(int i = 0; i < 5; i++)
	{
		if(one[i].person.patronymic[0] != '\0')
			printf("type%d: %s, %s %s. - %d\r\n", i, one[i].person.name, one[i].person.surname, one[i].person.patronymic, one[i].serial);
		else
			printf("type%d: %s, %s - %d\r\n", i, one[i].person.name, one[i].person.surname, one[i].person.patronymic, one[i].serial);
	}
}