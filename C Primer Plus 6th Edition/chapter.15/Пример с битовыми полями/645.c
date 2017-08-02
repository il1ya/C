/*В листинге 15.3 структура box_props используется в простом примере. 
Директивы #define применяются для создания символических констант, представляющих возможные значения членов. 
Обратите внимание, что основные цвета представлены включением единственного бита. 
Остальные цвета могут представляться комбинациями основных цветов. 
Например, пурпурный цвет создается включением битов синего и красного цветов, поэтому его можно записать как комбинацию BLUE | RED.*/

// Листинг 15.3. Программа fields.c
/*fields.c -- определение и использование полей*/
#include <stdio.h>
#include <stdbool.h> // C99, определение bool, true, false

/*стили линии*/
#define SOLID 0
#define DOTTED 1
#define DASHED 2

/*основые цвета*/
#define BLUE 4
#define GREEN 2
#define RED 1

/*смешанные цвета*/
#define BLACK 0
#define YELLOW (RED | GREEN)
#define MAGENTA (RED | BLUE)
#define CYAN (GREEN | BLUE)
#define WHITE (RED | GREEN | BLUE)

const char *colors[8] = { "black", "red", "green", "yellow", "blue", "purple", "blue", "white" };

struct box_props
{
	bool opaque					: 1;		// или unsigned int (до С99)
	unsigned int fill_color		: 3;
	unsigned int 				: 4;
	bool show_border 			: 1;		// или unsigned int (до С99)
	unsigned int border_color	: 3;
	unsigned int border_style 	: 2;
	unsigned int				: 2;
};
void show_settings(const struct box_props * pb);
int main(void)
{
	/*создание и инициализация структуры box_props*/
/*Отметим несколько моментов. Прежде всего, структуру битовых полей можно инициализировать с использованием обычного для структур синтаксиса:
struct box_props Ьох = { YES, YELLOW , YES, GREEN, DASHED };*/
	struct box_props box = { true, YELLOW, true, GREEN, DASHED };
	printf("Original box settings:\r\n"); // исходные настройки окна:
	show_settings(&box);

	box.opaque = false;
	box.fill_color = WHITE;
	box.border_color = MAGENTA;
	box.border_style = SOLID;
	printf("\r\nModified box settings:\r\n"); // Измененные настройки окна
	show_settings(&box);
	return 0;
}
void show_settings(const struct box_props *pb)
{
	printf("Box %s.\r\n", pb -> opaque == true ? "opaque" : "transparent"); // непрозрачно. прозрачно
/*Обратите внимание, что массив colors бьи определен так, чтобы каждое значение индекса соответствовало строковому представлению названия цвета, имеющего значение
индекса, которое совпадает с числовым значением цвета. Например, индекс 1 соответствует строке "красный" и константа RED имеет значение 1.*/
	printf("The fill color is %s.\r\n", colors[pb -> fill_color]); // Цвет фона
	printf("Border %s.\r\n", pb -> show_border == true ? "shown" : "not shown");
	printf("The border color is %s.\r\n", colors[pb -> border_color]); // цвет рамки
	printf("The border style is "); // стиль рамки
	switch(pb -> border_style)
	{
		case SOLID 		: printf("solid.\r\n");  break; // сплошной
		case DOTTED 	: printf("dotted.\r\n"); break; // пунктриный
		case DASHED 	: printf("dashed.\r\n"); break; // штриховой
		default 		: printf("unknown type.\r\n");  // неизвестного типа
	}
}