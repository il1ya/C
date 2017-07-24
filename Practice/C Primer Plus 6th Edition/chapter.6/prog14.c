// Что выведет следующая программа?
#include <stdio.h>
int main (void)
{
	int k;
	for (k = 1, printf("%d: Hi!\r\n", k); printf("k = %d\r\n", k), k * k < 26; k += 2, printf("Now k is %d\r\n", k))
	printf("k is %d in the loop\r\n", k);
	return 0;
}
/*
Вывод программы имеет следующий вид:
1: Hi !
к = 1
к is 1 in the loop
Now к is 3
к = 3
к is 3 in the loop
Now к is 5
к = 5
к is 5 in the loop
Now к is 7
к = 7
*/  