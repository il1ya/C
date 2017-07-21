#include <stdio.h>
#include <inttypes.h> // поддерживает переносимые типы
int main (void)
{
	int32_t me32; // me32 -- это 32-битная переменная со знаком
	me32 = 45933945;
	printf("First, that int32_t is an int: ");  // сначала предположим, что int32_t является int
	printf("me32 = %d\r\n", me32);
	printf("Further we will not make any assumptions.\r\n"); // далее не будем делать никаких предположений
	printf("Instead use the \"macro from\" the file inttypes.h: "); // Вместо этого воспользуемся макросом из файла
	printf("me32 = %" PRId32 "\n", me32);
	return 0;
}