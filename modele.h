#include <vector>
#include <SDL2/SDL.h>
using namespace std;

extern int QUATRE;

const int GAUCHE = 113, DROITE = 100, HAUT = 122, BAS = 115;
typedef vector<vector<int>> Plateau;


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
bool estRempli(Plateau plateau);


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


// Les fonctions utilisées pas l'interface graphique
int pourcentage(int p, int size);
bool touche_bouton(SDL_Rect btn, int x, int y);
vector<vector<int>> titre_menu(int pourcentage_x, int taille_block);
SDL_Texture * create_text(SDL_Renderer * renderer, char * text, SDL_Color color, int font_size = 80);
SDL_Texture * genere_cube(SDL_Renderer * renderer);
vector<SDL_Texture*> textFromPlateau(SDL_Renderer * renderer, Plateau plateau, SDL_Color color, vector<SDL_Texture*> textureTextTable);


Plateau plateauVideVariante();
Plateau ajouteDeux(Plateau plateau);
int scoreVariante(Plateau plateau);
Plateau plateauInitialVariante();
bool estGagnantVariante(Plateau p);