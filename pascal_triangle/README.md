# Pascal's Triangle

## Tâche 0 — pascal_triangle

Fonction qui retourne un tableau de tableaux d'entiers représentant le triangle de Pascal de `n`.

- Retourne une liste vide si `n <= 0`
- `n` est toujours un entier

### Exemple

```
[1]
[1,1]
[1,2,1]
[1,3,3,1]
[1,4,6,4,1]
```

### Algorithme

Chaque ligne commence et se termine par `1`. Les valeurs intermédiaires sont la somme des deux valeurs adjacentes de la ligne précédente : `triangle[i][j] = triangle[i-1][j-1] + triangle[i-1][j]`.

### Fichiers

| Fichier | Description |
|---------|-------------|
| `0-pascal_triangle.py` | Implémentation de la fonction |
