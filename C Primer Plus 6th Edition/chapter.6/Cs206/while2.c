/*
Всегда помните, что сам по себе оператор while, даже если в нем используется составной оператор, синтаксически считается одним оператором. 
Он простирается от ключевого слова while до первой точки с запятой или до закрывающей фигурной скобки при наличии составного оператора.
Расставляя точки с запятой, будьте внимательны. В качестве иллюстрации взгляните на код.
*/

// правильно расставляйте точки с запятой
#include <stdio.h>
int main (void)
{
	int n = 0;
	while (n++ < 3); 		  // строка 7
	printf("n is %d\r\n", n); // строка 8
	printf("That's all this program does.\r\n", n);
	return 0;
}
/*
Как упоминалось ранее, цикл заканчивается первым оператором, простым или составным, который следует непосредственно за условием проверки. 
Поскольку в строке 7 за условием проверки находится точка с запятой, именно в этом месте цикл и заканчивается, т.к. 
отдельно стоящая точка с занятой считается оператором. 
Оператор вывода в строке 8 не является частью цикла, поэтому значение переменной n увеличивается на каждой итерации цикла, 
но выводится только после выхода из цикла.
В этом примере после условия проверки следует пустой оператор, т.е. оператор, который ничего не делает. 
В языке С отдельно стоящая точка с запятой представляет пустой оператор. 
Временами программисты намеренно применяют оператор while с пустым оператором, 
поскольку вся полезная работа выполняется при проверке условия.
*/ 