#include "sort.h"

/**
 * bubble_sort - Calls func
 * @array: arr to be sorted
 * @size: Size of arr
 * Return: 0
 */
void bubble_sort(int *array, size_t size)
{
	unsigned int ps = 0;
	unsigned int cidx;

	if (!array)
		return;

	while (ps < size - 1)
	{
		cidx = 0;
		while (cidx < size - ps - 1)
		{
			if (array[cidx] > array[cidx + 1])
			{
				gat(&array[cidx], &array[cidx + 1]);
				print_array(array, size);
			}
			cidx++;
		}
		ps++;
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
