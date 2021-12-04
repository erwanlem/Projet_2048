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
Plateau plateauVideVariante(){
	Plateau plateau;
	plateau= Plateau(3);
	vector<int> lignes;
	lignes= vector<int>(3);
	for(int i=0; i<plateau.size(); i++){
		for(int j=0; j<lignes.size(); j++){
			lignes[j]=0;
		}
		plateau[i]=lignes;
	}
	return plateau;
}




/** Fonction ajouteDeuxOuQuatre
 * Permet de choisir aléatoirement une case vide dans
 * le plateau et d'y ajouter soit 2, soit 4
 * 
 * @param plateau le plateau à modifier
 * @return le plateau avec une nouvelle case remplie
 **/
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



/** Fonction score
 * Permet de calculer le score d'un plateau donné
 * Utilise la variable globale QUATRE
 * 
 * @param plateau la grille de jeu
 * @param quatre le nombre de quatre ajoutés au hasard par tireDeuxOuQuatre
 * @return int s le score obtenu pour la grille donné
 **/
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



/** Fonction plateauInitial
 * Initialise le plateau
 * @param plateau le plateau de jeu vide
 * @return le plateau de jeu initialisé
*/
Plateau plateauInitialVariante(){
    Plateau plateau = { {0,0,0}, {0,0,0}, {0,0,0} };
	plateau = ajouteDeux(plateau);
	plateau = ajouteDeux(plateau);
	return plateau;
}




/** Fonction estGagnant 
 * vérifie si la partie est gagnante
 * @param p le plateau de jeu
 * @return true si la partie est gagnée, false sinon
 **/
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





