#include "sort.h"
#include <limits.h>
#include <stdlib.h>



/**
 * compare - Create param for qsort
 * @a: fir num
 * @b: sec num
 * Return: num
 */
int compare(const void *a, const void *b)
{
	return (*(int *)a - *(int *)b);
}

/**
 * maxsteel - Find val_of_max in arr of ints
 * @array: array to find val_of_max val
 * @size: size of the array
 * Return: 0
 */
int maxsteel(int *array, int size)
{
	qsort(array, size, sizeof(int), compare);
	return (array[size - 1]);
}

/**
 * counting_sort - sort an array
 * @array: array to sort
 * @size: size of array to sort
 */
void counting_sort(int *array, size_t size)
{
	int *ca, *sorted_array;
	size_t i = 0, m_v;

	if (!array || size < 2)
		return;
	m_v = maxsteel(array, size), ca = calloc(m_v + 1, sizeof(*ca));
	if (!ca)
		return;
	sorted_array = malloc(sizeof(*sorted_array) * size);
	if (!sorted_array)
	{
		free(ca);
		return;
	}
	while (i < size)
	{
		ca[array[i]]++;
		i++;
	}
	i = 1;
	while (i < m_v + 1)
	{
		ca[i] += ca[i - 1];
		i++;
	}
	print_array(ca, m_v + 1);
	i = 0;
	while (i < size)
	{
		ca[array[i]]--;
		sorted_array[ca[array[i]]] = array[i];
		i++;
	}
	for (i = 0; i < size; i++)
	{
		array[i] = sorted_array[i];
	}
	free(ca);
	free(sorted_array);
}
