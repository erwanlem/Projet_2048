#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <iostream>
#include <vector>
#include <string>

using namespace std;


extern int WIDTH, HEIGHT; // largeur et hauteur de la fenêtre


const int GAUCHE = 113, DROITE = 100, HAUT = 122, BAS = 115;


typedef vector<vector<int>> Plateau;


// Structure de la partie
// -> contient le plateau et le nombre de 4 ajoutés sur la grille
struct Partie
{
    Plateau plateau;
    int quatre = 0;
};







/***********************************************/
/*********** Fonctions règles du jeu ***********/
/***********************************************/

/** Fonction plateauVide
 * créée un plateau de jeu vide
 * 
 * @return le plateau de type Plateau
 **/
Plateau plateauVide();



/** Fonction plateauInitial
 * Initialise le plateau
 * 
 * @return le plateau de jeu initialisé (de type Partie)
*/
Partie plateauInitial();




/** Fonction TireDeuxOuQuatre
 * 
 * @author Erwan Lemattre
 * @bug fonction testée, pas de difficulté rencontrée
 *      Confiance: 10/10
 * 
 * Fonction renvoyant 2 avec une proba de 8/10 ou 4 avec une proba de 2/10
 * 
 * @return un entier: soit 2, soit 4
 **/
int tireDeuxOuQuatre();




/** Fonction ajouteDeuxOuQuatre
 * Permet de choisir aléatoirement une case vide dans
 * le plateau et d'y ajouter soit 2, soit 4
 * Si un quatre apparait, la variable quatre de la 
 * struct Partie est incrémentée
 * 
 * @author Erwan Lemattre
 * @bug Fonction testée, pas de difficulté rencontrée
 *      Confiance: 10/10
 * 
 * @param plateau de type Partie, contient le plateau et les quatres
 * @return le plateau avec une nouvelle case remplie
 **/
Partie ajouteDeuxOuQuatre(Partie plateau);




/** Fonction deplacementGauche
 * Déplacement du plateau vers la gauche
 * 
 * @author Erwan Lemattre
 * @bug Fonction testée, première version avec un bug, corrigé
 *      Confiance: 8.5/10
 * 
 * @param plateau de type Plateau, le plateau de jeu
 * @return plateau de type plateau déplacé vers la gauche
 **/
Plateau deplacementGauche(Plateau plateau);




/** Fonction deplacementDroite
 * Déplacement du plateau vers la droite
 * 
 * @author Erwan Lemattre
 * @bug Fonction testée, première version avec un bug, corrigé
 *      Confiance: 8.5/10
 * 
 * @param plateau de type Plateau, le plateau de jeu
 * @return plateau de type plateau déplacé vers la droite
 **/
Plateau deplacementDroite(Plateau plateau);




/** Fonction deplacementHaut
 * Déplacement du plateau vers le haut
 * 
 * @author Erwan Lemattre
 * @bug Fonction testée, première version avec un bug, corrigé
 *      Confiance: 8.5/10
 * 
 * @param plateau de type Plateau, le plateau de jeu
 * @return plateau de type plateau déplacé vers le haut
 **/
Plateau deplacementHaut(Plateau plateau);




/** Fonction deplacementBas
 * Déplacement du plateau vers le bas
 * 
 * @author Erwan Lemattre
 * @bug Fonction testée, première version avec un bug, corrigé
 *      Confiance: 8.5/10
 * 
 * @param plateau de type Plateau, le plateau de jeu
 * @return plateau de type plateau déplacé vers le bas
 **/
Plateau deplacementBas(Plateau plateau);




/** Fonction deplacement
 * Déplacement du plateau donné en fonction d'une direction donné
 * @author Fonction du projet
 * @bug Fonction du projet
 * 
 * @param plateau de type Plateau, le plateau de jeu
 * @param direction un entier indiquant la direction dans laquelle bouger le plateau
 * @return plateau de type plateau déplacé vers le haut
 **/
Plateau deplacement(Plateau plateau, int direction);




/**
 * Vérifie si la partie est terminée
 * @param plateau le plateau de jeu
 * @return true si la partie est terminée, false sinon
*/
bool estTermine(Plateau plateau);




/** Fonction estGagnant 
 * vérifie si la partie est gagnante
 * @param p le plateau de jeu
 * @return true si la partie est gagnée, false sinon
 **/
bool estGagnant(Plateau plateau);




/** Fonction score
 * Permet de calculer le score d'un plateau donné
 * Utilise la variable globale QUATRE
 * @author Erwan Lemattre
 * @bug fonction testée, quelques problèmes sur les premières versions,
 *      corrigés pas d'erreurs rencontrées
 *      Confiance: 8/10
 * 
 * @param plateau de type Partie, contient le plateau et les quatres
 * @return int s le score obtenu pour la grille donné
 **/
int score(Partie plateau);




/** Fonction estRempli 
 * Vérifie si la grille est pleine
 * @author Erwan Lemattre
 * @bug Fonction testée, pas de difficulté rencontrée
 *      Confiance: 10/10
 * 
 * @param plateau le plateau de jeu
 * @return true si le grille est pleine, false sinon
 **/ 
bool estRempli(Plateau plateau);


//###########################################//
//### Les fonctions de test de modele.cpp ###//
//###########################################//

/** testTireDeuxOuQuatre
 * Test de la fonction tireDeuxOuQuatre
 **/
void testTireDeuxOuQuatre();

/** testAjouteDeuxOuQuatre
 * Test de la fonction ajouteDeuxOuQuatre
 * 
 * On regarde si pour x appels on a bien x cases remplies
 **/
void testAjouteDeuxOuQuatre();

/** testDeplacementGauche
 * Test de la fonction deplacementGauche
 **/
void testDeplacementGauche();

/** testDeplacementDroite
 * Test de la fonction deplacementDroite
 **/
void testDeplacementDroite();

/** testDeplacementHaut
 * Test de la fonction deplacementHaut
 **/
void testDeplacementHaut();

/** testDeplacementBas
 * Test de la fonction deplacementBas
 **/
void testDeplacementBas();

/**
 * Test de la fonction Deplacement
 **/
void testDeplacement();

/**
 * Test de la fonction estTermine
 **/
void testEstTermine();

/**
 * Test de la fonction plateauInitial
 **/
void testPlateauInitial();

/**
 * Test de la fonction estGagnant
 **/
void testEstGagnant();

/**
 ** Test de la fonction plateauVide
 **/
void testPlateauVide();




/***************************************************************/
/****** Fonctions intermédiaires de l'interface graphique ******/
/***************************************************************/


/**
 * @brief renvoie une valeur correspondant au poucentage d'une valeur donnée
 * @author Erwan Lemattre
 * @bug Fonction testée, pas de bug repéré
 *      Confiance: 9.5/10
 * 
 * @param p un entier, pourcentage désiré 
 * @param size un entier, l'élément dont on veut p%
 * @return int p% de size
 **/
int pourcentage(int p, int size);



/** Fonction touche_bouton
 * @brief verifie si (x, y) est sur le rectangle
 * @author Erwan Lemattre
 * @bug Fonction testée, pas de problème repéré
 *      Confiance: 9.5/10
 * 
 * @param btn le rectangle
 * @param x un entier, la position x
 * @param y un entier, la position y
 * @return true si (x, y) est sur le rectangle
 * @return false si (x, y) n'est pas sur le rectangle
 */
bool touche_bouton(SDL_Rect btn, int x, int y);




/** Fonction titre_menu
 * Génère le tableau contenant les coordonnées des cubes du titre
 * @author Erwan Lemattre
 * @bug Pas de problème repéré
 *      Confiance: 10/10
 * 
 * @param pourcentage_x un entier correspondant à la marge à gauche
 * @param taille_block une entier donnant la taille des cubes
 * @return le vecteur contenant les blocks
**/
vector<vector<int>> titre_menu(int pourcentage_x, int taille_block);




/** Fonction create_text
 * Créer la texture d'un texte
 * @author Erwan Lemattre
 * @bug Fonction non testée (tests difficilement réalisables), pas de problème repéré
 *      Confiance: 9/10
 * 
 * @param renderer la zone de rendu
 * @param text le texte à afficher
 * @param color couleur du texte
 * @param font_size taille du texte (plus élevée = meilleurs qualité)
 * @return SDL_Texture* la texture finale
 */
SDL_Texture * create_text(SDL_Renderer * renderer, char * text, SDL_Color color, int font_size = 160);




/** Fonction textFromPlateau
 * @brief transforme le vecteur plateau en un vecteur de textures à afficher à l'écran
 * @author Erwan Lemattre
 * @bug Pas de problème repéré
 *      Confiance: 8.5/10
 * 
 * @param renderer la zone de rendu
 * @param plateau le plateau de jeu
 * @param color la coulleur du texte à l'écran
 * @param textureTextTable le tableau contenant les textures (à modifier)
 * @return vector<SDL_Texture*> le tableau de textures modifié
 */
vector<SDL_Texture*> textFromPlateau(SDL_Renderer * renderer, Plateau plateau, SDL_Color color, vector<SDL_Texture*> textureTextTable);




/** Fonction transfertFichier
 * @brief Permet d'échanger les données avec le fichier data
 * @author Erwan Lemattre
 * @bug Fonction non testée. Tests affectués en interface graphique (en jeu), pas de bug repéré
 *      Confiance: 9/10
 * 
 * @param cat la catégorie de la donnée en écriture (0: score, 1: temps, 2: meilleurs score, 3: meilleurs temps)
 * @param data la donnée à ajouter
 * @param action 1 pour lire le fichier, 2 pour écrire
 * @return vector<int> les données lu ou les nouvelles données modifiées
 */
vector<int> transfertFichier(int cat, int data, int action);

//###########################//
//#### Fonctions de test ####//
//###########################//


/**
 * Test de la fonction pourcentage
 */
void testPourcentage();

/**
 * Test de la fonction touche_bouton
 */
void testTouche_bouton();



/***************************************************************/
/*************** Fonctions de la variante du jeu ***************/
/***************************************************************/


/** Fonction plateauVide
 * création d'un plateau de jeu vide
 * @author Erwan Lemattre
 * @bug fonction testée
 *      Confiance: 10/10
 * 
 * @return le plateau de type Plateau
 **/
Plateau plateauVideVariante();




/** Fonction ajouteDeux
 * Permet d'ajouter un deux aléatoirement dans la grille
 * 
 * @author Erwan Lemattre
 * @bug fonction testée, pas de bug repéré
 *      Confiance: 9.5/10
 * 
 * @param plateau le plateau à modifier
 * @return le plateau avec une nouvelle case remplie
 **/
Plateau ajouteDeux(Plateau plateau);




/** Fonction scoreVariante
 * Permet de calculer le score en mode 128 chrono
 * 
 * @author Erwan Lemattre
 * @bug fonction testée, pas de bug repéré
 *      Confiance: 8/10
 * 
 * @param plateau de type Plateau, le plateau de jeu
 * @return int s le score obtenu pour la grille donné
 **/
int scoreVariante(Plateau plateau);




/** Fonction plateauInitialVariante
 * Initialise le plateau pour la variante du jeu
 * 
 * @author Erwan Lemattre
 * @bug fonction testée, pas de bug repéré
 *      Confiance: 9.5/10
 * 
 * @param plateau le plateau de jeu vide
 * @return le plateau de jeu initialisé
*/
Plateau plateauInitialVariante();




/** Fonction estGagnantVariante
 * vérifie si la partie est gagnante
 * @author Erwan Lemattre
 * @bug fonction testée, pas de bug repéré
 *      Confiance: 9.5/10
 * 
 * @param p le plateau de jeu
 * @return true si la partie est gagnée, false sinon
 **/
bool estGagnantVariante(Plateau p);


//#################################//
//####### Fonctions de test #######//
//#################################//

/**
 * Test de la fonction estGagnantVariante
 */
void testEstGagnantVariante();

/**
 * Test de la fonction plateauVideVariante
 */
void testPlateauVideVariante();

/**
 * Test de la fonction plateauInitialVariante
 */
void testPlateauInitialVariante();

/**
 * Test de la fonction ajouteDeux
 */
void testAjouteDeux();

/**
 * Test de la fonction scoreVariante
 */
void testScoreVraiante();



/***************************************************************/
/***************** Fonctions affichages du jeu *****************/
/***************************************************************/



/**
 * Affiche fenêtre de victoire
 * @author Erwan Lemattre
 * @bug    Fonction difficilement testable par une autre fonction de test
 *         Les tests sont donc effectués en interface graphique.
 *         Pas de bug rencontré mais tous les cas ne peuvent pas forcément être traités.
 *         Confiance: 7/10
 * 
 * @param renderer la zone de rendu
 * @param game la partie jouée précédemment (-> personnalisation de l'affichage en fonction)
 * @return int le code de la prochaine fenêtre à afficher
 */
int victoire(SDL_Renderer * renderer, int game);




/**
 * Affiche fenêtre de défaite
 * @author Erwan Lemattre
 * @bug    Fonction difficilement testable par une autre fonction de test
 *         Les tests sont donc effectués en interface graphique.
 *         Pas de bug rencontré mais tous les cas ne peuvent pas forcément être traités.
 *         Confiance: 7/10
 * 
 * @param renderer la zone de rendu
 * @return int le code de la prochaine fenêtre à afficher
 */
int defaite(SDL_Renderer * renderer, int game);




/**
 * Fonction création du menu
 * @author Erwan Lemattre
 * @bug    Fonction difficilement testable par une autre fonction de test
 *         Les tests sont donc effectués en interface graphique.
 *         Pas de bug rencontré mais tous les cas ne peuvent pas forcément être traités.
 *         Confiance: 7/10
 * @param window le pointeur vers la fenêtre (permet d'adapter l'affichage à la taille de la fenêtre)
 * @param renderer la zone de rendu
 * @return int un entier correspondant à l'action à affectuer à la fin de cette fonction
 */
int menu(SDL_Renderer * renderer, SDL_Window * window);




/**
 * Fonction de jeu
 * @author Erwan Lemattre
 * @bug    Fonction difficilement testable par une autre fonction de test
 *         Les tests sont donc effectués en interface graphique.
 *         Pas de bug rencontré mais tous les cas ne peuvent pas forcément être traités.
 *         Confiance: 7/10
 * 
 * @param renderer la zone de dessin
 * @return int un entier correspondant à l'action à affectuer à la fin de la fonction
 */
int game(SDL_Renderer * renderer);




/**
 * Fonction du jeu 128 chrono !
 * @author Erwan Lemattre
 * @bug    Fonction difficilement testable par une autre fonction de test
 *         Les tests sont donc effectués en interface graphique.
 *         Pas de bug rencontré mais tous les cas ne peuvent pas forcément être traités.
 *         Confiance: 7/10
 * 
 * @param renderer la zone de dessin
 * @return int un entier correspondant à l'action à affectuer à la fin de la fonction
 */
int game_128(SDL_Renderer * renderer);
