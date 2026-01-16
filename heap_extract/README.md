# Heap Extract

Ce projet implémente la fonction `heap_extract` qui extrait le nœud racine d'un tas binaire maximum (Max Binary Heap).

## Description

La fonction `heap_extract` effectue les opérations suivantes :
1. Extrait et retourne la valeur du nœud racine
2. Remplace la racine par le dernier nœud en ordre de niveau
3. Supprime le dernier nœud
4. Reconstruit le tas pour maintenir la propriété du tas max

## Fichiers

- `0-heap_extract.c` : Implémentation de la fonction `heap_extract`
- `binary_trees.h` : Fichier d'en-tête avec les structures et prototypes
- `0-main.c` : Programme de test principal
- `binary_tree_print.c` : Fonction d'affichage du tas
- `heap_helpers.c` : Fonctions auxiliaires pour construire le tas
- `Makefile` : Fichier de compilation

## Compilation

```bash
make
```

## Utilisation

```bash
./0-heap_extract
```

## Test avec Valgrind

```bash
make valgrind
```

## Prototype

```c
int heap_extract(heap_t **root);
```

### Paramètres
- `root` : Double pointeur vers le nœud racine du tas

### Valeur de retour
- La valeur stockée dans le nœud racine
- `0` en cas d'échec

## Exemple de sortie

```
                      .-----------------(098)-----------------.
            .-------(095)-------.                   .-------(091)-------.
       .--(084)--.         .--(079)--.         .--(087)--.         .--(062)--.
  .--(047)     (034)     (002)     (020)     (022)     (068)     (001)     (021)
(032)
Extracted: 98
                 .-----------------(095)-----------------.
       .-------(084)-------.                   .-------(091)-------.
  .--(047)--.         .--(079)--.         .--(087)--.         .--(062)--.
(032)     (034)     (002)     (020)     (022)     (068)     (001)     (021)
```

## Auteur

Projet Holberton School - Interview Preparation
