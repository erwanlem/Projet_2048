#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <iostream>
#include <vector>
#include "modele.h"
#include <string>


using namespace std;

int width, height;
int QUATRE;



/**
 * Affiche fenêtre de victoire
 * 
 * @param renderer la zone de rendu
 * @return int le code de la prochaine fenêtre à afficher
 */
int victoire(SDL_Renderer * renderer){
    SDL_Color white = {255, 255, 255};

    char victoire[] = "Vous avez gagné !";
    char play[]     = "Rejouer";
    char menu[]     = "Menu";
    char quit[]     = "Quitter";

    // Message principal
    SDL_Texture * main_text_txt = create_text(renderer, victoire, white, 100);
    SDL_Rect main_rect          = { (width/2) - (pourcentage(46, width)/2), (height/2) - pourcentage(20, height), pourcentage(46, width), pourcentage(20, height)};

    // Boutons affichés à l'écran
    SDL_Rect play_rect     = { (width/10)*7 - (pourcentage(10, width)/2) - 10, pourcentage(70, height) - 5, pourcentage(10, width) + 20, pourcentage(8, height) + 10};
    SDL_Rect play_rect_txt = { (width/10)*7 - (pourcentage(10, width)/2), pourcentage(70, height), pourcentage(10, width), pourcentage(8, height)};
    SDL_Texture * play_txt = create_text(renderer, play, white, 100);

    SDL_Rect menu_rect     = { (width/10)*5 - (pourcentage(10, width)/2) - 10, pourcentage(70, height) - 5, pourcentage(10, width) + 20, pourcentage(8, height) + 10};
    SDL_Rect menu_rect_txt = { (width/10)*5 - (pourcentage(10, width)/2), pourcentage(70, height), pourcentage(10, width), pourcentage(8, height)};
    SDL_Texture * menu_txt = create_text(renderer, menu, white, 100);

    SDL_Rect quit_rect     = { (width/10)*3 - (pourcentage(10, width)/2) - 10, pourcentage(70, height) - 5, pourcentage(10, width) + 20, pourcentage(8, height) + 10};
    SDL_Rect quit_rect_txt = { (width/10)*3 - (pourcentage(10, width)/2), pourcentage(70, height), pourcentage(10, width), pourcentage(8, height)};
    SDL_Texture * quit_txt = create_text(renderer, quit, white, 100);


    /* -- -- -- -- -- -- -- -- -- -- -- -- -- */
    /*            BOUCLE EVENEMENTS           */


    bool victory_loop = true;
    SDL_Event e;
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
                return 2;
            }
        }

        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);

        SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
        SDL_RenderFillRect(renderer, &play_rect);
        SDL_RenderFillRect(renderer, &menu_rect);
        SDL_RenderFillRect(renderer, &quit_rect);

        SDL_RenderCopy(renderer, main_text_txt, NULL, &main_rect);
        SDL_RenderCopy(renderer, play_txt, NULL, &play_rect_txt);
        SDL_RenderCopy(renderer, menu_txt, NULL, &menu_rect_txt);
        SDL_RenderCopy(renderer, quit_txt, NULL, &quit_rect_txt);

        SDL_RenderPresent(renderer);
    }
    return 0;
}
/* ------ ------ ------ ------ ------ ------ ------ ------ ------ ------ ------ ------ ------ ------ ------  */
/* ------ ------ ------ ------ ------ FIN FONCTION VICTOIRE ----- ------ ------ ------ ------ ------ ------  */
/* ------ ------ ------ ------ ------ ------ ------ ------ ------ ------ ------ ------ ------ ------ ------  */






/**
 * Affiche fenêtre de défaite
 * 
 * @param renderer la zone de rendu
 * @return int le code de la prochaine fenêtre à afficher
 */
int defaite(SDL_Renderer * renderer){
    SDL_Color white = {255, 255, 255};

    char victoire[] = "Vous avez perdu :/";
    char play[]     = "Rejouer";
    char menu[]     = "Menu";
    char quit[]     = "Quitter";

    // Message principal
    SDL_Texture * main_text_txt = create_text(renderer, victoire, white, 100);
    SDL_Rect main_rect = { (width/2) - (pourcentage(46, width)/2), (height/2) - pourcentage(20, height), pourcentage(46, width), pourcentage(20, height)};


    // Boutons affichés à l'écran
    SDL_Rect play_rect     = { (width/10)*7 - (pourcentage(10, width)/2) - 10, pourcentage(70, height) - 5, pourcentage(10, width) + 20, pourcentage(8, height) + 10};
    SDL_Rect play_rect_txt = { (width/10)*7 - (pourcentage(10, width)/2), pourcentage(70, height), pourcentage(10, width), pourcentage(8, height)};
    SDL_Texture * play_txt = create_text(renderer, play, white, 100);

    SDL_Rect menu_rect     = { (width/10)*5 - (pourcentage(10, width)/2) - 10, pourcentage(70, height) - 5, pourcentage(10, width) + 20, pourcentage(8, height) + 10};
    SDL_Rect menu_rect_txt = { (width/10)*5 - (pourcentage(10, width)/2), pourcentage(70, height), pourcentage(10, width), pourcentage(8, height)};
    SDL_Texture * menu_txt = create_text(renderer, menu, white, 100);

    SDL_Rect quit_rect = { (width/10)*3 - (pourcentage(10, width)/2) - 10, pourcentage(70, height) - 5, pourcentage(10, width) + 20, pourcentage(8, height) + 10};
    SDL_Rect quit_rect_txt = { (width/10)*3 - (pourcentage(10, width)/2), pourcentage(70, height), pourcentage(10, width), pourcentage(8, height)};
    SDL_Texture * quit_txt = create_text(renderer, quit, white, 100);


    /* -- -- -- -- -- -- -- -- -- -- -- -- -- */
    /*            BOUCLE EVENEMENTS           */

    bool loose_loop = true;
    SDL_Event e;
    while (loose_loop)
    {
        SDL_PollEvent(&e);
        if (e.type == SDL_QUIT){
            loose_loop = false;
            return 0;
        } else if (e.type == SDL_MOUSEBUTTONDOWN){
            if (touche_bouton(quit_rect, e.motion.x, e.motion.y)){
                loose_loop = false;
                return 0;
            } else if (touche_bouton(menu_rect, e.motion.x, e.motion.y)){
                return 1;
            } else if (touche_bouton(play_rect, e.motion.x, e.motion.y)){
                SDL_DestroyTexture(play_txt);
                SDL_DestroyTexture(menu_txt);
                SDL_DestroyTexture(quit_txt);
                SDL_DestroyTexture(main_text_txt);
                return 2;
            }
        }

        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);

        SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
        SDL_RenderFillRect(renderer, &play_rect);
        SDL_RenderFillRect(renderer, &menu_rect);
        SDL_RenderFillRect(renderer, &quit_rect);

        SDL_RenderCopy(renderer, main_text_txt, NULL, &main_rect);
        SDL_RenderCopy(renderer, play_txt, NULL, &play_rect_txt);
        SDL_RenderCopy(renderer, menu_txt, NULL, &menu_rect_txt);
        SDL_RenderCopy(renderer, quit_txt, NULL, &quit_rect_txt);

        SDL_RenderPresent(renderer);
    }
    return 0;
}
/* ------ ------ ------ ------ ------ ------ ------ ------ ------ ------ ------ ------ ------ ------ ------  */
/* ------ ------ ------ ------ ------ FIN FONCTION DEFAITE ------ ------ ------ ------ ------ ------ ------  */
/* ------ ------ ------ ------ ------ ------ ------ ------ ------ ------ ------ ------ ------ ------ ------  */





/**
 * Fonction création du menu
 * 
 * @param renderer la zone de rendu
 * @return int un entier correspondant à l'action à affectuer à la fin de cette fonction
 */
int menu(SDL_Renderer * renderer){
    SDL_Color white = {255, 255, 255, 255};
    Uint32 last_time = SDL_GetTicks();
    Uint32 current_time;

    // Création des textures du texte
    char play_txt[] = "JOUER";
    char var_txt[]  = "2048 CHRONO !";
    char quit_txt[] = "QUITTER";
    SDL_Texture * texture_play = create_text(renderer, play_txt, white, 100);
    SDL_Texture * texture_var = create_text(renderer, var_txt, white, 100);
    SDL_Texture * texture_quit = create_text(renderer, quit_txt, white, 80);

    SDL_Rect rect_anim1 = { rand()%width - pourcentage(8, width), 0 - pourcentage(8, width), pourcentage(8, width), pourcentage(8, width)};
    SDL_Rect rect_anim2 = { rand()%width - pourcentage(8, width), 0 - pourcentage(8, width), pourcentage(8, width), pourcentage(8, width)};
    SDL_Texture * texture_anim1 = genere_cube(renderer);
    SDL_Texture * texture_anim2 = genere_cube(renderer);

    // Paramètres du titre (2048) et chargement des coordonnées
    int taille_block = pourcentage(3.5, (width + height) / 2);
    int pourcentage_x = pourcentage(25, width);
    vector<vector<int>> titre;
    titre = titre_menu(pourcentage_x, taille_block);

    // Paramètres des emplacements des éléments du menu
    int button_w = pourcentage(40, width);
    int button_h = pourcentage(20, height);
    SDL_Rect play_button = {width/2 - button_w/2, height/8 * 3, button_w, button_h};
    SDL_Rect opt_button  = {width/2 - button_w/2, height/8 * 5, button_w, button_h};
    SDL_Rect quit_button = {10, height-60, pourcentage(12, width), pourcentage(9, height)};

    // Emplacement du texte
    SDL_Rect play_button_text = {width/2 - button_w/2 + ((play_button.w - (int)(button_w*0.8))/2), (height/8 * 3 + (play_button.h - (int)(button_h*0.8))/2), (button_w*80)/100, (button_h*80)/100};
    SDL_Rect opt_button_text  = {width/2 - button_w/2 + ((opt_button.w - (int)(button_w*0.8))/2), (height/8 * 5 + (opt_button.h - (int)(button_h*0.8))/2), (button_w*80)/100, (button_h*80)/100};
    SDL_Rect quit_button_text = {10 + ((quit_button.w - pourcentage(10, width))/2), ((height-60) + (quit_button.h - pourcentage(6, height))/2), pourcentage(10, width), pourcentage(6, height)};
    

    // Couleur des boutons
    SDL_Color button_default_color = {30, 132, 127};
    SDL_Color button_over_default_color = {37, 178, 171};
    SDL_Color btn1_color = button_default_color;
    SDL_Color btn2_color = button_default_color;
    SDL_Color btn3_color = button_default_color;

    /* -- -- -- -- -- -- -- -- -- -- -- -- -- */
    /*            BOUCLE EVENEMENTS           */

    bool menu = true;
    SDL_Event e;
    
    while (menu)
    {
        current_time = SDL_GetTicks();
        if (current_time - last_time > 40){
            
        }

        SDL_PollEvent(&e);
        if (e.type == SDL_QUIT){
            menu = false;
        } else if (e.type == SDL_MOUSEBUTTONDOWN){
            if (touche_bouton(play_button, e.motion.x, e.motion.y)){
                return 2;
            } else if (touche_bouton(quit_button, e.motion.x, e.motion.y)){
                return 0;
            } else if (touche_bouton(opt_button, e.motion.x, e.motion.y)) {
                return 5;
            }
        } else if (e.type == SDL_MOUSEMOTION){
            if (touche_bouton(play_button, e.motion.x, e.motion.y)){
                btn1_color = button_over_default_color;
            } else {
                btn1_color = button_default_color;
            }
            if (touche_bouton(opt_button, e.motion.x, e.motion.y)){
                btn2_color = button_over_default_color;
            } else {
                btn2_color = button_default_color;
            }
            if (touche_bouton(quit_button, e.motion.x, e.motion.y)){
                btn3_color = button_over_default_color;
            } else {
                btn3_color = button_default_color;
            }
        }

        // Actualise l'affichage
        // -> Réinitialise l'écran en noir avant de dessiner dessus
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);

        SDL_SetRenderDrawColor(renderer, 236, 193, 156, 255);

        // Dessine tous les cubes du titre
        for (int i = 0; i < titre.size(); i ++){
            SDL_Rect rect = {titre[i][0], titre[i][1], taille_block, taille_block};
            SDL_RenderFillRect(renderer, &rect);
        }

        // Dessin des éléments
        SDL_SetRenderDrawColor(renderer, btn1_color.r, btn1_color.g, btn1_color.b, 255);
        SDL_RenderFillRect(renderer, &play_button);
        SDL_RenderCopy(renderer, texture_play, NULL, &play_button_text);
        SDL_SetRenderDrawColor(renderer, btn2_color.r, btn2_color.g, btn2_color.b, 255);
        SDL_RenderFillRect(renderer, &opt_button);
        SDL_RenderCopy(renderer, texture_var, NULL, &opt_button_text);
        SDL_SetRenderDrawColor(renderer, btn3_color.r, btn3_color.g, btn3_color.b, 255);
        SDL_RenderFillRect(renderer, &quit_button);
        SDL_RenderCopy(renderer, texture_quit, NULL, &quit_button_text);

        SDL_RenderCopy(renderer, texture_anim1, NULL, &rect_anim1);

        // Actualise l'affichage
        SDL_RenderPresent(renderer);
    }
    return 0;
}
/* ------ ------ ------ ------ ------ ------ ------ ------ ------ ------ ------ ------ ------ ------ ------  */
/* ------ ------ ------ ------ ------ - FIN FONCTION MENU ------- ------ ------ ------ ------ ------ ------  */
/* ------ ------ ------ ------ ------ ------ ------ ------ ------ ------ ------ ------ ------ ------ ------  */






/**
 * Fonction de jeu
 * 
 * @param renderer la zone de dessin
 * @return int un entier correspondant à l'action à affectuer à la fin de la fonction
 */
int game(SDL_Renderer * renderer){
    // On réinitialise QUATRE à 0
    QUATRE = 0;

    
    Plateau plateau = plateauVide();
    plateau = plateauInitial();

    // Définition couleur(s)
    SDL_Color white = {255, 255, 255};

    // Taille des cases de la grille
    int case_nbr_size = pourcentage(20, height);

    // Calcul des marges sur les côtés de la grille
    int margin_lr = (width - (pourcentage(20, height) * 4))/2;
    int margin_tb = (height - (pourcentage(20, height) * 4))/2;

    // Création d'un tableau avec les coordonnées de chaque case du plateau
    vector<vector<int>> plateau_coord;
    plateau_coord = vector<vector<int>>(16);
    int x = 0, y = 0;
    for (int i = 0; i < plateau_coord.size(); i++){
        plateau_coord[i] = {margin_lr + (x * case_nbr_size), margin_tb + (y * case_nbr_size)};
        x++;
        if (x > 3){
            x = 0;
            y++;
        }
    }

    

    // Création de tableaux contenant les coordonnées des cases de la grille
    vector<SDL_Rect> dessin_grille1;
    vector<SDL_Rect> dessin_grille2;
    dessin_grille1 = vector<SDL_Rect>(16);
    dessin_grille2 = vector<SDL_Rect>(16);
    for (int i = 0; i < dessin_grille1.size(); i++ ){
        SDL_Rect rect1;
        SDL_Rect rect2;
        rect1 = {plateau_coord[i][0], plateau_coord[i][1], case_nbr_size, case_nbr_size};
        rect2 = {plateau_coord[i][0] + 2, plateau_coord[i][1] + 2, case_nbr_size - 4, case_nbr_size - 4};

        dessin_grille1[i] = rect1;
        dessin_grille2[i] = rect2;
    }
    
    // Création des textures de chaque nombres du plateau
    // Les textures sont ajoutées dans un tableau que l'on
    // parcourt à l'affichage
    vector<SDL_Texture*> grilleTextTexture;
    grilleTextTexture = vector<SDL_Texture*>(16);
    grilleTextTexture = textFromPlateau(renderer, plateau, white, grilleTextTexture);


    // Délcaration des variables pour dessin du plateau
    SDL_Texture * number_case;
    SDL_Rect rect_txt;
    SDL_Rect rect;
    SDL_Rect rect1;

    // Affichage du score
    char s[] = "Score: 0";
    char const * scr;
    string scr_str;
    SDL_Texture * score_txt = create_text(renderer, s, white);
    SDL_Rect score_rect     = {20, 20, pourcentage(10, width), pourcentage(6, height)};

    

    /* Evite la répétition d'une touche si l'on reste appuyé dessus
    // -> utilisé dans evenements SDL_KEYDOWN pour que l'apuie sur 
    //    une flèche ne fasse qu'un seul déplacement par clique
    */
    bool up = true;


    /* -- -- -- -- -- -- -- -- -- -- -- -- -- */
    /*            BOUCLE EVENEMENTS           */

    bool game = true;
    SDL_Event e;
    while (game){
        SDL_PollEvent(&e);
        if (e.type == SDL_QUIT){
            game = false;
        } else if (e.type == SDL_KEYDOWN){
            if (up == false){
                continue;
            } else {
                switch (e.key.keysym.scancode)
                {
                case 41:
                    SDL_DestroyTexture(score_txt);
                    return 1;
                    break;
                case 79:
                    plateau = deplacement(plateau, DROITE);
                    up = false;
                    if ( !estRempli(plateau) ){
                        plateau = ajouteDeuxOuQuatre(plateau);
                    }
                    scr_str           = to_string(score(plateau));
                    scr_str           = "Score: " + scr_str;
                    scr               = scr_str.c_str();
                    score_txt         = create_text(renderer, (char*)scr, white);
                    grilleTextTexture = textFromPlateau(renderer, plateau, white, grilleTextTexture);
                    break;
                case 80:
                    plateau = deplacement(plateau, GAUCHE);
                    up = false;
                    if ( !estRempli(plateau) ){
                        plateau = ajouteDeuxOuQuatre(plateau);
                    }
                    scr_str           = to_string(score(plateau));
                    scr_str           = "Score: " + scr_str;
                    scr               = scr_str.c_str();
                    score_txt         = create_text(renderer, (char*)scr, white);
                    grilleTextTexture = textFromPlateau(renderer, plateau, white, grilleTextTexture);
                    break;
                case 81:
                    plateau = deplacement(plateau, BAS);
                    up = false;
                    if ( !estRempli(plateau) ){
                        plateau = ajouteDeuxOuQuatre(plateau);
                    }
                    scr_str           = to_string(score(plateau));
                    scr_str           = "Score: " + scr_str;
                    scr               = scr_str.c_str();
                    score_txt         = create_text(renderer, (char*)scr, white);
                    grilleTextTexture = textFromPlateau(renderer, plateau, white, grilleTextTexture);
                    break;
                case 82:
                    plateau = deplacement(plateau, HAUT);
                    up = false;
                    if ( !estRempli(plateau) ){
                        plateau = ajouteDeuxOuQuatre(plateau);
                    }
                    scr_str           = to_string(score(plateau));
                    scr_str           = "Score: " + scr_str;
                    scr               = scr_str.c_str();
                    score_txt         = create_text(renderer, (char*)scr, white);
                    grilleTextTexture = textFromPlateau(renderer, plateau, white, grilleTextTexture);
                    break;
                default:
                    break;
                }
                if (estGagnant(plateau)){
                    return 3;
                } else if (estTermine(plateau)){
                    return 4;
                }
            }
        } else if (e.type == SDL_KEYUP){
            if (up == false){
                up = true;
            }
        }

        // Nettoie affichage avant dessin
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);

        int x = 0, y = 0;
        for (int i = 0; i < plateau_coord.size(); i ++){
            rect  = dessin_grille1[i];
            rect1 = dessin_grille2[i];
            SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
            SDL_RenderFillRect(renderer, &rect);

            // Couleur de la case en fonction du nombre dans la case
            switch (plateau[y][x])
            {
            case 0:
                SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
                break;
            case 2:
                SDL_SetRenderDrawColor(renderer,  52, 73, 94 , 255);
                break;
            case 4:
                SDL_SetRenderDrawColor(renderer,  149, 165, 166 , 255);
                break;
            case 8:
                SDL_SetRenderDrawColor(renderer,  211, 84, 0 , 255);
                break;
            case 16:
                SDL_SetRenderDrawColor(renderer,  243, 156, 18 , 255);
                break;
            case 32:
                SDL_SetRenderDrawColor(renderer,   241, 196, 15 , 255);
                break;
            case 64:
                SDL_SetRenderDrawColor(renderer,   39, 174, 96 , 255);
                break;
            case 128:
                SDL_SetRenderDrawColor(renderer,  22, 160, 133 , 255);
                break;
            case 256:
                SDL_SetRenderDrawColor(renderer,   52, 152, 219 , 255);
                break;
            case 512:
                SDL_SetRenderDrawColor(renderer,  22, 160, 133 , 255);
                break;
            case 1024:
                SDL_SetRenderDrawColor(renderer,   142, 68, 173 , 255);
                break;
            case 2048:
                SDL_SetRenderDrawColor(renderer,   231, 76, 60 , 255);
                break;
            default:
                SDL_SetRenderDrawColor(renderer,  192, 57, 43 , 255);
                break;
            }
            SDL_RenderFillRect(renderer, &rect1);

            rect_txt = {plateau_coord[i][0] + 20, plateau_coord[i][1] + 10, case_nbr_size - 40, case_nbr_size - 20};
            SDL_RenderCopy(renderer, grilleTextTexture[i], NULL, &rect_txt);

            x++;
            if (x > 3){
                x = 0;
                y++;
            }
        }
        SDL_RenderCopy(renderer, score_txt, NULL, &score_rect);
        
        SDL_RenderPresent(renderer);
    }
    SDL_DestroyTexture(score_txt);
    return 0;
}
/* ------ ------ ------ ------ ------ ------ ------ ------ ------ ------ ------ ------ ------ ------ ------  */
/* ------ ------ ------ ------ ------ - FIN FONCTION GAME ------- ------ ------ ------ ------ ------ ------  */
/* ------ ------ ------ ------ ------ ------ ------ ------ ------ ------ ------ ------ ------ ------ ------  */




/**
 * Fonction du jeu 128 chrono !
 * 
 * @param renderer la zone de dessin
 * @return int un entier correspondant à l'action à affectuer à la fin de la fonction
 */
int game_128(SDL_Renderer * renderer){

    Plateau plateau = plateauVideVariante();
    plateau = plateauInitialVariante();

    // Définition couleur(s)
    SDL_Color white = {255, 255, 255};

    // Taille des cases de la grille
    int case_nbr_size = pourcentage(20, height);

    // Calcul des marges sur les côtés de la grille
    int margin_lr = (width - (pourcentage(20, height) * 3))/2;
    int margin_tb = (height - (pourcentage(20, height) * 3))/2;

    // Création d'un tableau avec les coordonnées de chaque case du plateau
    vector<vector<int>> plateau_coord;
    plateau_coord = vector<vector<int>>(9);
    int x = 0, y = 0;
    for (int i = 0; i < plateau_coord.size(); i++){
        plateau_coord[i] = {margin_lr + (x * case_nbr_size), margin_tb + (y * case_nbr_size)};
        x++;
        if (x > 2){
            x = 0;
            y++;
        }
    }

    

    // Création de tableaux contenant les coordonnées des cases de la grille
    vector<SDL_Rect> dessin_grille1;
    vector<SDL_Rect> dessin_grille2;
    dessin_grille1 = vector<SDL_Rect>(9);
    dessin_grille2 = vector<SDL_Rect>(9);
    for (int i = 0; i < dessin_grille1.size(); i++ ){
        SDL_Rect rect1;
        SDL_Rect rect2;
        rect1 = {plateau_coord[i][0], plateau_coord[i][1], case_nbr_size, case_nbr_size};
        rect2 = {plateau_coord[i][0] + 2, plateau_coord[i][1] + 2, case_nbr_size - 4, case_nbr_size - 4};

        dessin_grille1[i] = rect1;
        dessin_grille2[i] = rect2;
    }
    
    // Création des textures de chaque nombres du plateau
    // Les textures sont ajoutées dans un tableau que l'on
    // parcourt à l'affichage
    vector<SDL_Texture*> grilleTextTexture;
    grilleTextTexture = vector<SDL_Texture*>(9);
    grilleTextTexture = textFromPlateau(renderer, plateau, white, grilleTextTexture);


    // Délcaration des variables pour dessin du plateau
    SDL_Texture * number_case;
    SDL_Rect rect_txt;
    SDL_Rect rect;
    SDL_Rect rect1;

    // Affichage du score
    char s[] = "Score: 0";
    char const * scr;
    string scr_str;
    SDL_Texture * score_txt = create_text(renderer, s, white);
    SDL_Rect score_rect     = {20, 20, pourcentage(10, width), pourcentage(6, height)};

    // CHRONO
    string str_chrono1;
    string str_chrono2;
    string str_chrono3;
    char const * chrono_affiche;
    string point = ".";
    string point2 = ":";
    SDL_Rect chrono_rect     = {80, 100, pourcentage(10, width), pourcentage(6, height)};
    char t[] = "00:00.00";
    int chrono_min = 0;
    int chrono_ms = 0;
    int chrono_s = 0;
    SDL_Texture * chrono_txt = create_text(renderer, t, white);
    Uint32 lastTime = 0;
    Uint32 currentTime;

    /* Evite la répétition d'une touche si l'on reste appuyé dessus
    // -> utilisé dans evenements SDL_KEYDOWN pour que l'apuie sur 
    //    une flèche ne fasse qu'un seul déplacement par clique
    */
    bool up = true;

    
    /* -- -- -- -- -- -- -- -- -- -- -- -- -- */
    /*            BOUCLE EVENEMENTS           */

    bool game = true;
    SDL_Event e;
    while (game){
        SDL_PollEvent(&e);
        if (e.type == SDL_QUIT){
            game = false;
        } else if (e.type == SDL_KEYDOWN){
            if (up == false){
                continue;
            } else {
                switch (e.key.keysym.scancode)
                {
                case 41:
                    SDL_DestroyTexture(score_txt);
                    return 1;
                    break;
                case 79:
                    plateau = deplacement(plateau, DROITE);
                    
                    up = false;
                    if ( !estRempli(plateau) ){
                        plateau = ajouteDeux(plateau);
                    }
                    scr_str           = to_string(scoreVariante(plateau));
                    scr_str           = "Score: " + scr_str;
                    scr               = scr_str.c_str();
                    score_txt         = create_text(renderer, (char*)scr, white);
                    grilleTextTexture = textFromPlateau(renderer, plateau, white, grilleTextTexture);
                    break;
                case 80:
                    plateau = deplacement(plateau, GAUCHE);
                    up = false;
                    if ( !estRempli(plateau) ){
                        plateau = ajouteDeux(plateau);
                    }
                    scr_str           = to_string(scoreVariante(plateau));
                    scr_str           = "Score: " + scr_str;
                    scr               = scr_str.c_str();
                    score_txt         = create_text(renderer, (char*)scr, white);
                    grilleTextTexture = textFromPlateau(renderer, plateau, white, grilleTextTexture);
                    break;
                case 81:
                    plateau = deplacement(plateau, BAS);
                    up = false;
                    if ( !estRempli(plateau) ){
                        plateau = ajouteDeux(plateau);
                    }
                    scr_str           = to_string(scoreVariante(plateau));
                    scr_str           = "Score: " + scr_str;
                    scr               = scr_str.c_str();
                    score_txt         = create_text(renderer, (char*)scr, white);
                    grilleTextTexture = textFromPlateau(renderer, plateau, white, grilleTextTexture);
                    break;
                case 82:
                    plateau = deplacement(plateau, HAUT);
                    up = false;
                    if ( !estRempli(plateau) ){
                        plateau = ajouteDeux(plateau);
                    }
                    scr_str           = to_string(scoreVariante(plateau));
                    scr_str           = "Score: " + scr_str;
                    scr               = scr_str.c_str();
                    score_txt         = create_text(renderer, (char*)scr, white);
                    grilleTextTexture = textFromPlateau(renderer, plateau, white, grilleTextTexture);
                    break;
                default:
                    break;
                }
                if (estGagnantVariante(plateau)){
                    return 3;
                } else if (estTermine(plateau)){
                    return 4;
                }
            }
        } else if (e.type == SDL_KEYUP){
            if (up == false){
                up = true;
            }
        }

        // Nettoie affichage avant dessin
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);

        int x = 0, y = 0;
        for (int i = 0; i < plateau_coord.size(); i ++){
            rect  = dessin_grille1[i];
            rect1 = dessin_grille2[i];
            SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
            SDL_RenderFillRect(renderer, &rect);

            // Couleur de la case en fonction du nombre dans la case
            switch (plateau[y][x])
            {
            case 0:
                SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
                break;
            case 2:
                SDL_SetRenderDrawColor(renderer,  52, 73, 94 , 255);
                break;
            case 4:
                SDL_SetRenderDrawColor(renderer,  149, 165, 166 , 255);
                break;
            case 8:
                SDL_SetRenderDrawColor(renderer,  211, 84, 0 , 255);
                break;
            case 16:
                SDL_SetRenderDrawColor(renderer,  243, 156, 18 , 255);
                break;
            case 32:
                SDL_SetRenderDrawColor(renderer,   241, 196, 15 , 255);
                break;
            case 64:
                SDL_SetRenderDrawColor(renderer,   39, 174, 96 , 255);
                break;
            case 128:
                SDL_SetRenderDrawColor(renderer,  22, 160, 133 , 255);
                break;
            default:
                SDL_SetRenderDrawColor(renderer,  192, 57, 43 , 255);
                break;
            }
            SDL_RenderFillRect(renderer, &rect1);

            rect_txt = {plateau_coord[i][0] + 20, plateau_coord[i][1] + 10, case_nbr_size - 40, case_nbr_size - 20};
            SDL_RenderCopy(renderer, grilleTextTexture[i], NULL, &rect_txt);

            x++;
            if (x > 2){
                x = 0;
                y++;
            }
        }
        SDL_RenderCopy(renderer, score_txt, NULL, &score_rect);
        
        currentTime = SDL_GetTicks();
        if (currentTime > lastTime + 10){
            chrono_ms += 1;
            if (chrono_ms >= 100){
                chrono_ms = 0;
                chrono_s += 1;
            }
            if (chrono_s >= 60){
                chrono_s = 0;
                chrono_min += 1;
            }
            str_chrono1 = to_string(chrono_ms);
            str_chrono2 = to_string(chrono_s);
            str_chrono3 = to_string(chrono_min);

            if (chrono_min < 10){
                str_chrono3 = "0" + str_chrono3;
            }
            if (chrono_s < 10){
                str_chrono3 = str_chrono3 + point2 + "0" + str_chrono2;
            } else {
                str_chrono3 = str_chrono3 + point2 + str_chrono2;
            }
            if (chrono_ms < 10){
                str_chrono3 = str_chrono3 + point + "0" + str_chrono1;
            } else {
                str_chrono3 = str_chrono3 + point + str_chrono1;
            }
            chrono_affiche = str_chrono3.c_str();
            chrono_txt = create_text(renderer, (char*)chrono_affiche, white);
            lastTime = currentTime;
        }
        SDL_RenderCopy(renderer, chrono_txt, NULL, &chrono_rect);

        SDL_RenderPresent(renderer);
    }
    SDL_DestroyTexture(score_txt);
    return 0;
}
/* ------ ------ ------ ------ ------ ------ ------ ------ ------ ------ ------ ------ ------ ------ ------  */
/* ------ ------ ------ ------ ------ - FIN FONCTION GAME ------- ------ ------ ------ ------ ------ ------  */
/* ------ ------ ------ ------ ------ ------ ------ ------ ------ ------ ------ ------ ------ ------ ------  */












/** --> Index de retour fonction et signification <--
 * 
 * 0 -> Quitter le jeu
 * 1 -> Aller au menu
 * 2 -> Lancer une partie (classique)
 * 3 -> Affiche victoire
 * 4 -> Affiche défaite
 */


int main(int argc, char const *argv[])
{
    srand(time(0));

    SDL_Window *window = NULL;
    SDL_Renderer *renderer = NULL;

    SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER);
    TTF_Init();
    window = SDL_CreateWindow("MA FENETRE", 100, 100, 1000, 600, SDL_WINDOW_SHOWN);
    if (window == NULL){
        cout << SDL_GetError() << endl;
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 0;
    }
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (renderer == NULL){
        cout << SDL_GetError() << endl;
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 0;
    }

    SDL_GetWindowSize(window, &width, &height);

    int place = 1; // Correspond à notre place dans le jeu
    
    while (place != 0){
        if (place == 1){
            place = menu(renderer);
        } else if (place == 2){
            place = game(renderer);
        } else if (place == 3) {
            place = victoire(renderer);
        } else if (place == 4) {
            place = defaite(renderer);
        } else if (place == 5){
            place = game_128(renderer);
        } else {
            place = 0;
        }
    }
    
    
    
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    TTF_Quit();
    SDL_Quit();
    return 0;
}
