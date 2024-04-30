#include "sort.h"

/**
 * quick_sort - Func that sorts an array based on __
 * quick sort algo
 * @array: Arr to be sort
 * @size: Size of arr
 * Return: 0
 */
void quick_sort(int *array, size_t size)
{
	size_t pivot;

	if (!array || size < 2)
		return;

	s_rt(array, size, 1);

	pivot = part(array, size);

	quick_sort(array, pivot);

	quick_sort(array + pivot, size - pivot);
}


/**
 * part - Function that sets the pivot
 *
 * @array: Array to part
 * @size: Size of arr
 * Return: (a + 1)
 */
size_t part(int array[], size_t size)
{
    int pivot;
    size_t smaller = 0;
    size_t current = 0;

    if (!array || size < 2)
        return 0;

    pivot = array[size - 1];

    while (current < size - 1)
    {
        if (array[current] <= pivot)
        {
            if (smaller != current)
            {
                gat(&array[smaller], &array[current]);
                s_rt(array, size, 0);
            }
            smaller++;
        }
        current++;
    }

    if (smaller != size - 1)
    {
        gat(&array[smaller], &array[size - 1]);
        s_rt(array, size, 0);
    }

    return smaller;
}

/**
 * s_rt - Function that prints
 * @array: Array to be printed
 * @size: Size of array
 * @firs: Should initialize array
 * Return: 0
 */
void s_rt(int array[], size_t size, int firs)
{
	static int *a = NULL;
	static size_t b;

	if (!a && firs)
	{
		a = array;
		b = size;
	}
	if (!firs)
		print_array(a, b);
}

/**
 * gat - Function that swaps two values
 *
 * @n1: Fisrt value
 * @num2: Second value
 * Return: 0
 */
void gat(int *n1, int *n2)
{
	int temp;

	temp = *n2;
	*n2 = *n1;
	*n1 = temp;
}
