# TP de compilation - Analyseur syntaxique et évaluation d'une expression arithmétique

## Description du projet

Ce projet implémente un analyseur syntaxique ascendant LALR(1) pour évaluer des expressions arithmétiques. Il est basé sur la grammaire suivante :

```
1) E' → E
2) E  → E + E
3) E  → E * E
4) E  → ( E )
5) E  → val
```

Les conflits de la table LALR(1) sont résolus ainsi :
- Associativité **gauche** de `+` : conflit d4/r2 → r2
- Associativité **gauche** de `*` : conflit d5/r3 → r3
- Priorité de `*` sur `+` : conflit d5/r2 → d5, conflit d4/r3 → r3

---

## Structure du projet

```bash
projet/
├── main.cpp          
├── tests.cpp         # Tests unitaires
├── lexer.cpp/h       # Analyseur lexical
├── automate.cpp/h    # Automate LALR
├── etat.cpp/h        # Classe abstraite Etat (design pattern State)
├── symbole.cpp/h     # Classes Symbole, Entier, Expr
├── makefile
└── Etats/            # dossiers de tous les états
    ├── E0.cpp/h      
    ├── E1.cpp/h      
    ├── E2.cpp/h     
    ├── E3.cpp/h      
    ├── E4.cpp/h   
    ├── E5.cpp/h    
    ├── E6.cpp/h    
    ├── E7.cpp/h     
    ├── E8.cpp/h    
    └── E9.cpp/h    
```

---

## Compilation et utilisation

### Compiler le programme principal
```bash
make
```

### Lancer le programme

Pour lancer le main, il suffit de taper dans la console: 

```bash
./analyser
```
Le programme va vous demander de rentrer une expression:

```bash
Entrez une expression : 
```
Ecrivez une expression mathématique avec les symboles _+_, _*_, _(_ et _)_

```bash
(1+2)*3
```
Le programme vous renverra le résultat:

```bash
Résultat = 9
```

### Lancer les tests

Il vous suffit de taper la commande suivante pour générer le fichier test .o, et lancer l'execution du fichier:

```bash
make test
```

### Nettoyer les fichiers compilés
```bash
make clean    # supprime les .o
make fclean   # supprime les .o et les exécutables
make re       # recompile tout
```

---

## Exemples

| Expression    | Résultat | Remarque                        |
|---------------|----------|---------------------------------|
| `42`          | 42       | Valeur simple                   |
| `1+2*3`       | 7        | Priorité * sur + : 1+(2*3)      |
| `(1+2)*3`     | 9        | Parenthèses changent la priorité|
| `1+2+3`       | 6        | Associativité gauche : (1+2)+3  |
| `1++2`        | erreur   | Syntaxe invalide                |

---

## Architecture

Le projet utilise le **design pattern State** :
- `Automate` contient deux piles : une pile d'**états** et une pile de **symboles**
- Chaque état implémente `transition()` qui décide de l'action selon le token courant
- Trois actions possibles : `decalage()`, `reduction()`, `transitionsimple()`



- ANTONIETTI Léa
- MERCUL Oïlhan