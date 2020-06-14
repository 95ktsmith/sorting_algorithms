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
 * selection_sort - sorts an array using selection sort algorithm
 * @array: Pointer to array to be sorted
 * @size: Size of the array
 */
void selection_sort(int *array, size_t size)
{
	unsigned int index = 0, lowest, current;

	if (array == NULL || size < 2)
		return;

	while (index < size)
	{
		lowest = index;
		current = index;

		while (current < size)
		{
			if (array[current] < array[lowest])
				lowest = current;
			current++;
		}
		if (array[lowest] < array[index])
		{
			swap(&(array[index]), &(array[lowest]));
			print_array(array, size);
		}
		index++;
	}
}
