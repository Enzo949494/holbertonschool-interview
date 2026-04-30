# Wild Compare

## Tâche 0 — wildcmp

Fonction qui compare deux chaînes et retourne `1` si elles peuvent être considérées identiques, `0` sinon.

**Prototype :** `int wildcmp(char *s1, char *s2);`

`s2` peut contenir le caractère spécial `*` qui remplace n'importe quelle chaîne (y compris une chaîne vide).

### Algorithme

Approche récursive :
- Si `s2` est vide → match uniquement si `s1` est aussi vide
- Si `s2[0] == '*'` → deux cas : `*` consomme 0 caractère (`wildcmp(s1, s2+1)`) ou 1 caractère de `s1` (`wildcmp(s1+1, s2)`)
- Sinon → les caractères doivent être identiques, on avance dans les deux chaînes

### Fichiers

| Fichier | Description |
|---------|-------------|
| `0-wildcmp.c` | Implémentation de la fonction |
| `holberton.h` | Header avec le prototype |
