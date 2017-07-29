/*Часто удобно иметь массив символьных строк. Тогда для доступа к разным строкам можно применять индекс. 
В листинге 11.4 продемонстрированы два подхода: массив указателей на строки и массив из массивов типа char.*/
// Листинг 11.4. Программа arrchar.c
// arrchar.c -- Массив указателей, массив строк
#include <stdio.h>
#define SLEN 40
#define LIM 5
int main(void)
{
	const char *mytalents[LIM] = {
		"Adding numbers swiftly",
		"Multiplying accurately", "Stashing data",
		"Following instructions to the letter",
		"Understanding the C language"

	};
	char yourtalents[LIM][SLEN] = {
		"Walking in a straight line",
		"Sleeping", "Watching television",
		"Mailing letters", "Reading email"
	};
	puts("Let's compare talents."); // puts() = printf() #include <stdio.h>
	printf("%-36s %-25s\r\n", "My talents", "Your Talents");
	for(int i = 0; i < LIM; i++)
	printf("%-36s %-25s\r\n", mytalents[i], yourtalents[i]);
	printf("\r\nsizeof mytalents: %d, sizeof yourtalents: %d\r\n", sizeof(mytalents), sizeof(yourtalents));
	return 0;
}
/*массив mytalents — это массив из пяти указателей, занимающий в нашей системе 40 байтов. 
Но yourtalents — массив, состоящий из пяти массивов по 40 значений char и занимающий в нашей системе 200 байтов. 
Таким образом, тип массива mytalents отличается от типа yourtalents, несмотря на то, что и mytalents[0], и yourtalents[0] — это строки.*/