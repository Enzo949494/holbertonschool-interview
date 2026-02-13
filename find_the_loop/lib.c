#include "lists.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * add_nodeint - adds a new node at the beginning of a listint_t list
 * @head: pointer to a pointer of the first node of listint_t list
 * @n: integer to be stored in the node
 *
 * Return: the address of the new element, or NULL if it fails
 */
listint_t *add_nodeint(listint_t **head, const int n)
{
	listint_t *new;

	new = (listint_t *)malloc(sizeof(listint_t));
	if (new == NULL)
		return (NULL);

	new->n = n;
	new->next = *head;
	*head = new;

	return (new);
}

/**
 * print_listint_safe - prints a listint_t linked list (safe with loops)
 * @head: pointer to the first node of listint_t list
 *
 * Return: the number of nodes in the list
 */
size_t print_listint_safe(const listint_t *head)
{
	size_t count;
	const listint_t *slow, *fast, *loop_start;

	if (head == NULL)
		return (0);

	slow = head;
	fast = head;

	/* Detect loop using Floyd's algorithm */
	while (fast != NULL && fast->next != NULL)
	{
		slow = slow->next;
		fast = fast->next->next;
		if (slow == fast)
			break;
	}

	/* If no loop detected */
	if (fast == NULL || fast->next == NULL)
	{
		count = 0;
		slow = head;
		while (slow != NULL)
		{
			printf("[%p] %d\n", (void *)slow, slow->n);
			count++;
			slow = slow->next;
		}
		return (count);
	}

	/* Find the start of the loop */
	slow = head;
	while (slow != fast)
	{
		slow = slow->next;
		fast = fast->next;
	}
	loop_start = slow;

	/* Print nodes up to the loop start */
	count = 0;
	slow = head;
	while (slow != loop_start)
	{
		printf("[%p] %d\n", (void *)slow, slow->n);
		count++;
		slow = slow->next;
	}

	/* Print loop nodes once */
	printf("-> [%p] %d\n", (void *)slow, slow->n);
	count++;
	slow = slow->next;
	while (slow != loop_start && count < 10000)
	{
		printf("[%p] %d\n", (void *)slow, slow->n);
		count++;
		slow = slow->next;
	}

	return (count);
}

/**
 * free_listint_safe - frees a listint_t list (safe with loops)
 * @h: pointer to a pointer of the first node of listint_t list
 *
 * Return: the size of the list that was freed
 */
size_t free_listint_safe(listint_t **h)
{
	size_t count;
	listint_t *node;
	listint_t *slow, *fast, *loop_start;

	count = 0;

	if (h == NULL || *h == NULL)
		return (count);

	slow = *h;
	fast = *h;

	/* Detect loop */
	while (fast != NULL && fast->next != NULL)
	{
		slow = slow->next;
		fast = fast->next->next;
		if (slow == fast)
			break;
	}

	/* If there's a loop, break it */
	if (fast != NULL && fast->next != NULL && slow == fast)
	{
		/* Find the start of the loop */
		slow = *h;
		while (slow != fast)
		{
			slow = slow->next;
			fast = fast->next;
		}
		loop_start = slow;

		/* Break the loop */
		slow = loop_start;
		while (slow->next != loop_start)
			slow = slow->next;
		slow->next = NULL;
	}

	/* Now free all nodes */
	while (*h != NULL)
	{
		count++;
		node = *h;
		*h = (*h)->next;
		free(node);
	}

	return (count);
}
