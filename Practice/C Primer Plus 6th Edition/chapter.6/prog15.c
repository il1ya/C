// ch06ex15.c

/* Write a program that reads in a line of input & then prints the line in reverse order. You can store the input in an array of char; assume that the line is no longer than 255 characters. recall that you can use scanf() with the %c specifier to read a character at a time from input and that the newline character (\n) is generated when you press the Enter key. */

#include <stdio.h>
#include <string.h>

int main(void)
{
	const int SIZE = 255;
    char arr[SIZE];
    int length;
	
    printf("Enter a line of input to be reversed: ");

    int i = 0;
	
    while (scanf("%c", &arr[i]) == 1 && arr[i] != '\n')
    {
        i++;
    }

    length = strlen(arr);

    for (i = (length - 1); i >= 0; i--)
    {
        printf("%c", arr[i]);
    }

    getch();
    return 0;
}