/*
Текстовый файл содержит информацию о команде по софтболу (разновидность бейсбола). 
В каждой строке данные упорядочены следующим образом: 4 Джесси Джойбет 5 2 1 1
Первым членом является номер игрока (обычно это число из диапазона 0-18). Второй член — это имя игрока, а третий — его фамилия. Каждое имя состоит из одного слова. 
Следующий плен показывает, сколько раз игрок принимал мяч, за
которым следует количество нанесенных игроком ударов, проходов и засчитанных пробежек. 
Файл может содержать результаты более чем одной игры, следовательно, для одного и того же игрока может быть несколько строк. 
Напишите программу, которая сохраняет соответствующие данные в массиве структур.
Структура должна состоять из членов, в которых представлены фамилия и имя,
количество набранных очков, проходов и засчитанных пробежек, а также средний результат (эти значения вычисляются позже). 
В качестве индекса массива можете использовать номер игрока. 
Программа должна выполнять чтение до конца файла, и накапливать итоговые результаты по каждому игроку.
Мир статистики бейсбола довольно сложен. Например, проход или взятие базы в результате ошибки не расценивается так же высоко, как тот же самый результат,
полученный за счет меткого удара, однако он позволяет получить выигранную пробежку. 
Но эта программа должна только читать и обрабатывать файлы данных, как описано ниже, не заботясь о реалистичности данных.
Простейший способ предусматривает инициализацию содержимого структуры нулями, 
чтение данных из файла во временные переменные и затем их добавление к содержимому соответствующей структуры. 
После того, как программа завершит чтение файла, она должна вычислить средний уровень достижений для каждого игрока и запомнить его в соответствующем члене структуры. 
Средний уровень достижений вычисляется путем деления накопленного числа ударов, выполненных
игроком, на количество выходов на ударные позиции; вычисление должно быть с плавающей запятой. 
Затем программа должна отобразить накапливаемые данные по каждому игроку наряду со строкой, в которой содержатся суммарные статистические данные по всей команде.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LEN 30
#define MAX 20

typedef struct
{
	char first[LEN];
	char last[LEN];
}id;

typedef struct
{
	int play;
	int hit;
	int brun;
	int RBI;
}data;

struct player
{
	int number;
	id name;
	data score;
	float averg;
};

int main(void)
{
	FILE *fp;
	int tpnum, tpplay, tphit, tpbrun, tpRBI;
	int total_play = 0, total_hit = 0, total_brun = 0, total_RBI = 0;
	float total_averg = 0.0;
	char tpfirst[LEN];
	char tplast[LEN];

	struct player teamx[MAX];

	int line = 0;
	int mark = - 1;
	if((fp = fopen("baseball.txt", "rb")) == NULL)
	{
		fprintf(stderr, "Can't open file baseball.txt\r\n");
		exit(1);
	}
	while(fscanf(fp, "%d %s %s %d %d %d %d", &tpnum, tpfirst, tplast, &tpplay, &tphit, &tpbrun, &tpRBI) == 7)
	{
		if(line < 1)
		{
			teamx[0].number = tpnum;
			strcpy(teamx[0].name.first, tpfirst);
			strcpy(teamx[0].name.last, tplast);
			teamx[0].score.play = tpplay;
			teamx[0].score.hit = tphit;
			teamx[0].score.brun = tpbrun;
			teamx[0].score.RBI = tpRBI;
			line++;
		}
		else if(line >= 1)
		{
			for(int i = 0; i < line; i++)
				if(tpnum == teamx[i].number)
					mark = i;
				if(mark == -1)
				{
					teamx[line].number = tpnum;
					strcpy(teamx[line].name.first, tpfirst);
					strcpy(teamx[line].name.last, tplast);
					teamx[line].score.play = tpplay;
					teamx[line].score.hit = tphit;
					teamx[line].score.brun = tpbrun;
					teamx[line].score.RBI = tpRBI;
					line++;
				}
				else if(mark != -1)
				{
					teamx[mark].score.play += tpplay;
					teamx[mark].score.hit += tphit;
					teamx[mark].score.brun += tpbrun;
					teamx[mark].score.RBI += tpRBI;
				}
		}
		printf("%d player%c: %d %s %s %d %d %d %d\r\n", line, ((line > 1) ? 's' : '\b'), tpnum, tpfirst, tplast, tpplay, tphit, tpbrun, tpRBI);
	}
	puts("The players's data: ");
	for(int i = 0; i < line; i++)
	{
		total_play += teamx[i].score.play;
		total_hit += teamx[i].score.hit;
		total_brun += teamx[i].score.brun;
		total_RBI += teamx[i].score.RBI;
		teamx[i].averg = (float)teamx[i].score.hit / teamx[i].score.play;
		printf("%d %s %s %d %d %d %d %.4f\r\n", teamx[i].number, teamx[i].name.first, teamx[i].name.last, teamx[i].score.play, teamx[i].score.hit, teamx[i].score.brun, teamx[i].score.RBI, teamx[i].averg);
	}
	total_averg = (float)total_hit / total_play;
	puts("Total statistics:");
	printf("%d %d %d %d %.4f\r\n", total_play, total_hit, total_brun, total_RBI, total_averg);
	return 0;
}