#include "deck.h"
#include <stdlib.h>

/**
 * card_compare - Compares two card nodes
 * @a: First card node
 * @b: Second card node
 *
 * Return: Difference of kind and value
 */
int card_compare(const void *a, const void *b)
{
	const card_t *card_a = *(const card_t **)a;
	const card_t *card_b = *(const card_t **)b;
	int value_a, value_b;

	if (card_a->kind > card_b->kind)
		return (1);
	if (card_a->kind < card_b->kind)
		return (-1);

	value_a = (card_a->value[0] == 'A') ? 1 :
		(card_a->value[0] == 'K') ? 13 :
		(card_a->value[0] == 'Q') ? 12 :
		(card_a->value[0] == 'J') ? 11 : atoi(card_a->value);

	value_b = (card_b->value[0] == 'A') ? 1 :
		(card_b->value[0] == 'K') ? 13 :
		(card_b->value[0] == 'Q') ? 12 :
		(card_b->value[0] == 'J') ? 11 : atoi(card_b->value);

	return (value_a - value_b);
}

/**
 * list_to_array - Converts a linked list to an array
 * @deck: Head of the linked list
 * @arr: Array of card pointers
 */
void list_to_array(deck_node_t *deck, const card_t **arr)
{
	size_t i = 0;

	while (deck)
	{
		arr[i++] = deck->card;
		deck = deck->next;
	}
}

/**
 * array_to_list - Converts an array to a linked list
 * @arr: Array of card pointers
 * @deck: Head of the linked list
 */
void array_to_list(const card_t **arr, deck_node_t *deck)
{
	size_t i;

	for (i = 0; i < 51; ++i)
	{
		deck->card = arr[i];
		deck = deck->next;
	}
	deck->card = arr[i];
	deck->next = NULL;
}

/**
 * sort_deck - Sorts a deck of cards
 * @deck: Double pointer to the head of the linked list
 */
void sort_deck(deck_node_t **deck)
{
	const card_t *arr[52];

	list_to_array(*deck, arr);
	qsort(arr, 52, sizeof(card_t *), card_compare);
	array_to_list(arr, *deck);
}
