#include <iostream>
#include <time.h>
#include "modeleIA.h"

using namespace std;


int main(int argc, char const *argv[])
{
    // Initialisation du temps pour l'aléatoire
    srand((int)time(0));

    bool jeu = true;
    Plateau plateau;
    Plateau np;
    do
    {
        plateau = plateauVide();
        plateau = plateauInitial();
        bool termine=!estTermine(plateau);
        while (    termine){
            cout << "\nScore: " << score(plateau) << "\n\n";
            dessine(plateau);  
            np= ia (plateau,5).dep;
            if (plateau  == np) {
                termine=false;
            }else{      
                plateau = np;
                termine=!estTermine(plateau);;
            }
       }
       cout << "\nScore: " << score(plateau) << "\n\n";
       dessine(plateau);
       if (estGagnant(plateau)){
           cout << "Vous avez gagné !" << endl;
       } else {
           cout << "Vous avez perdu !" << endl;
       }
       

        string rejouer;
        cout << "Rejouer ? (y/n) >>" << endl;
        cin  >> rejouer;
        if (rejouer[0] == 'y'){
            jeu = true;
        } else {
            jeu = false;
        }
    } while (jeu == true);
   
    return 0;
}

