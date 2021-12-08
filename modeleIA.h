#include <vector>
using namespace std;

extern int QUATRE;

const int GAUCHE = 113, DROITE = 100, HAUT = 122, BAS = 115;
typedef vector<vector<int>> Plateau;

struct Deplacement{
    Plateau dep;
    int score;
};

Plateau plateauVide();
Plateau plateauInitial();
int tireDeuxOuQuatre();
Plateau ajouteDeuxOuQuatre(Plateau plateau);

Plateau deplacementGauche(Plateau plateau);
Plateau deplacementDroite(Plateau plateau);
Plateau deplacementHaut(Plateau plateau);
Plateau deplacementBas(Plateau plateau);
Plateau deplacement(Plateau plateau, int direction);

void dessine(Plateau plateau);
bool estTermine(Plateau plateau);
bool estGagnant(Plateau plateau);
int score(Plateau plateau);
int scoreNb(int nombre);
bool estRempli(Plateau plateau);

Deplacement ia(Plateau plateau,  int rec);

// Les fonctions de test
void testTireDeuxOuQuatre();
void testAjouteDeuxOuQuatre();
void testDeplacementGauche();
void testDeplacementDroite();
void testDeplacementHaut();
void testDeplacementBas();
void testDeplacement();
void testEstTermine();
void testPlateauInitial();
void testEstGagnant();
void testPlateauVide();
