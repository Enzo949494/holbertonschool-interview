# Infinite Multiplication

Ce programme multiplie deux nombres positifs de taille arbitraire (potentiellement très grands).

## Description

Le programme utilise l'algorithme de multiplication traditionnel (comme enseigné à l'école) pour multiplier deux nombres représentés sous forme de chaînes de caractères. Cela permet de gérer des nombres qui dépassent la capacité des types de données standard en C.

## Algorithme

L'algorithme fonctionne comme suit :
1. Multiplie chaque chiffre de `num1` par chaque chiffre de `num2`
2. Place les résultats partiels aux bonnes positions
3. Gère les retenues (carry)
4. Stocke le résultat dans un tableau d'entiers
5. Affiche le résultat en évitant les zéros de tête

## Fichiers

- `0-mul.c` : Programme principal avec l'algorithme de multiplication
- `_putchar.c` : Fonction pour afficher un caractère
- `main.h` : Fichier d'en-tête avec les prototypes
- `Makefile` : Fichier de compilation

## Compilation

```bash
gcc -Wall -pedantic -Werror -Wextra 0-mul.c _putchar.c -o mul
```

Ou simplement :
```bash
make
```

## Utilisation

```bash
./mul num1 num2
```

### Paramètres
- `num1` : Premier nombre positif (base 10)
- `num2` : Deuxième nombre positif (base 10)

### Codes de sortie
- `0` : Succès
- `98` : Erreur (nombre d'arguments incorrect ou caractères non-numériques)

## Exemples

```bash
$ ./mul 10 98
980

$ ./mul 123 456
56088

$ ./mul 0 999
0

$ ./mul 235234693269436436223446526546334576437634765378653875874687649698659586695898579 28658034365084365083426083109679137608216408631430814308651084650816406134060831608310853086103769013709675067130586570832760732096730978014607369739567864508634086304807450973045703428580934825098342095832409850394285098342509834209583425345267413639235755891879970464524226159074760914989935413350556875770807019893069201247121855122836389417022552166316010013074258781583143870461182707893577849408672040555089482160343085482612348145322689883025225988799452329290281169927532160590651993511788518550547570284574715925006962738262888617840435389140329668772644708
6741363923575589187997046452422615907476091498993541335055687577080701989306920124712185512283638941702255216631601001307425878158314387046118270789357784940867204055508948216034308548261234814532268988302522598879945232929028116992753216059081057377926651337612618248332113256902485974371969385156015068813868274000683912187818601667058605418678284322237297213673482412392922068159291496274311170208689056585352782844484721140846367741649962638649229509281867896067208474178402156294978940712959518351846413859141792380853313812015295333546716634344284086426775480775747808150030732119704867805688704303461042373101473485092019906795014369069932
```

### Gestion d'erreurs

```bash
$ ./mul
Error
(exit status: 98)

$ ./mul 12a 45
Error
(exit status: 98)

$ ./mul 12 45 78
Error
(exit status: 98)
```

## Tests

Pour exécuter les tests :
```bash
make test
```

## Complexité

- **Temps** : O(n × m) où n et m sont les longueurs de num1 et num2
- **Espace** : O(n + m) pour stocker le résultat

## Auteur

Projet Holberton School - Interview Preparation
