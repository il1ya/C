// использование операции sizeof
// в примере применяется определенный в стандарте с99 модификатор %z; если в вашей системе модификатор %zd не поддерживается, попробуйте 
// вместо него %u или %lu
#include <stdio.h> 
int main (void)
{
	int n = 0;
	size_t intsize;
	intsize = sizeof (int);
	printf("n = %d, n comprises %u bytes; all values int have %u bytes\r\n", n, sizeof n, intsize); // состоит из байтов; все значения имеют байтов.
	return 0;
}
