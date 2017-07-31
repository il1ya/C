/*Создайте текстовый файл, состоящий из 20 строк по 30 целых чисел. Целые значения должны входить в диапазон от О до 9 и отделяться друг от друга пробелами.
Файл является цифровым представлением изображения, при этом значения от О до 9 воспроизводят возрастающие уровни темноты. 
Напишите программу, которая читает содержимое этого файла в массив элементов int с размером 20 на 30. 
При грубом подходе к преобразованию такого цифрового представления в изображение программа должна использовать значения из этого массива для
инициализации массива элементов char с размером 20 на 31. 
При этом О соответствует символу пробела, 1 - символу точки и т.д.; большее значение представляется символом, занимающим большую площадь. 
Например, символ # может использоваться для представления значения 9. Последний символ (31-й) в каждой строке должен быть нулевым, образуя в итоге массив из 20 строк. 
Программа должна отобразить результирующее изображение (т.е. вывести строки) и также сохранить результат в текстовом файле. 
Например, предположим, что начальные данные выглядят так:*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROM_NUM 20
#define COL_NUM 30
#define DIM 10

int main(void)
{
	FILE *fp_raw;
	FILE *fp_image;
	int digit = 0;
	int i = 0;
	int j = 0;
	char dim[DIM] = { ' ', '.', ',', ':', ';', '~', '=', '*', '%', '#'};
	if((fp_raw = fopen("raw.dat", "w+")) == NULL)
	{
		printf("Can't open file raw.dat!\r\n");
		exit(EXIT_FAILURE);
	}

	srand(time(NULL));
	for(i = 0; i < ROW_NUM; i++)
	{
		for(j = 0; j < COL_NUM; j++)
		{
			digit = rand() % DIM;
			fprintf(fp_raw, "%d ", digit);
		}
		fprintf(fp_raw, "\n");
	}
	fclose(fp_raw);

	if((fp_raw = fopen("raw.dat", "r")) == NULL)
	{
		printf("Can't open file raw.dat!\r\n");
		exit(EXIT_FAILURE);
	}
	if((fp_image = fopen("image.dat!", "w+")) == NULL)
	{
		printf("Can't open file image.dat!\r\n");
		exit(EXIT_FAILURE);
	}
	for(i = 0; i < ROW_NUM; i++)
	{
		for(j = 0; j < COL_NUM; j++)
		{
			fscanf(fp_raw, "%d", &digit);
			fprintf(fp_image, "%c", dim[digit]);
		}
		fprintf(fp_image, "\n");
	}
	fclose(fp_raw);
	fclose(fp_image);
	return 0;
}