#include "sort.h"

/**
 * swap_nodes - Swaps two nodes in a doubly linked list.
 *
 * @list: Pointer to a pointer to the first node of the list.
 * @a: First node to be swapped.
 * @b: Second node to be swapped.
 *
 * Description: This function swaps two nodes in a doubly linked list.
 * It updates the links between the nodes to maintain the list structure.
 * The list pointer (list) may be updated if the swapped nodes were the first
 * and/or last nodes in the list.
 */
void swap_nodes(listint_t **list, listint_t *a, listint_t *b)
{
	listint_t *prev_a = a->prev;
	listint_t *prev_b = b->prev;
	listint_t *next_b = b->next;

	if (prev_a)
		prev_a->next = b;
	else
		*list = b;

	if (next_b)
		next_b->prev = a;
	a->next = next_b;

	b->prev = prev_a;
	b->next = a;

	a->prev = b;
	if (prev_b != a)
		prev_b->next = a;
}

/**
 * cocktail_sort_list - Sorts a doubly linked list using the Cocktail
 * Shaker sort algorithm
 *
 * @list: Pointer to a pointer to the first node of the list.
 */
void cocktail_sort_list(listint_t **list)
{
	int swapped;
	listint_t *start = NULL, *end = NULL;
	listint_t *current;

	if (!list || !(*list) || (*list)->next == NULL)
		return;

	do {
		swapped = 0;
		current = start = *list;

		while (current->next != end)
		{
			if (current->n > current->next->n)
			{
				swap_nodes(list, current, current->next);
				print_list(*list);
				swapped = 1;
			}
			else
				current = current->next;
		}
		end = current;
		if (!swapped)
			break;
		swapped = 0;
		current = end;
		while (current->prev != start)
		{
			if (current->n < current->prev->n)
			{
				swap_nodes(list, current->prev, current);
				print_list(*list);
				swapped = 1;
			}
			else
				current = current->prev;
		}
		start = current;
	} while (swapped);
}

