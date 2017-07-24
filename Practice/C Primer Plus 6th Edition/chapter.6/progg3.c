/*
Воспользуйтесь вложенными циклами, чтобы написать программу, которая выводит следующую последовательность символов:
F
FE
FED
FEDC
FEDCB
FEDCBA
Примечание: если в вашей системе нс используется ASCII или какая-то другая кодировка, в которой буквы представлены в числовом порядке, 
то для инициализации символьного массива буквами алфавита вы можете применять следующее объявление:
char lets[27] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
Затем для выбора конкретных букв можно использовать индексы массива, например,
lets[О] для 'А' и т.д.
*/
#include <stdio.h>
int main (void)
// вариант программы без цикла используя только массивы
{
	char simv[27] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	printf("%c\r\n", simv[5]);
	printf("%c%c\r\n", simv[5], simv[4]);
	printf("%c%c%c\r\n", simv[5], simv[4], simv[3]);
	printf("%c%c%c%c\r\n", simv[5], simv[4], simv[3], simv[2]);
	printf("%c%c%c%c%c\r\n", simv[5], simv[4], simv[3], simv[2], simv[1]);
	printf("%c%c%c%c%c%c\r\n", simv[5], simv[4], simv[3], simv[2], simv[1], simv[0]);
	return 0;
}