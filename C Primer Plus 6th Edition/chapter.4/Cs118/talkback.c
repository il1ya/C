#include <stdio.h>
#include <string.h> // для прототипа функции strlen()
#define DENSITY 62.4 // удельная масса человека в фунтах на кубический фут
int main ()
{
	float weight, volume;
	int size, letters;
	char name [40]; // name представляет собой массив из 40 символов
	printf("Hello! Wath your name?\r\n"); // Здраствуйте! Как вас зовут?
	scanf("%s", name);
	printf("%s, how much you weigh in pounds?\r\n", name); // сколько вы весите в фунтах?
	scanf("%f", &weight);
	size = sizeof name;
	letters = strlen(name);
	volume = weight / DENSITY;
	printf("Good, %s, your volume is %2.2f cubic feet.\r\n", name, volume); // Хорошо, ваш обьем составляет кубических футов.
	printf("Besides, your name is made up of %d letter,\r\n", letters); // К тому же ваше имя состоит из букв
	printf("and we have 40 bytes for storage\r\n", size); // и мы располагаем байтами для его сохранения.
	return 0;

}