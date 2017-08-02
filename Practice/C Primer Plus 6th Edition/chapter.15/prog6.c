/*6. 
Разработайте структуру битовых полей, которая содержит следующую информацию:
• Идентификатор шрифта: число от 0 до 255
• Размер шрифта: число от 0 до 127
• Выравнивание: число от 0 до 2, представляющее опции выравнивания влево, по центру и вправо
• Полужирный: отключен (0) или включен (1)
• Курсив: отключен (0) или включен (1)
• Подчеркнутый: отключен (0) или включен (1)
Используйте эту структуру в программе, которая отображает параметры шрифта и дает пользователю возможность менять параметры с помощью циклического меню. 
Ниже приводится пример выполнения программы:

ИД 	РАЗМЕР 	ВЫРАВНИВАНИЕ 	Ж 		К 		Ч
1 	12 		влево 			откл. 	откл. 	откл.

ш) изменить шрифт  	р) изменить размер  	в) изменить выравнивание
ж) полужирный 		к) курсив 				п) подчеркнутый
з) завершить
р

Введите размер шрифта (0-127): 36
ИД 	РАЗМЕР 	ВЫРАВНИВАНИЕ 	Ж 		К 		Ч
1 	36		влево 			откл. 	откл. 	откл.

ш) изменить шрифт  	р) изменить размер  	в) изменить выравнивание
ж) полужирный 		к) курсив 				п) подчеркнутый
з) завершить
в

Выберите выравнивание:
л) влево 			ц) по центру 			п) вправо

п
ИД 	РАЗМЕР 	ВЫРАВНИВАНИЕ 	Ж 		К 		Ч
1 	36		вправо 			откл. 	откл. 	откл.

ш) изменить шрифт  	р) изменить размер  	в) изменить выравнивание
ж) полужирный 		к) курсив 				п) подчеркнутый
з) завершить
к

ИД 	РАЗМЕР 	ВЫРАВНИВАНИЕ 	Ж 		К 		Ч
1 	36		вправо 			откл. 	вкл. 	откл.
ш) изменить шрифт  	р) изменить размер  	в) изменить выравнивание
ж) полужирный 		к) курсив 				п) подчеркнутый
з) завершить
з

Программа завершена.
Чтобы обеспечить преобразование вводимых значений идентификатора и размера шрифта в значения из указанного диапазона, программа должна применять операцию & и подходящие маски.*/

#include <stdio.h>
#include <ctype.h>
#define LEFT 0
#define CENTER 1
#define RIGHT 2
#define ON 1
#define OFF 0

struct font
{
	unsigned int font_id: 8;
	unsigned int font_size: 7;
	unsigned int alignment: 2;
	unsigned int bold: 1;
	unsigned int italic: 1;
	unsigned int underline: 1;
};

void change_font(struct font *pf);
void change_size(struct font *pf);
void change_alig(struct font *pf);
void change_bius(struct font *pf, int key);
void display(const struct font *pf);
void show_menu(void);

int main(void)
{
	char choice[10];
	struct font sample = { 1, 12, LEFT, OFF, OFF, OFF };
	struct font *sp = &sample;

	display(sp);
	show_menu();
	gets(choice);
	while(choice[0] != 'q')
	{
		switch(choice[0])
		{
			case 'f': change_font(sp); break;
			case 's': change_size(sp); break;
			case 'a': change_alig(sp); break;
			case 'b': change_bius(sp, 0); break;
			case 'i': change_bius(sp, 1); break;
			case 'u': change_bius(sp, 2); break;
			default: puts("Please enter options correctly");
		}
		display(sp);
		show_menu();
		gets(choice);
	}
	puts("End of program");
	return 0;
}

void show_menu(void)
{
	puts("f) change font 	s) change size 		a) change alignment");
	puts("b) toggle bold 	i) toggle italic 	u) toggle underline");
	puts("q) quit");
}

void display(const struct font *pf)
{
	char alig[3][10] = { "Left", "center", "right" };
	puts(" ID SIZE   ALIGNMENT B    I   U");
	printf("%3d %3d %8s %7d %2d %2d\r\n\r\n", pf -> font_id, pf -> font_size, alig[pf -> alignment], pf -> bold, pf -> italic, pf -> underline);
}

void change_font(struct font *pf)
{
	int id;
	printf("Please enter font ID (0-255):\r\n");
	if(scanf("%d", &id) != 1)
		printf("Invalid input.");
	pf -> font_id = id;
	getchar();
}

void change_size(struct font *pf)
{
	int size;
	printf("Please enter font size (0-127):\r\n");
	if(scanf("%d", &size) != 1)
		printf("Invalid input.");
	pf -> font_size = size;
	getchar();
}

void change_alig(struct font *pf)
{
	char mode[10];
	printf("Please enter alignment mode (left, centre or right): \r\n");
	gets(mode);
	switch(tolower(mode[0]))
	{
		case 'l': pf -> alignment = LEFT; break;
		case 'c': pf -> alignment = CENTER; break;
		case 'r': pf -> alignment = RIGHT; break;
		default: puts("Invalid input.");
	}
}

void change_bius(struct font *pf, int key)
{
	switch(key)
	{
		case 0: pf -> bold ^= ON; break;
		case 1: pf -> italic ^= ON; break;
		case 2: pf -> underline ^= ON; break;
		default: puts("Invalid input.");
	}
}