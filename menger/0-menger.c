#include "menger.h"

/**
 * is_empty - Determines if a position should be empty in Menger sponge
 * @row: Row position
 * @col: Column position
 *
 * Return: 1 if position should be empty, 0 otherwise
 */
int is_empty(int row, int col)
{
	while (row > 0 || col > 0)
	{
		if (row % 3 == 1 && col % 3 == 1)
			return (1);
		row /= 3;
		col /= 3;
	}
	return (0);
}

/**
 * menger - Draws a 2D Menger sponge
 * @level: Level of the Menger Sponge to draw
 *
 * Description: Draws a 2D Menger sponge of the specified level.
 * If level is lower than 0, the function does nothing.
 */
void menger(int level)
{
	int size, row, col;

	if (level < 0)
		return;

	size = pow(3, level);

	for (row = 0; row < size; row++)
	{
		for (col = 0; col < size; col++)
		{
			if (is_empty(row, col))
				printf(" ");
			else
				printf("#");
		}
		printf("\n");
	}
}
