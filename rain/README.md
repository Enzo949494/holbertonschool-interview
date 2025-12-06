# Probleme de retention d'eau de pluie

## Description

Ce projet resout le **probleme de piege a eau de pluie** : etant donne une liste d'entiers non-negatifs representant des hauteurs de murs, calculer combien d'unites carrees d'eau seront retenues apres la pluie.

## Probleme

Imaginez des murs de differentes hauteurs alignes. Quand il pleut, l'eau reste piegee entre les murs. Le but est de calculer le volume total d'eau piegee.

### Exemple visuel

```
Murs: [0, 1, 0, 2, 0, 3, 0, 4]

       |
   |www|    w = eau piegee
   |w|w|    | = mur
 |w|w|w|
 --------
Resultat: 6 unites carrees d'eau
```

## Algorithme

La solution utilise une **approche de precalcul avec deux tableaux** :

1. **Tableau Max Gauche** : Pour chaque position, stocker la hauteur maximale de mur a sa gauche
2. **Tableau Max Droite** : Pour chaque position, stocker la hauteur maximale de mur a sa droite
3. **Calcul de l'eau** : A chaque position, niveau d'eau = `min(max_gauche, max_droite) - hauteur_mur`

### Complexite
- **Temps** : O(n) - Trois passages dans le tableau
- **Espace** : O(n) - Deux tableaux auxiliaires

## Exigences

- Python 3.4.3
- Ubuntu 14.04 LTS
- Style PEP 8 (version 1.7.x)
- Aucun module externe autorise

## Fichiers

- `0-rain.py` - Implementation de la fonction principale
- `0_main.py` - Fichier de test avec exemples

## Utilisation

```bash
./0_main.py
```

### Prototype de la fonction

```python
def rain(walls)
```

**Parametres :**
- `walls` (list) : Liste d'entiers non-negatifs representant les hauteurs de murs

**Retour :**
- `int` : Quantite totale d'eau de pluie retenue

**Cas limites :**
- Liste vide retourne 0
- Listes avec moins de 3 elements retournent 0
- Les extremites de la liste ne retiennent pas d'eau

## Exemple

```python
#!/usr/bin/python3
rain = __import__('0-rain').rain

walls = [0, 1, 0, 2, 0, 3, 0, 4]
print(rain(walls))  # Sortie: 6

walls = [2, 0, 0, 4, 0, 0, 1, 0]
print(rain(walls))  # Sortie: 6
```

## Auteur

Holberton School - Projet de preparation aux entretiens
