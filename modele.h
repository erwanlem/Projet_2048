#include <vector>
using namespace std;

const int GAUCHE = 260, DROITE = 261, HAUT = 259, BAS = 258, QUITTER = 27;
typedef vector<vector<int>> Plateau;


struct Partie {
    int score;
    Plateau plateau;
    int quatre = 0;
};


Plateau plateauVide();
Partie plateauInitial();
int tireDeuxOuQuatre();
Partie ajouteDeuxOuQuatre(Partie plateau);

Plateau deplacementGauche(Plateau plateau);
Plateau deplacementDroite(Plateau plateau);
Plateau deplacementHaut(Plateau plateau);
Plateau deplacementBas(Plateau plateau);
Plateau deplacement(Plateau plateau, int direction);

void dessine(Plateau plateau);
bool estTermine(Plateau plateau);
bool estGagnant(Plateau plateau);
int score(Partie plateau);
bool estRempli(Plateau plateau);
void dessineCouleur(string plateau);


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
void testScore();