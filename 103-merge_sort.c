#include "sort.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * m_h - merge sort uppp
 * @array: array to be sort
 * @temp_array: to arr for holding sorted elements
 * @size: size of the array
 */
void m_h(int *array, int *temp_array, size_t size)
{
	size_t h_s = size / 2;
	size_t l_i = 0, r_i = 0, merged_index;

	if (size < 2)
		return;

	m_h(array, temp_array, h_s);
	m_h(array + h_s, temp_array + h_s, size - h_s);

	printf("%s", "Merging...\n");
	printf("%s", "[left]: ");
	print_array(array, h_s);
	printf("%s", "[right]: ");
	print_array(array + h_s, size - h_s);

	merged_index = 0;
	while (merged_index < size)
	{
		if (r_i >= size - h_s || (l_i < h_s && array[l_i] < (array + h_s)[r_i]))
		{
			temp_array[merged_index] = array[l_i];
			l_i++;
		}
		else
		{
			temp_array[merged_index] = (array + h_s)[r_i];
			r_i++;
		}
		merged_index++;
	}

	merged_index = 0;
	while (merged_index < size)
	{
		array[merged_index] = temp_array[merged_index];
		merged_index++;
	}

	printf("%s", "[Done]: ");
	print_array(array, size);
}

/**
 * merge_sort - initiate merge sort
 * @array: arr to be sort
 * @size: size of the array
 */
void merge_sort(int *array, size_t size)
{
	int *tp;

	if (!array || size < 2)
		return;

	tp = malloc(sizeof(*tp) * size);
	if (!tp)
		return;

	m_h(array, tp, size);
	free(tp);
}
