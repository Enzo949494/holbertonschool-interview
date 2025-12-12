# Heap Sort

## Description
Implémentation de l'algorithme de tri Heap Sort qui trie un tableau d'entiers en ordre ascendant.

## Fonctionnalités
- Tri par tas utilisant l'algorithme sift-down
- Affichage du tableau après chaque échange d'éléments

## Concept de Heap Sort

### Qu'est-ce qu'un Heap (Tas) ?
Un heap est une structure de données en forme d'arbre binaire où chaque parent est plus grand que ses enfants (max heap).

Exemple avec le tableau `[19, 48, 99, 71, 13]` :
```
       99
      /  \
    71    48
   / \
  19  13
```

### Comment fonctionne Heap Sort ?

1. **Construire un max heap** : On réorganise le tableau pour que le plus grand élément soit à la racine
2. **Extraire les éléments** : On échange le premier élément (le plus grand) avec le dernier, puis on réduit la taille du heap
3. **Sift-down** : On replace le nouvel élément à la racine à sa bonne position pour maintenir les propriétés du heap
4. **Répéter** : On continue jusqu'à ce que le heap ne contienne qu'un seul élément

### Résultat
À chaque itération, les plus grands éléments se retrouvent à la fin du tableau, trié en ordre ascendant.

## Fichiers
- `sort.h` : En-tête avec les prototypes des fonctions
- `0-heap_sort.c` : Implémentation de l'algorithme heap sort
- `0-O` : Complexité temporelle Big O

## Compilation
```bash
gcc -Wall -Wextra -Werror -pedantic 0-main.c 0-heap_sort.c print_array.c -o 0-heap
```

## Exécution
```bash
./0-heap
```

## Complexité Temporelle
- Meilleur cas : O(nlog(n))
- Cas moyen : O(nlog(n))
- Pire cas : O(nlog(n))

## Contraintes
- Pas de variables globales
- Maximum 5 fonctions par fichier
- Pas d'utilisation de la stdlib (sauf stdlib.h pour size_t)
- Tableau de moins de 2 éléments n'a pas besoin d'être trié
