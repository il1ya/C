/*9. Авиакомпания Colossus Airlines (из упражнения 8) приобрела второй самолет
(с тем же количеством мест) и расширила обслуживание до четырех рейсов ежедневно (рейсы с номерами 102, 311, 444 и 519). 
Модифицируйте программу для обработки четырех рейсов. 
Она должна предлагать меню верхнего уровня, которое позволяет выбирать интересующий рейс и выходить из программы. 
После выбора рейса должно отобразиться меню, подобное показанному в упражнении 8.
Однако в него должен быть добавлен новый элемент — подтверждение брони места. 
Кроме того, вариант выхода из программы потребуется заменить вариантом возвращения в меню верхнего уровня. 
При каждом отображении должен указываться номер рейса, обрабатываемого в текущий момент. 
Вдобавок при отображении брони мест должно выводиться состояние подтверждения.*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define LEN 40
#define SIZE 12
#define FLT 4

struct seat
{
	char code;
	int sold;
	char first[LEN];
	char last[LEN];
};

const char flts[FLT][5] = {"102", "311", "444", "519"};

void showmenu(void);
void choseflt(void);
int shownumber(struct seat *(*ptr)[SIZE], int n);
void empty_list(struct seat *(*ptr)[SIZE], int n);
void sortedlist(struct seat *(*ptr)[SIZE], int n);
void assignseat(struct seat *(*ptr)[SIZE], int n);
void deleteseat(struct seat *(*ptr)[SIZE], int n);
void readfile(struct seat (*ptr)[], char *filename);
void writefile(struct seat (*ptr)[], char *filename);

int main(void)
{
    int seats = SIZE;
    int fltnum;                      // record chosen flgit number
    char command[LEN];                  // get choice
    struct seat flights[FLT][SIZE];
    struct seat *pp[FLT][SIZE];
    
    for (int f = 0; f < FLT; f++)
        for (int i = 0; i < SIZE; i++)  // initialize
        {
            flights[f][i].code = 'A' + i;
            flights[f][i].sold = 0;
        }
    
    readfile(flights, "data.dat");      // load file and override initialization
    
    for (int f = 0; f < FLT; f++)
        for (int i = 0; i < SIZE; i++)      // temporary array of struct pointer initialization
            pp[f][i] = &(flights[f][i]);
            
    int flago = 1;
    int flagi = 0;
    while (flago == 1) 
    {
        puts("Please select a flight or quit:");
        puts("a)flight 102    b)flight 311");
        puts("c)flight 444    d)flight 519");
        puts("e)quit");
        gets(command);
        switch (command[0])
        {
            case 'a': fltnum = 0; flagi = 1; break;
            case 'b': fltnum = 1; flagi = 1; break;
            case 'c': fltnum = 2; flagi = 1; break;
            case 'd': fltnum = 3; flagi = 1; break;
            case 'e': flago = 0; flagi = 0; break;
            default: puts("choose a/b/c/d/e");
        }
        
        while (flagi == 1)
        {
            showmenu();
            gets(command);
            switch (command[0])
            {
                case 'a': shownumber(pp, fltnum); break;
                case 'b': empty_list(pp, fltnum); break;
                case 'c': sortedlist(pp, fltnum); break;
                case 'd': assignseat(pp, fltnum); break;
                case 'e': deleteseat(pp, fltnum); break;
                case 'f': flagi = 0; break;
                default: puts("choose a/b/c/d/e/f");
            }
        }
    }
    writefile(flights, "data.dat");
    puts("Good bye");
    return 0;
}

void showmenu(void)
{
	printf("To choose a function, enter its letter lable:\r\n");
	printf("a) Show number of empty seats\r\n");
	printf("b) Show list of empty seats\r\n");
	printf("c) Show alphabetical list of seats\r\n");
	printf("d) Assign a customer to seat assignment\r\n");
	printf("e) Delete a seat assignment\r\n");
	printf("f) Quit\r\n");
}

int shownumber(struct seat *(*ptr)[SIZE], int n)
{
	int left_t = SIZE * FLT;
	int left = SIZE;
	for(int f = 0; f < FLT; f++)
		for(int i = 0; i < SIZE; i++)
		{
			if(ptr[f][i] -> sold == 1)
			left -= 1;
			if(ptr[f][i] -> sold == 1 && f == n)
				left -= 1;
		}
		printf("There are %d seats still available in flight %s.\r\n", left, flts[n]);
		printf("Total remaining seats in all four flights is %d.\r\n", left_t);
		return left;
}

void empty_list(struct seat *(*ptr)[SIZE], int n)
{
	for(int f = 0; f < FLT; f++)
		for(int i = 0; i < SIZE; i++)
		if(ptr[f][i] -> sold == 0 && f == n)
			printf("%s: %c\r\n", flts[n], ptr[f][i] -> code);
}

void sortedlist(struct seat *(*ptr)[SIZE], int n)
{
	struct seat *temp;
	for(int f = 0; f < FLT - 1; f++)
		for(int i = 0; i < SIZE; i++)
			for(int j = i + 1; j < SIZE; j++)
			if(ptr[f][i] -> code > ptr[f][j] -> code)
			{
				temp = ptr[f][i];
				ptr[f][i] = ptr[f][j];
				ptr[f][j] = temp;
			}
			puts("Alphabetical list of seats:");
			for(int f = 0; f < FLT; f++)
			{
				if(f == n)
				{
					for(int i = 0; i < SIZE; i++)
					{
						printf("Flight %s:\r\n", flts[n]);
						printf("%c\r\n", ptr[f][i] -> code);
					}
				}
			}
}

void assignseat(struct seat *(*ptr)[SIZE], int n)
{
	if(shownumber(ptr, n) == 0)
		puts("Sorry, all tickets sold out.");
	else
	{
		int i;
		for(i = 0; i < SIZE; i++)
			if(ptr[n][i] -> sold == 0)
			{
				puts("Please enter passenger's first name:");
				scanf("%s", &ptr[n][i] -> first);
				getchar();
				puts("Please enter passenger's last name:");
				scanf("%s", &ptr[n][i] -> last);
				getchar();
				ptr[n][i] -> sold = 1;
				break;
			}
			printf("%s %s has booked seat %c.\r\n", ptr[n][i] -> first, ptr[n][i] -> last, ptr[n][i] -> code, flts[n]);
	}
}

void deleteseat(struct seat *(*ptr)[SIZE], int n)
{
	char code;
	char tfirst[LEN], tlast[LEN];
	puts("Please enter your seat code:");
	scanf("%c", &code);
	getchar();
	for(int i = 0; i < SIZE; i++)
		if(ptr[n][i] -> code == code)
		{
			strcpy(tfirst, ptr[n][i] -> first);
			strcpy(ptr[n][i] -> first, "");
			strcpy(tlast, ptr[n][i] -> last);
			strcpy(ptr[n][i] -> last, "");
			ptr[n][i] -> sold = 0;
			break;
		}
		printf("%s %s, your assignment is canceled.\r\n", tfirst, tlast);
}

void readfile(struct seat (*p)[FLT], char *filename)
{
	FILE *ps;
	int count = 0;
	if((ps = fopen(filename, "a+b")) == NULL)
	{
		printf("Can't open %s file\r\n", filename);
		exit(1);
	}
	rewind(ps);
	while (count < FLT && fread(p+count, SIZE * sizeof(struct seat), 1, ps) == 1)
		count++;
	if(ferror(ps) != 0)
		fprintf(stderr, "Error in loading structure data\r\n");
	fclose(ps);
}

void writefile(struct seat (*p)[FLT], char *filename)
{
	FILE *ps;
	ps = fopen(filename, "r+b");
	fwrite(p, SIZE * sizeof(struct seat), FLT, ps);
	if(ferror(ps) != 0)
		fprintf(stderr, " Error in saving structure data\r\n");
	fclose(ps);
}