#include <stdio.h>
#include <stdlib.h>
#include "lists.h"
/**
 * reverse - inverse une liste chaînée simple
 * @head: pointeur vers pointeur du premier nœud de la liste listint_t
 * Return: pointeur vers le premier nœud de la liste inversée
 */
listint_t *reverse(listint_t **head)
{
    listint_t *prev = NULL;   /* Nœud précédent (commence à NULL) */
    listint_t *current;       /* Nœud actuel en cours de traitement */
    listint_t *next;          /* Nœud suivant (pour éviter de le perdre) */
    current = *head;
    /* Parcourir la liste et inverser les liens */
    while (current != NULL)
    {
        next = current->next;    /* Sauvegarder le nœud suivant avant de changer le lien */
        current->next = prev;    /* Inverser le lien */
        prev = current;          /* Faire avancer prev */
        current = next;          /* Faire avancer current */
    }
    *head = prev;  /* Mettre à jour head pour pointer vers le nouveau premier nœud */
    return (*head);
}
/**
 * is_palindrome - vérifie si une liste chaînée simple est un palindrome
 * @head: pointeur vers pointeur du premier nœud de la liste listint_t
 * Return: 0 si ce n'est pas un palindrome, 1 si c'est un palindrome
 */
int is_palindrome(listint_t **head)
{
    listint_t *slow;              /* Pointeur lent (tortue) */
    listint_t *fast;              /* Pointeur rapide (lièvre) */
    listint_t *prev_slow;         /* Nœud précédent du pointeur lent */
    listint_t *second_half;       /* Début de la seconde moitié */
    listint_t *first_half;        /* Début de la première moitié */
    listint_t *second_half_head;  /* Tête de la seconde moitié inversée */
    int is_palindrome = 1;        /* Drapeau résultat (on suppose palindrome) */
    /* ÉTAPE 1: Gérer les cas simples - liste vide ou nœud unique */
    if (*head == NULL || (*head)->next == NULL)
        return (1);  /* Liste vide ou nœud unique est un palindrome */
    /* ÉTAPE 2: Trouver le milieu avec deux pointeurs (tortue et lièvre) */
    slow = *head;
    fast = *head;
    /* Le rapide avance de 2 pas, le lent de 1 pas */
    /* Quand le rapide atteint la fin, le lent sera au milieu */
    while (fast != NULL && fast->next != NULL)
    {
        fast = fast->next->next;  /* Faire avancer le pointeur rapide de 2 pas */
        prev_slow = slow;         /* Garder trace du précédent lent */
        slow = slow->next;        /* Faire avancer le pointeur lent de 1 pas */
    }
    /* ÉTAPE 3: Diviser la liste et inverser la seconde moitié */
    prev_slow->next = NULL;       /* Couper la liste en deux */
    second_half = reverse(&slow); /* Inverser la seconde moitié */
    /* ÉTAPE 4: Comparer la première moitié avec la seconde moitié inversée */
    first_half = *head;
    second_half_head = second_half;
    /* Comparer les nœuds un par un */
    while (first_half != NULL && second_half != NULL)
    {
        if (first_half->n != second_half->n)
        {
            is_palindrome = 0;    /* Ce n'est pas un palindrome */
            break;
        }
        first_half = first_half->next;
        second_half = second_half->next;
    }
    /* ÉTAPE 5: Restaurer la structure originale de la liste */
    prev_slow->next = reverse(&second_half_head);
    return (is_palindrome);
}
