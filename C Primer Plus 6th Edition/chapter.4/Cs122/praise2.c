#include <stdio.h>
#include <string.h> // предоставляет прототип strlen()
#define PRAISE "You great person"
int main (void)
{
	char name[40];
	printf("What your name?"); // Как вас зовут?
	scanf("%s", name);
	printf("Hello, %s. %s\r\n", name, PRAISE);
	printf("Your name consists of %d Symbols and occupies %d the memory cells\r\n", strlen(name), sizeof name); /*
	Ваше имя состоит из символов и занимает ячеек памяти*/
	printf("Praise phrase contains characters %d ", strlen(PRAISE)); //Хвалебная фраза содержит
	printf("and a memory %d cell occupies\r\n", sizeof PRAISE); // и занимает ячеек памяти
	return 0;


}