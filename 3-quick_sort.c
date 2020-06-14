#include "sort.h"
#include <stdio.h>
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
 * partition - partitions an array using the Lomuto partition scheme
 * @array: array to partition
 * @size: size of the array
 * Return: Index the pivot has been moved to
 */
unsigned int partition(int *array, size_t size)
{
	unsigned int index = 0, swap_index = 0;
	static size_t array_size, set_vars = 1;
	static int *array_start;

	if (set_vars)
	{
		array_start = array;
		array_size = size;
		set_vars = 0;
	}

	while (index < size)
	{
		if (array[index] < array[size - 1])
		{
			if (index != swap_index)
			{
				swap(&(array[index]), &(array[swap_index]));
				print_array(array_start, array_size);
			}
			swap_index++;
		}
		index++;
	}
	if (array[index - 1] < array[swap_index])
	{
		swap(&(array[index - 1]), &(array[swap_index]));
		print_array(array_start, array_size);
	}
	return (swap_index);
}

/**
 * quick_sort - Sorts an array of integers using the quick sort algorithm
 * @array: Array to sort
 * @size: Size of the array
 */
void quick_sort(int *array, size_t size)
{
	unsigned int part;

	if (array == NULL || size < 2)
		return;

	part = partition(array, size);

	quick_sort(array, part);
	quick_sort(array + part + 1, size - part - 1);
}
