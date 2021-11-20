#include <iostream>
#include <time.h>
#include "modele.h"

using namespace std;

<<<<<<< HEAD

struct Partie {
    int score;
    Plateau plateau;
    int quatre;
};

=======
>>>>>>> parent of d85094f (Niveau 1 - Avance)

int main(int argc, char const *argv[])
{
    // Initialisation du temps pour l'aléatoire
    srand((int)time(0));

    bool jeu = true;
    int touche_int, quatre, s;
    string touche;
    Plateau plateau;

    do
    {
<<<<<<< HEAD
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
                plateau.plateau = ajouteDeuxOuQuatre(plateau);
=======
        plateau = plateauVide();
        plateau = plateauInitial();
        s = 0;
        quatre  = 0;
        while ( !estGagnant(plateau) &&  !estTermine(plateau) ){
            cout << "\nScore: " << score(plateau) << "\n\n";
            dessine(plateau);
            cout << "\nEntrer commande (z/q/s/d) >>";
            cin  >> touche;
            cout << endl;
            touche_int = (int)touche[0];
            plateau    = deplacement(plateau, touche_int);
            if ( !estRempli(plateau) ){
                plateau = ajouteDeuxOuQuatre(plateau);
>>>>>>> parent of d85094f (Niveau 1 - Avance)
            }
       }
       dessine(plateau);
       if (estGagnant(plateau)){
           cout << "Vous avez gagné !" << endl;
       } else {
           cout << "Vous avez perdu !" << endl;
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
   
    return 0;
}

