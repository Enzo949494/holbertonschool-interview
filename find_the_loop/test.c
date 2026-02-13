#include "lists.h"
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	listint_t *head, *node, *tmp;
	int i;

	/* Test 1: No loop */
	head = (listint_t *)malloc(sizeof(listint_t));
	head->n = 0;
	node = head;

	for (i = 1; i < 5; i++)
	{
		tmp = (listint_t *)malloc(sizeof(listint_t));
		tmp->n = i;
		node->next = tmp;
		node = tmp;
	}
	node->next = NULL;

	printf("Test 1: No loop\n");
	if (find_listint_loop(head) == NULL)
		printf("PASS: No loop found\n\n");
	else
		printf("FAIL: Loop found when there should be none\n\n");

	/* Clean up test 1 */
	while (head)
	{
		tmp = head;
		head = head->next;
		free(tmp);
	}

	/* Test 2: With loop */
	head = (listint_t *)malloc(sizeof(listint_t));
	head->n = 10;
	node = head;

	for (i = 11; i < 15; i++)
	{
		tmp = (listint_t *)malloc(sizeof(listint_t));
		tmp->n = i;
		node->next = tmp;
		node = tmp;
	}

	/* Create a loop by making last node point to second node */
	node->next = head->next;

	printf("Test 2: With loop\n");
	tmp = find_listint_loop(head);
	if (tmp != NULL && tmp->n == 11)
		printf("PASS: Loop starts at node with value 11\n");
	else if (tmp != NULL)
		printf("FAIL: Loop found at node with value %d (expected 11)\n", tmp->n);
	else
		printf("FAIL: No loop found when there should be one\n");

	return (0);
}
