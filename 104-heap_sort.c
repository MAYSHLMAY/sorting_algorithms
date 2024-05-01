#include "sort.h"

/**
 * heap_sort - Sorting arr using heap sort algor
 * @array: arr to be sort
 * @size: Size of the arr
 * Return: 0
 */
void heap_sort(int *array, size_t size)
{
	int i;

	if (!array || size < 2)
		return;

	i = size / 2;
	while (i >= 0)
	{
		heapify(array, size, i, size);
		i--;
	}

	i = size - 1;
	while (i >= 0)
	{
		gat(&array[i], &array[0]);
		if (i != 0)
			print_array(array, size);
		heapify(array, i, 0, size);
		i--;
	}
}

/**
 * heapify - Recursive function to sort btree
 * @array: arr to be sort as btree
 * @las: Last node in btree
 * @pri: First node of btree
 * @size: Size of the arr to sort
 * Return: 0
 */
void heapify(int *array, int las, int pri, size_t size)
{
	int max_idx = pri;
	int left_idx = 2 * pri + 1;
	int right_idx = 2 * pri + 2;

	if (!array || size < 2)
		return;

	switch (left_idx < las && array[left_idx] > array[max_idx])
	{
		case 1:
			max_idx = left_idx;
			break;
		default:
			break;
	}

	switch (right_idx < las && array[right_idx] > array[max_idx])
	{
		case 1:
			max_idx = right_idx;
			break;
		default:
			break;
	}

	if (pri != max_idx)
	{
		gat(&array[pri], &array[max_idx]);
		print_array(array, size);
		heapify(array, las, max_idx, size);
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
	int tempo;

	tempo = *n2;
	*n2 = *n1;
	*n1 = tempo;
}
