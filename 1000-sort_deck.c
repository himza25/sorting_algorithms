#include "deck.h"
#include <stdlib.h>
#include <string.h>

/**
 * compare_cards - Compares two cards.
 * @a: First card.
 * @b: Second card.
 * Return: Difference in cards.
 */
int compare_cards(const void *a, const void *b)
{
	const deck_node_t *nodeA = *(const deck_node_t **)a;
	const deck_node_t *nodeB = *(const deck_node_t **)b;
	int valueA = strcmp(nodeA->card->value, nodeB->card->value);
	int kindA = nodeA->card->kind;
	int kindB = nodeB->card->kind;

	if (kindA != kindB)
		return (kindA - kindB);

	if (valueA == 0)
		return (0);

	if (strcmp(nodeA->card->value, "Ace") == 0)
		return (-1);
	if (strcmp(nodeB->card->value, "Ace") == 0)
		return (1);
	if (strcmp(nodeA->card->value, "King") == 0)
		return (1);
	if (strcmp(nodeB->card->value, "King") == 0)
		return (-1);
	if (strcmp(nodeA->card->value, "Queen") == 0)
		return (1);
	if (strcmp(nodeB->card->value, "Queen") == 0)
		return (-1);
	if (strcmp(nodeA->card->value, "Jack") == 0)
		return (1);
	if (strcmp(nodeB->card->value, "Jack") == 0)
		return (-1);

	return (valueA);
}

/**
 * sort_deck - Sorts a deck of cards.
 * @deck: Deck to sort.
 */
void sort_deck(deck_node_t **deck)
{
	deck_node_t *current = *deck;
	deck_node_t **array;
	size_t i = 0, size = 52;

	array = malloc(sizeof(deck_node_t *) * size);
	if (!array)
		return;

	while (current)
	{
		array[i++] = current;
		current = current->next;
	}

	qsort(array, size, sizeof(deck_node_t *), compare_cards);

	for (i = 0; i < size; ++i)
	{
		array[i]->prev = i > 0 ? array[i - 1] : NULL;
		array[i]->next = i < size - 1 ? array[i + 1] : NULL;
	}

	*deck = array[0];
	free(array);
}
