// ch06ex13v2.c

// Write a version of ch06ex13 that uses pow() from math.h.

#include <stdio.h>
#include <math.h>

int main(void)
{
	const int SIZE = 8;
    int i, j, twopows[SIZE];
	
    for (i = 0; i < SIZE; i++)
    {
        twopows[i] = pow(2, i);
    }

    i = 0;
    
    do
    {
        printf("%d ", twopows[i]);
        i++;
    }
    while (i < SIZE);

    getch();
    return 0;
}