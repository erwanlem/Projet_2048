#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

extern int WIDTH, HEIGHT; // largeur et hauteur de la fenêtre

const int GAUCHE = 113, DROITE = 100, HAUT = 122, BAS = 115;

typedef vector<vector<int>> Plateau;

struct Partie
{
    Plateau plateau;
    int quatre = 0;
};

// Fonction jeu de base
Plateau plateauVide();
Partie plateauInitial();
int tireDeuxOuQuatre();
Partie ajouteDeuxOuQuatre(Partie plateau);

Plateau deplacementGauche(Plateau plateau);
Plateau deplacementDroite(Plateau plateau);
Plateau deplacementHaut(Plateau plateau);
Plateau deplacementBas(Plateau plateau);
Plateau deplacement(Plateau plateau, int direction);

bool estTermine(Plateau plateau);
bool estGagnant(Plateau plateau);
int score(Partie plateau);
bool estRempli(Plateau plateau);



// Les fonctions de test de modele.cpp
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


// Les fonctions de test de variante .cpp
void testEstGagnantVariante();
void testPlateauVideVariante();
void testPlateauInitialVariante();
void testAjouteDeux();
void testScoreVraiante();


// Les fonctions de test de graphic_outils.cpp
void testPourcentage();
void testTouche_bouton();


// Les fonctions utilisées par l'interface graphique
int pourcentage(int p, int size);
bool touche_bouton(SDL_Rect btn, int x, int y);
vector<vector<int>> titre_menu(int pourcentage_x, int taille_block);
SDL_Texture * create_text(SDL_Renderer * renderer, char * text, SDL_Color color, int font_size = 160);
SDL_Texture * genere_cube(SDL_Renderer * renderer);
vector<SDL_Texture*> textFromPlateau(SDL_Renderer * renderer, Plateau plateau, SDL_Color color, vector<SDL_Texture*> textureTextTable);
vector<int> transfertFichier(int cat, int data, int action);


// Fonctions de variante
Plateau plateauVideVariante();
Plateau ajouteDeux(Plateau plateau);
int scoreVariante(Plateau plateau);
Plateau plateauInitialVariante();
bool estGagnantVariante(Plateau p);


// Fonctions fenêtres du jeu
int victoire(SDL_Renderer * renderer, int game);
int defaite(SDL_Renderer * renderer, int game);
int menu(SDL_Renderer * renderer, SDL_Window * window);
int game(SDL_Renderer * renderer);
int game_128(SDL_Renderer * renderer);
