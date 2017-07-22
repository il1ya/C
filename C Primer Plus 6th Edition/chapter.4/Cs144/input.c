#include <stdio.h> // ситуации, когда должен использоваться символ &
int main (void)
{
	int age; // переменная
	float assets; // переменная
	char pet[30]; // строка
	printf("Enter information about your age the amount in the bank and your favorite animal\r\n"); // Введите информацию о своем возрасте, сумме в банке и любимом животном
	scanf("%d %f", &age, &assets); // здесь должен быть указан &
	scanf("%s", pet); // для строкового массива символ & не нужен
	printf("%d $%.2f %s", age, assets, pet);
	return 0;
}