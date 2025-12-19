# Recherche Binaire Avancée

## Description

Ce projet implémente une **recherche binaire avancée** qui trouve l'index de la **première occurrence** d'une valeur dans un tableau trié d'entiers.

## Fonctionnalités

- ✅ Recherche récursive dans un tableau trié
- ✅ Retourne l'index de la première occurrence (si la valeur apparaît plusieurs fois)
- ✅ Affiche chaque sous-tableau exploré pendant la recherche
- ✅ Gère les cas limites (tableau NULL, valeur non trouvée)
- ✅ Complexité temporelle : **O(log n)**

## Installation

```bash
gcc -Wall -Wextra -Werror -pedantic 0-main.c 0-advanced_binary.c -o 0-advanced_binary
```

## Utilisation

```bash
./0-advanced_binary
```

## Fichiers

- `0-advanced_binary.c` - Implémentation de la recherche binaire
- `search_algos.h` - Fichier header avec le prototype de la fonction
- `0-main.c` - Programme de test

---

## Concept Simplifié : Comment Fonctionne la Recherche Binaire

### Le Problème
Vous avez un tableau de 10 nombres triés et vous cherchez le chiffre 5. Au lieu de vérifier chaque nombre un par un (ce qui prendrait du temps), vous pouvez être plus malin !

### La Solution : Diviser pour Conquérir

**Étape 1 : Couper le tableau en deux**
```
Tableau : [0, 1, 2, 5, 5, 6, 6, 7, 8, 9]
         ^                            ^
      Gauche                       Droite
      
Milieu = 5 (c'est l'index 4)
```

**Étape 2 : Regarder le milieu et décider**
- Si le milieu = 5 → Trouvé ! Mais c'est peut-être pas le premier... vérifiez à gauche
- Si le milieu < 5 → Le nombre est forcément à **droite** (car le tableau est trié)
- Si le milieu > 5 → Le nombre est forcément à **gauche**

**Étape 3 : Recommencer avec la moitié choisie**
```
Exemple : Si on cherche 5 et le milieu = 6
→ 5 est plus petit que 6
→ On cherche dans la moitié gauche

Nouvelle recherche : [0, 1, 2, 5, 5]
```

### Avantage
Au lieu de vérifier 10 éléments, on en vérifie seulement 3-4 ! Et plus le tableau est grand, plus on économise de vérifications.