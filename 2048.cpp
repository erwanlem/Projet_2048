#include <iostream>
#include <time.h>
#include "modele.h"
#include <ncurses.h>


using namespace std;



int main(int argc, char const *argv[])
{
    testEstGagnant();
    // Initialisation du temps pour l'aléatoire
    srand((int)time(0));

    initscr();
    keypad(stdscr, true);
    start_color();

    bool jeu = true;
    int touche, quatre, s;
    Partie plateau;
    Plateau lastPlateau;

    do
    {   
        init_pair(10, COLOR_BLUE, COLOR_BLACK);
        init_pair(11, COLOR_RED, COLOR_BLACK);
        plateau = plateauInitial();
        while ( !estGagnant(plateau.plateau) &&  !estTermine(plateau.plateau) ){
            clear();
            attron(COLOR_PAIR(10));
            printw("\n\n ################## 2048 ##################\n #### Utiliser les flèches pour jouer #####\n #### Cliquer sur echap pour quitter  #####");
            attroff(COLOR_PAIR(10));
            attron(COLOR_PAIR(11));
            printw("\n\n\n\tScore: %d\n\n",score(plateau));
            attroff(COLOR_PAIR(11));
            dessine(plateau.plateau);
            touche = getch();
            lastPlateau = plateau.plateau;
            plateau.plateau = deplacement(plateau.plateau, (int)touche);
            if ( !estRempli(plateau.plateau) && lastPlateau != plateau.plateau){
                plateau = ajouteDeuxOuQuatre(plateau);
            }
            refresh();
       }
       clear();
       dessine(plateau.plateau);
       if (estGagnant(plateau.plateau) && estTermine(plateau.plateau)){
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

