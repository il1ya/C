#include <stdio.h> // автоматическое преобразование типов
int main (void)
{
	char ch;
	int i;
	float fl;
	fl = i = ch = 'C';										/* строка 9 */
	printf("ch = %c, i = %d, fl = %2.2f\r\n", ch, i, fl);	/* строка 10 */
	ch = ch + 1;											/* строка 11 */
	i = fl + 2 * ch;										/* строка 12 */
	fl = 2.0 * ch + i;										/* строка 13 */
	printf("ch = %c, i = %d, fl = %2.2f\r\n", ch, i, fl);	/* строка 14 */
	ch = 11;												/* строка 15 */
	printf("Now ch = %c\r\n", ch);							/* строка 16 */
	ch = 80.89;												/* строка 17 */			
	printf("Now ch = %c\r\n", ch);							/* строка 18 */
	return 0;
}