#include <stdlib.h>
#include "sort.h"

/**
 * get_max - returns the maximum value in an array
 * @array: the array
 * @size: number of elements
 *
 * Return: maximum value
 */
static int get_max(int *array, size_t size)
{
	int max;
	size_t i;

	max = array[0];
	for (i = 1; i < size; i++)
		if (array[i] > max)
			max = array[i];
	return (max);
}

/**
 * counting_sort_exp - sorts array by a specific digit (exp = 1, 10, 100, ...)
 * @array: the array to sort
 * @size: number of elements
 * @exp: current digit position (power of 10)
 */
static void counting_sort_exp(int *array, size_t size, int exp)
{
	int *output;
	int count[10] = {0};
	size_t i;

	output = malloc(sizeof(int) * size);
	if (!output)
		return;

	for (i = 0; i < size; i++)
		count[(array[i] / exp) % 10]++;

	for (i = 1; i < 10; i++)
		count[i] += count[i - 1];

	for (i = size; i > 0; i--)
	{
		int digit = (array[i - 1] / exp) % 10;

		output[count[digit] - 1] = array[i - 1];
		count[digit]--;
	}

	for (i = 0; i < size; i++)
		array[i] = output[i];

	free(output);
}

/**
 * radix_sort - sorts an array of integers using LSD radix sort
 * @array: the array to sort
 * @size: number of elements
 */
void radix_sort(int *array, size_t size)
{
	int max, exp;

	if (!array || size < 2)
		return;

	max = get_max(array, size);

	for (exp = 1; max / exp > 0; exp *= 10)
	{
		counting_sort_exp(array, size, exp);
		print_array(array, size);
	}
}
