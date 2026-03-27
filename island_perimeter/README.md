# Island Perimeter

Python function that calculates the perimeter of an island in a grid.

## Description

Given a grid of 0s (water) and 1s (land), returns the perimeter of the island.

**Algorithm:** For each land cell, start with 4 sides. Subtract 2 for each shared edge with an adjacent land cell (top or left neighbor — avoids double counting).

## File

| File | Description |
|------|-------------|
| `0-island_perimeter.py` | Contains the `island_perimeter` function |

## Prototype

```python
def island_perimeter(grid):
```

## Constraints

- `grid` is a list of lists of integers (0 = water, 1 = land)
- Grid dimensions do not exceed 100×100
- Only one island, no lakes

## Example

```python
grid = [
    [0, 0, 0, 0, 0, 0],
    [0, 1, 0, 0, 0, 0],
    [0, 1, 0, 0, 0, 0],
    [0, 1, 1, 1, 0, 0],
    [0, 0, 0, 0, 0, 0]
]
island_perimeter(grid)  # returns 12
```

## Repository

- **GitHub repository:** holbertonschool-interview
- **Directory:** island_perimeter
- **File:** 0-island_perimeter.py
