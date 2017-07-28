/*В листинге 10.13 представлены восемь базовых операций, которые можно выполнять над переменными типа указателя. 
В дополнение к этим операциям можно использовать операции отношений для сравнения указателей.*/
// ptr_ops.c -- операции над указателями
#include <stdio.h>
int main(void)
{
	int urn[5] = { 100, 200, 300, 400, 500 };
	int *ptr1, *ptr2, *ptr3;
	ptr1 = urn; // присваивание указателю адреса
	ptr2 = &urn[2]; // то же самое
					// разыменование указателя и получение
					// адреса указателя
	printf("pointer value, dereferenced pointer, pointer address:\r\n");
	printf("ptr1 = %p, *ptr1 = %d, &ptr1 = %p\r\n", ptr1, *ptr1, &ptr1);
	// сложение указателей
	ptr3 = ptr1 + 4;
	printf("\r\nadding an int to a pointer:\r\n");
	printf("ptr1 + 4 = %p, *(ptr4 + 3) = %d\r\n", ptr1 + 4, *(ptr1 + 3));
	ptr1++; // инкрементирование указателя
	printf("\r\nvalues after ptr1++:\r\n");
	printf("ptr2 = %p, *ptr2 = %d, &ptr2 = %p\r\n", ptr2, *ptr2, &ptr2);
	ptr2--; // декрементирование указателя
	printf("\r\nvalues after --ptr2:\r\n");
	printf("*ptr2 = %p, *ptr2 =  %d, &ptr2 =  %p\r\n", ptr2, *ptr2, &ptr2);
	--ptr1; // восстановление исходного значения
	++ptr2; // восстановление исходного значения
	printf("\r\nPointers reset to original values:\r\n");
	printf("ptr1 = %p, ptr2 = %p\r\n", ptr1, ptr2);
	// вычитание одного указателя из другого
	printf("\r\nsubtracting one pointer from another:\r\n");
	printf("ptr2 = %p, ptr1 = %p, ptr2 - ptr1 = %td\r\n", ptr2, ptr1, ptr2 - ptr1);
	// вычитание целого значения из указателя
	printf("\r\nsubtracting an int from a pointer:\r\n");
	printf("ptr3 = %p, ptr3 - 2 = %p\r\n", ptr3, ptr3 - 2);
	return 0;
}