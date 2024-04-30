#include "sort.h"

/**
 * insertion_sort_list - perform I-sort
 * @list: The head node of LL-st
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *live, *gat, *prior;

	if (!list || !*list)
		return;

	live = *list;
	for (live = live->next; live != NULL; live = live->next)
	{
		gat = live;
		for (; gat->prev && gat->n < gat->prev->n; gat = gat->prev)
		{
			prior = gat->prev;
			if (gat->next)
				gat->next->prev = prior;
			if (prior->prev)
				prior->prev->next = gat;
			else
				*list = gat;
			prior->next = gat->next;
			gat->prev = prior->prev;
			gat->next = prior;
			prior->prev = gat;

			print_list(*list);
		}
	}
}
