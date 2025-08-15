#!/usr/bin/python3
"""
1st algo b/d fs
"""


def canUnlockAll(boxes):
    """
    algo
    """
    n = len(boxes)
    ouvertes = set([0])
    pile = [0]

    while pile:
        boite = pile.pop()
        for cle in boxes[boite]:
            if 0 <= cle < n and cle not in ouvertes:
                ouvertes.add(cle)
                pile.append(cle)

    return len(ouvertes) == n
