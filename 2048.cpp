#include <vector>
#include <iostream>
#include "modele.h"

using namespace std;

const int GAUCHE = 7, DROITE = 4, HAUT = 8, BAS = 2;
typedef vector<vector<int>> Plateau;

Plateau deplacement(Plateau plateau, int direction) {
  switch ( direction ) {
    case GAUCHE:
      return deplacementGauche(plateau);
    case DROITE:
      return deplacementDroite(plateau);
    case HAUT:
      return deplacementHaut(plateau);
    case BAS:
      return deplacementBas(plateau);
    default:
      cerr << "Deplacement non-autorise!" << endl;
      exit(-1);
  }
}

int main(int argc, char const *argv[])
{
    testEstTermine();
    // Initialisation du temps pour l'aléatoire
    srand((int)time(0));

    bool jeu = true;
    int touche_int, quatre, s;
    string touche;
    Plateau plateau;

    do
    {
        plateau = plateauVide();
        plateau = plateauInitial(plateau);
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

