#include "sort.h"

/**
 * insertion_sort_list -  sorts a doubly linked list of integers in ascending
 * order using the Insertion sort algorithm
 * @list: Linked list with integers
 *
 * Return: Nothing
 *
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *current;

	if (!list || !(*list) || !((*list)->next))
		return;

	current = (*list)->next;

	while (current)
	{
		listint_t *temp = current;

		while (temp->prev && temp->n < temp->prev->n)
		{
			temp->prev->next = temp->next;

			if (temp->next)
				temp->next->prev = temp->prev;

			temp->next = temp->prev;
			temp->prev = temp->prev->prev;

			if (temp->prev)
				temp->prev->next = temp;

			temp->next->prev = temp;

			if (!temp->prev)
				*list = temp;

			print_list(*list);
		}
		current = current->next;
	}
}
