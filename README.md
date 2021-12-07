# Projet_2048
Création du jeu 2048


## Niveau 3 

Librairies nécessaires:
  - SDL2
  - SDL_ttf 2.0
    -> L'utilisation de la librairies SDL_ttf peut nécessiter également celle
        de la librairie freetype6 (voir loir de l'installation)

Installation des librairies:  
* SDL2:  
sudo apt install libsdl2-dev  
* SDL_ttf:  
sudo apt install libsdl2-ttf-dev  
* freetype6 (pour SDL_ttf):  
sudo apt install libfreetype-dev libfreetype6
    
 
 **COMPILATION (MANUELLE):**
 
  1. g++ -c variante.cpp
  2. g++ -c graphic_outils.cpp
  3. g++ -c main.cpp
  4. g++ -c modele.cpp
  5. g++ -c windows.cpp
  6. g++ main.o modele.o windows.o variante.o graphic_outils.o -lSDL2_ttf -lSDL2 -lSDL2main -o 2048
  
 
 **COMPILATION MAKEFILE:**
 
 Utilisatin de la commande 'make' -> création de l'executable '2048'
 
 
 
 Toutes les fonctions de test sont écrites par l'auteur de la fonction de base (sauf indication).
 
 ### Fichiers associés au niveau 3:
    
    main.cpp :
          Fonction principale de l'interface graphique. Contient la fonction main qui gère le passage d'une fenêtre du jeu à une autre.
    windows.cpp :
          Fonctions des fenêtres de l'interface graphique. Chaque fonction correspond à un affichage différent dans le jeu. 
          Chaque fonction renvoie un entier correspondant au prochain affichage (la fonction main gère cette partie).
    graphic_outils.cpp :
          Fonctions utiles au fonctions principales de l'interface graphique (contenues dans windows.cpp).
    modele.cpp :
          Fonctions de base du jeu (mêmes fonctions qu'aux niveaux précédents)
    variante.cpp :
          Fonctions adaptées pour la variante du jeu (128 chrono). Les fonctions sont dérivées des fonctions de modele.cpp
    data :
          Contient les données de sauvegarde des meilleurs parties. On a dans l'ordre :
                                                                              - score (dernière partie jouée)
                                                                              - temps (dernière partie jouée de 128 chrono)
                                                                              - meilleurs score
                                                                              - meilleurs temps (128 chrono)
