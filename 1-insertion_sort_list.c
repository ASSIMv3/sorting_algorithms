#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list of integers in ascending
 *                       order using the Insertion sort algorithm
 *
 * @list: Double pointer to the head of the list to be sorted
 */
void insertion_sort_list(listint_t **list)
{
	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	listint_t *current, *sorted, *temp;

	sorted = (*list)->next;

	while (sorted != NULL)
	{
		current = sorted;
		sorted = sorted->next;

		while (current->prev != NULL && current->n < current->prev->n)
		{
			temp = current->prev;
			current->prev = temp->prev;
			temp->next = current->next;

			if (current->next != NULL)
				current->next->prev = temp;

			if (temp->prev != NULL)
				temp->prev->next = current;
			else
				*list = current;

			current->next = temp;
			temp->prev = current;

			print_list(*list);
		}
	}
}
