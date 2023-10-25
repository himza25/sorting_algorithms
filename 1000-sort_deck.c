#include "deck.h"
#include <stdlib.h>
#include <string.h>

/**
 * card_value - Get numerical value of card
 * @card: Card string
 * Return: Numerical value
 */
static int card_value(const char *card)
{
	if (strcmp(card, "Ace") == 0)
		return (1);
	if (strcmp(card, "Jack") == 0)
		return (11);
	if (strcmp(card, "Queen") == 0)
		return (12);
	if (strcmp(card, "King") == 0)
		return (13);
	return (atoi(card));
}

/**
 * cmp_nodes - Compare two cards
 * @node1: First node
 * @node2: Second node
 * Return: 1 if node1 > node2 else 0
 */
static int cmp_nodes(deck_node_t *node1, deck_node_t *node2)
{
	int val1 = card_value(node1->card->value);
	int val2 = card_value(node2->card->value);
	int kind1 = node1->card->kind;
	int kind2 = node2->card->kind;

	if (kind1 == kind2)
		return (val1 > val2);
	return (kind1 > kind2);
}

/**
 * sort_deck - Sort deck of cards
 * @deck: Pointer to deck
 */
void sort_deck(deck_node_t **deck)
{
	deck_node_t *curr, *next, *tmp;

	if (!deck || !*deck || !(*deck)->next)
		return;

	for (curr = *deck; curr; curr = next)
	{
		next = curr->next;
		for (tmp = curr; tmp->prev && cmp_nodes(tmp, tmp->prev); tmp = tmp->prev)
		{
			tmp->prev->next = tmp->next;
			if (tmp->next)
				tmp->next->prev = tmp->prev;
			tmp->next = tmp->prev;
			tmp->prev = tmp->prev->prev;
			tmp->next->prev = tmp;
			if (tmp->prev)
				tmp->prev->next = tmp;
			else
				*deck = tmp;
		}
	}
}
