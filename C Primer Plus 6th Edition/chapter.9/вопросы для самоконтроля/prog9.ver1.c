#include <stdio.h>
void showmenu(void); // обьявление ипользуемых функций

int getchoice(int, int);

int main(void)
{
	int res;
	showmenu();
	while((res = getchoice(1,4)) != 4)
	{
		printf("I am satisfied with the version %d.\r\n", res);
		showmenu();
	}
	printf("program done.\r\n");
	return 0;
}

void showmenu(void)
{
	printf("Select one of the following options:\r\n"); // Выберите один из следующих вариантов
	printf("1) copy the files 		2) move the files\r\n"); // 1) копировать файлы  	2) переместить файлы
	printf("3) delete files 		4) to leave the program\r\n"); // 3) удалить файлы 		4) выйти из программы
	printf("Enter the number of the selected option: "); // Введите номер выбранного варианта:
}

int getchoice(int low, int high)
{
	int ans;
	int good;
	good = scanf("%d", &ans);
	while(good == 1 && (ans < low || ans > high))
	{
		printf("%d is not a valid choice; try again\r\n", ans);
		showmenu();
		scanf("%d", &ans);
	}
	if(good != 1)
	{
		printf("Non-numeric input. ");
		ans = 4;
	}
	return ans;
}