#include "sort.h"



/**
 * maxsteel - Find val_of_max in arr of ints
 * @array: array to find val_of_max val
 * @size: size of the array
 * Return: max
 */
int maxsteel(int *array, int size)
{
	int max = array[0];
	int index = 1;

	while (index < size)
	{
		if (array[index] > max)
			max = array[index];
		index++;
	}

	return (max);
}

/**
 * rcs - Sort the sgs of an array of ints
 * @array: An array of integers.
 * @size: The size of the array.
 * @s_fig: The significant digit
 * @buf: A buffer to store the sorted array.
 */
void rcs(int *array, size_t size, int s_fig, int *buf)
{
	int cnt[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	size_t i = 0;

	while (i < size)
	{
		cnt[(array[i] / s_fig) % 10] += 1;
		i++;
	}

	i = 1;
	while (i < 10)
	{
		cnt[i] += cnt[i - 1];
		i++;
	}

	i = size - 1;
	while ((int)i >= 0)
	{
		buf[cnt[(array[i] / s_fig) % 10] - 1] = array[i];
		cnt[(array[i] / s_fig) % 10] -= 1;
		i--;
	}

	i = 0;
	while (i < size)
	{
		array[i] = buf[i];
		i++;
	}
}

/**
 * radix_sort - Sort an array of integers in ascending
 * @array: An array of integers.
 * @size: The size of the array.
 */
void radix_sort(int *array, size_t size)
{
	int max, s_fig, *buf;

	if (array == NULL || size < 2)
		return;

	buf = malloc(sizeof(int) * size);
	if (buf == NULL)
		return;

	max = maxsteel(array, size);
	s_fig = 1;
	while (max / s_fig > 0)
	{
		rcs(array, size, s_fig, buf);
		print_array(array, size);
		s_fig *= 10;
	}

	free(buf);
}
