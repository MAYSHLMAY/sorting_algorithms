#include "sort.h"
#include "stdbool.h"

/**
 * swap_node_ahead - Swap a node in a listint_t doubly-linked list
 *                   list of integers with the node ahead of it.
 * @list: A pointer to the head of a doubly-linked list of integers.
 * @tail: A pointer to the tail of the doubly-linked list.
 * @cocksha: A pointer to the current swapping node of the cocktail cocksha algo.
 */
void swap_node_ahead(listint_t **list, listint_t **tail, listint_t **cocksha)
{
    listint_t *t = (*cocksha)->next;

    switch ((*cocksha)->prev != NULL)
    {
        case true:
            (*cocksha)->prev->next = t;
            break;
        case false:
            *list = t;
            break;
    }

    t->prev = (*cocksha)->prev;
    (*cocksha)->next = t->next;

    switch (t->next != NULL)
    {
        case true:
            t->next->prev = *cocksha;
            break;
        case false:
            *tail = *cocksha;
            break;
    }

    (*cocksha)->prev = t;
    t->next = *cocksha;
    *cocksha = t;
}

/**
 * swap_node_behind - Swap a node in a listint_t doubly-linked
 *                    list of integers with the node behind it.
 * @list: A pointer to the head of a doubly-linked list of integers.
 * @tail: A pointer to the tail of the doubly-linked list.
 * @cocksha: A pointer to the current swapping node of the cocktail cocksha algo.
 */
void swap_node_behind(listint_t **list, listint_t **tail, listint_t **cocksha)
{
    listint_t *t = (*cocksha)->prev;

    switch ((*cocksha)->next != NULL)
    {
        case true:
            (*cocksha)->next->prev = t;
            break;
        case false:
            *tail = t;
            break;
    }

    t->next = (*cocksha)->next;
    (*cocksha)->prev = t->prev;

    switch (t->prev != NULL)
    {
        case true:
            t->prev->next = *cocksha;
            break;
        case false:
            *list = *cocksha;
            break;
    }

    (*cocksha)->next = t;
    t->prev = *cocksha;
    *cocksha = t;
}

/**
 * cocktail_sort_list - Sort a listint_t doubly-linked list of integers in
 *                      ascending order using the cocktail cocksha algorithm.
 * @list: A pointer to the head of a listint_t doubly-linked list.
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *t, *s;
	bool shu = false;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	for (t = *list; t->next != NULL;)
		t = t->next;

	while (!shu)
	{
		shu = true;
		for (s = *list; s != t; s = s->next)
		{
			if (s->n > s->next->n)
			{
				swap_node_ahead(list, &t, &s);
				print_list((const listint_t *)*list);
				shu = false;
			}
		}
		for (s = s->prev; s != *list; s = s->prev)
		{
			if (s->n < s->prev->n)
			{
				swap_node_behind(list, &t, &s);
				print_list((const listint_t *)*list);
				shu = false;
			}
		}
	}
}