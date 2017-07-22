#include <stdio.h>
#define PI 3.141593
int main (void)
{
	int number = 7;
	float pies = 12.75;
	int cost = 7800;
	printf("%d participants ate competition %0.2f pies with cherries\r\n", number, pies); // %d участники соревнования сьели %f пирожков с вишней
	printf("the value of pi=%f\r\n", PI); // значение PI =
	printf("Bye! Your art is much expensive\r\n"); //Bye! Your art is much expensive
	printf("%c%d", '$', cost * 2);
	return 0;
}