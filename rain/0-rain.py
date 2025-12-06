#!/usr/bin/python3
"""
Module to calculate the amount of rainwater retained
"""


def rain(walls):
    """
    Calculate how many square units of water will be retained after it rains.

    Args:
        walls: List of non-negative integers representing wall heights

    Returns:
        Integer indicating total amount of rainwater retained
    """
    if not walls or len(walls) < 3:
        return 0

    n = len(walls)
    water = 0

    # Step 1: Precompute the maximum wall height to the left of each position
    left_max = [0] * n
    left_max[0] = walls[0]
    for i in range(1, n):
        left_max[i] = max(left_max[i - 1], walls[i])

    # Step 2: Precompute the maximum wall height to the right of each position
    right_max = [0] * n
    right_max[n - 1] = walls[n - 1]
    for i in range(n - 2, -1, -1):
        right_max[i] = max(right_max[i + 1], walls[i])

    # Step 3: Calculate water retained at each position
    for i in range(n):
        # Water above position i is limited by the minimum of
        # max left and max right, minus the wall height
        water_level = min(left_max[i], right_max[i])
        water += water_level - walls[i]

    return water
