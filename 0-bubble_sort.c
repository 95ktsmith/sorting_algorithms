#include "sort.h"

/**
 * swap - swaps the value of two integers
 * @a: Address of the first integer
 * @b: Address of the second
 */
void swap(int *a, int *b)
{
	int c;

	c = *a;
	*a = *b;
	*b = c;
}

/**
 * bubble_sort - Sorts an array of ints using bubble sort algorithm
 * @array: Array to sort
 * @size: Size of the array
 */
void bubble_sort(int *array, size_t size)
{
	unsigned int index, sorted = 0;

	if (array == NULL || size < 2)
		return;

	while (!sorted)
	{
		sorted = 1;
		for (index = 0; index < size - 1; index++)
		{
			if (array[index] > array[index + 1])
			{
				swap(&(array[index]), &(array[index + 1]));
				print_array(array, size);
				sorted = 0;
			}
		}
	}
}
