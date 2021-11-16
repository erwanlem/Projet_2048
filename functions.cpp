#include <iostream>
#include <vector>
#include <assert.h>
#include <cmath>
#include <time.h>
#include <conio.h> // Pour getch() (à voir plus tard)


using namespace std;

const int GAUCHE = 7, DROITE = 4, HAUT = 8, BAS = 2;
typedef vector<vector<int>> Plateau;

// Prototypes des fonctions
int tireDeuxOuQuatre();
Plateau ajouteDeuxOuQuatre(Plateau plateau);
Plateau deplacementGauche(Plateau plateau);
Plateau deplacementDroite(Plateau plateau);
Plateau deplacementHaut(Plateau plateau);
Plateau deplacementBas(Plateau plateau);
Plateau deplacement(Plateau plateau, int direction);
// Les fonctions de test
void testTireDeuxOuQuatre();
void testAjouteDeuxOuQuatre();
void testDeplacementGauche();
void testDeplacementDroite();
void testDeplacementHaut();
void testDeplacementBas();
void testDeplacement();


// Fonction provisoire pour afficher le plateau (aide développement)
void affichePlateau(Plateau plateau){
    for (int i = 0; i < 4; i++){
        for (int j = 0; j < 4; j++){
            cout << plateau[i][j] << " ";
        }
        cout << endl;
    }
}


/** Fonction ajouteDeuxOuQuatre
 * Permet de choisir aléatoirement une case vide dans
 * le plateau et d'y ajouter soit 2, soit 4
 * 
 * @param plateau le plateau à modifier
 * @return le plateau avec une nouvelle case remplie
 **/
Plateau ajouteDeuxOuQuatre(Plateau plateau){
    int a, b;
    a = rand()%4;
    b = rand()%4;
    while (plateau[a][b] != 0){
        a = rand()%4;
        b = rand()%4;
    }
    plateau[a][b] = tireDeuxOuQuatre();
    return plateau;
}

/** Fonction TireDeuxOuQuatre
 * Fonction renvoyant 2 avec une proba de 8/10 ou 4 avec une proba de 2/10
 * 
 * @return un entier: soit 2, soit 4
 **/
int tireDeuxOuQuatre(){
    int i;
    i = rand()%10;

    if (i < 9){
        return 2;
    } else {
        return 4;
    }
}


/** Fonction deplacementGauche
 * Déplacement du plateau vers la gauche
 * 
 * @param plateau de type Plateau, le plateau de jeu
 * @return plateau de type plateau déplacé vers la gauche
 **/
Plateau deplacementGauche(Plateau plateau){
    int rangMax;
    for (int i = 0; i < 4; i++){
        rangMax = 0;
        for (int j = 0; j < 4; j++){
            if (plateau[i][j] != 0){
                if (j > rangMax && plateau[i][j-1] == 0 ){
                    plateau[i][j-1] = plateau[i][j];
                    plateau[i][j] = 0;
                    j = rangMax;
                } else if (j > rangMax && plateau[i][j-1] == plateau[i][j]){
                    plateau[i][j-1] = plateau[i][j-1] * 2;
                    plateau[i][j] = 0;
                    rangMax += 1;
                }
            }
        }
    }
    return plateau;
}


/** Fonction deplacementDroite
 * Déplacement du plateau vers la droite
 * 
 * @param plateau de type Plateau, le plateau de jeu
 * @return plateau de type plateau déplacé vers la droite
 **/
Plateau deplacementDroite(Plateau plateau){
    int rangMax;
    for (int i = 0; i < 4; i++){
        rangMax = 3;
        for (int j = 3; j >= 0; j--){
            if (plateau[i][j] != 0){
                if (j < rangMax && plateau[i][j+1] == 0 ){
                    plateau[i][j+1] = plateau[i][j];
                    plateau[i][j] = 0;
                    j = rangMax;
                } else if (j < rangMax && plateau[i][j+1] == plateau[i][j]){
                    plateau[i][j+1] = plateau[i][j+1] * 2;
                    plateau[i][j] = 0;
                    rangMax -= 1;
                }
            }
        }
    }
    return plateau;
}

/** Fonction deplacementBas
 * Déplacement du plateau vers le bas
 * 
 * @param plateau de type Plateau, le plateau de jeu
 * @return plateau de type plateau déplacé vers le bas
 **/
Plateau deplacementBas(Plateau plateau){
    int rangMax;
    for (int i = 0; i < 4; i++){
        rangMax = 3;
        for (int j = 3; j >= 0; j--){
            if (plateau[j][i] != 0){
                if (j < rangMax && plateau[j+1][i] == 0 ){
                    plateau[j+1][i] = plateau[j][i];
                    plateau[j][i] = 0;
                    j = rangMax;
                } else if (j < rangMax && plateau[j+1][i] == plateau[j][i]){
                    plateau[j+1][i] = plateau[j+1][i] * 2;
                    plateau[j][i] = 0;
                    rangMax -= 1;
                }
            }
        }
    }
    return plateau;
}


/** Fonction deplacementHaut
 * Déplacement du plateau vers le haut
 * 
 * @param plateau de type Plateau, le plateau de jeu
 * @return plateau de type plateau déplacé vers le haut
 **/
Plateau deplacementHaut(Plateau plateau){
    int rangMax;
    for (int i = 0; i < 4; i++){
        rangMax = 0;
        for (int j = 0; j < 4; j++){
            if (plateau[j][i] != 0){
                if (j > rangMax && plateau[j-1][i] == 0 ){
                    plateau[j-1][i] = plateau[j][i];
                    plateau[j][i] = 0;
                    j = rangMax;
                } else if (j > rangMax && plateau[j-1][i] == plateau[j][i]){
                    plateau[j-1][i] = plateau[j-1][i] * 2;
                    plateau[j][i] = 0;
                    rangMax += 1;
                }
            }
        }
    }
    return plateau;
}


/** Fonction deplacement
 * Déplacement du plateau donné en fonction d'une direction donné
 * 
 * @param plateau de type Plateau, le plateau de jeu
 * @param direction un entier indiquant la direction dans laquelle bouger le plateau
 * @return plateau de type plateau déplacé vers le haut
 **/
Plateau deplacement(Plateau plateau, int direction){
    if (direction == HAUT){
        plateau = deplacementHaut(plateau);
    } else if (direction == GAUCHE){
        plateau = deplacementGauche(plateau);
    } else if (direction == BAS){
        plateau = deplacementBas(plateau);
    } else if (direction == DROITE){
        plateau = deplacementDroite(plateau);
    }
    return plateau;
}


/********************************************************************************/ 
/**************************** TEST DES FONCTIONS ********************************/
/********************************************************************************/ 

/** testeTireDeuxOuQuatre
 * Test de la fonction tireDeuxOuQuatre
 **/
void testTireDeuxOuQuatre(){
    assert(tireDeuxOuQuatre() == 2 || tireDeuxOuQuatre() == 4);
    
    // On vérifie la proba
    double a, b;
    for (int i = 0; i < 1000; i++){
        if (tireDeuxOuQuatre() == 2){
            a++;
        } else {
            b++;
        }
    }
    a = round( (a * 10.0) / 1000 );
    b = round( (b * 10.0) / 1000 );
    assert( a == 9 && b == 1);
}

/** testAjouteDeuxOuQuatre
 * Test de la fonction ajouteDeuxOuQuatre
 * 
 * On regarde si pour x appels on a bien x cases remplies
 **/
void testAjouteDeuxOuQuatre(){
    for (int x = 1; x <= 5; x++){
        Plateau plt = { {0,0,0,0}, {0,0,0,0}, {0,0,0,0}, {0,0,0,0} };
        for (int k = 0; k < x; k++){
            plt = ajouteDeuxOuQuatre(plt);
        }
        int a = 0;
        for (int i = 0; i < 4; i++){
            for (int j = 0; j < 4; j++){
                if (plt[i][j] == 2 || plt[i][j] == 4){
                    a++;
                }
            }
        }
        assert(a == x); // On vérifie si le plateau a x cases de remplies
    }
}

/** testDeplacementGauche
 * Test de la fonction deplacementGauche
 **/
void testDeplacementGauche(){
    Plateau plt1        = { {0,2,0,0}, {0,4,0,4}, {0,8,0,0}, {2,2,0,2} };
    Plateau plt1_gauche = { {2,0,0,0}, {8,0,0,0}, {8,0,0,0}, {4,2,0,0} };
    Plateau plt2        = { {4,0,2,0}, {2,2,2,2}, {0,0,0,2}, {0,32,32,0} };
    Plateau plt2_gauche = { {4,2,0,0}, {4,4,0,0}, {2,0,0,0}, {64,0,0,0} };
    assert( deplacementGauche(plt1) == plt1_gauche );
    assert( deplacementGauche(plt2) == plt2_gauche );
}

/** testDeplacementDroite
 * Test de la fonction deplacementDroite
 **/
void testDeplacementDroite(){
    Plateau plt1        = { {0,2,0,0}, {0,4,0,4}, {0,8,0,0}, {2,2,0,2} };
    Plateau plt1_droite = { {0,0,0,2}, {0,0,0,8}, {0,0,0,8}, {0,0,2,4} };
    Plateau plt2        = { {4,0,2,0}, {2,2,2,2}, {0,0,0,2}, {0,32,32,0} };
    Plateau plt2_droite = { {0,0,4,2}, {0,0,4,4}, {0,0,0,2}, {0,0,0,64} };
    assert( deplacementDroite(plt1) == plt1_droite );
    assert( deplacementDroite(plt2) == plt2_droite );
}

/** testDeplacementHaut
 * Test de la fonction deplacementHaut
 **/
void testDeplacementHaut(){
    Plateau plt1      = { {0,2,0,0}, {0,4,0,4}, {0,8,0,0}, {2,2,0,2} };
    Plateau plt1_haut = { {2,2,0,4}, {0,4,0,2}, {0,8,0,0}, {0,2,0,0} };
    Plateau plt2      = { {4,0,2,0}, {2,2,2,2}, {0,0,0,2}, {0,32,32,0} };
    Plateau plt2_haut = { {4,2,4,4}, {2,32,32,0}, {0,0,0,0}, {0,0,0,0} };
    assert( deplacementHaut(plt1) == plt1_haut );
    assert( deplacementHaut(plt2) == plt2_haut );
}

/** testDeplacementBas
 * Test de la fonction deplacementBas
 **/
void testDeplacementBas(){
    Plateau plt1     = { {0,2,0,0}, {0,4,0,4}, {0,8,0,0}, {2,2,0,2} };
    Plateau plt1_bas = { {0,2,0,0}, {0,4,0,0}, {0,8,0,4}, {2,2,0,2} };
    Plateau plt2     = { {4,0,2,0}, {2,2,2,2}, {0,0,0,2}, {0,32,32,0} };
    Plateau plt2_bas = { {0,0,0,0}, {0,0,0,0}, {4,2,4,0}, {2,32,32,4} };
    assert( deplacementBas(plt1) == plt1_bas );
    assert( deplacementBas(plt2) == plt2_bas );
}

void testDeplacement(){
    Plateau plt        = { {0,2,0,0}, {0,4,0,4}, {0,8,0,0}, {2,2,0,2} };
    Plateau plt_gauche = { {2,0,0,0}, {8,0,0,0}, {8,0,0,0}, {4,2,0,0} };
    Plateau plt_droite = { {0,0,0,2}, {0,0,0,8}, {0,0,0,8}, {0,0,2,4} };
    Plateau plt_haut   = { {2,2,0,4}, {0,4,0,2}, {0,8,0,0}, {0,2,0,0} };
    Plateau plt_bas    = { {0,2,0,0}, {0,4,0,0}, {0,8,0,4}, {2,2,0,2} };
    assert( deplacement(plt, GAUCHE) == plt_gauche );
    assert( deplacement(plt, DROITE) == plt_droite );
    assert( deplacement(plt, HAUT)   == plt_haut   );
    assert( deplacement(plt, BAS)    == plt_bas    );
}

/********************************************************************************/
/********************************************************************************/ 



int main(int argc, char const *argv[])
{
    // Initialisation du temps pour l'aléatoire
    srand((int)time(0));

    Plateau plateau = {
        {0,0,0,0},
        {0,0,0,0},
        {0,0,0,0},
        {0,0,0,0}
    };
    plateau = ajouteDeuxOuQuatre(plateau);
    affichePlateau(plateau);
    /*
    char touche;
    int direction;
    cin >> touche;
    while (touche != 'l'){
        if (touche == 'z'){
            direction = HAUT;
        } else if (touche == 'q'){
            direction = GAUCHE;
        } else if (touche == 's'){
            direction = BAS;
        } else if (touche == 'd'){
            direction = DROITE;
        } else {
            direction = 0;
        }
        plateau = deplacement(plateau, direction);
        cout << endl;
        affichePlateau(plateau);
        cout << endl;
        cin >> touche;
    }
    */
    
    return 0;
}


