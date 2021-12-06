#include <iostream>
#include <assert.h>
#include <cmath>
#include <ncurses.h>
#include "modele.h"


using namespace std;



Plateau plateauVide(){
	Plateau plateau;
	plateau = {
        {0, 0, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0}
    };
	return plateau;
}





int tireDeuxOuQuatre(){
    int i;
    i = rand()%10;

    if (i < 9){
        return 2;
    } else {
        return 4;
    }
}





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
    case 27:
        endwin();
        exit(0);
    default:
      return plateau;
  }
}





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





Partie plateauInitial(){
    Partie plateau;
    plateau.plateau = plateauVide();
	plateau = ajouteDeuxOuQuatre(plateau);
	plateau = ajouteDeuxOuQuatre(plateau);
	return plateau;
}

    




void afficheLignePleine(){
	init_pair(1, COLOR_WHITE, COLOR_BLACK);
	for(int i=0; i<25; i++){
        attron(COLOR_PAIR(1));
		printw("*");
        attroff(COLOR_PAIR(1));
	}
	printw("\n");
}





void afficheLigneNombre(vector<int> line){
    init_color(20, 1000, 500, 0);
    init_color(21, 1000, 0, 1000);
    init_color(22, 0, 1000, 1000);
    init_pair(12, COLOR_YELLOW, COLOR_BLACK);
    init_pair(1, COLOR_BLUE, COLOR_BLACK);
	init_pair(2, COLOR_GREEN, COLOR_BLACK);
	init_pair(3, COLOR_RED, COLOR_BLACK);
	init_pair(4, COLOR_YELLOW, COLOR_BLACK);
	init_pair(5, COLOR_CYAN, COLOR_BLACK);
	init_pair(6, COLOR_MAGENTA, COLOR_BLACK);
    init_pair(7, 20, COLOR_BLACK);
    init_pair(8, 21, COLOR_BLACK);
    init_pair(9, 22, COLOR_BLACK);

    attron(COLOR_PAIR(12));
    printw("*");
    attroff(COLOR_PAIR(12));
	for(int i=0; i<4; i++){
		if(line[i]==0){
            attron(COLOR_PAIR(12));
			printw("     *");
            attroff(COLOR_PAIR(12));
		} else {
            int couleur = 1;
            int nb_case = 2;
            while (nb_case != line[i])
            {
                couleur += 1;
                nb_case = nb_case * 2;
                if (couleur > 9){
                    couleur = 1;
                }
            }
            attron(COLOR_PAIR(couleur));
            if (line[i]<10){
			    printw("  %d  ", line[i]);
		    }else if(line[i]<100){
                printw(" %d  ", line[i]);
		    }else if(line[i]<1000){
                printw(" %d " ,line[i]);
            }else if(line[i]<10000){
                printw(" %d" , line[i]);
            }else{
                printw("%d" , line[i]);
            }
            attroff(COLOR_PAIR(couleur));
            attron(COLOR_PAIR(12));
            printw("*");
            attroff(COLOR_PAIR(12));
        }
	}
	printw("\n");
}






bool estTermine(Plateau p){
	for (int i=0; i<4; i++){
		for(int j=0; j<4; j++){
			if(p[i][j]==0){
				return false;
			}
			if(i-1>-1){
				if(p[i-1][j]==p[i][j]){
					return false;
				}
			}
			if(i+1<4){
				if(p[i+1][j]==p[i][j]){
					return false;
				}
			}
			if(j+1<4){
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





bool estGagnant(Plateau p){
	for(int i=0; i<4; i++){
		for(int j=0; j<4; j++){
			if(p[i][j]>=2048){
				return true;
			}
		}
	}
	return false;
}





bool estRempli(Plateau plateau){
    for (int i = 0; i < 4; i++){
        for (int j = 0; j < 4; j++){
            if (plateau[i][j] == 0){
                return false;
            }
        }
    }
    return true;
}





void dessine(Plateau plateau){
    printw("\t");
	afficheLignePleine();
	for(int i=0; i<4;i++){
        printw("\t");
		afficheLigneNombre(plateau[i]);
        printw("\t");
		afficheLignePleine();
	}
    printw("\t");
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
        Partie plt;
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
	Plateau plt1={{2,2,2,2},{2,4096,2,2},{2,2,2,2},{2,2,2,2}};
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

void testScore(){
    Partie plt1;
    plt1.plateau = {{4,0,0,0},{0,0,0,4},{0,0,0,0},{0,0,0,4}};
    Partie plt2;
    plt2.plateau = {{4,0,0,0},{0,0,0,0},{0,0,0,2},{8,0,0,0}};
    assert ( score(plt1) == 0  );
    assert ( score(plt2) == 16 );
}

/********************************************************************************/
/********************************************************************************/ 