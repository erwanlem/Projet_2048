#include <iostream>
#include <vector>
#include <assert.h>
#include <cmath>
#include <time.h>
#include "modele.h"


/** Fonction plateauVide
 * créée un plateau de jeu vide
 * @return le plateau de type Plateau
 **/
Plateau plateauVide(){
	Plateau plateau = {
        {0, 0, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0}
    };
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



/** Fonction ajouteDeuxOuQuatre
 * Permet de choisir aléatoirement une case vide dans
 * le plateau et d'y ajouter soit 2, soit 4
 * 
 * @param plateau le plateau à modifier
 * @return le plateau avec une nouvelle case remplie
 **/
Partie ajouteDeuxOuQuatre(Partie plateau){
    int a, b;
    a = rand()%4;
    b = rand()%4;
    while (plateau.plateau[a][b] != 0){
        a = rand()%4;
        b = rand()%4;
    }
    plateau.plateau[a][b] = tireDeuxOuQuatre();
    if (plateau.plateau[a][b] == 4){
        plateau.quatre += 1;
    }
    return plateau;
}



/** Fonction deplacementGauche
 * Déplacement du plateau vers la gauche
 * 
 * @param plateau de type Plateau, le plateau de jeu
 * @return plateau de type plateau déplacé vers la gauche
 **/
Plateau deplacementGauche(Plateau plateau){
    for (int i = 0; i < plateau.size(); i++){
        for (int j = 0; j < plateau[i].size() - 1; j++){
            int n = 1;
            if (plateau[i][j] != 0){
                while (j + n < plateau[i].size() ){
                    if (plateau[i][j+n] == plateau[i][j]){
                        plateau[i][j] = plateau[i][j] * 2;
                        plateau[i][j+n] = 0;
                        break;
                    } else if (plateau[i][j+n] != 0) {
                        break;
                    } else {
                        n += 1;
                    }
                }
            }
        }
        for (int j = 0; j < plateau[i].size(); j++){
            if (plateau[i][j] != 0){
                while (j > 0 && plateau[i][j-1] == 0 ){
                    plateau[i][j-1] = plateau[i][j];
                    plateau[i][j] = 0;
                    j--;
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
    for (int i = 0; i < plateau.size(); i++){
        for (int j = plateau[i].size() - 1; j > 0; j--){
            int n = 1;
            if (plateau[i][j] != 0){
                while (j - n >= 0){
                    if (plateau[i][j-n] == plateau[i][j]){
                        plateau[i][j] = plateau[i][j] * 2;
                        plateau[i][j-n] = 0;
                        break;
                    } else if (plateau[i][j-n] != 0) {
                        break;
                    } else {
                        n += 1;
                    }
                }
            }
        }
        for (int j =  plateau[i].size() - 1 ; j >= 0; j--){
            if (plateau[i][j] != 0){
                while (j < plateau[i].size() - 1 && plateau[i][j+1] == 0 ){
                    plateau[i][j+1] = plateau[i][j];
                    plateau[i][j] = 0;
                    j++;
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
    for (int i = 0; i < plateau.size(); i++){
        for (int j = plateau[i].size() - 1; j > 0; j--){
            int n = 1;
            if (plateau[j][i] != 0){
                while (j - n >= 0){
                    if (plateau[j-n][i] == plateau[j][i]){
                        plateau[j][i] = plateau[j][i] * 2;
                        plateau[j-n][i] = 0;
                        break;
                    } else if (plateau[j-n][i] != 0) {
                        break;
                    } else {
                        n += 1;
                    }
                }
            }
        }
        for (int j = plateau[i].size() - 1 ; j >= 0; j--){
            if (plateau[j][i] != 0){
                while (j < plateau[i].size() - 1 && plateau[j+1][i] == 0 ){
                    plateau[j+1][i] = plateau[j][i];
                    plateau[j][i] = 0;
                    j++;
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
    for (int i = 0; i < plateau.size(); i++){
        for (int j = 0; j < plateau[i].size() - 1; j++){
            int n = 1;
            if (plateau[j][i] != 0){
                while (j + n < plateau[i].size() ){
                    if (plateau[j+n][i] == plateau[j][i]){
                        plateau[j][i] = plateau[j][i] * 2;
                        plateau[j+n][i] = 0;
                        break;
                    } else if (plateau[j+n][i] != 0) {
                        break;
                    } else {
                        n += 1;
                    }
                }
            }
        }
        for (int j = 0; j < plateau[i].size(); j++){
            if (plateau[j][i] != 0){
                while (j > 0 && plateau[j-1][i] == 0 ){
                    plateau[j-1][i] = plateau[j][i];
                    plateau[j][i] = 0;
                    j--;
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


/** Fonction score
 * Permet de calculer le score d'un plateau donné
 * Utilise la variable globale QUATRE
 * 
 * @param plateau la grille de jeu
 * @param quatre le nombre de quatre ajoutés au hasard par tireDeuxOuQuatre
 * @return int s le score obtenu pour la grille donné
 **/
int score(Partie plateau){
    int s = 0;
    int mult, nbr_case;
    for (int i = 0; i < 4; i++){
        for (int j = 0; j < 4; j++){
            if (plateau.plateau[i][j] != 0 && plateau.plateau[i][j] != 2){
                nbr_case = 4;
                mult = 1;
                while (nbr_case != plateau.plateau[i][j]){
                    mult += 1;
                    nbr_case = nbr_case * 2;
                }
                s = s + nbr_case * mult;
            }
        }
    }
    s = s - (4 * plateau.quatre);  // On soustrait les quatres qui apparaissent sur la grille
    return s;
}



/** Fonction plateauInitial
 * Initialise le plateau
 * @param plateau le plateau de jeu vide
 * @return le plateau de jeu initialisé
*/
Partie plateauInitial(){
    Partie plateau;
    plateau.plateau = { {0,0,0,0}, {0,0,0,0}, {0,0,0,0}, {0,0,0,0} };
	plateau = ajouteDeuxOuQuatre(plateau);
	plateau = ajouteDeuxOuQuatre(plateau);
	return plateau;
}


/**
 * Vérifie si la partie est terminée
 * @param plateau le plateau de jeu
 * @return true si la partie est terminée, false sinon
*/
bool estTermine(Plateau p){
	for (int i=0; i<p.size(); i++){
		for(int j=0; j<p[i].size(); j++){
			if(p[i][j]==0){
				return false;
			}
			if(i-1>-1){
				if(p[i-1][j]==p[i][j]){
					return false;
				}
			}
			if(i+1<p.size()){
				if(p[i+1][j]==p[i][j]){
					return false;
				}
			}
			if(j+1<p.size()){
				if(p[i][j+1]==p[i][j]){
					return false;
				}
			}
			if(j-1>-1){
				if(p[i][j-1]==p[i][j]){
					return false;
				}
			}
		}
	}
	return true;
}




/** Fonction estGagnant 
 * vérifie si la partie est gagnante
 * @param p le plateau de jeu
 * @return true si la partie est gagnée, false sinon
 **/
bool estGagnant(Plateau p){
	for( int i = 0 ; i < 4 ; i++ ) {
		for( int j = 0; j < 4; j++ ) {
			if( p[i][j] >= 2048 ) {
				return true;
			}
		}
	}
	return false;
}


/** Fonction estRempli 
 * Vérifie si la grille est pleine
 * @param plateau le plateau de jeu
 * 
 * @return true si le grille est pleine, false sinon
 **/ 
bool estRempli(Plateau plateau){
    for (int i = 0; i < plateau.size(); i++){
        for (int j = 0; j < plateau[i].size(); j++){
            if (plateau[i][j] == 0){
                return false;
            }
        }
    }
    return true;
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
    Partie plt;
    for (int x = 1; x <= 5; x++){
        plt.plateau = { {0,0,0,0}, {0,0,0,0}, {0,0,0,0}, {0,0,0,0} };
        for (int k = 0; k < x; k++){
            plt = ajouteDeuxOuQuatre(plt);
        }
        int a = 0;
        for (int i = 0; i < 4; i++){
            for (int j = 0; j < 4; j++){
                if (plt.plateau[i][j] == 2 || plt.plateau[i][j] == 4){
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
    Plateau plt1        = { {4,2,2,8}, {0,4,0,4}, {0,8,0,0}, {2,2,0,2} };
    Plateau plt1_droite = { {0,4,4,8}, {0,0,0,8}, {0,0,0,8}, {0,0,2,4} };
    Plateau plt1_erreur = { {0,0,8,8}, {0,0,0,8}, {0,0,0,8}, {0,0,2,4} };
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



/**
 * Test de la fonction Deplacement
 **/
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



/**
 * Test de la fonction estTermine
 **/
void testEstTermine(){
	assert(estTermine({{2,4,2,4},{4,2,4,2},{2,4,2,4},{4,2,4,2}}));
	assert(not(estTermine({{2,4,2,4},{4,2,4,2},{2,4,2,4},{4,2,0,2}})));
	assert(not(estTermine({{2,4,2,4},{4,2,4,2},{2,4,2,4},{4,2,2,2}})));
}



/**
 * Test de la fonction estGagnant
 **/
void testEstGagnant(){
	Plateau plt0={{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0}};
	Plateau plt1={{2,2,2,2},{2,2048,2,2},{2,2,2,2},{2,2,2,2}};
	assert ( not(estGagnant(plt0)));
	assert ( estGagnant(plt1));
}



/**
 * Test de la fonction plateauInitial
 **/
void testPlateauInitial(){
	Plateau plt = {{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0}};
	Partie traite = plateauInitial();
	int compt= 0;
	for ( int i = 0 ; i < 4 ; i++){
		for ( int j = 0 ; j < 4 ; j++){
			if(traite.plateau[i][j] == 2 or traite.plateau[i][j] == 4){
				compt += 1;
			}
		}
	}
	assert (compt == 2);
}



/**
 ** Test de la fonction plateauVide
 **/
void testPlateauVide(){
	Plateau plt3={{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0}};
	assert(plateauVide()==plt3);
}

/********************************************************************************/
/********************************************************************************/ 