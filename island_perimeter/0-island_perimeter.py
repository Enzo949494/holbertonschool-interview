#!/usr/bin/python3
"""Module for island_perimeter function"""


def island_perimeter(grid):
    """Returns the perimeter of the island described in grid"""
    perimeter = 0
    for i, row in enumerate(grid):
        for j, cell in enumerate(row):
            if cell == 1:
                perimeter += 4
                if i > 0 and grid[i - 1][j] == 1:
                    perimeter -= 2
                if j > 0 and grid[i][j - 1] == 1:
                    perimeter -= 2
    return perimeter
