#ifndef _SORT_H
#define _SORT_H

#include <stdio.h>
#include <stdlib.h>


/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer  stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;


void gat(int *n1, int *n2);
void heapify(int *array, int ed, int firs, size_t size);


void bubble_sort(int *array, size_t size);
void insertion_sort_list(listint_t **list);
void quick_sort(int *array, size_t size);
void selection_sort(int *array, size_t size);
size_t sega(int array[], size_t size);
void s_rt(int array[], size_t size, int firs);


void shell_sort(int *array, size_t size);
void cocktail_sort_list(listint_t **list);
void heap_sort(int *array, size_t size);
void bitonic_sort(int *array, size_t size);
void counting_sort(int *array, size_t size);
void radix_sort(int *array, size_t size);
void merge_sort(int *array, size_t size);


void print_list(const listint_t *list);
void print_array(const int *array, size_t size);



#endif /* SORT_H */
