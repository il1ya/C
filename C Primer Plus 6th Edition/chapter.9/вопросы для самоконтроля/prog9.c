#include <stdio.h>
#define NUMBER '#'
int main(void)
{
	int enter;
	printf("Select one of the following options:\r\n"); // Выберите один из следующих вариантов
	printf("1) copy the files 		2) move the files\r\n"); // 1) копировать файлы  	2) переместить файлы
	printf("3) delete files 		4) to leave the program\r\n"); // 3) удалить файлы 		4) выйти из программы
	printf("Enter the number of the selected option: "); // Введите номер выбранного варианта:
	// while((scanf("%d", &enter)) != '\n')
	scanf("%d", &enter);
	printf("your choice: %d\r\n", enter);
	{
	switch(enter)
		{
	case 1:
		printf("1) copy the files\r\n");
		break;
	case 2:
		printf("2) move the files\r\n");
		break;
	case 3:
		printf("3) delete files\r\n");
		break;
	case 4:
		printf("4) to leave the program\r\n");
		break;
		default:
		printf("Invalid entry!\r\n");
		}
	}
	return 0;
}