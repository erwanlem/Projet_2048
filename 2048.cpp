#include <iostream>
#include <time.h>
#include "modele.h"
#include <ncurses.h>

using namespace std;

struct Partie {
    int score;
    Plateau plateau;
    int quatre;
};


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
        plateau.quatre  = 0;
        while ( !estGagnant(plateau.plateau) &&  !estTermine(plateau.plateau) ){
            clear();
            printw("Score: %d\n\n",score(plateau.plateau, plateau.quatre));
            dessine(plateau.plateau);
            touche = getch();
            plateau.plateau = deplacement(plateau.plateau, (int)touche);
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

