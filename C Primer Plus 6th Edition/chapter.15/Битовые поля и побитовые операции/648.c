/*Вспомните, что объединение может иметь инициализированный первый член, поэтому установленные значения соответствуют представлению структуры. 
Программа отображает свойства окна с помощью функции, основанной на представлении структуры,
и также посредством функции, основанной на представлении unsigned short.
Любой из подходов обеспечивает доступ к данным, но по-разному. 
Вдобавок в программе применяется определенная ранее в главе функция itobs(), которая позволяет
отобразить данные в виде строки двоичных цифр, чтобы можно было видеть, какие биты включены, а какие выключены.*/
// Листинг 15.4. Программа dualview.c
/*dualview.c -- битовые поля и побитовые операции*/
#include <stdio.h>
#include <stdbool.h>
#include <limits.h>
/*КОНСТАНТЫ БИТОВЫХ ПОЛЕЙ*/
/*стили линии*/
#define SOLID 0
#define DOTTED 1
#define DASHED 2
/*основные цвета*/
#define BLUE 4
#define GREEN 2
#define RED 1
/*смешанные цвета*/
#define BLACK 0
#define YELLOW (RED | GREEN)
#define MAGENTA (RED | BLUE)
#define CYAN (GREEN | BLUE)
#define WHITE (RED | GREEN | BLUE)
/*ПОБИТОВЫЕ КОНСТАНТЫ*/
#define OPAQUE 0x1
#define FILL_BLUE 0x8
/*Здесь Ох8 — это значение, когда в 1 установлен только бит 3, а Ох800 - значение, когда в 1 установлен только бит 11. 
Первую константу можно применять при установке бита синего цвета для фона окна, а вторую - при установке бита синего цвета для рамки. 
Шестнадцатеричная запись упрощает выяснение, какие биты задействованы.
Вспомните, что каждая шестнадцатеричная цифра представляет четыре бита.
Следовательно, значение Ох800 соответствует комбинации битов Ох8, но с дописанными восемью битами с состоянием 0. 
Глядя на десятичные эквиваленты, 2048 и 8, заметить такую связь гораздо труднее.*/
#define FILL_GREEN 0x4
#define FILL_RED 0x2
#define FILL_MASK 0xE
#define BORDER 0x100
#define BORDER_BLUE 0x800
/*Ох800 - значение, когда в 1 установлен только бит 11.*/
#define BORDER_GREEN 0x400
#define BORDER_RED 0x200
#define BORDER_MASK 0xE00
#define B_SOLID 0
#define B_DOTTED 0x1000
#define B_DASHED 0x2000
#define STYLE_MASK 0x3000

const char *colors[8] = { "black", "red", "green", "yellow", "blue", "magenta", "cyan", "while" };
struct box_props
{
	bool opaque 			  : 1;
	unsigned int fill_color   : 3;
	unsigned int 			  : 4;
	bool show_border 		  : 1;
	unsigned int border_color : 3;
	unsigned int border_style : 2;
	unsigned int 			  : 2;
};

union Views /*взгляд на данные как на struct или как на unsigned short*/
{
	struct box_props st_view;
	unsigned short us_view;
};

void show_settings(const struct box_props * pb);
void show_settings1(unsigned short);
char *itobs(int n, char *ps);

int main(void)
{
	/*создание объукта Views, инициализация представления в виде структуры*/
	union Views box = {{true, YELLOW, true, GREEN, DASHED}};
	char bin_str[8 * sizeof(unsigned int) + 1];

	printf("Original box settings:\r\n"); // Исходные настройки окна
	show_settings(&box.st_view);
	printf("\r\nBox settings using unsigned int view:\r\n"); // Настройки окна с использованием представления unsigned short
	show_settings1(box.us_view);

	printf("bits are %s\r\n", itobs(box.us_view, bin_str)); // комбинация битов
/*Дело в том, что цвет также полагается на настройку бита, отвечающего за красный цвет. 
Если этот бит был включен ранее (скажем, для получения желтого цвета), то
приведенный код оставит бит красного цвета установленным и установит в 1 биты синего и зеленого цветов, давая в результате белый цвет. 
Обойти эту проблему проще всего, сначала отключив все биты, отвечающие за цвет, и лишь затем устанавливать новые значения. 
Именно поэтому в программе содержится следующий код:*/
	box.us_view &= ~FILL_MASK; 					/*очистить биты фона*/
	box.us_view |= (FILL_BLUE | FILL_GREEN);	/*переустановить фон*/
	box.us_view ^= OPAQUE;						/*переключить прозрачность*/
/*Для демонстрации того, что может произойти, если предварительно не очистить соответствующие биты, в программе также предусмотрена такая строка:*/
	box.us_view |= BORDER_RED;					/*ошибочный подход*/
	box.us_view &= ~STYLE_MASK;					/*очистить биты стиля*/
	box.us_view |= B_DOTTED;					/*установить пунктирный стиль*/
	printf("\r\nModified box settings:\r\n"); // измененные настройки окна
	show_settings(&box.st_view);
	printf("\r\nBox settings using unsigned int view:\r\n"); // настройки окна с ипользованием представления unsigned int
	show_settings1(box.us_view);
	printf("bits are %s\r\n", itobs(box.us_view, bin_str)); // комбинация битов
	return 0;
}

void show_settings(const struct box_props *pb)
{
	printf("Box is %s.\r\n", pb -> opaque == true ? "opaque": "transparent");
	printf("The fill color is %s.\r\n", colors[pb -> fill_color]);
	printf("Border %s.\r\n", pb -> show_border == true ? "shown" : "not shown");
/*операторе выражение pb->border_color имеет значение из диапазона 0-7, поэтому его можно использовать как индекс в массиве colors.*/
	printf("The border color is %s.\r\n", colors[pb -> border_color]);
	printf("The border style is ");
	switch(pb -> border_style)
	{
		case SOLID : printf("solid.\r\n"); break;
		case DOTTED : printf("dotted.\r\n"); break;
		case DASHED : printf("dashed.\r\n"); break;
		default : printf("unknown type.\r\n");
	}
}
void show_settings1(unsigned short us)
{
	printf("box is %s.\r\n", (us & OPAQUE) == OPAQUE ? "opaque" : "transparent");
	printf("The fill color is %s.\r\n", colors[(us >> 1) & 07]);
	printf("Border %s.\r\n", (us & BORDER) == BORDER ? "shown" : "not shown");
	printf("The border style is ");
	switch(us & STYLE_MASK)
	{
		case B_SOLID : printf("solid.\r\n"); break;
		case B_DOTTED : printf("dotted.\r\n"); break;
		case B_DASHED : printf("dashed.\r\n"); break;
		default : printf("unknown type.\r\n");
	}
	printf("The border color is %s.\r\n", colors[(us >> 9) & 07]);
}

char *itobs(int n, char *ps)
{
	int i;
	const static int size = CHAR_BIT *sizeof(int);
	for(i = size - 1; i >= 0; i--, n >>= 1)
		ps[i] = (01 & n) + '0';
	ps[size] = '\0';
	return ps;
}