/*
Данная программа читает букву и отвечает выводом названия животного, которое начинается с такой буквы.
*/
// использование оператора switch
#include <stdio.h>
#include <ctype.h>
int main(void)
{
	char ch;
	printf("Give me a letter of the alphabet, and I will give "); // Дайте мне букву алфавита, и я укажу вам
	printf("an animal name\r\nbeginning with that letter.\r\n"); // название животного, начаинающееся с этой буквы
	printf("Please type in a letter; tupe # to end my act.\r\n"); // Введите букву или # для заверщения
	while ((ch = getchar()) != '#')
	{
		if('\n' == ch)
			continue;
		if (islower(ch)) // только строчные буквы
			switch (ch)
		{
			case 'a' :
			printf("argali, a wild sheep of Asia\r\n"); // архар, дикий горный азиатский баран
			break;

			case 'b' :
			printf("babirus, a wild pig of Malay\r\n"); // бабирусса, дикая малайская свинья
			break;

			case 'c' :
			printf("coati, racoonlike mammal\r\n"); // коати, носуха обыкновенная
			break;

			case 'd' :
			printf("desman, aquatic, molelike critter\r\n"); // выхухоль, водоплавающее существо
			break;

			case 'e' :
			printf("echidna, the spiny anteater\r\n"); // ехидна, игольчатый муравьед
			break;

			case 'f' :
			printf("fisher, brownish marten\r\n"); // рыболов, светло-коричневая куница
			break;

			default :
			printf("That's a stumper!\r\n"); // Вопрос озадачил!
			//  конец оператора выбора
		}
		else
			printf("I recognize only lowercase letters.\r\n"); // Распознаются только строчные буквы
		while (getchar() != '\n')
			continue; // пропустить оставшуюся часть входной строки
		printf("Please type another letter or a #.\r\n"); // Введите следующую букву или # для завершения
	}// конец цикла while
	printf("Buy!\r\n"); // До свидания!
	return 0;
}