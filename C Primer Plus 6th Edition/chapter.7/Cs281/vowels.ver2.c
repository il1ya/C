#include <stdio.h>
#include <ctype.h>
int main(void)
{
	char ch;
	int a_ct, e_ct, i_ct, o_ct, u_ct;
	a_ct = e_ct = i_ct = o_ct = u_ct = 0;
	printf("Enter some text; enter # to quit.\r\n");
	while ((ch = getchar()) != '#')
	{
		ch = toupper(ch);
		switch(ch)
		{
			case 'A' : a_ct++;
						break;
			case 'E' : e_ct++;
						break;
			case 'I' : i_ct++;
						break;
			case 'O' : o_ct++;
						break;
			case 'U' : u_ct++;
						break;
			default : break;
		} // конец оператора switch
	} // конец цикла while
	printf("number of vowels:    A    E    I    O    U\r\n");
	printf("                  %4d %4d %4d %4d %4d", a_ct, e_ct, i_ct, o_ct, u_ct);
	return 0;
}