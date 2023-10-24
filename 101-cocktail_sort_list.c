#include "sort.h"

/**
 * swap_nodes - Swaps two nodes in a doubly linked list.
 * @list: Double pointer to the head node of the list.
 * @node1: Pointer to the first node.
 * @node2: Pointer to the second node.
 */
void swap_nodes(listint_t **list, listint_t *node1, listint_t *node2)
{
	if (node1->prev)
		node1->prev->next = node2;
	else
		*list = node2;

	if (node2->next)
		node2->next->prev = node1;

	node1->next = node2->next;
	node2->prev = node1->prev;

	node1->prev = node2;
	node2->next = node1;

	if (node2->prev)
		node2->prev->next = node2;

	if (node1->next)
		node1->next->prev = node1;

	print_list(*list);
}

/**
 * cocktail_sort_list - Sorts a doubly linked list using Cocktail Shaker sort.
 * @list: Double pointer to the head node of the list.
 */
void cocktail_sort_list(listint_t **list)
{
	char swapped = 1;
	listint_t *temp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	temp = *list;

	while (swapped)
	{
		swapped = 0;
		while (temp->next)
		{
			if (temp->n > temp->next->n)
			{
				swap_nodes(list, temp, temp->next);
				swapped = 1;
			}
			else
			{
				temp = temp->next;
			}
		}
		if (!swapped)
			break;

		swapped = 0;
		while (temp->prev)
		{
			if (temp->n < temp->prev->n)
			{
				swap_nodes(list, temp->prev, temp);
				swapped = 1;
			}
			else
			{
				temp = temp->prev;
			}
		}
	}
}
