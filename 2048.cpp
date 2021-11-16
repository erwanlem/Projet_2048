#include <vector>
#include <iostream>

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
  /* code */
  return 0;
}

