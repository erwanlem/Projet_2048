# Projet_2048
Création du jeu 2048

## Niveau 1

* utilisation de la librairie ncurses

**Installation librairie(s):**
* ncurses:  
          sudo apt-get install libncurses5-dev
      
**COMPILATION:**

  1. g++ -c 2048.cpp
  2. g++ -c modele.cpp
  3. g++ modele.o 2048.o -lncurses -o 2048  
  


* Toutes les fonctions de test sont écrites par l'auteur de la fonction de base (sauf indication).

### Fichiers associés au niveau 1:

    modele.cpp:
             Contient toutes les fonctions de base du jeu
    2048.cpp  :
             Fichier contenant la fonction main permettant de faire fonctionner le jeu
