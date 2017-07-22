#include <stdio.h> // 1.программа, которая запрашивает скорость загрузки в мегабитах в секунду и размер файла в мегабайтах.
//Программа должна вычислять время загрузки файла.
int main (void)
{
	char name[10];
	float speedinmegabits;
	float filesize;
	float share;
	printf("Good afternoon! please, introduce yourself ");
	scanf("%s", name);
	printf("\r\nWelcome! %s, first enter your download speed in megabits\r\n", name);
	scanf("%f", &speedinmegabits);
	printf("\r\nGood! Now %s enter your file size\r\n", name);
	scanf("%f", &filesize);
	printf("\r\nVery good %s", name);
	share = speedinmegabits / filesize;
	printf("\r\nWith download speeds %.2fMbps, file size %.2fMB loaded for %.2fseconds\r\n", speedinmegabits, filesize, share);
	return 0;

}