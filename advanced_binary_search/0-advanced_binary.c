#include <stdio.h>
#include "search_algos.h"

/**
 * print_array - Affiche un tableau d'entiers
 * @array: Pointeur sur le tableau
 * @left: Index gauche du sous-tableau
 * @right: Index droit du sous-tableau
 */
void print_array(int *array, size_t left, size_t right)
{
	size_t i;

	printf("Searching in array: ");
	for (i = left; i <= right; i++)
	{
		printf("%d", array[i]);
		if (i < right)
			printf(", ");
	}
	printf("\n");
}

/**
 * advanced_binary_helper - Fonction récursive pour recherche binaire
 * @array: Pointeur sur le tableau à rechercher
 * @left: Index gauche du sous-tableau courant
 * @right: Index droit du sous-tableau courant
 * @value: Valeur à rechercher
 *
 * Return: Index de la première occurrence de value, ou -1 si non trouvée
 */
int advanced_binary_helper(int *array, size_t left, size_t right, int value)
{
	size_t mid;

	if (left > right)
		return (-1);

	print_array(array, left, right);

	mid = left + (right - left) / 2;

	if (array[mid] == value)
	{
		/* Vérifier si c'est la première occurrence */
		if (mid == left || array[mid - 1] != value)
			return (mid);
		/* Sinon, chercher dans la moitié gauche */
		return (advanced_binary_helper(array, left, mid - 1, value));
	}
	else if (array[mid] < value)
		return (advanced_binary_helper(array, mid + 1, right, value));
	else
		return (advanced_binary_helper(array, left, mid - 1, value));
}

/**
 * advanced_binary - Recherche une valeur dans un tableau trié
 * @array: Pointeur sur le premier élément du tableau à rechercher
 * @size: Nombre d'éléments dans le tableau
 * @value: Valeur à rechercher
 *
 * Return: Index où se trouve value, ou -1 si non trouvée ou tableau NULL
 */
int advanced_binary(int *array, size_t size, int value)
{
	if (array == NULL || size == 0)
		return (-1);

	return (advanced_binary_helper(array, 0, size - 1, value));
}
