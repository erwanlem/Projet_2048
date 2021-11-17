#include <iostream>
#include <vector>
#include <assert.h>
#include <cmath>
#include <time.h>
#include <conio.h> // Pour getch() (à voir plus tard)


using namespace std;

const int GAUCHE = 113, DROITE = 100, HAUT = 122, BAS = 115;
typedef vector<vector<int>> Plateau;

int QUATRE = 0; // Variable utilisée dans le calcul du score (voir fonction)

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
        QUATRE += 1;
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
    } else {
        return plateau;
    }
    return plateau;
}

/** Fonction score
 * Permet de calculer le score d'un plateau donné
 * Utilise la variable globale QUATRE
 * 
 * @param plateau la grille de jeu
 * @return int s le score obtenu pour la grille donné
 **/
int score(Plateau plateau){
    int s = 0;
    int mult, nbr_case;
    for (int i = 0; i < 4; i++){
        for (int j = 0; j < 4; j++){
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
    s = s - (4 * QUATRE);  // On soustrait les quatres qui apparaissent sur la grille
    return s;
}

/** Fonction plateauVide
 * créée un plateau de jeu vide
 * @return le plateau de type Plateau
 **/
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

/** Fonction plateauInitial
 * Initialise le plateau
 * @param plateau le plateau de jeu vide
 * @return le plateau de jeu initialisé
*/
Plateau plateauInitial(Plateau plateau){
	plateau = ajouteDeuxOuQuatre(plateau);
	plateau = ajouteDeuxOuQuatre(plateau);
	return plateau;
}

/** Fonction afficheLignePLeine
 * Affiche une ligne pleine de "*"
 **/
void afficheLignePleine(){
	for(int i=0; i<25; i++){
		cout << "*";
	}
	cout << endl;
}

/** Fonction afficheLigneNombre
 * Affiche une ligne de nombre
 * @param line la ligne a traiter
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

/** Fonction dessine
 * affiche le plateau de jeu
 * @param plateau le plateau de jeu
 **/
void dessine(Plateau plateau){
	afficheLignePleine();
	for(int i=0; i<4;i++){
		afficheLigneNombre(plateau[i]);
		afficheLignePleine();
	}
}

/** Fonction estGagnant
 * vérifie si la partie est gagnante
 * @param p le plateau de jeu
 * @return true si la partie est gagnée, false sinon
 **/
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


/**
 * Vérifie si la partie est terminée
 * @param plateau le plateau de jeu
 * @return true si la partie est terminée, false sinon
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

void testEstTermine(){
	cout << estTermine({{4,2,4,2},{2,8,64,16},{8,16,4,2},{2,4,8,4}}) << endl;
	assert(not(estTermine({{2,2,2,4},{4,2,4,2},{2,4,2,4},{4,2,0,2}})));
	assert(not(estTermine({{2,4,2,4},{4,2,4,2},{2,4,2,4},{4,2,2,2}})));
}

/********************************************************************************/
/********************************************************************************/ 



int main(int argc, char const *argv[])
{
    testEstTermine();
    // Initialisation du temps pour l'aléatoire
    srand((int)time(0));
/*
    Plateau plateau = {
        {0,0,0,2},
        {2,0,2,0},
        {0,0,0,8},
        {0,0,0,0}
    };
    cout << score(plateau) << endl;
    plateau = ajouteDeuxOuQuatre(plateau);
    affichePlateau(plateau);
    
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
   bool jeu = true;
   string touche;
   int touche_int;
   Plateau plateau;
   do
   {
       plateau = plateauVide();
       plateau = plateauInitial(plateau);
       while (not estGagnant(plateau) &&  not estTermine(plateau)){
           dessine(plateau);
           cout << "Entrer commande (z/q/s/d) >>";
           cin >> touche;
           cout << endl;
           touche_int = (int)touche[0];
           if (plateau == deplacement(plateau, touche_int)){
               cout << "Entrée invalide" << endl;
           } else {
               plateau = deplacement(plateau, touche_int);
               plateau = ajouteDeuxOuQuatre(plateau);
           }
       }
       

        string rejouer;
        cout << "Rejouer ? (y/n) >>" << endl;
        cin >> rejouer;
        if (rejouer[0] == 'y'){
            jeu = true;
        } else if (rejouer[0] == 'n'){
            jeu = false;
        }
   } while (jeu == true);
   
    
    return 0;
}


