#include <stdio.h> // несоответствия при преобразовании целочисленных типов
#define PAGES 336 
#define	WORDS 65618
int main (void)
{
	short num = PAGES;
	short mnum = -PAGES;
	printf("num as a type short and type unsigned short: %hd %hu\r\n", num, num); // num как тип short и тип unsigned short:
	printf("-num as a type short and type unsigned short: %hd %hu\r\n", mnum, mnum);
	printf("num as a type int and type char: %d %c\r\n", num, num);
	printf("WORDS as a type int, short and char: %d %hd %c\r\n", WORDS, WORDS, WORDS);
	return 0;
}