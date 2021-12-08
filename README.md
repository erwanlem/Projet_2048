# Projet_2048
Création du jeu 2048

## Mise en place du joueur automatique

**COMPILATION (MANUELLE):**
  
  1. g++ -c 2048_IA.cpp
  2. g++ -c modeleIA.cpp
  3. g++ modeleIA.o 2048_IA.o -o 2048_IA

**COMPILATION MAKEFILE:**
 
  Utiliser commande 'make' -> création d'un executable '2048_IA'

### Fichiers associés au joueur automatique:

    modeleIA.cpp :
             Contient toutes les fonctions de base du jeu et du joueur automatique 
    modeleIA.h :
          Contient les en-têtes des fonctions implentées ainsi que leur documentation
    2048_IA.cpp  :
             Fichier contenant la fonction main permettant de faire fonctionner le jeu
    makefile:
            Fichier permettant la compilation automatiquement.
