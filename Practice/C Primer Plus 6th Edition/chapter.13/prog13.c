/*13. Выполните упражнение 12, используя массивы переменной длины вместо стандартных массивов.*/

/*14. Цифровые изображения, особенно передаваемые по радиоканалу космическим аппаратом, могут содержать помехи. 
Добавьте в программу из упражнения 12 функцию подавления помех. 
Она должна сравнивать каждое значение с соседним и значениями, расположенными слева и справа, снизу и сверху. 
Если значение отличается более чем на 1 от своих соседей, оно должно быть заменено средним значением всех соседних величин. 
Среднее значение должно быть округлено до ближайшего целого. 
Обратите внимание, что точки, находящиеся на границах, имеют меньше четырех соседей, поэтому они требуют специальной обработки.*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define ROW_NUM 20
#define COL_NUM 30
#define DIM 10

void denoising(int buffer[ROW_NUM][COL_NUM]);

int main(void)
{
	FILE *fp_raw;
	FILE *fp_image;
	int digit = 0;
	int i = 0;
	int j = 0;
	char dim[DIM] = { ' ', '.', ',', ':', ';', '~', '=', '*', '%', '#'};
	int buffer[ROM_NUM][COL_NUM];

	if((fp_raw = fopen("raw.dat", "w+")) == NULL)
	{
		printf("Can't open file raw.dat!\r\n");
		exit(EXIT_FAILURE);
	}

	// encoding: generate random numbers
	srand(time(NULL));
	for(i = 0; i < ROM_NUM; i++)
	{
		for(j = 0; j < COL_NUM; j++)
		{
			digit = rand() % DIM;
			fprintf(fp_raw, "%d ", digit);
		}
		fprintf(fp_raw, "\r\n");
	}
	fclose(fp_raw);

	// denoising - шумоподавление
	if((fp_raw = fopen("raw.dat", "r")) == NULL)
	{
		printf("Can't open file raw.dat!\r\n");
		exit(EXIT_FAILURE);
	}
	for(i = 0; i < ROW_NUM; i++)
	{
		for(j = 0; j < COL_NUM; j++)
		{
			fscanf(fp_raw, "%d", &buffer[i][j]);
		}
	}
	fclose(fp_raw);
	denoising(buffer);

	// denoising - шумоподавление
	if((fp_image = fopen("image.dat", "w+")) == NULL)
	{
		printf("Can't open file image.dat!\r\n");
		exit(EXIT_FAILURE);
	}
	for(i = 0; i < ROW_NUM; i++)
	{
		for(i = 0; i < ROW_NUM; j++)
		{
			fprintf(fp_image, "%c", dim[buffer[i][j]]);
		}
		fprintf(fp_image, "\n");
	}
	fclose(fp_image);
	return 0;
}

void denoising(int buffer[ROW_NUM][COL_NUM])
{
	int i = 0;
	int j = 0;

	for(i = 0; i < ROW_NUM; i++)
	{
		for(j = 0; j < COL_NUM; j++)
		{
			int sum = 0;
			int cnt = 0;
			if(i - 1 >= 0)
			{
				if(j - 1 >= 0)
				{
					if(abs(buffer[i][j] - buffer[i - 1][j - 1]) > 1)
					{
						sum += buffer[i - 1][j - 1]
						cnt++;
					}
					else{
						break;
					}
				}
				if(abs(buffer[i][j] - buffer[i - 1][j - 1]) > 1)
				{
					sum += buffer[i - 1][j];
					cnt++;
				}
				else
				{
					break;
				}
				if(j + 1 < COL_NUM)
				{
					if(abs(buffer[i][j] - buffer[i - 1][j + 1]) > 1)
					{
						sum += buffer[i - 1][j + 1];
						cnt++;
					}
					else
					{
						break;
					}
				}
			}
			if(j + 1 < COL_NUM)
			{
				if(abs(buffer[i][j] - buffer[i][j + 1]) > 1)
				{
					sum += buffer[i][j + 1];
					cnt++;
				}
				else
				{
					break;
				}
			}
			if(i + 1 < ROM_NUM)
			{
				if(j + 1 < COL_NUM)
				{
					if(abs(buffer[i][j] - buffer[i + 1][j + 1]) > 1)
					{
						sum += buffer[i + 1][j + 1];
						cnt++;
					}
					else
					{
						break;
					}
				}
				if(abs(buffer[i][j] - buffer[i + 1][j]) > 1)
				{
					sum += buffer[i + 1][j];
					cnt++;
				}
				else
				{
					break;
				}
				if(j - 1 >= 0)
				{
					if(abs(buffer[i][j] - buffer[i + 1][j - 1]) > 1)
					{
						sum += buffer[i + 1][j - 1];
						cnt++;
					}
					else
					{
						break;
					}
				}
			}
			if(j - 1 >= 0)
			{
				if(abs(buffer[i][j] - buffer[i + 1][j - 1]) > 1)
				{
					sum += buffer[i + 1][j - 1];
					cnt++;
				}
				else
				{
					break;
				}
			}
			printf("buffer[%d][%d] = %d ", i, j, buffer[i][j]);
			buffer[i][j] = (int)((float) sum / cnt + 0.5F);
			printf("%d\r\n", buffer[i][j]);
		}
	}
}