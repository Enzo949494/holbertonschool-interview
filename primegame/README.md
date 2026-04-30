# Prime Game

## Tâche 0 — isWinner

Fonction qui détermine qui gagne le plus de manches d'un jeu de nombres premiers.

**Prototype :** `def isWinner(x, nums)`

- `x` : nombre de manches
- `nums` : tableau des valeurs `n` pour chaque manche
- Retourne le nom du joueur qui a gagné le plus de manches (`"Maria"` ou `"Ben"`), ou `None` si égalité
- Maria joue toujours en premier, les deux joueurs jouent de façon optimale

### Règles du jeu

À chaque tour, le joueur choisit un nombre premier dans l'ensemble `{1..n}` et supprime ce nombre ainsi que tous ses multiples. Le joueur qui ne peut plus jouer perd.

### Algorithme

Le nombre total de coups disponibles dans une manche vaut le nombre de premiers ≤ n. Si ce nombre est impair, Maria (premier joueur) gagne. S'il est pair, Ben gagne.

1. **Crible d'Ératosthène** jusqu'à `max(nums)` pour identifier les nombres premiers
2. **Préfixe cumulatif** `prime_count[i]` = nombre de premiers ≤ i
3. Pour chaque manche : si `prime_count[n]` est impair → Maria gagne, sinon Ben gagne

### Exemple

```
isWinner(5, [2, 5, 1, 4, 3]) -> "Ben"
```

### Fichiers

| Fichier | Description |
|---------|-------------|
| `0-prime_game.py` | Implémentation de la fonction |
