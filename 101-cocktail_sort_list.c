#include "sort.h"
#include <stdio.h>

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
 * list_length - returns the length of a listint_t list
 * @list: Pointer to the head of the list
 * Return: Length of the list
 */
unsigned int list_length(listint_t *list)
{
	unsigned int length = 0;

	while (list != NULL)
	{
		length++;
		list = list->next;
	}

	return (length);
}

/**
 * cocktail_sort_list - Sorts a list using cocktail sort algorithm
 * @list: Pointer to the head of the list to sort
 */
void cocktail_sort_list(listint_t **list)
{
	unsigned int left = 0, right, index = 0;
	listint_t *current = *list;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	right = list_length(*list) - 1;
	while (right - left > 1)
	{
		while (index < right)
		{
			if (current->next != NULL &&
			current->n > current->next->n)
			{
				swap(current, current->next);
				print_list(head(*list));
			}
			else
				current = current->next;
			index++;
		}
		right--;
		while (index > left)
		{
			if (current->prev != NULL &&
			current->n < current->prev->n)
			{
				swap(current->prev, current);
				print_list(head(*list));
			}
			else
				current = current->prev;
			index--;
		}
		left++;
	}
	*list = head(*list);
}
