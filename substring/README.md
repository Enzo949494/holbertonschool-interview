# Substring with Concatenated Words

## Tâche 0 — find_substring

Fonction qui trouve tous les indices de départ des sous-chaînes d'une chaîne `s` qui sont une concaténation exacte de tous les mots du tableau `words`.

**Prototype :** `int *find_substring(char const *s, char const **words, int nb_words, int *n);`

- Tous les mots ont la même longueur
- Chaque mot doit apparaître exactement une fois, sans caractères intermédiaires
- Retourne un tableau alloué d'indices, ou `NULL` si aucune solution

### Exemple

```
./a.out barfoothefoobarman foo bar     -> Indices -> [0, 9]
./a.out wordgoodgoodgoodbestword word good best word  -> Indices -> []
./a.out wordgoodgoodgoodbestword word good best good  -> Indices -> [8]
```

### Algorithme

Pour chaque position `i` dans `s` (jusqu'à `len(s) - window_len`) :
- Découpe la fenêtre en `nb_words` chunks de `word_len` caractères
- Vérifie que chaque chunk correspond à un mot non encore utilisé
- Si tous les mots sont consommés exactement une fois → index valide

### Fichiers

| Fichier | Description |
|---------|-------------|
| `substring.c` | Implémentation de la fonction |
| `substring.h` | Header avec le prototype |
