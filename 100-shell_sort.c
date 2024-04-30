#include "sort.h"

/**
 * shell_sort - Sorts an array of ints
 * @array: The array to be sort
 * @size: The size of the array
 */
void shell_sort(int *array, size_t size)
{
	size_t spac = 1;
	size_t outerIndex, innerIndex;
	int temp;

	if (array == NULL || size < 2)
		return;

	while (spac < size / 3)
		spac = spac * 3 + 1;

	while (spac >= 1)
	{
		outerIndex = spac;
		while (outerIndex < size)
		{
			temp = array[outerIndex];
			innerIndex = outerIndex;
			while (innerIndex >= spac && array[innerIndex - spac] > temp)
			{
				array[innerIndex] = array[innerIndex - spac];
				innerIndex -= spac;
			}
			array[innerIndex] = temp;
			outerIndex++;
		}
		spac /= 3;
		print_array(array, size);
	}
}
