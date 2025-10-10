# 🔤 Validateur UTF-8

> *Un algorithme élégant pour valider l'encodage UTF-8 en Python*

---

## 🎯 Objectif

Développer une méthode robuste qui détermine si un ensemble de données représente un **encodage UTF-8 valide**. Ce projet fait partie des défis d'algorithmique avancée.

## 🚀 Fonctionnalité

```python
def validUTF8(data) -> bool
```

**✨ Caractéristiques :**
- ✅ Validation complète des séquences UTF-8 (1 à 4 octets)
- ✅ Gestion des caractères multi-octets
- ✅ Vérification des bits de continuation
- ✅ Optimisé pour les performances

## 📋 Spécifications Techniques

| Critère | Description |
|---------|-------------|
| 🔄 **Entrée** | Liste d'entiers (chaque entier = 1 octet) |
| ↩️ **Sortie** | `True` si UTF-8 valide, `False` sinon |
| 🎛️ **Traitement** | 8 bits moins significatifs uniquement |
| 📏 **Taille caractère** | 1 à 4 octets par caractère |

## 🔧 Règles d'Encodage UTF-8

### 📊 Patterns Binaires

| Type | Pattern | Exemple |
|------|---------|---------|
| **1 octet** | `0xxxxxxx` | ASCII (0-127) |
| **2 octets** | `110xxxxx 10xxxxxx` | Caractères étendus |
| **3 octets** | `1110xxxx 10xxxxxx 10xxxxxx` | Caractères Unicode |
| **4 octets** | `11110xxx 10xxxxxx 10xxxxxx 10xxxxxx` | Émojis, symboles |

### 🔍 Algorithme de Validation

1. **Analyse du premier octet** → Détermine la longueur du caractère
2. **Vérification des octets de continuation** → Pattern `10xxxxxx`
3. **Validation de la séquence complète** → Aucun octet manquant

## 💻 Exemples d'Utilisation

```python
#!/usr/bin/python3
validUTF8 = __import__('0-validate_utf8').validUTF8

# ✅ Caractère ASCII simple
data = [65]  # 'A'
print(validUTF8(data))  # True

# ✅ Phrase complète
data = [80, 121, 116, 104, 111, 110, 32, 105, 115, 32, 99, 111, 111, 108, 33]
print(validUTF8(data))  # True ("Python is cool!")

# ❌ Séquence invalide
data = [229, 65, 127, 256]
print(validUTF8(data))  # False
```

## 📁 Structure du Projet

```
utf8_validation/
├── 📄 0-validate_utf8.py    # 🧠 Logique de validation
├── 🧪 0-main.py            # 🔬 Tests et démonstration
└── 📖 README.md            # 📚 Documentation
```

## 🎓 Concepts Clés

- **🔢 Manipulation binaire** : Opérations sur bits et masques
- **🔄 Machine à états** : Suivi des octets de continuation
- **✅ Validation de protocole** : Respect des standards UTF-8
- **⚡ Optimisation** : Algorithme en O(n) linéaire

---

*Développé dans le cadre du programme d'algorithmique avancée • Holberton School*