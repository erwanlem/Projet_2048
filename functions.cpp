#include <iostream>
#include <vector>
#include <assert.h>
#include <cmath>
#include <time.h>
#include <conio.h> // Pour getch() (à voir plus tard)
#include "modele.h"


using namespace std;


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


