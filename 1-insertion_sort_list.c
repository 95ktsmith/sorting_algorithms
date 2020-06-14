#include "sort.h"

/**
 * swap - Swaps two nodes in a listint_t list
 * @a: Pointer to first node
 * @b: Pointer to second. Must come after a in list.
 */
void swap(listint_t *a, listint_t *b)
{
	listint_t *c;

	if (a->next == b)
	{
		a->next = b->next;
		b->next = a;

		b->prev = a->prev;
		a->prev = b;
	}
	else
	{
		c = a->next;
		a->next = b->next;
		b->next = c;

		c = a->prev;
		a->prev = b->prev;
		b->prev = c;
	}

	if (a->next != NULL)
		a->next->prev = a;
	if (a->prev != NULL)
		a->prev->next = a;

	if (b->next != NULL)
		b->next->prev = b;
	if (b->prev != NULL)
		b->prev->next = b;
}

/**
 * head - returns the head node of a listint_t list
 * @list: Any node in the list
 * Return: Pointer to the head node
 */
listint_t *head(listint_t *list)
{
	while (list->prev != NULL)
		list = list->prev;
	return (list);
}

/**
 * insertion_sort_list - sorts a list using selection sort algorithm
 * @list: Address of the head of the listint_t list to sort
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	current = (*list)->next;
	while (current)
	{
		while (current->prev != NULL && current->n < current->prev->n)
		{
			swap(current->prev, current);
			*list = head(current);
			print_list(*list);
		}
		current = current->next;
	}
}
