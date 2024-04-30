#include "sort.h"

/**
 * selection_sort - Calls func
 * @array: Arr to be sort
 * @size: Size of arr given
 * Return: 0
 */
void selection_sort(int *array, size_t size)
{
	unsigned int ps = 0;
	unsigned int midx;

	if (!array)
		return;

	while (ps < size - 1)
	{
		midx = ps;
		unsigned int cidx = ps + 1;
		while (cidx < size)
		{
			if (array[cidx] < array[midx])
				midx = cidx;
			cidx++;
		}

		if (ps != midx)
		{
			gat(&array[midx], &array[ps]);
			print_array(array, size);
		}

		ps++;
	}
}

/**
 * gat - Function that swaps two values
 *
 * @n1: Fisrt value
 * @n2: Second value
 * Return: 0
 */
void gat(int *n1, int *n2)
{
	int tp;

	tp = *n2;
	*n2 = *n1;
	*n1 = tp;
}
