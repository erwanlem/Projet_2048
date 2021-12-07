# Projet_2048
Création du jeu 2048


## Niveau 2

Fichiers similaires à ceux du niveau 1.  
Ajout d'un fichier makefile  


* Utilisation de la librairie ncurses

**Installation librairie(s):**
  * ncurses:  
  sudo apt-get install libncurses5-dev

**COMPILATION (MANUELLE):**
  
  1. g++ -c 2048.cpp
  2. g++ -c modele.cpp
  3. g++ modele.o 2048.o -o 2048

**COMPILATION MAKEFILE:**
 
  Utiliser commande 'make' -> création d'un executable '2048'
  
 
 * Toutes les fonctions de test sont écrites par l'auteur de la fonction de base (sauf indication).

### Fichiers associés au niveau 2:

    modele.cpp:
             Contient toutes les fonctions de base du jeu
    2048.cpp  :
             Fichier contenant la fonction main permettant de faire fonctionner le jeu
    modele.h :
             Contient les en-têtes des fonctions implentées ainsi que leur documentation
    makefile  :
             Instructions de compilation avec la commande make
