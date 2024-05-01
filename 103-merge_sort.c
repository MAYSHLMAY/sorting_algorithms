#include "sort.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * m_h - merge sort uppp
 * @array: array to be sort
 * @tp: to arr for holding sorted elements
 * @size: size of the array
 */
void m_h(int *array, int *temp_array, size_t size)
{
    size_t half_size = size / 2;
    size_t left_index = 0, right_index = 0, merged_index;

    if (size < 2)
        return;

    m_h(array, temp_array, half_size);
    m_h(array + half_size, temp_array + half_size, size - half_size);

    printf("%s", "Merging...\n");
    printf("%s", "[left]: ");
    print_array(array, half_size);
    printf("%s", "[right]: ");
    print_array(array + half_size, size - half_size);

    merged_index = 0;
    while (merged_index < size)
    {
        if (right_index >= size - half_size || (left_index < half_size && array[left_index] < (array + half_size)[right_index]))
        {
            temp_array[merged_index] = array[left_index];
            left_index++;
        }
        else
        {
            temp_array[merged_index] = (array + half_size)[right_index];
            right_index++;
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
