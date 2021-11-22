#include <iostream>
#include <time.h>
#include "modele.h"
#include <ncurses.h>

using namespace std;



int main(int argc, char const *argv[])
{
    // Initialisation du temps pour l'aléatoire
    srand((int)time(0));

    initscr();
    keypad(stdscr, true);
    start_color();

    bool jeu = true;
    int touche, quatre, s;
    Partie plateau;

    do
    {
        plateau.plateau = plateauVide();
        plateau.plateau = plateauInitial();
        plateau.deplacements  = 0;
        while ( !estGagnant(plateau.plateau) &&  !estTermine(plateau.plateau) ){
            clear();
            printw("Utiliser les flèches pour jouer\nCliquer sur toute autre touche pour quitter\n\n\n\tScore: %d\n\n",score(plateau.plateau, plateau.deplacements));
            dessine(plateau.plateau);
            touche = getch();
            Plateau p = deplacement(plateau.plateau, (int)touche);
            if ( !estRempli(p) ){
                p = ajouteDeuxOuQuatre(p);
            }
            if (p != plateau.plateau){
                plateau.deplacements += 1;
                plateau.plateau = p;
            }
            refresh();
       }
       clear();
       dessine(plateau.plateau);
       if (estGagnant(plateau.plateau)){
           printw("\n\n\tVous avez gagné !\nVous pouvez continuer de jouer...\n");
       } else {
           printw("\nOups... Vous avez perdu\n");
       }
       

        int rejouer;
        printw("Rejouer ? (y/n)");
        rejouer = getch();
        if ((int)rejouer == 121){
            jeu = true;
        } else {
            jeu = false;
        }
    } while (jeu == true);

    endwin();
    return 0;
}

