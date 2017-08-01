1. Что неправильно в следующем шаблоне?
structure 
{
	char itable;
	int num[20];
	char * togs
}
Ответ.

1. struct name
{
	char itable;
	int num[20];
	char *togs;

};
Правильным ключевым словом является struct, а не structure. 
Шаблон требует наличия либо дескриптора перед открывающей скобкой, либо имени переменной после закрывающей скобки. 
Кроме того, символ точки с запятой должен присутствовать после выражения *togs и в конце шаблона.

2. Ниже приведен фрагмент программы. Что он выведет?

#include <stdio.h>
struct house
{
	float sqft;
	int rooms;
	int stories;
	char address[40];
};
int main(void)
{
	struct house fruzt = { 1560.0, 6, 1, "22 Spiffo Road" };
	struct house *sign;
	sign = &fruzt;
	printf("%d %d\r\n", fruzt.rooms, sign -> stories);
	printf("%s \r\n", fruzt.address);
	printf("%c %c\r\n", sign -> address[3], fruzt.address[4]);
	return 0;
}
ответ:
6 1
22 Spiffo Road
S p

3. Разработайте шаблон структуры, которая будет содержать название месяца, его трехбуквенную аббревиатуру, количество дней в месяце и его номер.

struct name
{
	char month[20];
	char abbreviation[3];
	int day;
	int number;
};

4. Определите массив из 12 структур вида, описанного в вопросе 3, и инициализируйте ее для года, который не является високосным.

struct name names[12] =
{
	{ "January", "jan", 31, 1},
	{ "February", "feb", 28, 2},
	{ "March", "mar", 31, 3},
	{ "April", "apr", 30, 4},
	{ "May", "may", 31, 5},
	{ "June", "jun", 30, 6},
	{ "July", "jul", 31, 7},
	{ "August", "aug", 31, 8},
	{ "September", "sem", 30, 9},
	{ "October", "oct", 31, 10},
	{ "November", "nov", 30, 11},
	{ "December", "dec", 31, 12}
};

5. Напишите функцию, которая после получения номера месяца возвращает общее количество дней с начала года до конца указанного месяца. 
Предположите, что шаблон структуры, описанный в вопросе 3, и подходящий массив таких структур объявлены внешне.

5. Ответ

extern struct month months[];
int days(int month)
{
	int index, total;
	if(month < 1 || month > 12)
		return(-1); /*сигнал ошибки*/
	else
	{
		for(index = 0; total = 0; index < month; index++)
			total += months[index].days;
		return(total);
	}
}

6. 
а. Имея показанное ниже определение typedef, объявите 10-элементный массив указанных структур. 
Затем с помощью присваивания индивидуальных членов сделайте так, чтобы третий элемент этого массива описывал объектив марки
Remarkatar с фокусным расстоянием 500 мм и диафрагмой f/2.0.

typedef struct lens { /*дескриптор структуры lens*/
	float foclen;	  /*фокусное расстояние в миллиметрах*/
	float fstop;	  /*диафрагма*/
	char brand[30];		/*марка производителя*/
}LENS;

Чтобы можно было использовать функцию strcpy(), включите заголовочный файл string.h:
LENS bigEye[10];
bigEye[2].foclen = 500;
bigEye[2].fstop = 2.0;
strcpy(bigEye[2].brand, "Remarkatar");

б. Повторите часть а), но воспользуйтесь в объявлении списком инициализации
с назначенным инициализатором вместо написания отдельных операторов присваивания для каждого члена.

LENS bigEye[10] = { [2] = {500, 2, "Remarkatar"} };

8. Взгляните на следующие объявления:
struct fullname
{
	char fname[20];
	char lname[20];
};
struct bard
{
	struct fullname name;
	int born;
	int died;
};
struct bard willie;
struct bard *pt = &willie;

а. Идентифицируйте член born структуры willie с помощью идентификатора willie.
a. willie.born

б. Идентифицируйте член born структуры willie с помощью идентификатора pt.
pt -> born

в. С помощью функции scanf() прочитайте значение для члена born, используя идентификатор willie.
scanf("%d", &willie.born);

г. С помощью функции scanf() прочитайте значение для члена born, используя идентификатор pt.
scnaf("%d", &pt -> born);

д. С помощью функции scanf() прочитайте значение для члена lname структуры name, используя идентификатор willie.
scanf("%s", willie.name.lname);

е. С помощью функции scanf() прочитайте значение для члена lname структуры name, используя идентификатор pt.
scanf("%s", pt -> name.lname);

ж. Создайте идентификатор для третьей буквы фамилии того, кто описан переменной willie.
willie.name.fname[2]

з. Напишите выражение, которое представляет общее количество букв в имени и фамилии того, кто описан переменной willie.
strlen(willie.name.fname) + strlen(willie.name.lname);

9. 
Определите шаблон структуры, подходящий для хранения следующих элементов:
марка автомобиля, его мощность в лошадиных силах, экологический рейтинг, колесная база и год сборки. В качестве дескриптора шаблона используйте car.

struct car
{
	char mark[20];
	float power;
	float ecological;
	float wheelbase;
	int year;
};

10.
Предположим, что имеется следующая структура:

struct gas
{
	float distance;
	float gals;
	float mpg;
};

а. 
Напишите функцию, которая принимает аргумент struct gas. 
Предположите, что передаваемая структура содержит информацию distance и gals. 
Эта функция должна вычислять корректное значение для члена mpg и возвращать уже заполненную структуру.
б. 
Напишите функцию, которая принимает в качестве аргумента адрес struct gas. 
Предположите, что передаваемая структура содержит информацию distance и gals. 
Эта функция должна вычислять корректное значение для члена mpg и присваивать его.

struct gas
{
	float distance;
	float gals;
	float mpg;
};

struct gas mpgs(struct gas trip)
{
	if(trip.gals > 0)
		trip.mpg = trip.distance / trip.gals;
	else
		trip.mpg = - 1.0;
	return trip;
}
void set_mpgs(struct gas *ptrip)
{
	if(ptrip -> gals > 0)
		ptrip -> mpg = ptrip -> distance / ptrip -> gals;
	else
		ptrip -> mpg = - 1.0;
}
Обратите внимание, что первая функция не может напрямую изменять значения
из вызывающей программы, поэтому для передачи информации необходимо использовать возвращаемое значение:

struct gas idaho = { 430.0, 14.8 }; // установка значений двух первых членов
idaho = mpgs(idaho);				// переустановка структуры
Однако вторая функция обращается к исходной структуре непосредственно:
struct gas ohio = { 583, 17.6 }; // установка значений двух первых членов
set_mpgs(ohio); // установка значения третьего члена

11. 
Объявите перечисление с дескриптором choices, которое устанавливает перечислимые константы no, yes и maybe в 0, 1 и 2 соответственно.
enum choices { no, yes, maybe };

12. Объявите указатель на функцию, которая возвращает указатель на char и принимает в качестве аргументов указатель на char и значение char.

char *(pfun)(char *, char);

13. Объявите четыре функции и инициализируйте массив указателей на них.
Каждая функция должна принимать два аргумента double и возвращать значение double.
Кроме того, продемонстрируйте два способа использования массива для вызова второй функции с аргументами 10.0 и 2.5.


double one(double, double);
double two(double, double);
double three(double, double);
double four(double, double);

double(*pfl[4])(double, double) = { one, two, three, four };

Чтобы упростить код, последнюю строку можно заменить следующими двумя строками:
typedef double (*ptype)(double, double);
ptype pf[4] = { one, two, three, four };

Функция diff() вызывается слудующим образом:
pfl[1](10.0, 2.5); 		// первая форма записи
(*pfl[1])(10.0, 2.5); 	// эквивалентная форма записи