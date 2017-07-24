// ch06ex11.c
// Write a program that reads eight integers into an array & then prints them in reverse order.
#include <stdio.h>
int main(void)
{
    const int SIZE = 8;
    int i, number[SIZE];
    printf("Enter 8 integer values separated by spaces:\r\n");
    for (i = 0; i < SIZE; i++)
    {
        scanf("%d", &number[i]);
    }
    for (i = SIZE - 1; i >= 0; i--)
    {
        printf("%d ", number[i]);
    }
    return 0;
}