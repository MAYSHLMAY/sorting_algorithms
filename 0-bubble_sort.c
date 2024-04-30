#include "sort.h"

/**
 * bubble_sort - Calls func
 * @array: arr to be sorted
 * @size: Size of arr
 * Return: 0
 */
void bubble_sort(int *array, size_t size)
{
	unsigned int pass = 0;
	unsigned int current_index;

	if (!array)
		return;

	while (pass < size - 1)
	{
		current_index = 0;
		while (current_index < size - pass - 1)
		{
			if (array[current_index] > array[current_index + 1])
			{
				gat(&array[current_index], &array[current_index + 1]);
				print_array(array, size);
			}
			current_index++;
		}
		pass++;
	}
}


/**
 * gat - func that swaps
 *
 * @n1: Fisrt val
 * @n2: Second val
 * Return: 0
 */
void gat(int *n1, int *n2)
{
	int tp;

	tp = *n2;
	*n2 = *n1;
	*n1 = tp;
}
