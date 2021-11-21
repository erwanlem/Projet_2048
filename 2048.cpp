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
            printw("Score: %d\n\n",score(plateau.plateau, plateau.deplacements));
            dessine(plateau.plateau);
            touche = getch();
            plateau.plateau = deplacement(plateau.plateau, (int)touche);
            plateau.deplacements += 1;
            if ( !estRempli(plateau.plateau) ){
                plateau.plateau = ajouteDeuxOuQuatre(plateau.plateau);
            }
            dessine(plateau.plateau);
            refresh();
       }
       if (estGagnant(plateau.plateau)){
           printw("Vous aez gagné !\n");
       } else {
           printw("Oups... Vous avez perdu\n");
       }
       

        string rejouer;
        cout << "Rejouer ? (y/n) >>" << endl;
        cin  >> rejouer;
        if (rejouer[0] == 'y'){
            jeu = true;
        } else {
            jeu = false;
        }
    } while (jeu == true);

    endwin();
    return 0;
}

