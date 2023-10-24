#include "deck.h"
#include <string.h>

/**
 * sort_deck - Sorts a deck of cards.
 * @deck: Double pointer to the deck.
 */
void sort_deck(deck_node_t **deck)
{
	deck_node_t *tmp, *min;
	int i, j;
	char *values[] = {"Ace", "2", "3", "4", "5", "6", "7", "8", "9", "10",
	"Jack", "Queen", "King"};

	if (deck == NULL || *deck == NULL)
		return;

	for (tmp = *deck; tmp; tmp = tmp->next)
	{
		min = tmp;
		for (i = 0; i < 13; i++)
		{
			if (strcmp(tmp->card->value, values[i]) == 0)
				break;
		}
		for (; tmp->next; tmp = tmp->next)
		{
			for (j = 0; j < 13; j++)
			{
				if (strcmp(tmp->next->card->value, values[j]) == 0)
					break;
			}
			if (i > j)
			{
				min = tmp->next;
				i = j;
			}
		}
		if (min != tmp)
			swap_nodes(deck, tmp, min);
	}
	sort_by_suits(deck);
}
