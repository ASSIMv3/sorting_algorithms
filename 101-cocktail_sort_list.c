#include "sort.h"

/**
 * cocktail_sort_list - Sorts a doubly linked list
 * using the Cocktail Shaker Sort algorithm
 *
 * @list: Double pointer to the head of the doubly linked list
 *
 * Return: void
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *end, *current;
	int swapped = 0;

	if (!list || *list == NULL || (*list)->next == NULL)
		return;

	for (end = *list; end->next != NULL;)
		end = end->next;

	while (!swapped)
	{
		swapped = 1;
		for (current = *list; current != end; current = current->next)
		{
			if (current->n > current->next->n)
			{
				swap_nodes_forward(list, &end, &current);
				print_list((const listint_t *)*list);
				swapped = 0;
			}
		}
		for (current = current->prev; current != *list;
				current = current->prev)
		{
			if (current->n < current->prev->n)
			{
				swap_nodes_backward(list, &end, &current);
				print_list((const listint_t *)*list);
				swapped = 0;
			}
		}
	}
}

/**
 * swap_nodes_forward - Swap two adjacent nodes in a doubly linked list
 * in the forward direction
 *
 * @list: Double pointer to the head of the doubly linked list
 * @end: Double pointer to the end of the doubly linked list
 * @current: Double pointer to the current node
 *
 * Return: void
 */
void swap_nodes_forward(listint_t **list, listint_t **end, listint_t **current)
{
	listint_t *temp = (*current)->next;

	if ((*current)->prev != NULL)
		(*current)->prev->next = temp;
	else
		*list = temp;
	temp->prev = (*current)->prev;
	(*current)->next = temp->next;
	if (temp->next != NULL)
		temp->next->prev = *current;
	else
		*end = *current;
	(*current)->prev = temp;
	temp->next = *current;
	*current = temp;
}

/**
 * swap_nodes_backward - Swap two adjacent nodes in a doubly linked list
 * in the backward direction
 *
 * @list: Double pointer to the head of the doubly linked list
 * @end: Double pointer to the end of the doubly linked list
 * @current: Double pointer to the current node
 *
 * Return: void
 */
void swap_nodes_backward(listint_t **list, listint_t **end,
		listint_t **current)
{
	listint_t *temp = (*current)->prev;

	if ((*current)->next != NULL)
		(*current)->next->prev = temp;
	else
		*end = temp;
	temp->next = (*current)->next;
	(*current)->prev = temp->prev;
	if (temp->prev != NULL)
		temp->prev->next = *current;
	else
		*list = *current;
	(*current)->next = temp;
	temp->prev = *current;
	*current = temp;
}
