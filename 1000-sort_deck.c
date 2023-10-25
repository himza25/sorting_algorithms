#include "deck.h"
#include <stdlib.h>
#include <string.h>

/**
 * card_value - Get card's numerical value.
 * @value: Card name.
 * Return: Numerical value of the card.
 */
int card_value(const char *value)
{
	if (strcmp(value, "Ace") == 0)
		return (1);
	if (strcmp(value, "Jack") == 0)
		return (11);
	if (strcmp(value, "Queen") == 0)
		return (12);
	if (strcmp(value, "King") == 0)
		return (13);
	return (atoi(value));
}

/**
 * swap_nodes - Swap two nodes in a list.
 * @node1: First node.
 * @node2: Second node.
 */
void swap_nodes(deck_node_t **node1, deck_node_t **node2)
{
	deck_node_t *tmp = (*node1)->prev;
	(*node1)->prev = (*node2)->prev;
	(*node1)->next = (*node2)->next;
	(*node2)->prev = tmp;
	(*node2)->next = (*node1);
	if ((*node1)->prev)
		(*node1)->prev->next = (*node1);
	if ((*node1)->next)
		(*node1)->next->prev = (*node1);
	if ((*node2)->prev)
		(*node2)->prev->next = (*node2);
	(*node2)->next->prev = (*node2);
}

/**
 * sort_deck - Sort a deck of cards.
 * @deck: Pointer to the head of the list.
 */
void sort_deck(deck_node_t **deck)
{
	deck_node_t *current, *sorted = NULL;
	int swapped;

	if (!deck || !(*deck) || !(*deck)->next)
		return;

	do {
		swapped = 0;
		current = *deck;

		while (current->next != sorted)
		{
			if (current->card->kind > current->next->card->kind ||
				(current->card->kind == current->next->card->kind &&
				card_value(current->card->value) >
				card_value(current->next->card->value)))
			{
				swap_nodes(&current, &current->next);
				swapped = 1;

				if (current->prev == NULL)
					*deck = current;
			}
			if (current->next)
				current = current->next;
		}
		sorted = current;
	} while (swapped);
}
