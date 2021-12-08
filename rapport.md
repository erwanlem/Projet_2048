# Rapport de projet

*Les paragraphes en italique comme celui-ci vous donnent des
indications sur le contenu attendu; ils sont à supprimer une fois
votre rapport rédigé*

*Ce rapport pourra servir de support pour votre présentation orale*

*Soyez objectifs et factuels! Vous ne serez pas évalué sur ce que vous
affirmez, mais sur la pertinence et la justesse de ce que vous
affirmez.*

## Auteurs

- Lemattre, Erwan, erwan.lemattre@universite-paris-saclay.fr, LDDIM2
- Dufour, Ewen, ewen.dufour@universite-paris-saclay.fr, LDDIM2

## Résumé du travail effectué

*Pour chaque niveau du sujet, décrire brièvement l'avancement de votre
projet. Exemples de réponses: «non traitée», «réalisée, documentée,
testée», «réalisée, sauf 2.3», «réalisée mais non testée», «réalisée
sauf 2.4 pour lequel notre programme ne compile pas». Pour les
questions «Aller plus loin» plus ouvertes, décrire plus en détail ce
que vous avez choisi de réaliser.*

*En plus du rapport, la documentation de chaque fonction dans le code
devra préciser son auteur et votre degré de confiance dans
l'implantation et les éléments factuels motivant cette confiance:
présence de tests, bogues et limitations connus, etc.*

#### **Vous pouvez retrouver notre projet sur [ce lien](https://github.com/erwanlem/Projet_2048/)**


Chaque niveau est associé à un fichier readMe.md contenant les librairies utilisées pour ce niveau et d'autres informations telles que la méthode de compilation, etc...


- Niveau 0:  Niveau complet: fonctions réalisées, documentées, testées. Pas de difficulté particulière.
- Niveau 1:  Niveau complet: fonctions réalises, documentées, testées. Pas de difficulté particulière. Les fonctions de ce niveau sont pour la plupart les mêmes que celle du niveau précédent. Modification des fonctions de dessin afin de mettre en couleur et modification de la fonction main pour adapter à ncurses. Certaines fonctions sont également modifiées pour gérer une structure plutôt qu'un plateau comme au     niveau 0. Pas de difficultés particulière à ce niveau.\n- Niveau 2:\n    Niveau similaire au niveau 1. Ajout d'un fichier makefile et création d'un GitHub.
- Niveau 3:  Toutes les étapes sauf la 3.4 sont réalisées:
    * 3.1: IA réalisée. Tuile Maximale obtenue (pour le moment) 2048. Effectue des test sur 5 générations. Pour la compilation:\n Section spéciale attribuée sur le github. Utilise une variante du niveau 0. Peut etre implémentée sur le niveau 3.
    * 3.2: Variante réalisée, documentée et testée. Variante imaginée par Erwan Lemattre (pas trouvé d'équivalent                   sur internet). Variante: 128 chrono! Le but est d'arriver à 128 le plus rapidement possible. Avantage: parties rapide           et petit défis (faire le meilleurs temps). Les fonctions sont similaires à celles du 2048 classique sauf quelques une           adaptées pour cette variante. On retrouve les fonctions spécifiques à cette variante dans le fichier \"variante.cpp\".\n        Cette variante est réalisée sur l'interface graphique (pas disponible en console).\n        \n    
    * 3.3: Interface graphique réalisée, documentée et testée. L'interface graphique utilise la librairie SDL2 ainsi que           SDL2_ttf (pour écriture). Les instructions d'installation des librairies sont dans le fichier readMe associé à ce               niveau. L'interface graphique est composée d'un menu, du jeu 2048 classique et de la variante 128 chrono. Il y a également des affichages dédiés à la victoire et la défaite. Les affichages décrient précédemment sont dans le fichier windows.cpp. On retrouve le fichier modele.cpp, contenant le 2048 (mêmes fonctions qu'au niveau 0). Le fichier variante.cpp contient les fonctions décrites au niveau précédent. Le fichier graphic_outils.cpp contient les fonctions nécessaire à l'interface graphique. Enfin le fichier main.cpp contient la boucle principale de l'interface graphique. Plus d'informations relatives aux fichiers dans le fichier readMe du niveau 3. \n    Quelques problèmes dû à un oubli de désallocation en mémoire avec "SDL_Destroy", menant à une saturation totale de la mémoire rendant le pc inutilisable. Problème assez facilement réglé. Autre problème lors de l'utilisation de la librairie SDL_ttf, qui nécessite l'ajout d'un paramètre de compilation. Problème réglé facilement mais identifié après beaucoup de temps. Pas d'autre problème rencontré à ce niveau.\n        \n    
    * 3.4: Non traitée.

## Démonstration

*Soutenez ce que vous affirmez dans la section précédente au moyen de
quelques exemples **bien choisis**. Vous pourrez par exemple compiler et
lancer certains de vos programmes, lancer des tests, etc.*

*À titre d'inspiration, vous trouverez ci-dessous comment compiler un
programme du projet depuis cette feuille. Notez comment on lance une
commande shell en la préfixant d'un point d'exclamation.*

*Ne gardez que des exemples pertinents qui mettent en valeur votre
travail. Inutile de perdre du temps sur le premier programme si vous
avez fait les suivants plus compliqués; l'auditeur se doutera bien que
vous avez réussi à le faire.*


```
#include <vector>
using namespace std;
typedef vector<vector<int>> Plateau;
```

### Fonction deplacementGauche
Une fonction intéressante car elle se passe en deux étapes:
* l'association des valeurs
* le décallage à gauche du tableau


```
Plateau deplacementGauche(Plateau plateau){
    for (int i = 0; i < plateau.size(); i++){
        // association
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
        // décallage
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
```


```
// Tests de la fonction

void testDeplacementGauche(){
    Plateau plt1        = { {0,2,0,0}, {0,4,0,4}, {0,8,0,0}, {2,2,0,2} };
    Plateau plt1_gauche = { {2,0,0,0}, {8,0,0,0}, {8,0,0,0}, {4,2,0,0} };
    Plateau plt2        = { {4,0,2,0}, {2,2,2,2}, {0,0,0,2}, {0,32,32,0} };
    Plateau plt2_gauche = { {4,2,0,0}, {4,4,0,0}, {2,0,0,0}, {64,0,0,0} };
    Plateau plt3        = { {16,0,2,0}, {8,4,2,2}, {16,16,0,2}, {0,32,32,32} };
    Plateau plt3_gauche = { {16,2,0,0}, {8,4,2,0}, {32,2,0,0}, {64,32,0,0} };
    CHECK ( deplacementGauche(plt1) == plt1_gauche );
    CHECK ( deplacementGauche(plt2) == plt2_gauche );
    CHECK( deplacementGauche(plt3) == plt3_gauche )
}
```

### Fonction touche_bouton
Cette fonction permet de vérifier si la souris touche un bouton donné en paramètre  
**Fonction non éxécutable sur Jupyter (nécessite SDL2)**


```
bool touche_bouton(SDL_Rect btn, int x, int y){
    // on regarde si nos coordonnées sont dans le rectangle
    if (x >= btn.x && x <= (btn.x + btn.w) && y >= btn.y && y <= (btn.y + btn.h)){
        return true;
    } else {
        return false;
    }
}
```

### Fonction victoire
La fonction victoire fait partie des fonctions d'affichage. La structure de ces fonctions reste similaire.
Cette fonction est intéressante car dans cette fonction (et toutes les fonctions d'affichage) ce n'est pas le programme qui guide l'utilisateur mais l'utilisateur qui guide le programme (programmation événementielle).  
**Fonction non éxécutable sur Jupyter (nécessite SDL2)**


```
int victoire(SDL_Renderer * renderer, int game){
    
    /*
    
    Tout ce qui se trouve avant la boucle des événements sert à définir des variables, tableaux, etc... qui ensuite
    sont utilisés dans la boucle des événements (permet de ne pas redéfinir des variable à chaque tour de boucle)
    
    */
    
    
    SDL_Color white = {255, 255, 255};
    SDL_Color gold = {255, 215, 0};

    char victoire[] = "Vous avez gagné !";
    char play[]     = "Rejouer";
    char menu[]     = "Menu";
    char quit[]     = "Quitter";
    string mainStat = "Score: 0";
    string bestStat = "Meilleurs score: 0";


    int m, s, ms, t; // Variables du chrono

    // Modification l'affichage en fonction du mode de jeu
    if (game == 1){
        mainStat = "Score: " + to_string(transfertFichier(0, 0, 1)[0]);
        bestStat = "Record: " + to_string(transfertFichier(0, 0, 1)[2]);
    } else {
        t = transfertFichier(0, 0, 1)[1];
        m = t / 6000;
        s = (t - (t /6000) * 6000) / 100;
        ms = (t - (m * 6000)) - (s * 100);
        mainStat = "Temps: " + to_string( m ) + ":" + to_string( s ) + "." + to_string( ms );

        t = transfertFichier(0, 0, 1)[3];
        m = t / 6000;
        s = (t - (t /6000) * 6000) / 100;
        ms = (t - (m * 6000)) - (s * 100);
        bestStat = "Record: " + to_string( m ) + ":" + to_string( s ) + "." + to_string( ms );
    }
    char const* mainStatChar = mainStat.c_str();
    char const* bestStatChar = bestStat.c_str();


    // Message principal
    SDL_Texture * main_text_txt = create_text(renderer, victoire, gold, 100);
    SDL_Rect main_rect          = { (WIDTH/2) - (pourcentage(46, WIDTH)/2), (HEIGHT/3) - pourcentage(20, HEIGHT), pourcentage(46, WIDTH), pourcentage(20, HEIGHT)};
    
    SDL_Rect stat_rect_txt = { (WIDTH/2) - (pourcentage(26, WIDTH)/2), pourcentage(36, HEIGHT), pourcentage(26, WIDTH), pourcentage(12, HEIGHT)};
    SDL_Texture * stat_txt = create_text(renderer, (char*)mainStatChar, white, 100);

    SDL_Rect best_stat_rect_txt = { (WIDTH/2) - (pourcentage(26, WIDTH)/2), pourcentage(50, HEIGHT), pourcentage(26, WIDTH), pourcentage(12, HEIGHT)};
    SDL_Texture * best_stat_txt = create_text(renderer, (char*)bestStatChar, white, 100);

    // Boutons affichés à l'écran
    // Jouer
    SDL_Rect play_rect    = { (WIDTH/10)*7 - (pourcentage(10, WIDTH)/2) - 10, pourcentage(70, HEIGHT) - 5, pourcentage(10, WIDTH) + 20, pourcentage(8, HEIGHT) + 10};
    SDL_Rect play_rect_txt = { (WIDTH/10)*7 - (pourcentage(10, WIDTH)/2), pourcentage(70, HEIGHT), pourcentage(10, WIDTH), pourcentage(8, HEIGHT)};
    SDL_Texture * play_txt = create_text(renderer, play, white, 100);

    // Menu
    SDL_Rect menu_rect     = { (WIDTH/10)*5 - (pourcentage(10, WIDTH)/2) - 10, pourcentage(70, HEIGHT) - 5, pourcentage(10, WIDTH) + 20, pourcentage(8, HEIGHT) + 10};
    SDL_Rect menu_rect_txt = { (WIDTH/10)*5 - (pourcentage(10, WIDTH)/2), pourcentage(70, HEIGHT), pourcentage(10, WIDTH), pourcentage(8, HEIGHT)};
    SDL_Texture * menu_txt = create_text(renderer, menu, white, 100);

    // Quitter le jeu
    SDL_Rect quit_rect     = { (WIDTH/10)*3 - (pourcentage(10, WIDTH)/2) - 10, pourcentage(70, HEIGHT) - 5, pourcentage(10, WIDTH) + 20, pourcentage(8, HEIGHT) + 10};
    SDL_Rect quit_rect_txt = { (WIDTH/10)*3 - (pourcentage(10, WIDTH)/2), pourcentage(70, HEIGHT), pourcentage(10, WIDTH), pourcentage(8, HEIGHT)};
    SDL_Texture * quit_txt = create_text(renderer, quit, white, 100);


    SDL_Color button_default_color = {10, 210, 10};
    SDL_Color button_over_default_color = {0, 128, 0};
    SDL_Color btn1_color = button_default_color;
    SDL_Color btn2_color = button_default_color;
    SDL_Color btn3_color = button_default_color;

    /* -- -- -- -- -- -- -- -- -- -- -- -- -- */
    /*            BOUCLE EVENEMENTS           */


    bool victory_loop = true;
    SDL_Event e;
    
    /* 
    On arrive en suite à notre boucle.
    la boucle des événements récupère en permanence les entrées utilisateur et agit en fonction
    
    */
    while (victory_loop)
    {
        SDL_PollEvent(&e);
        if (e.type == SDL_QUIT){
            victory_loop = false;
            return 0;
        } else if (e.type == SDL_MOUSEBUTTONDOWN){
            if (touche_bouton(quit_rect, e.motion.x, e.motion.y)){
                victory_loop = false;
                return 0;
            } else if (touche_bouton(menu_rect, e.motion.x, e.motion.y)){
                return 1;
            } else if (touche_bouton(play_rect, e.motion.x, e.motion.y)){
                SDL_DestroyTexture(play_txt);
                SDL_DestroyTexture(menu_txt);
                SDL_DestroyTexture(quit_txt);
                SDL_DestroyTexture(main_text_txt);
                if (game == 1){
                    return 2;
                } else {
                    return 5;
                }
            }
        } else if (e.type == SDL_MOUSEMOTION){  // changement de couleur des boutons si la souris est au-dessus
            if (touche_bouton(play_rect, e.motion.x, e.motion.y)){
                btn1_color = button_over_default_color;
            } else {
                btn1_color = button_default_color;
            }
            if (touche_bouton(menu_rect, e.motion.x, e.motion.y)){
                btn2_color = button_over_default_color;
            } else {
                btn2_color = button_default_color;
            }
            if (touche_bouton(quit_rect, e.motion.x, e.motion.y)){
                btn3_color = button_over_default_color;
            } else {
                btn3_color = button_default_color;
            }
        }

        
        /* 
            L'affichage est en permanence "nettoyé" puis redéssiné
        */
        
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);

        // Rendu des boutons (rectangles) et mise en couleur
        SDL_SetRenderDrawColor(renderer, btn1_color.r, btn1_color.g, btn1_color.b, 255);
        SDL_RenderFillRect(renderer, &play_rect);
        SDL_SetRenderDrawColor(renderer, btn2_color.r, btn2_color.g, btn2_color.b, 255);
        SDL_RenderFillRect(renderer, &menu_rect);
        SDL_SetRenderDrawColor(renderer, btn3_color.r, btn3_color.g, btn3_color.b, 255);
        SDL_RenderFillRect(renderer, &quit_rect);

        // On ajoute le texte à l'écran
        SDL_RenderCopy(renderer, main_text_txt, NULL, &main_rect);
        SDL_RenderCopy(renderer, play_txt, NULL, &play_rect_txt);
        SDL_RenderCopy(renderer, menu_txt, NULL, &menu_rect_txt);
        SDL_RenderCopy(renderer, quit_txt, NULL, &quit_rect_txt);
        SDL_RenderCopy(renderer, stat_txt, NULL, &stat_rect_txt);
        SDL_RenderCopy(renderer, best_stat_txt, NULL, &best_stat_rect_txt);

        SDL_RenderPresent(renderer);
    }
    return 0;
    /*
    
        Les fonctions d'affichage revoient toute un entier qui indique à la fonction main l'action suivante 
        (quitter le jeu, retour au menu)
    
    */
}
```
### Implémentation de l'intélligence artificielle
Cette fonction calcule les 4 prochains coup et determine lequel d'entre eux est le plus judicieux.
**Nécéssite une variante du niveau 0 pour fonctionner. Non implémenté dans le niveau 3**
```
Deplacement ia(Plateau plateau, int rec){
	Plateau pltg=deplacementGauche(plateau);	
	Plateau pltd=deplacementDroite(plateau);
	Plateau plth=deplacementHaut(plateau);
    Plateau pltb=deplacementBas(plateau);
    bool state;
    Deplacement choix;
    choix.score=-1;
    choix.dep=plateau;
    int scores=0;
    vector<Plateau> mvt;
    mvt=vector<Plateau>(4);
    mvt={pltg, pltd, plth, pltb};

    for(int i=0; i<mvt.size(); i++){
        if(not(estRempli(mvt[i]))){
            mvt[i]=ajouteDeuxOuQuatre(mvt[i]);
            state=true;
        }
        else{
            state=false;
        }
        if(state){
            if(rec!=0){
                scores=ia(mvt[i], rec-1).score;
            }else{
                scores=score(mvt[i]);
            }
            if(scores>choix.score){
                choix.score=scores;
                choix.dep=mvt[i];
            }
            
        }
    } 
    return choix;

}
```
### Compilation et exécution de l'IA 

```
! info-111 g++ -c modeleIA.cpp
```


```
! info-111 g++ -c 2048IA.cpp
```


```
! info-111 g++ 2048IA.o modeleIA.o -o 2048IA
```


```
! ./2048IA
```

### Compilation et exécution des test du niveau 0
Compilation des fichiers du niveau 0. Les fonctions de test sont également ajoutées au main, si tout fonctionne bien il ne devrait pas y avoir d'erreurs à l'exécution.


```
! info-111 g++ -c modele.cpp
```


```
! info-111 g++ -c 2048.cpp
```


```
! info-111 g++ 2048.o modele.o -o 2048
```


```
! ./2048
```

## Organisation du travail

*Décrire en quelques phrases comment vous vous êtes organisés pour
travailler sur le projet: nombre d'heures consacrées au projet,
répartition du travail dans le binôme, moyens mis en œuvre pour
collaborer, etc. Si vous avez bénéficié d'aide (en dehors de celle
de vos enseigants), précisez le.*

#### Erwan:
Mise en place dès le début d'un GitHub permettant le partage du code plus facilement. Nous nous sommes répartis les fonctions du niveau 0. Réalisation des niveau 1 et 2 par moi. Niveau 3 partagé en 2: je fais l'interface graphique, il fait le robot. Pas d'obligation de travail précise, le code reste accessible et modifiable pour amélioration ou correction même si ce n'est pas le notre.  
Estimation du temps accordé à ce projet: 30-40H

####

## Prise de recul

*Décrire en quelques phrases les difficultés rencontrées, ce que vous
avez appris à l'occasion du projet, le cas échéant comment vous vous y
prendriez si vous aviez à le refaire.*

#### Erwan:
Pas trop de difficulté sur ce projet. Pour le niveau 3,  expérience avec pygame (python) basé sur SDL2 donc assez familier avec ce genre de programmation.
Découverte de GitHub, outil très pratique sur ce genre de projet.
Pour une prochaine fois, peut-être penser dès le début à une organisation exacte du projet (changement dans la disposition des fichiers au niveau 3 au cours de ce projet).

#### Ewen:
Programation de l'IA assez fastidieuse. Algorithme testé: Mouvement avec le meilleur score, Meilleur score+Plus grand nombre de case vide, meilleur score sur plusieurs générations.
Algorithme choisi: Meilleur score sur plusieurs générations.
