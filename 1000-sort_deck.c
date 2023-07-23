#include "deck.h"

/**
 * _strcmp - Compares two strings
 *
 * @s1: the first string
 * @s2: the second string
 *
 * Return: 0 if strings are equal,
 * otherwise the difference of first non-matching characters
 */
int _strcmp(const char *s1, const char *s2)
{
	while (*s1 == *s2)
	{
		if (*s1 == '\0')
			return (0);
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

/**
 * get_deck_length - Calculates the number of nodes in the deck
 *
 * @list: Pointer to the head of the deck
 *
 * Return: The number of nodes in the deck
 */
size_t get_deck_length(deck_node_t *list)
{
	size_t length = 0;

	while (list)
	{
		length++;
		list = list->next;
	}
	return (length);
}

/**
 * card_value - Calculates the value of a card
 * based on its face value and kind
 *
 * @node: Pointer to the deck_node_t containing the card
 *
 * Return: The calculated value of the card
 */
int card_value(deck_node_t *node)
{
	char *values[13] = {"Ace", "2", "3", "4", "5", "6",
		"7", "8", "9", "10", "Jack", "Queen", "King"};
	char *kinds[4] = {"SPADE", "HEART", "CLUB", "DIAMOND"};
	int i, kind_value = 0;

	for (i = 1; i <= 13; i++)
	{
		if (!_strcmp(node->card->value, values[i - 1]))
			kind_value = i;
	}

	for (i = 1; i <= 4; i++)
	{
		if (!_strcmp(kinds[node->card->kind], kinds[i - 1]))
			kind_value = kind_value + (13 * i);
	}

	return (kind_value);
}

/**
 * sort_deck - Sorts a deck of cards in ascending order using bubble sort
 *
 * @deck: Double pointer to the head of the deck
 *
 * Return: void
 */
void sort_deck(deck_node_t **deck)
{
	deck_node_t *current;
	deck_node_t *prev_one, *prev_two, *curr_node, *next_node;
	size_t len;

	len = get_deck_length(*deck);

	if (!deck || !*deck || len < 2)
		return;

	current = *deck;
	while (current)
	{
		if (current->prev && card_value(current) < card_value(current->prev))
		{
			prev_two = current->prev->prev;
			prev_one = current->prev;
			curr_node = current;
			next_node = current->next;

			prev_one->next = next_node;
			if (next_node)
				next_node->prev = prev_one;
			curr_node->next = prev_one;
			curr_node->prev = prev_two;
			if (prev_two)
				prev_two->next = curr_node;
			else
				*deck = curr_node;
			prev_one->prev = curr_node;
			current = *deck;
			continue;
		}
		else
			current = current->next;
	}
}
