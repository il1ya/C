/*4. Разработайте и протестируйте функцию, подобную описанной в упражнении 3, за исключением того, что она принимает второй параметр, указывающий максимальное
количество символов, которые могут быть прочитаны.*/
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdio_ext.h>

const char * search_char(const char *, const char);

int main(void)
{
    const unsigned int LEN = 128;
    char str[LEN];
    char ch;
    const char * ptr;

    while(true)
    {
        puts("Input a string('Enter' to quit):");
        __fpurge(stdin);
        fgets(str, LEN, stdin);
        if (*str == '\n')
        {
            break;
        }
        puts("Input a char to search");
        __fpurge(stdin);
        ch = getchar();
        ptr = search_char(str, ch);
        if (ptr == NULL)
        {
            puts("Not found!");
        }
        else
        {
            puts("Found!");
            printf("Char: %c\n", *ptr);
            printf("Address: %p\n", ptr);
        }
    }

    return 0;
}

const char * search_char(const char * str, const char ch)
{
    const char * ptr = str;

    while (*ptr != '\0')
    {
        if (*ptr == ch)
        {
            break;
        }
        ptr++;
    }

    if (*ptr != '\0')
    {
        return ptr;
    }
    else
    {
        return NULL;
    }
}