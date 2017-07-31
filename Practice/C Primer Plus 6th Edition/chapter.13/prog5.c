/*Модифицируйте программу в листинге 13.6, чтобы вместо интерактивного интерфейса она использовала интерфейс командной строки.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFSIZE 1000

void append(FILE *source, FILE *dest);

int main(int argc, char *argv[])
{
	FILE *fa, *fs;
	int files = 0;
	char *file_app;
	char *file_src;

	if(argc < 2)
	{
		fprintf(stderr, "Usage: %s filename.\r\n", argv[0]);
		exit(1);
	}
	file_app = argv[1];

	if((fa = fopen(file_app, "a")) == NULL)
	{
		fprintf(stderr, "Can't open %s\r\n", file_app);
		exit(1);
	}

	if(setvbuf(fa, NULL, _IOFBF, BUFSIZE) != 0)
	{
		fputs("Can't create output buffer\r\n", stderr);
		exit(3);
	}
	for(int i = 2; i < argc; i++)
	{
		file_src = argv[i];
		if(strcmp(file_src, file_app) == 0)
			fputs("Can't append a file to itself", stderr);
		else if((fs = fopen(file_src, "r")) == NULL)
			fprintf(stderr, "Can't open %s\r\n", file_src);
		else
		{
			if(setvbuf(fs, NULL, _IOFBF, BUFSIZE) != 0)
			{
				fputs("Can't create input buffer\r\n", stderr);
				continue;
			}

			append(fs, fa);

			if(ferror(fs) != 0)
				fprintf(stderr, "Error in reading file %s.\r\n", file_src);
			if(ferror(fa) != 0)
				fprintf(stderr, "Error in writing file %s.\r\n", file_app);
			fclose(fs);
			files++;
			printf("File %s appended.\r\n", file_src);
			puts("Next file (empty line to quit): ");
		}
	}
	printf("Done. %d files appended.\r\n", files);
	fclose(fa);
	return 0;
}

void append(FILE *source, FILE *dest)
{
	size_t bytes;
	static char temp[BUFSIZE];
	while((bytes = fread(temp, sizeof(char), BUFSIZE, source)) > 0)
		fwrite(temp, sizeof(char), bytes, dest);
}