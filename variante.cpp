#include <vector>
#include <assert.h>
#include <cmath>
#include <time.h>
#include "modele.h"



Plateau plateauVideVariante(){
	Plateau plateau;
	plateau = {
        {0, 0, 0},
        {0, 0, 0},
        {0, 0, 0}
    };
	return plateau;
}



Plateau ajouteDeux(Plateau plateau){
    int a, b;
    a = rand()%3;
    b = rand()%3;
    while (plateau[a][b] != 0){
        a = rand()%3;
        b = rand()%3;
    }
    plateau[a][b] = 2;
    return plateau;
}



int scoreVariante(Plateau plateau){
    int s = 0;
    int mult, nbr_case;
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            if (plateau[i][j] != 0 && plateau[i][j] != 2){
                nbr_case = 4;
                mult = 1;
                while (nbr_case != plateau[i][j]){
                    mult += 1;
                    nbr_case = nbr_case * 2;
                }
                s = s + nbr_case * mult;
            }
        }
    }
    return s;
}



Plateau plateauInitialVariante(){
    Plateau plateau =  plateauVideVariante();
	plateau = ajouteDeux(plateau);
	plateau = ajouteDeux(plateau);
	return plateau;
}





bool estGagnantVariante(Plateau p){
	for(int i=0; i<p.size(); i++){
		for(int j=0; j<p[i].size(); j++){
			if(p[i][j]==128){
				return true;
			}
		}
	}
	return false;
}





/********************************************************************************/ 
/**************************** TEST DES FONCTIONS ********************************/
/********************************************************************************/ 



/**
 * Test de la fonction estGagnantVariante
 */
void testEstGagnantVariante(){
    Plateau p1 = { {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}};
    Plateau p2 = { {0, 2, 0, 4}, {8, 0, 16, 0}, {0, 2, 2, 0}, {4, 0, 0, 8}};
    Plateau p3 = { {2, 0, 0, 0}, {4, 2, 0, 2}, {0, 2, 0, 32}, {0, 0, 128, 0}};

    assert( estGagnantVariante(p1) == false);
    assert( estGagnantVariante(p2) == false);
    assert( estGagnantVariante(p3) == true);
}


/**
 * Test de la fonction plateauVideVariante
 */
void testPlateauVideVariante(){
    Plateau p1 = plateauVideVariante();
    Plateau p1_test = { {0, 0, 0}, {0, 0, 0}, {0, 0, 0} };
    assert ( p1 == p1_test );
}

/**
 * Test de la fonction plateauInitialVariante
 */
void testPlateauInitialVariante() {
    Plateau plt = plateauVideVariante();
	Plateau traite = plateauInitialVariante();
	int compt= 0;
	for ( int i = 0 ; i < 3 ; i++ ) {
		for ( int j = 0 ; j < 3 ; j++ ) {
			if(traite[i][j] == 2) {
				compt += 1;
			}
		}
	}
	assert (compt == 2);
}


/**
 * Test de la fonction ajouteDeux
 */
void testAjouteDeux(){
    Plateau p1 = plateauVideVariante();
    Plateau p2 = plateauVideVariante();
    p1 = ajouteDeux(p1);
    p2 = ajouteDeux(p2);
    p2 = ajouteDeux(p2);
    p2 = ajouteDeux(p2);
    int p1_deux = 0;
    int p2_deux = 0;
    for (int i = 0; i < 3; i++ ){
        for ( int j = 0; j < 3; i++ ){
            if ( p1[i][j] == 2 ){
                p1_deux += 1;
            }
            if ( p2[i][j] == 2){
                p2_deux += 1;
            }
        }
    }
    assert ( p1_deux == 1);
    assert ( p2_deux == 3);
}

/**
 * Test de la fonction scoreVariante
 */
void testScoreVraiante() {
    Plateau p1 = plateauVideVariante();
    Plateau p2 = { {0, 8, 0}, {0, 0, 0}, {2, 4, 0} };
    Plateau p3 = { {4, 8, 0}, {32, 0, 8}, {2, 4, 0} };

    assert ( scoreVariante(p3) == 168 );
    assert ( scoreVariante(p1) == 0 );
    assert ( scoreVariante(p2) == 20 );
}