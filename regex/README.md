# Regex

## Tâche 0 — regex_match

Fonction qui vérifie si un pattern correspond à une chaîne.

**Prototype :** `int regex_match(char const *str, char const *pattern);`

- Retourne `1` si le pattern correspond, `0` sinon
- `str` peut être vide, ne contient pas `.` ni `*`
- `pattern` peut être vide, peut contenir `.` et `*`
- `.` correspond à n'importe quel caractère unique
- `*` correspond à zéro ou plusieurs occurrences du caractère précédent

### Algorithme

Approche récursive :
- Si `pattern` est vide → match uniquement si `str` est aussi vide
- Si le caractère suivant dans `pattern` est `*` → deux cas : consomme zéro occurrence (`regex_match(str, pattern+2)`) ou avance dans `str` tant que le caractère courant correspond
- Sinon → le caractère courant doit correspondre (`.` ou égalité), on avance dans les deux

### Fichiers

| Fichier | Description |
|---------|-------------|
| `regex.c` | Implémentation de la fonction |
| `regex.h` | Header avec le prototype |
