/*Вспомните, что целью перечислимых типов является улучшение читабельности программы и упрощение ее сопровождения. 
Если вы имеете дело с цветами, то применение red(красный) и blue(голубой) намного информативнее, чем указание значений 0 и 1. 
Обратите внимание, что перечислимые типы предназначены для внутреннего использования. 
Если вы хотите ввести значение orange для переменной color, то должны вводить 1, а не слово orange, 
или же можно прочитать строку "orange" и заставить программу преобразовать ее в значение orange.
Из-за того, что перечислимый тип является целочисленным, переменные enum могут применяться в выражениях таким же образом, как целочисленные переменные.
Они представляют собой удобные метки для операторов case.
В листинге 14.15 приведен краткий пример использования enum. 
Пример полагается на стандартную схему присваивания значений. 
В результате константа red получает значение О, которое делает ее индексом для указателя на строку "red".
Листинг 14. 15. Программа enwn.с
*/
/*enum.c -- использование перечислимых значений*/

#include <stdio.h>
#include <string.h> 	// для strcmp(), strchr()
#include <stdbool.h> 	// средство С99

char *s_gets(char *st, int n);

enum spectrum {red, orange, yellow, green, blue, violet};

const char *colors[] = { "red", "orange", "yellow", "green", "blue", "violet" };

#define LEN 30

int main(void)
{
	char choice[LEN];
	enum spectrum color;
	bool color_is_found = false;

	puts("Enter a color (empty line to quit):"); // Введите цвет (или пустую строку для выхода)
	while(s_gets(choice, LEN) != NULL && choice[0] != '\0')
	{
/*Цикл for завершается, когда входная строка совпадает с одной из строк, на которые указывают элементы массива colors. 
Если цикл находит совпадающий цвет, то значение перечислимой переменной применяется для сопоставления с перечислимой константой, используемой в качестве метки case.*/
		for(color = red; color <= violet; color++)
		{
			if(strcmp(choice, colors[color]) == 0)
			{
				color_is_found = true;
				break;
			}
		}
		if(color_is_found)
			switch(color)
		{
			case red : puts("Roses are red.");
			break;
			case orange : puts("Poppies are orange.");
			break;
			case yellow : puts("Sunflowers are yellow.");
			break;
			case green : puts("Grass is green.");
			break;
			case blue : puts("Bluebells are blue.");
			break;
			case violet : puts("Violets are violet.");
			break;
		}
		else
			printf("I don't know about the color %s.\r\n", choice);
		color_is_found = false;
		puts("Next color, please (empty line to quit):");
	}
	puts("Goodbye!");

	return 0;
}

char *s_gets(char *st, int n)
{
	char *ret_val;
	char *find;

	ret_val = fgets(st, n, stdin);
	if(ret_val)
	{
		find = strchr(st, '\n'); // поиск новой строки
		if(find) // если адрес не равен NULL
			*find = '\0'; // поместить туда нулевой символ
		else
			while(getchar() != '\n')
				continue; // отбросить остаток строки
	}
	return ret_val;
}