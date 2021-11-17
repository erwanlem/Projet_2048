using namespace std;
#include <iostream>
#include <vector>
#include <cstdlib>
#include <time.h>
#include <assert.h>

typedef vector<vector<int> > Plateau;

/*
*cette fonction créée un plateau de jeu vide
*@return le plateau de type Plateau
*/
Plateau plateauVide(){
	Plateau plateau;
	plateau= Plateau(4);
	vector<int> lignes;
	lignes= vector<int>(4);
	for(int i=0; i<plateau.size(); i++){
		for(int j=0; j<lignes.size(); j++){
			lignes[j]=0;
		}
		plateau[i]=lignes;
	}
	return plateau;
}


/*
*teste si la fonction plateauVide fonctionne correctement
*/
void testPlateauVide(){
	Plateau plt3={{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0}};
	assert(plateauVide()==plt3);
}


/*
*Cette fonction initialise le plateau
*@param plateau le plateau de jeu vide
*@return le plateau de jeu initialisé
*/
Plateau plateauInitial(Plateau plateau){
	plateau = ajouteDeuxOuQuatre(plateau);
	plateau = ajouteDeuxOuQuatre(plateau);
	return plateau;
}


/*
*teste si la fonction plateauInitial fonctionne correctement
*/
void testPlateauInitial(){
	Plateau plt={{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0}};
	Plateau traite=plateauInitial(plt);
	int compt=0;
	for (int i=0; i<4; i++){
		for(int j=0; j<4; j++){
			if(traite[i][j]==2 or traite[i][j]==4){
				compt+=1;
			}
		}
	}
	assert (compt==2);
}

/*
*cette fonction sert a afficher une ligne pleine de "*"
*/
void afficheLignePleine(){
	for(int i=0; i<25; i++){
		cout << "*";
	}
	cout << endl;
}

/*
*cette fonction permet l'affichage d'une ligne de nombre
*@param line la ligne a traiter
*/
void afficheLigneNombre(vector<int> line){
	cout << "*";
	for(int i=0; i<4; i++){
		if(line[i]==0){
			cout << "     *";
		}else if (line[i]<10){
			cout << "  " << line[i] << "  *";
		}else if(line[i]<100){
			cout << " " << line[i] << "  *";
		}else if(line[i]<1000){
			cout << " " << line[i] << " *";
		}else if(line[i]<10000){
			cout << "" << line[i] << " *";
		}else{
			cout << line[i] << "*";	
		}
	}
	cout << endl;
}

/*
*cette fonction affiche le plateau de jeu
*@param g le plateau de jeu
*/
void dessine(Plateau g){
	afficheLignePleine();
	for(int i=0; i<4;i++){
		afficheLigneNombre(g[i]);
		afficheLignePleine();
	}
}

/*
*cette fonction vérifie si la partie est gagnante
*@param p le plateau de jeu
*@return true si la partie est gagnée
*/
bool estGagnant(Plateau p){
	for(int i=0; i<4; i++){
		for(int j=0; j<4; j++){
			if(p[i][j]==2048){
				return true;
			}
		}
	}
	return false;
}

/*
*teste si la fonction estGagnant fonctionne correctement
*/
void testEstGagnant(){
	Plateau plt0={{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0}};
	Plateau plt1={{2,2,2,2},{2,2048,2,2},{2,2,2,2},{2,2,2,2}};
	assert ( not(estGagnant(plt0)));
	assert ( estGagnant(plt1));
}


/*
*Cette fonction vérifie si la partie est terminée
*@param p le plateau de jeu
*@return true si la partie est terminée
*/
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


/*
*teste si la fonction estTermine fonctionne correctement
*/
void testEstTermine(){
	assert(estTermine({{2,4,2,4},{4,2,4,2},{2,4,2,4},{4,2,4,2}}));
	assert(not(estTermine({{2,4,2,4},{4,2,4,2},{2,4,2,4},{4,2,0,2}})));
	assert(not(estTermine({{2,4,2,4},{4,2,4,2},{2,4,2,4},{4,2,2,2}})));
}