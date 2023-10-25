#include "deck.h"
#include <stdlib.h>

/**
 * get_card_value - gets the numerical value of a card.
 * @card: pointer to a card.
 *
 * Return: numerical value of the card.
 */
int get_card_value(const card_t *card)
{
	/* Handle face cards and ace */
	if (card->value[0] == 'A')
		return (1);
	if (card->value[0] == 'K')
		return (13);
	if (card->value[0] == 'Q')
		return (12);
	if (card->value[0] == 'J')
		return (11);
	return (atoi(card->value));
}

/**
 * card_compare - compares two cards.
 * @a: pointer to a card pointer.
 * @b: pointer to a card pointer.
 *
 * Return: negative if a < b, 0 if a == b, positive if a > b.
 */
int card_compare(const void *a, const void *b)
{
	const card_t *card_a = *(const card_t **)a;
	const card_t *card_b = *(const card_t **)b;
	int suit_diff = card_b->kind - card_a->kind;

	if (suit_diff)
		return (suit_diff);
	return (get_card_value(card_a) - get_card_value(card_b));
}

/**
 * list_to_array - converts a linked list to an array.
 * @deck: pointer to the head of the linked list.
 * @arr: pointer to an array of card pointers.
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
 * array_to_list - converts an array to a linked list.
 * @arr: pointer to an array of card pointers.
 * @deck: pointer to the head of the linked list.
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
 * sort_deck - sorts a deck of cards.
 * @deck: double pointer to the head of the linked list.
 */
void sort_deck(deck_node_t **deck)
{
	const card_t *arr[52];

	list_to_array(*deck, arr);
	qsort(arr, 52, sizeof(card_t *), card_compare);
	array_to_list(arr, *deck);
}
