// ch06ex14.c

/* Write a program that creates two eight-element arrays of doubles & uses a loop to let the user enter values for the eight elements of the first array. Have the program set the elements of the second array to the cumulative totals of the elements of the first array. For example, the fourth element of the second array should equal the sum of the first four elements of the first array, & the fifth element of the second array should equal the sum of the first five elements of the first array. (It's possible to do this with nested loops, but by using the fact that the fifth element of the second array equals the fourth element of the second array plus the fifth element of the first array, you can avoid nesting & just use a single loop for this task.) Finally, use loops to display the contents of the two arrays, with the first array displayed on one line & with each element of the second array displayed below the corresponding element of the first array. */

#include <stdio.h>

int main(void)
{
	const int SIZE = 8;
 	double arr[SIZE], arr_cumul[SIZE];
 	int i;

	printf("Enter %d numbers:\n", SIZE);
	
	for (i = 0; i < SIZE; i++)
	{
		printf("value #%d: ", i + 1);
		scanf("%lf", &arr[i]);
	}
	
	arr_cumul[0] = arr[0];
	
	for (i = 1; i < SIZE; i++)
	{
		arr_cumul[i] = arr_cumul[i-1] + arr[i];
	}

 	for (i = 0; i < SIZE; i++)
	{
		printf("%8g ", arr[i]);
	}
	
	printf("\n");
	 
	for (i = 0; i < SIZE; i++)
	{
		printf("%8g ", arr_cumul[i]);
	}
	
	printf("\n");
	
	getch();
	return 0;
}