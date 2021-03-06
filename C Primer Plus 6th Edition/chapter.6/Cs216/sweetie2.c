/*
Цикл for собирает все три указанных выше действия (инициализацию, проверку и обновление) в одном месте. 
Используя цикл for, предыдущую программу можно заменить кодом, приведенным в листинге.
*/
// цикл for со счетчиком
#include <stdio.h>
int main (void)
{
	const int NUMBER = 22;
	int count;
	for (count = 1; count <= 5; count++)
		printf("Be my Valentine!\r\n");
	return 0;
}
/*
В круглых скобках, следующих за ключевым словом fo r, содержатся три выражения, разделенные двумя точками с запятой. 
Первое выражение — это инициализация.
Она осуществляется только один раз при первом запуске цикла for. 
Второе выражение представляет собой условие проверки; оно вычисляется перед каждым потенциальным проходом цикла. 
Когда выражение имеет значение false (когда значение счетчика count больше, чем NUMBER), цикл завершается. 
Третье выражение, которое выполняет изменение или обновление, вычисляется в конце каждой итерации.
*/ 