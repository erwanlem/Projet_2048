using namespace std;
#include <iostream>
#include <vector>
#include <cstdlib>
#include <time.h>

typedef vector<vector<int> > Plateau;

/*
//cette fonction créée un plateau de jeu vide
//@return le plateau de type Plateau
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
//Cette fonction initialise le plateau
//@param plateau le plateau de jeu vide
//@return le plateau de jeu initialisé
*/
Plateau plateauInitial(Plateau plateau){
	plateau = ajouteDeuxOuQuatre(plateau);
	plateau = ajouteDeuxOuQuatre(plateau);
	return plateau;
}

/*
//cette fonction sert a afficher une ligne pleine de "*"
*/
void afficheLignePleine(){
	for(int i=0; i<25; i++){
		cout << "*";
	}
	cout << endl;
}

/*
//cette fonction permet l'affichage d'une ligne de nombre
//@param line la ligne a traiter
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
			cout << " " << line[i] << "*";
		}else{
			cout << line[i] << "*";	
		}
	}
	cout << endl;
}

/*
//cette fonction affiche le plateau de jeu
//@param g le plateau de jeu
*/
void dessine(Plateau g){
	afficheLignePleine();
	for(int i=0; i<4;i++){
		afficheLigneNombre(g[i]);
		afficheLignePleine();
	}
}

/*
//cette fonction vérifie si la partie est gagnante
//@param p le plateau de jeu
//@return true si la partie est gagnée
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

void testEstGagnant(){
	CHECK ( not(estGagnant({{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0}})))
	CHECK ( estGagnat({{2,2,2,2},{2,2048,2,2},{2,2,2,2},{2,2,2,2}}))
}

/*
//Cette fonction verifie si un mouvement est possible
//@param p le plateau de jeu
//@param ligne la ligne de la case vérifiée
//@param colonne la colonne de la case vérifiée
//@return true si un mouvement est possible avec la case
*/
bool mouvementPossible(Plateau p, int ligne, int colonne){
	for(int i=0; i<4; i++){
		for(int j=0; j<4; j++){
			if(p[i][j]==0){
				return true;
			}
		}
	}
	if(ligne-1>-1){
		if(p[ligne-1][colonne]==p[ligne][colonne]){
			return true;
		}
	}
	if(ligne+1<4){
		if(p[ligne+1][colonne]==p[ligne][colonne]){
			return true;
		}
	}
	if(colonne+1<4){
		if(p[ligne][colonne+1]==p[ligne][colonne]){
			return true;
		}
	}
	if(colonne-1>-1){
		if(p[ligne][colonne-1]==p[ligne][colonne]){
			return true;
		}
	}
	return false;
}

/*
//Cette fonction vérifie si la partie est terminée
//@param p le playeau de jeu
//@return true si la partie est terminée
*/
bool estTermine(Plateau p){
	for (int i=0; i<4; i++){
		for(int j=0; j<4; j++){
			if(mouvementPossible(p, i, j)){
				return false;
			}
		}
	}
	return true;
}