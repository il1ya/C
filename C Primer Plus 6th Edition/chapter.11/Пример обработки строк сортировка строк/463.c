/*Давайте решим практическую задачу сортировки строк в алфавитном порядке. Эта задача возникает при подготовке списков фамилий, во время индексации и во многих других ситуациях. 
Одним из основных инструментов в такой программе является функция strcmp(), поскольку она может применяться для выяснения порядка следования двух строк. 
Генеральный план предполагает чтение массива строк, их сортировку и вывод.
Ранее мы представляли схему для чтения строк, и с этого мы начнем настоящую программу. С выводом строк никаких проблем не связано. 
Мы будет использовать один из стандартных алгоритмов сортировки, который объясним позже. 
Кроме того, мы применим также несколько необычный прием; посмотрите, сможете ли вы самостоятельно обнаружить его. Программа показана в листинге 11.29.*/
// Листинг 11.29. Программа sort_str.c
// sort_str.c -- считывает строки и сортирует их
#include <stdio.h>
#include <string.h>
#define SIZE 81 /*лимит на длину строки, включая \0*/
#define LIM 20 /*максимальное количество читаемых строк*/
#define HALT "" /*нулевая строка для прекращения ввода*/
void stsrt(char *strings[], int num); /*функция сортировки строк*/
char *s_gets(char *st, int n);
int main(void)
{
	char input[LIM][SIZE]; /*массив для сохранения входных данных*/
	char *ptstr[LIM]; /*массив переменных типа указателя*/
	int ct = 0;	/*счетчик ввода*/
	int k; /*счетчик вывода*/
	printf("input up to %d lines, and i will sort them.\r\n", LIM);
	printf("To stop, press the Enter key at a line's stars.\r\n");
	while(ct < LIM && s_gets(input[ct], SIZE) != NULL && input[ct][0] != '\0')
	{
		ptstr[ct] = input[ct]; /*установка указателей на строки*/
		ct++;
	}
	stsrt(ptstr, ct); /*сортировщик строк*/
	puts("\r\nHere's the sorted list:\r\n");
	for(k = 0; k < ct; k++)
		puts(ptstr[k]); /*отсортированные указатели*/
		return 0;
}
/*функция сортировки указателей на строки*/
void stsrt(char *strings[], int num)
{
	char *temp;
	int top, seek;
	for(top = 0; top < num - 1; top++)
		for(seek = top + 1; seek < num; seek++)
			if(strcmp(strings[top], strings[seek]) > 0)
			{
				temp = strings[top];
				strings[top] = strings[seek];
				strings[seek] = temp;
			}
}
char *s_gets(char *st, int n)
{
	char *ret_val;
	int i = 0;
	ret_val = fgets(st, n, stdin);
	if(ret_val)
	{
		while(st[i] != '\n' && st[i] != '\0')
			i++;
		if(st[i] == '\n')
			st[i] = '\0';
		else // требуется наличие words[i] == '\0'
			while(getchar() != '\n')
				continue;
	}
	return ret_val;
}
/*
that I was where I would be,
Then would I be where I am not;
But where I am I must be,
And where I would be I can not.

Here's the sorted list:

And where I would be I can not.
But where I am I must be,
O that I was where I would be,
Then would I be where I am not;
*/

/*Сложная часть этой программы связана с тем, что вместо самих строк переупорядочиваются указатели на эти строки. Давайте посмотрим, что это означает. 
Первоначально элемент ptrst[0] установлен в input[0] и т.д. 
В результате указатель ptrst[i] ссылается на первый символ массива input [i]. Каждый элемент input[i] представляет собой массив из 81 элемента, 
а каждый элемент ptrst[i] — отдельную переменную.
Процедура сортировки переупорядочивает ptrst, оставляя input незатронутым.
Если, например, в алфавитном порядке input[1] находится перед input[0], то программа переключит указатели в ptrst, 
из-за чего ptrst[0] будет ссылаться на начало input[1], а ptrst[1] — на начало input[0]. 
Это намного проще, чем использование функции strcpy() для обмена содержимым двух строк в input. 
На рис. 11.6 представлена еще одна точка зрения на этот процесс. Данный процесс также обладает тем преимуществом, что сохраняет первоначальный порядок в массиве input.*/

/*Алгоритм сортировки выбором
Для сортировки указателей мы применяем алгоритм сортировки выбором. Идея заключается в использовании цикла for для сравнения всех элементов по очереди с первым. 
Если сравниваемый элемент предшествует текущему первому элементу, они меняются местами. 
К моменту, когда достигается конец цикла, первый элемент содержит указатель на строку, находящуюся первой в последовательности сопоставления машины. 
Затем внешний цикл for повторяет процесс, начиная на этот раз со второго элемента input. 
Когда внутренний цикл завершится, во втором элементе ptrst окажется указатель на строку, находящуюся второй в последовательности сопоставления.
Процесс продолжается до тех пор, пока не будут отсортированы все элементы.

Давайте более подробно рассмотрим сортировку выбором. Ниже показан ее набросок в псевдокоде:
для n = первый до n = предпоследний элемент
найти наибольшее из оставшихся чисел и поместить его в n-й элемент

Это работает следующим образом. Начините с n = О. Просмотрите весь массив, найдите наибольшее число и поменяйте его и первый элемент местами. 
Далее установите n = 1 и просмотрите все элементы массива кроме первого. Найдите наибольший из оставшихся элементов и поменяйте его и второй элемент местами. 
Продолжайте этот процесс до тех пор, пока не достигнете предпоследнего элемента. 
Теперь остались только два элемента. Сравните их и поместите больший в позицию предпоследнего элемента. 
В итоге наименьший элемент занял свою окончательную позицию.
Выглядит так, что это задача для цикла for, но мы еще должны более подробно описать процесс “найти и поместить". 
Один из способов выбора наибольшего значения из числа оставшихся предполагает сравнение первого и второго элементов в оставшейся части массива. 
Если второй элемент больше первого, выполните обмен их значениями. Далее сравните первый элемент с третьим. 
Если третий элемент больше, произведите обмен их значениями. Каждый обмен приводит к перемещению большего элемента ближе к началу списка. 
Продолжайте действовать в подобной манере до тех пор, пока не произойдет сравнение первого элемента с последним. 
После завершения наибольшее значение окажется в первом элементе оставшегося массива. 
Итак, вы отсортировали массив для первого элемента, однако остальные элементы находятся в беспорядке. 
Вот как можно представить процедуру с помощью псевдокода:
для n = предпредпоследний элемент 
сравнить n-й элемент с первым элементом;
если n-й элемент больше, выполнить обмен их значениями

Этот процесс выглядит как еще один цикл for. Он должен быть вложен в первый цикл for. 
Внешний цикл указывает, какой элемент массива должен быть заполнен. а внутренний цикл находит значение, которое в него следует поместить. 
Объединив вместе обе части псевдокода и переведя его на С, мы получаем функцию, показанную в листинге 11.29. 
Кстати, в библиотеке С имеется более совершенная функция сортировки по имени qsort(). 
Помимо прочего она принимает указатель на функцию, выполняющую сравнение при сортировке. Ее работа будет продемонстрирована в главе 1б.*/
