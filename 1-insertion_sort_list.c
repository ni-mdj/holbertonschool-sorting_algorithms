#include "sort.h"
#include <stdio.h>

/**
* insertion_sort_list - Sorts a doubly linked list of
*  integers in ascending order
*                       using the Insertion Sort algorithm
* @list: Double pointer to the head of the list
*/
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *prev;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	current = (*list)->next;
	while (current)
	{
		prev = current->prev;
		while (prev && current->n < prev->n)
		{
			if (prev->prev)
				prev->prev->next = current;
			else
				*list = current;

			if (current->next)
				current->next->prev = prev;

			prev->next = current->next;
			current->prev = prev->prev;
			current->next = prev;
			prev->prev = current;

			print_list(*list);
			prev = current->prev;
		}
		current = current->next;
	}
}
