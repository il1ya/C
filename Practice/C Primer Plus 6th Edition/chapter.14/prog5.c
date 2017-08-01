/*5. Напишите программу, которая соответствуем следующим требованиям.

а. Программа внешне определяет шаблон структуры name с двумя членами: 
строкой для хранения имени и строкой для хранения фамилии.

б. Программа внешне определяет шаблон структуры student с тремя членами:
структуры name, массивом grade для хранения трех оценок в виде чисел с плавающей запятой и переменной для хранения среднего значения этих трех оценок.

в. Программа содержит функцию main(), где объявляется массив из CSIZE
(с CSIZE = 4) структур student, в которых инициализируются члены name именами по вашему выбору. 
Для выполнения задач, описанных в частях г), д), е) и ж), используйте функции.

г. Программа интерактивно вводит оценки для каждого студента, запрашивая у пользователя ввод имени студента и его оценок. 
Поместите оценки в массив grade соответствующей структуры. 
Требуемый цикл можно реализовать в main() или в специальной функции по вашему усмотрению.

д. Программа вычисляет среднюю оценку для каждой структуры и присваивает ее соответствующему члену.
е. Программа выводит информацию из куклой структуры.
ж. Программа выводит среднее значение по курсу для каждого числового члена структуры.*/

#include <stdio.h>
#define CSIZE 5
#define LEN 31

struct name 
{
	char first[LEN];
	char last[LEN];
};

struct student
{
	struct name person;
	float grade[3];
	float averg;
};

void setgrade(struct student array[], int n);
void aver(struct student array[], int n);
void display(const struct student array[], int n);
void caver(struct student array[], int n);

int main(void)
{
	struct student tops[CSIZE] =
	{
		{{"Skvortsov", "Illya"}},
		{{"Freecss", "Gon"}},
		{{"von Einzbern", "Illyasviel"}},
		{{"Takashi", "Natsume"}},
		{{"Sakata", "Gintoki"}}
	};

	setgrade(tops, 5);
	aver(tops, 5);
	display(tops, 5);
	caver(tops, 5);
	return 0;
}

void setgrade(struct student array[], int n)
{
	for(int i = 1; i <= n; i++)
	{
		printf("Please enter No.%d student's 3 grades:\r\n", i);
		while(scanf("%f %f %f", &array[i - 1].grade[0], &array[i -1].grade[1], &array[i - 1].grade[2]) < 3)
		{
			puts("Please try again.");
			while(getchar() != '\n')
				continue;
		}
	}
}
void aver(struct student array[], int n)
{
	for(int i = 0; i < n; i++)
		array[i].averg = (array[i].grade[0] + array[i].grade[1] + array[i].grade[2]) / 3;
}
void display(const struct student array[], int n)
{
	for(int i =0; i < n; i++)
		printf("%s: %.1f %.1f %.1f -> %.1f\r\n", array[i].person.first, array[i].grade[0], array[i].grade[1], array[i].grade[2], array[i].averg);
}
void caver(struct student array[], int n)
{
	float sum1 = 0;
	float sum2 = 0;
	float sum3 = 0;
	float suma = 0;
	for(int i = 0; i < n; i++)
	{
		sum1 += array[i].grade[0];
		sum2 += array[i].grade[1];
		sum3 += array[i].grade[2];
		suma += array[i].averg;
	}
	printf("Averages of %d students\r\n", n);
	printf("grade1: %.1f grade2: %.1f grade3: %.1f averg: %.1f\r\n", sum1 / n, sum2 / n, sum3 / n, suma / n);
}