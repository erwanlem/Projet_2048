# Projet_2048
Création du jeu 2048


## Niveau 2

Fichiers similaires à ceux du niveau 1.
Ajout d'un fichier makefile

-> Utilisation de la librairie ncurses

Installation librairie(s):
  ncurses:
      sudo apt-get install libncurses5-dev

**COMPILATION (MANUELLE):**
  
  1. g++ -c 2048.cpp
  2. g++ -c modele.cpp
  3. g++ modele.o 2048.o -o 2048

**COMPILATION MAKEFILE:**
 
  Utiliser commande 'make' -> création d'un executable '2048'
  
 
 Toutes les fonctions de test sont écrites par l'auteur de la fonction de base (sauf indication).
