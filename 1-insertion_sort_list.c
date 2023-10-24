#include "sort.h"

/**
 * insertion_sort_list - sorts a doubly linked list in ascending order
 * @list: double pointer to the head of the list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *temp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	current = (*list)->next;
	while (current != NULL)
	{
		temp = current->prev;
		while (temp != NULL && current->n < temp->n)
		{
			temp->next = current->next;
			if (current->next != NULL)
				current->next->prev = temp;
			current->prev = temp->prev;
			current->next = temp;
			if (temp->prev != NULL)
				temp->prev->next = current;
			else
				*list = current;
			temp->prev = current;
			print_list((const listint_t *)*list);
			temp = current->prev;
		}
		current = current->next;
	}
}
