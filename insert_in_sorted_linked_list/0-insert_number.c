#include "lists.h"
#include <stdlib.h>
/**
* insert_node - inserts a number into a sorted singly linked list
* @head: double pointer to the head of the list
* @number: number to insert
*
* Return: address of the new node, or NULL if it failed
*/
listint_t *insert_node(listint_t **head, int number)
{
	listint_t *new_node;
	listint_t *current;
	/* Check if head pointer is valid */
	if (head == NULL)
		return (NULL);
	/* Create new node */
	new_node = malloc(sizeof(listint_t));
	if (new_node == NULL)
		return (NULL);
	new_node->n = number;
	/* If list is empty or number should be inserted at the beginning */
	if (*head == NULL || (*head)->n > number)
	{
		new_node->next = *head;
		*head = new_node;
		return (new_node);
	}
	/* Find the correct position to insert */
	current = *head;
	while (current->next != NULL && current->next->n < number)
		current = current->next;
	/* Insert the new node after current */
	new_node->next = current->next;
	current->next = new_node;
	return (new_node);
}
