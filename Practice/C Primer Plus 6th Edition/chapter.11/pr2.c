#include <stdio.h>
int main(void)
{
	char note[] = "See you tomorrow at the cafe. ";
	char *ptr;
	ptr = note;
	puts(ptr);
	puts(++ptr);
	note[7] = '\0';
	puts(note);
	puts(++ptr);
	return 0;
}