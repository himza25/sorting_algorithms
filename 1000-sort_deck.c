#include <stdio.h>
#include <stdlib.h>
#include "deck.h"

/**
 * compare_cards - Compares two cards.
 * @a: Pointer to the first card.
 * @b: Pointer to the second card.
 * Return: Difference between cards.
 */
int compare_cards(const void *a, const void *b)
{
	const deck_node_t *nodeA = *(const deck_node_t **)a;
	const deck_node_t *nodeB = *(const deck_node_t **)b;
	const char *values[] = {"Ace", "2", "3", "4", "5", "6", "7", "8", "9",
			"10", "Jack", "Queen", "King"};
	int i, valueA, valueB;

	for (i = 0; i < 13; i++)
	{
		if (strcmp(nodeA->card->value, values[i]) == 0)
			valueA = i;
		if (strcmp(nodeB->card->value, values[i]) == 0)
			valueB = i;
	}

	if (nodeA->card->kind == nodeB->card->kind)
		return (valueA - valueB);

	return ((int)nodeA->card->kind - (int)nodeB->card->kind);
}

/**
 * sort_deck - Sorts a deck of cards.
 * @deck: Pointer to the head of the deck.
 */
void sort_deck(deck_node_t **deck)
{
	deck_node_t **array, *current = *deck;
	size_t size = 0, i = 0;

	while (current)
		current = current->next, size++;

	array = malloc(sizeof(deck_node_t *) * size);
	if (!array)
		return;

	for (i = 0, current = *deck; i < size; i++, current = current->next)
		array[i] = current;

	qsort(array, size, sizeof(deck_node_t *), compare_cards);

	for (i = 0; i < size; i++)
	{
		array[i]->prev = i > 0 ? array[i - 1] : NULL;
		array[i]->next = i < size - 1 ? array[i + 1] : NULL;
	}

	*deck = array[0];
	free(array);
}
