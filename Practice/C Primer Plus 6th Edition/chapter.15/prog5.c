/*5. 
Напишите функцию, которая циклически сдвигает биты значения типа unsigned int на указанное количество позиций влево. 
Например, функция rotate_ l(х,4) перемещает биты значения х на четыре позиции влево, при этом утраченные слева биты воспроизводятся в правой части комбинации.
Другими словами, вытесненный старший бит помещается в позицию младшего бита. Протестируйте функцию в какой-нибудь программе.*/

#include <stdio.h>
int rotate(int num, int bit);
int main(void)
{
	int number, bits;
	int newnum;
	puts("Please enter a number and rotate bits: ");
	scanf("%d %d", &number, &bits);
	newnum = rotate(number, bits);
	printf("Rotated number is %d.\r\n", newnum);
	return 0;
}

int rotate(int num, int bit)
{
	int bs = 0;
	int move;
	int mask = 1;
	int temp = num;
	while(temp > 0)
	{
		temp >>= 1;
		bs++;
	}
	for(int i = 0; i < bs; i++)
		mask = (mask << 1) | 1;
	move = num >> (bs - bit%bs);
	num <<= bit;
	num &= mask;
	num |= move;
	return num;
}