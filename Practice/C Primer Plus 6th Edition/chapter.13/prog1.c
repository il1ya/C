Вопросы для самоконтроля

1. 
Что неправильно в следующей программе:

int main(void)
{
	int *fp;
	int k;
	fp = fopen("gelatin");
	for(k = 0; k < 30; k++);
		fputs(fp, "Nanette eats gelatin");
	fclose("gelatin");
	return 0;
}

Правильная версия программы

#include <stdio.h>
int main(void)
{
	FILE *fp;
	int k;

	fp = fopen("gelatin", "w"); // или возможно режима "a".
	for(k = 0; k < 30; k++)
		fputs("Nanette eats gelatin.\r\n", fp);
	fclose(fp);
	return 0;
}

Программа должна содержать строку #include <stdio.h>, чтобы можно было использовать определения этого файла. 
Переменная fp должна быть объявлена как файловый указатель: FILE *fp;. 
Функция fopen() требует указания режима:
fopen("gelatin", "w") или, возможно режима "а". Порядок следования аргументов функции fputs() должен быть обратным. 
Для повышения удобочитаемости строка вывода должна иметь символ новой строки, поскольку fputs() не добавляет его автоматически. 
Функция fclose() требует передачи в качестве аргумента файлового указателя, а не имени файла: fclose(fp);.

2. 
Что делает следующая программа? (Предположите, что она запускается в среде командной строки.)

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, char *argv[])
{
	int ch;
	FILE *fp;

	if(argc < 2)
		exit(EXIT_FAILURE);
	if((fp = fopen(argv[1], "r")) == NULL)
		exit(EXIT_FAILURE);
	while((ch = getc(fp)) != EOF)
		if(isdigit(ch))
			putchar(ch);
		fclose(fp);
		return 0;
}

По возможности она будет открывать файл, имя которого задано в первом аргументе командной строки, 
и выводить на экран каждый присутствующий в файле цифровой символ.

3. 
Предположим, что в программе имеются следующие операторы:

#include <stdio.h>
FILE *fp1, *fp2;
char ch;

fp1 = fopen("terky", "r");
fp2 = fopen("jerky", "w");
Кроме того, предположим, что оба файла были успешно открыты. Добавьте недостающие аргументы в следующие вызовы функций:

a. ch = getc(fp1);
б. fprintf(fp2, "%c\r\n", ch);
в. putc(ch, fp2);
г. fclose(fp1);

На заметку!
Указатель fpl используется для операций ввода, поскольку он идентифицирует файл, открытый в режиме чтения. 
Подобным же образом файл, на который указывает fp2, был открыт в режиме записи, поэтому он применяется с функциями вывода.

4. 
Напишите программу, которая принимает ноль или один аргумент командной строки. Если имеется один аргумент, он интерпретируется как имя файла.
Если аргумент не указан, то должен использоваться стандартный ввод (stdin). Предположите, что ввод состоит целиком из чисел с плавающей запятой.
Программа должна вычислять и отображать среднее арифметическое значение для введенных чисел.

#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[])
{
	FILE *fp;
	double n;
	double sum = 0.0;
	int ct = 0;

	if(argc == 1)
		fp = stdin;
	else if(argc == 2)
	{
		if((fp = fopen(argv[1], "r")) == NULL)
		{
			fprintf(stderr, "Can't open %s\r\n", argv[1]); // Не удается открыть
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		fprintf(stderr, "Usage: %s [filename]\r\n", argv[0]); // Использование [имя_файла]
		exit(EXIT_FAILURE);
	}
	while(fscanf(fp, "%lf", &n) == 1)
	{
		sum += n;
		++ct;
	}
	if(ct > 0)
		printf("Average of %d values = %f\r\n", ct, cum / ct); // Среднее арифметическое значение
	else
		printf("No valid data.\r\n"); // Допустимые данные отсутсвуют
	return 0;
}

5. 
Напишите программу, которая принимает два аргумента командной строки.
Первым аргументом является символ, а вторым — имя файла. Программа должна выводить из файла только те строки, которые содержат указанный символ.
На заметку!
Строки файла идентифицируются символом новой строки '\n'. Предположим, что ни одна из строк по длине не превышает 256 символов
Возможно, потребуется использовать функцию fgets().

#include <stdio.h>
#include <stdlib.h>

#define BUF 256

int has_ch(char ch, const char *line);

int main(int argc, char *argv[])
{
	FILE *fp;
	char ch;
	char line[BUF];

	if(argc != 3)
	{
		printf("Usage: %s character filename\r\n", argv[0]);
		exit(EXIT_FAILURE);
	}
	ch = argv[1][0];
	if((fp = fopen(argv[2], "r")) == NULL)
	{
		printf("Can't open %s\r\n", argv[2]);
		exit(EXIT_FAILURE);
	}
	while(fgets(line, BUF, fp) != NULL)
	{
		if(has_ch(ch, line))
			fputs(line, stdout);
	}
	fclose(fp);
	return 0;
}
int has_ch(char ch, const char *line)
{
	while(*line)
		if(ch == *line++)
			return(1);
		return 0;
}

6. 
В чем разница между двоичными и текстовыми файлами с одной стороны и двоичными и текстовыми потоками — с другой?

Отличие между двоичными текстовым файлами определяется системнозависимыми особенностями этих файловых форматов. 
Отличие между двоичными текстовым потоками связано с преобразованиями, выполняемыми программой во время чтения или записи потоков. 
(В двоичном потоке преобразования не делаются; в текстовом потоке могут осуществляться преобразования символов новой строки и других символов.)

7.
а. В чем разница между сохранением числа 8238201 с помощью fprintf() и его сохранением посредством fwrite()?
Сохранение числа 8238201 с помощью функции fprintf() приводит к его сохранению
в виде семи символов, занимающих 7 байтов. 
При использовании функции fwrite() число сохраняется в виде двоичного предстакления 4-байтового целого числового значения.

б. В чем разница между сохранением символа S с помощью putc() и его сохранением посредством fwrite()?
Ни в чем. В обоих случаях символ сохраняется в виде 1-байтового двоичного кода.

8. 
Чем отличаются друг от друга следующие операторы?
printf("Здравствуйте, %s\n", name);
fprintf(stdout, "Здравствуйте, %s\n", name);
fprintf(stderr, "Здравствуйте, %s\n", name);

Первый оператор представляет собой всего лишь сокращенную форму записи второго оператора. 
Третий оператор выполняет запись в стандартный вывод ошибок. 
Обычно стандартные сообщения об ошибках направляются туда же, куда и стандартный вывод, но переадресация стандартного вывода нс оказывает влияния на стандартный вывод ошибок.

9. 
Режимы "а+", "r+" и "w+" открывают файл для чтения и записи. 
Какой из них лучше всего подходит для изменения содержимого, находящегося в файле?

Режим "r+" позволяет выполнять чтение и запись в любом месте файла, поэтому он наиболее подходит в данном случае. 
Режим "а+" позволяет только дописывать данные в конец файла, 
режим "w+" начинает работу с “чистого листа”, удаляя предыдущее содержимое файла.