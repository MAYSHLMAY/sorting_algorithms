#include "sort.h"

/**
 * insertion_sort_list - perform I-sort
 * @list: The head node of LL-st
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *live, *gat, *prv;

	if (!list || !*list)
		return;

	live = *list;
	for (live = live->next; live != NULL; live = live->next)
	{
		gat = live;
		while (gat->prev && gat->n < gat->prev->n)
		{
			prv = gat->prev;
			if (gat->next)
				gat->next->prev = prv;
			if (prv->prev)
				prv->prev->next = gat;
			else
				*list = gat;
			prv->next = gat->next;
			gat->prev = prv->prev;
			gat->next = prv;
			prv->prev = gat;

			print_list(*list);
		}
	}
}
