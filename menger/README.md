# Éponge de Menger (Menger Sponge)

Ce projet implémente une fonction qui dessine une éponge de Menger en 2D à un niveau spécifié.

## Description

L'éponge de Menger est une fractale tridimensionnelle créée par Karl Menger en 1926. C'est l'analogue tridimensionnel du tapis de Sierpiński. Dans ce projet, nous dessinons une version 2D simplifiée de cette structure fractale fascinante.

### Qu'est-ce qu'une fractale ?

Une fractale est une figure géométrique qui présente une structure similaire à toutes les échelles. L'éponge de Menger est un exemple parfait : chaque partie de la structure reproduit le motif global.

### Principe de construction

- **Niveau 0** : Un simple carré de 1×1 représenté par le caractère `#`
- **Niveau 1** : On divise l'espace en une grille 3×3, puis on laisse le centre vide
- **Niveau 2** : On applique le même principe à chaque sous-carré du niveau 1
- **Niveau N** : On continue récursivement le processus

### Formule de taille

La taille d'une éponge de Menger de niveau N est calculée par : **3^N**
- Niveau 0 : 3^0 = 1 (1×1)
- Niveau 1 : 3^1 = 3 (3×3)
- Niveau 2 : 3^2 = 9 (9×9)
- Niveau 3 : 3^3 = 27 (27×27)
- Niveau 4 : 3^4 = 81 (81×81)

## Fichiers du projet

- **`menger.h`** - Fichier d'en-tête contenant les prototypes et les includes nécessaires
- **`0-menger.c`** - Implémentation de la fonction menger et de ses fonctions auxiliaires
- **`0-main.c`** - Fichier de test (fourni à titre d'exemple)

## Prototype de la fonction

```c
void menger(int level);
```

### Paramètres
- **`level`** : Le niveau de l'éponge de Menger à dessiner
  - Si `level < 0`, la fonction ne fait rien (retour immédiat)
  - Si `level >= 0`, dessine l'éponge au niveau spécifié

### Comportement
- Affiche l'éponge caractère par caractère sur la sortie standard
- Utilise `#` pour les parties pleines
- Utilise ` ` (espace) pour les parties vides
- Chaque ligne se termine par un retour à la ligne `\n`

## Compilation

```bash
gcc -Wall -Wextra -Werror -pedantic -o 0-menger 0-menger.c 0-main.c -lm
```

### Flags de compilation
- **`-Wall`** : Active tous les avertissements principaux
- **`-Wextra`** : Active des avertissements supplémentaires
- **`-Werror`** : Traite les avertissements comme des erreurs
- **`-pedantic`** : Force le respect strict du standard C
- **`-lm`** : Lie la bibliothèque mathématique (pour la fonction `pow()`)

## Utilisation

```bash
./0-menger level
```

### Exemples d'exécution

#### Niveau 0 (1×1)
```bash
$ ./0-menger 0
#
```

#### Niveau 1 (3×3)
```bash
$ ./0-menger 1
###
# #
###
```
On voit la structure de base : une grille 3×3 avec le centre vide.

#### Niveau 2 (9×9)
```bash
$ ./0-menger 2
#########
# ## ## #
#########
###   ###
# #   # #
###   ###
#########
# ## ## #
#########
```
Chaque bloc de 3×3 du niveau 1 est remplacé par une copie du motif complet, sauf au centre.

#### Niveau -1 (cas limite)
```bash
$ ./0-menger -1
# (aucune sortie)
```

## Algorithme détaillé

### Vue d'ensemble

L'implémentation utilise une approche mathématique élégante basée sur la division modulaire plutôt qu'une approche récursive. Cela permet d'économiser de la mémoire et d'éviter les débordements de pile.

### Fonction principale : `menger(int level)`

```c
void menger(int level)
{
    int size, row, col;

    if (level < 0)
        return;

    size = pow(3, level);

    for (row = 0; row < size; row++)
    {
        for (col = 0; col < size; col++)
        {
            if (is_empty(row, col))
                printf(" ");
            else
                printf("#");
        }
        printf("\n");
    }
}
```

**Étapes :**
1. **Validation** : Si `level < 0`, retour immédiat
2. **Calcul de la taille** : `size = 3^level` (utilise `pow()` de `math.h`)
3. **Double boucle** : Parcourt chaque position (row, col)
4. **Décision** : Pour chaque position, détermine si elle doit être vide ou pleine
5. **Affichage** : Imprime `' '` ou `'#'` selon le résultat

### Fonction auxiliaire : `is_empty(int row, int col)`

```c
int is_empty(int row, int col)
{
    while (row > 0 || col > 0)
    {
        if (row % 3 == 1 && col % 3 == 1)
            return (1);
        row /= 3;
        col /= 3;
    }
    return (0);
}
```

**Principe mathématique :**

Cette fonction détermine si une position doit être vide en vérifiant à **toutes les échelles** si elle tombe au centre d'un bloc 3×3.

**Comment ça marche :**
1. On examine la position à différentes échelles (en divisant par 3)
2. À chaque échelle, on vérifie si la position modulo 3 est (1, 1) (le centre)
3. Si c'est le cas à **n'importe quelle échelle**, la position est vide

**Exemple concret :**
- Position (4, 4) au niveau 2 :
  - Échelle 1 : 4 % 3 = 1 et 4 % 3 = 1 → **CENTRE** → Vide ✓

- Position (0, 0) au niveau 2 :
  - Échelle 1 : 0 % 3 = 0 et 0 % 3 = 0 → Pas le centre
  - Échelle 2 : 0 / 3 = 0, terminé → Pleine ✓

- Position (1, 1) au niveau 1 :
  - Échelle 1 : 1 % 3 = 1 et 1 % 3 = 1 → **CENTRE** → Vide ✓

### Complexité

- **Temps** : O(size²) où size = 3^level
- **Espace** : O(1) (pas de récursion, pas de tableau)

## Contraintes respectées

✓ Pas de variables globales
✓ Maximum 5 fonctions par fichier (2 fonctions utilisées)
✓ Fichier d'en-tête `menger.h` avec include guards
✓ Utilisation de la bibliothèque mathématique (`-lm`)
✓ Gestion du cas `level < 0`

## Concepts clés

### 1. Les fractales
Structure auto-similaire à différentes échelles. Chaque zoom révèle la même structure.

### 2. Division modulaire
L'utilisation de `% 3` permet de déterminer la position relative dans un bloc 3×3 :
- 0 : gauche/haut
- 1 : centre
- 2 : droite/bas

### 3. Puissances de 3
La taille double (triple en fait) à chaque niveau, créant une croissance exponentielle.

### 4. Itération vs Récursion
Au lieu d'une approche récursive coûteuse en mémoire, on utilise une approche itérative avec des divisions successives.

## Auteur

Projet Holberton School - Algorithmes avancés