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
	for (live = live->follow; live != NULL; live = live->follow)
	{
		gat = live;
		for (; gat->prev && gat->n < gat->prev->n; gat = gat->prev)
		{
			prior = gat->prev;
			if (gat->follow)
				gat->follow->prev = prior;
			if (prior->prev)
				prior->prev->follow = gat;
			else
				*list = gat;
			prior->follow = gat->follow;
			gat->prev = prior->prev;
			gat->follow = prior;
			prior->prev = gat;

			print_list(*list);
		}
	}
}
