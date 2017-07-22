#include <stdio.h>
#define BLURB "Authentic imitation!"
int main (void)
{
	printf("[%2s]\r\n", BLURB);
	printf("[%24s]\r\n", BLURB);
	printf("[%24.5s]\r\n", BLURB);
	printf("[%-24.5s]\r\n", BLURB);
	return 0;
}