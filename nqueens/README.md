# Le Problème des N Reines (N Queens)

Ce projet implémente une solution au célèbre problème des N reines en utilisant l'algorithme de backtracking.

## Description

Le problème des N reines est un puzzle classique en informatique et en mathématiques. Le défi consiste à placer N reines sur un échiquier de taille N×N de manière à ce qu'aucune reine ne puisse en attaquer une autre.

### Contexte historique

Ce problème a été popularisé par la joueuse d'échecs **Judit Polgár**, considérée comme la plus forte joueuse d'échecs féminine de tous les temps. Le problème des 8 reines a été posé pour la première fois en 1848 par le joueur d'échecs Max Bezzel.

### Règles des échecs - La reine

Aux échecs, une reine peut attaquer dans 8 directions :
- Horizontalement (gauche et droite)
- Verticalement (haut et bas)
- Diagonalement (4 directions diagonales)

Pour qu'aucune reine ne s'attaque, il faut qu'elles ne partagent ni :
- La même ligne
- La même colonne
- La même diagonale

## Fichier du projet

- **`0-nqueens.py`** - Programme Python qui résout le problème des N reines

## Utilisation

```bash
./0-nqueens.py N
```

### Paramètres
- **`N`** : Taille de l'échiquier (entier ≥ 4)

### Validation des entrées

Le programme valide rigoureusement les entrées :

1. **Nombre d'arguments** : Exactement 1 argument requis
   ```bash
   $ ./0-nqueens.py
   Usage: nqueens N
   ```

2. **N doit être un nombre entier**
   ```bash
   $ ./0-nqueens.py abc
   N must be a number
   ```

3. **N doit être au moins 4**
   ```bash
   $ ./0-nqueens.py 3
   N must be at least 4
   ```

### Format de sortie

Chaque solution est affichée sous forme de liste de coordonnées `[ligne, colonne]` :
- Chaque paire représente la position d'une reine
- `[0, 1]` signifie : reine à la ligne 0, colonne 1
- Une solution par ligne

## Exemples d'exécution

### Échiquier 4×4
```bash
$ ./0-nqueens.py 4
[[0, 1], [1, 3], [2, 0], [3, 2]]
[[0, 2], [1, 0], [2, 3], [3, 1]]
```

**Visualisation de la première solution :**
```
. Q . .    (ligne 0, colonne 1)
. . . Q    (ligne 1, colonne 3)
Q . . .    (ligne 2, colonne 0)
. . Q .    (ligne 3, colonne 2)
```

### Échiquier 6×6
```bash
$ ./0-nqueens.py 6
[[0, 1], [1, 3], [2, 5], [3, 0], [4, 2], [5, 4]]
[[0, 2], [1, 5], [2, 1], [3, 4], [4, 0], [5, 3]]
[[0, 3], [1, 0], [2, 4], [3, 1], [4, 5], [5, 2]]
[[0, 4], [1, 2], [2, 0], [3, 5], [4, 3], [5, 1]]
```

### Échiquier 8×8
L'échiquier classique a **92 solutions** !
```bash
$ ./0-nqueens.py 8 | wc -l
92
```

## Algorithme : Backtracking

### Principe général

Le **backtracking** (retour sur trace) est une technique algorithmique qui explore systématiquement toutes les possibilités en abandonnant dès qu'on détecte qu'une solution partielle ne peut pas mener à une solution complète.

### Comment ça fonctionne ?

1. **Placement progressif** : On place les reines ligne par ligne
2. **Validation** : À chaque placement, on vérifie si la position est sûre
3. **Récursion** : Si la position est valide, on passe à la ligne suivante
4. **Backtrack** : Si aucune position n'est valide, on revient en arrière
5. **Solution trouvée** : Quand on a placé N reines, on a une solution

### Exemple visuel (N=4)

```
Étape 1: Essayer colonne 0, ligne 0
Q . . .
. . . .
. . . .
. . . .

Étape 2: Ligne 1 - colonnes 0,1 attaquées, essayer colonne 2
Q . . .
. . Q .
. . . .
. . . .

Étape 3: Ligne 2 - toutes les colonnes attaquées!
BACKTRACK → Retour à ligne 1

Étape 4: Essayer colonne 3 à ligne 1
Q . . .
. . . Q
. . . .
. . . .

Étape 5: Continue jusqu'à trouver une solution...
. Q . .
. . . Q
Q . . .
. . Q .
```

## Structure du code

### 1. Fonction `is_safe(board, row, col, n)`

Vérifie si on peut placer une reine en toute sécurité.

```python
def is_safe(board, row, col, n):
    for queen in board:
        # Même colonne
        if queen[1] == col:
            return False
        # Même diagonale
        if abs(queen[0] - row) == abs(queen[1] - col):
            return False
    return True
```

**Vérifications effectuées :**

1. **Colonne** : `queen[1] == col`
   - Vérifie qu'aucune reine n'est dans la même colonne

2. **Diagonale** : `abs(queen[0] - row) == abs(queen[1] - col)`
   - Si la différence des lignes égale la différence des colonnes
   - Alors les reines sont sur la même diagonale

**Pourquoi pas de vérification de ligne ?**
- On place une seule reine par ligne (ligne par ligne)
- Donc impossible d'avoir deux reines sur la même ligne

**Explication de la diagonale :**

Sur un échiquier, deux cases sont sur la même diagonale si :
```
|ligne1 - ligne2| = |colonne1 - colonne2|
```

Exemple :
- Case [2, 3] et case [4, 5] :
  - Différence lignes : |2 - 4| = 2
  - Différence colonnes : |3 - 5| = 2
  - 2 == 2 → Même diagonale ✓

### 2. Fonction `solve_nqueens(n, row, board, solutions)`

Résout le problème récursivement avec backtracking.

```python
def solve_nqueens(n, row, board, solutions):
    # Cas de base : toutes les reines placées
    if row == n:
        solutions.append(board[:])
        return

    # Essayer chaque colonne
    for col in range(n):
        if is_safe(board, row, col, n):
            board.append([row, col])           # Placer la reine
            solve_nqueens(n, row + 1, board, solutions)  # Récursion
            board.pop()                        # Backtrack
```

**Étapes détaillées :**

1. **Condition d'arrêt** : `if row == n`
   - Toutes les lignes ont une reine → solution complète
   - On sauvegarde une copie : `board[:]`

2. **Exploration** : `for col in range(n)`
   - Teste chaque colonne de la ligne actuelle

3. **Validation** : `if is_safe(...)`
   - Vérifie si le placement est sûr

4. **Placement** : `board.append([row, col])`
   - Ajoute la reine à la position

5. **Récursion** : `solve_nqueens(n, row + 1, ...)`
   - Passe à la ligne suivante

6. **Backtrack** : `board.pop()`
   - Retire la reine pour essayer d'autres positions
   - C'est le cœur du backtracking !

### 3. Fonction `main()`

Gère les entrées et affiche les résultats.

```python
def main():
    # Validation des arguments
    if len(sys.argv) != 2:
        print("Usage: nqueens N")
        sys.exit(1)

    # Validation du type
    try:
        n = int(sys.argv[1])
    except ValueError:
        print("N must be a number")
        sys.exit(1)

    # Validation de la valeur
    if n < 4:
        print("N must be at least 4")
        sys.exit(1)

    # Résolution
    solutions = []
    solve_nqueens(n, 0, [], solutions)

    # Affichage
    for solution in solutions:
        print(solution)
```

## Complexité

### Complexité temporelle
**O(N!)** - Factorielle

- Au pire cas, on explore N! possibilités
- N=4 : 24 possibilités maximum
- N=8 : 40 320 possibilités maximum
- Mais le backtracking élimine beaucoup de branches

### Complexité spatiale
**O(N)** - Linéaire

- Profondeur de récursion : N (une par ligne)
- Stockage du plateau : N positions
- Pas de tableau 2D nécessaire !

### Nombre de solutions

| N  | Nombre de solutions |
|----|---------------------|
| 4  | 2                   |
| 5  | 10                  |
| 6  | 4                   |
| 7  | 40                  |
| 8  | 92                  |
| 9  | 352                 |
| 10 | 724                 |

## Concepts clés

### 1. Backtracking (Retour sur trace)

Technique d'exploration exhaustive qui :
- Construit des solutions partielles
- Abandonne dès qu'une contrainte est violée
- Revient en arrière pour explorer d'autres chemins

### 2. Récursion

La fonction `solve_nqueens` s'appelle elle-même :
- Divise le problème en sous-problèmes plus petits
- Chaque appel traite une ligne de l'échiquier
- La pile d'appels représente l'état du plateau

### 3. Validation intelligente

Au lieu de générer toutes les combinaisons puis de filtrer :
- On vérifie **avant** de placer une reine
- Économise énormément de calculs inutiles
- C'est ce qui rend le backtracking efficace

### 4. Représentation efficace

On utilise une liste de coordonnées `[[0,1], [1,3], ...]` :
- Pas besoin d'un tableau 2D
- Une seule reine par ligne garantie
- Économie de mémoire

## PEP 8

Le code respecte le guide de style Python PEP 8 :
- Indentation de 4 espaces
- Lignes de maximum 79 caractères
- Docstrings pour toutes les fonctions
- Noms de variables descriptifs en snake_case
- Espaces autour des opérateurs

Vérification :
```bash
pycodestyle 0-nqueens.py
```

## Exigences techniques

- **Interpréteur** : Python 3 (version 3.4.3)
- **Système** : Ubuntu 14.04 LTS
- **Shebang** : `#!/usr/bin/python3`
- **Permissions** : Fichier exécutable (`chmod +x`)
- **Imports** : Uniquement `sys`
- **Style** : PEP 8 (version 1.7.*)

## Ressources

- [Problème des huit reines (Wikipedia)](https://fr.wikipedia.org/wiki/Problème_des_huit_reines)
- [Backtracking (Wikipedia)](https://fr.wikipedia.org/wiki/Retour_sur_trace)
- [PEP 8 - Style Guide for Python Code](https://www.python.org/dev/peps/pep-0008/)

## Auteur

Projet Holberton School - Algorithmes d'entretien
