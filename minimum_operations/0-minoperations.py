#!/usr/bin/python3
"""
Module for calculating minimum operations
"""


def minOperations(n):
    """
    Calculates the fewest number of operations needed to result in exactly
    n H characters in the file.
    Args:
        n: The target number of H characters
    Returns:
        Integer representing minimum operations, or 0 if impossible
    """
    if n <= 1:
        return 0
    operations = 0
    factor = 2
    while factor * factor <= n:
        while n % factor == 0:
            operations += factor
            n //= factor
        factor += 1
    if n > 1:
        operations += n
    return operations
