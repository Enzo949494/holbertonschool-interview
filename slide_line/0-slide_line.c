#include "slide_line.h"

/**
 * slide_left - Slides and merges array to the left
 * @line: Pointer to array of integers
 * @size: Number of elements in array
 */
static void slide_left(int *line, size_t size)
{
	size_t i, j, k;

	/* Slide all non-zero elements to the left */
	for (i = 0, j = 0; i < size; i++)
	{
		if (line[i] != 0)
		{
			line[j] = line[i];
			if (i != j)
				line[i] = 0;
			j++;
		}
	}

	/* Merge adjacent identical values */
	for (i = 0; i < size - 1; i++)
	{
		if (line[i] != 0 && line[i] == line[i + 1])
		{
			line[i] *= 2;
			line[i + 1] = 0;
		}
	}

	/* Slide again to remove zeros created by merging */
	for (i = 0, j = 0; i < size; i++)
	{
		if (line[i] != 0)
		{
			line[j] = line[i];
			if (i != j)
				line[i] = 0;
			j++;
		}
	}

	/* Fill remaining positions with zeros */
	for (k = j; k < size; k++)
		line[k] = 0;
}

/**
 * slide_right - Slides and merges array to the right
 * @line: Pointer to array of integers
 * @size: Number of elements in array
 */
static void slide_right(int *line, size_t size)
{
	size_t i, j, write_pos;

	/* Slide all non-zero elements to the right */
	for (i = size - 1, j = size - 1; i < size; i--)
	{
		if (line[i] != 0)
		{
			line[j] = line[i];
			if (i != j)
				line[i] = 0;
			j--;
		}
	}

	/* Merge adjacent identical values from right to left */
	for (i = size - 1; i > 0; i--)
	{
		if (line[i] != 0 && line[i] == line[i - 1])
		{
			line[i] *= 2;
			line[i - 1] = 0;
		}
	}

	/* Slide again to remove zeros created by merging */
	for (i = size - 1, j = size - 1; i < size; i--)
	{
		if (line[i] != 0)
		{
			line[j] = line[i];
			if (i != j)
				line[i] = 0;
			j--;
		}
	}

	/* Fill remaining positions with zeros */
	write_pos = (j >= size) ? 0 : j + 1;
	for (i = 0; i < write_pos; i++)
		line[i] = 0;
}

/**
 * slide_line - Slides and merges an array of integers
 * @line: Pointer to array of integers
 * @size: Number of elements in the array
 * @direction: Direction to slide (SLIDE_LEFT or SLIDE_RIGHT)
 *
 * Return: 1 on success, 0 on failure
 */
int slide_line(int *line, size_t size, int direction)
{
	if (line == NULL || size == 0)
		return (0);

	if (direction == SLIDE_LEFT)
	{
		slide_left(line, size);
		return (1);
	}
	else if (direction == SLIDE_RIGHT)
	{
		slide_right(line, size);
		return (1);
	}

	return (0);
}
