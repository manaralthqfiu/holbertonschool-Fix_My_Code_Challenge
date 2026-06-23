#include "lists.h"
#include <stdlib.h>

/**
 * delete_dnodeint_at_index - Deletes the node at index of a dlistint_t list.
 * @head: Double pointer to the first node of the list.
 * @index: Index of the node that should be deleted. Index starts at 0.
 *
 * Return: 1 if it succeeded, -1 if it failed.
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
 dlistint_t *saved_head;
 unsigned int i;

 if (head == NULL || *head == NULL)
  return (-1);

 saved_head = *head;
 i = 0;
 while (i < index && *head != NULL)
 {
  *head = (*head)->next;
  i++;
 }
 if (i != index || *head == NULL)
 {
  *head = saved_head;
  return (-1);
 }
 if (index == 0)
 {
  *head = (*head)->next;
  if (*head != NULL)
   (*head)->prev = NULL;
  free(saved_head);
  return (1);
 }
 (*head)->prev->next = (*head)->next;
 if ((*head)->next != NULL)
  (*head)->next->prev = (*head)->prev;
 free(*head);
 *head = saved_head;
 return (1);
}
