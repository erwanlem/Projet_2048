#include <vector>
using namespace std;

const int GAUCHE = 260, DROITE = 261, HAUT = 259, BAS = 258, QUITTER = 27;
typedef vector<vector<int>> Plateau;


struct Partie {
    int score;
    Plateau plateau;
    int quatre = 0;
};



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
 * Affiche le plateau de jeu
 * @param plateau le plateau de jeu
 **/
void dessine(Plateau plateau);




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
 * 
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





// Les fonctions de test



/** testeTireDeuxOuQuatre
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


/**
 * Test de la fonction score
 */
void testScore();