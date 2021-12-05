#include "modele.h"


/**
 * Affiche fenêtre de victoire
 * 
 * @param renderer la zone de rendu
 * @param game la partie jouée précédemment (-> personnalisation de l'affichage en fonction)
 * @return int le code de la prochaine fenêtre à afficher
 */
int victoire(SDL_Renderer * renderer, int game){
    SDL_Color white = {255, 255, 255};
    SDL_Color gold = {255, 215, 0};

    char victoire[] = "Vous avez gagné !";
    char play[]     = "Rejouer";
    char menu[]     = "Menu";
    char quit[]     = "Quitter";

    string mainStat = "Score: 0";
    string bestStat = "Meilleurs score: 0";
    int m, s, ms, t;
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
    SDL_Rect play_rect    = { (WIDTH/10)*7 - (pourcentage(10, WIDTH)/2) - 10, pourcentage(70, HEIGHT) - 5, pourcentage(10, WIDTH) + 20, pourcentage(8, HEIGHT) + 10};
    SDL_Rect play_rect_txt = { (WIDTH/10)*7 - (pourcentage(10, WIDTH)/2), pourcentage(70, HEIGHT), pourcentage(10, WIDTH), pourcentage(8, HEIGHT)};
    SDL_Texture * play_txt = create_text(renderer, play, white, 100);

    SDL_Rect menu_rect     = { (WIDTH/10)*5 - (pourcentage(10, WIDTH)/2) - 10, pourcentage(70, HEIGHT) - 5, pourcentage(10, WIDTH) + 20, pourcentage(8, HEIGHT) + 10};
    SDL_Rect menu_rect_txt = { (WIDTH/10)*5 - (pourcentage(10, WIDTH)/2), pourcentage(70, HEIGHT), pourcentage(10, WIDTH), pourcentage(8, HEIGHT)};
    SDL_Texture * menu_txt = create_text(renderer, menu, white, 100);

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
        } else if (e.type == SDL_MOUSEMOTION){
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

        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);

        SDL_SetRenderDrawColor(renderer, btn1_color.r, btn1_color.g, btn1_color.b, 255);
        SDL_RenderFillRect(renderer, &play_rect);
        SDL_SetRenderDrawColor(renderer, btn2_color.r, btn2_color.g, btn2_color.b, 255);
        SDL_RenderFillRect(renderer, &menu_rect);
        SDL_SetRenderDrawColor(renderer, btn3_color.r, btn3_color.g, btn3_color.b, 255);
        SDL_RenderFillRect(renderer, &quit_rect);

        SDL_RenderCopy(renderer, main_text_txt, NULL, &main_rect);
        SDL_RenderCopy(renderer, play_txt, NULL, &play_rect_txt);
        SDL_RenderCopy(renderer, menu_txt, NULL, &menu_rect_txt);
        SDL_RenderCopy(renderer, quit_txt, NULL, &quit_rect_txt);
        SDL_RenderCopy(renderer, stat_txt, NULL, &stat_rect_txt);
        SDL_RenderCopy(renderer, best_stat_txt, NULL, &best_stat_rect_txt);

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
int defaite(SDL_Renderer * renderer, int game){
    SDL_Color white = {255, 255, 255};
    SDL_Color red = {255, 0, 0};

    char victoire[] = "Game Over";
    char play[]     = "Rejouer";
    char menu[]     = "Menu";
    char quit[]     = "Quitter";

    // Message principal
    SDL_Texture * main_text_txt = create_text(renderer, victoire, red, 120);
    SDL_Rect main_rect = { (WIDTH/2) - (pourcentage(46, WIDTH)/2), (HEIGHT/3) - pourcentage(20, HEIGHT), pourcentage(46, WIDTH), pourcentage(20, HEIGHT)};


    // Boutons affichés à l'écran
    SDL_Rect play_rect     = { (WIDTH/10)*7 - (pourcentage(10, WIDTH)/2) - 10, pourcentage(70, HEIGHT) - 5, pourcentage(10, WIDTH) + 20, pourcentage(8, HEIGHT) + 10};
    SDL_Rect play_rect_txt = { (WIDTH/10)*7 - (pourcentage(10, WIDTH)/2), pourcentage(70, HEIGHT), pourcentage(10, WIDTH), pourcentage(8, HEIGHT)};
    SDL_Texture * play_txt = create_text(renderer, play, white, 100);

    SDL_Rect menu_rect     = { (WIDTH/10)*5 - (pourcentage(10, WIDTH)/2) - 10, pourcentage(70, HEIGHT) - 5, pourcentage(10, WIDTH) + 20, pourcentage(8, HEIGHT) + 10};
    SDL_Rect menu_rect_txt = { (WIDTH/10)*5 - (pourcentage(10, WIDTH)/2), pourcentage(70, HEIGHT), pourcentage(10, WIDTH), pourcentage(8, HEIGHT)};
    SDL_Texture * menu_txt = create_text(renderer, menu, white, 100);

    SDL_Rect quit_rect = { (WIDTH/10)*3 - (pourcentage(10, WIDTH)/2) - 10, pourcentage(70, HEIGHT) - 5, pourcentage(10, WIDTH) + 20, pourcentage(8, HEIGHT) + 10};
    SDL_Rect quit_rect_txt = { (WIDTH/10)*3 - (pourcentage(10, WIDTH)/2), pourcentage(70, HEIGHT), pourcentage(10, WIDTH), pourcentage(8, HEIGHT)};
    SDL_Texture * quit_txt = create_text(renderer, quit, white, 100);

    
    SDL_Rect stat_rect_txt;
    SDL_Texture * stat_txt;
    SDL_Rect best_stat_rect_txt;
    SDL_Texture * best_stat_txt;
    if (game == 1){
        string mainStat = "Score: 0";
        string bestStat = "Meilleurs score: 0";
        mainStat = "Score: " + to_string(transfertFichier(0, 0, 1)[0]);
        bestStat = "Record: " + to_string(transfertFichier(0, 0, 1)[2]);
        char const* mainStatChar = mainStat.c_str();
        char const* bestStatChar = bestStat.c_str();

        stat_rect_txt = { (WIDTH/2) - (pourcentage(26, WIDTH)/2), pourcentage(36, HEIGHT), pourcentage(26, WIDTH), pourcentage(12, HEIGHT)};
        stat_txt = create_text(renderer, (char*)mainStatChar, white, 100);

        best_stat_rect_txt = { (WIDTH/2) - (pourcentage(26, WIDTH)/2), pourcentage(50, HEIGHT), pourcentage(26, WIDTH), pourcentage(12, HEIGHT)};
        best_stat_txt = create_text(renderer, (char*)bestStatChar, white, 100);
    }




    SDL_Color button_default_color = {255, 0, 0};
    SDL_Color button_over_default_color = {160, 0, 0};
    SDL_Color btn1_color = button_default_color;
    SDL_Color btn2_color = button_default_color;
    SDL_Color btn3_color = button_default_color;

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
                if (game == 1){
                    return 2;
                } else {
                    return 5;
                }
                
            } 
        } else if (e.type == SDL_MOUSEMOTION){
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

        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);

        SDL_SetRenderDrawColor(renderer, btn1_color.r, btn1_color.g, btn1_color.b, 255);
        SDL_RenderFillRect(renderer, &play_rect);
        SDL_SetRenderDrawColor(renderer, btn2_color.r, btn2_color.g, btn2_color.b, 255);
        SDL_RenderFillRect(renderer, &menu_rect);
        SDL_SetRenderDrawColor(renderer, btn3_color.r, btn3_color.g, btn3_color.b, 255);
        SDL_RenderFillRect(renderer, &quit_rect);

        SDL_RenderCopy(renderer, main_text_txt, NULL, &main_rect);
        SDL_RenderCopy(renderer, play_txt, NULL, &play_rect_txt);
        SDL_RenderCopy(renderer, menu_txt, NULL, &menu_rect_txt);
        SDL_RenderCopy(renderer, quit_txt, NULL, &quit_rect_txt);
        if (game == 1){
            SDL_RenderCopy(renderer, stat_txt, NULL, &stat_rect_txt);
            SDL_RenderCopy(renderer, best_stat_txt, NULL, &best_stat_rect_txt);
        }

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
int menu(SDL_Renderer * renderer, SDL_Window * window){
    SDL_Color white = {255, 255, 255, 255};
    Uint32 last_time;
    Uint32 current_time;

    // Création des textures du texte
    char play_txt[] = "Le 2048";
    char var_txt[]  = "128 CHRONO !";
    char quit_txt[] = "QUITTER";

    SDL_Texture * texture_play = create_text(renderer, play_txt, white, 120);
    SDL_Texture * texture_var = create_text(renderer, var_txt, white, 100);
    SDL_Texture * texture_quit = create_text(renderer, quit_txt, white, 80);


    // Paramètres des emplacements des éléments du menu
    int button_w = pourcentage(40, WIDTH);
    int button_h = pourcentage(20, HEIGHT);
    SDL_Rect play_button = {WIDTH/2 - button_w/2, HEIGHT/8 * 3, button_w, button_h};
    SDL_Rect opt_button  = {WIDTH/2 - button_w/2, HEIGHT/8 * 5, button_w, button_h};
    SDL_Rect quit_button = {pourcentage(3, WIDTH), HEIGHT - pourcentage(12, HEIGHT), pourcentage(12, WIDTH), pourcentage(9, HEIGHT)};

    // Emplacement du texte
    SDL_Rect play_button_text = {WIDTH/2 - button_w/2 + ((play_button.w - (int)(button_w*0.7))/2), (HEIGHT/8 * 3 + (play_button.h - (int)(button_h*0.8))/2), (button_w*70)/100, (button_h*80)/100};
    SDL_Rect opt_button_text  = {WIDTH/2 - button_w/2 + ((opt_button.w - (int)(button_w*0.8))/2), (HEIGHT/8 * 5 + (opt_button.h - (int)(button_h*0.8))/2), (button_w*80)/100, (button_h*80)/100};
    SDL_Rect quit_button_text = {pourcentage(3, WIDTH) + ((quit_button.w - pourcentage(10, WIDTH))/2), ((HEIGHT - pourcentage(12, HEIGHT)) + (quit_button.h - pourcentage(6, HEIGHT))/2), pourcentage(10, WIDTH), pourcentage(6, HEIGHT)};
    
    // Paramètres du titre (2048) et chargement des coordonnées
    int taille_block = pourcentage(3.5, (WIDTH + HEIGHT) / 2);
    int pourcentage_x = pourcentage(25, WIDTH);
    vector<vector<int>> titre;
    titre = titre_menu(pourcentage_x, taille_block);
    int anim_color = -1;
    bool end_anim = true;
    vector<SDL_Color> couleurs_titre = {{0, 0, 0}, {255, 255, 255}, {255, 0, 0}, {128, 0, 0}, {255, 255, 0}, {128, 128, 0}, {0, 255, 0}, {0, 128, 0}, {0, 255, 255}, {0, 128, 128}, {0, 0, 255}, {0, 0, 128}, {255, 0, 255}, {128, 0, 128}};
    SDL_Color current_color = couleurs_titre[0];
    SDL_Color new_color = couleurs_titre[1];
    int current_color_index = 0;
    int new_color_index = 1;
    last_time = SDL_GetTicks() + 3000;

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
        if (e.type == SDL_WINDOWEVENT) {
            if (e.window.event == SDL_WINDOWEVENT_RESIZED){
                SDL_GetWindowSize(window, &WIDTH, &HEIGHT);
                return 1;
            }
        }

        // Actualise l'affichage
        // -> Réinitialise l'écran en noir avant de dessiner dessus
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);


        // Animation du titre toutes les secondes
        if (end_anim) {
            current_time = SDL_GetTicks();
            if (current_time - last_time > 4000){
                end_anim = false;
                last_time = current_time;
            }
        } else {
            current_time = SDL_GetTicks();
            if (current_time - last_time > 60){
                anim_color += 1;
                if (anim_color > 20){
                    if (current_color_index + 1 > couleurs_titre.size() -1){
                        current_color_index = 1;
                    } else {
                        current_color_index += 1;
                    }
                    if (new_color_index + 1 > couleurs_titre.size() -1){
                        new_color_index = 1;
                    } else {
                        new_color_index += 1;
                    }
                    current_color = couleurs_titre[current_color_index];
                    new_color = couleurs_titre[new_color_index];
                    anim_color = -1;
                    end_anim = true;
                }
                last_time = current_time;
            }
        }

        // Dessine tous les cubes du titre
        for (int i = 0; i < titre.size(); i ++){
            SDL_Rect rect = {titre[i][0], titre[i][1], taille_block, taille_block};
            if (rect.x <= pourcentage_x + (anim_color * taille_block)){
                SDL_SetRenderDrawColor(renderer, new_color.r, new_color.g, new_color.b, 255);
            } else {
                SDL_SetRenderDrawColor(renderer, current_color.r, current_color.g, current_color.b, 255);
            }
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
    Partie plateau;
    plateau = plateauInitial();
    Plateau lastPlateau;

    // Définition couleur(s)
    SDL_Color white = {255, 255, 255};

    // Taille des cases de la grille
    int case_nbr_size = pourcentage(20, HEIGHT);

    // Calcul des marges sur les côtés de la grille
    int margin_lr = (WIDTH - (pourcentage(20, HEIGHT) * 4))/2;
    int margin_tb = (HEIGHT - (pourcentage(20, HEIGHT) * 4))/2;

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
    grilleTextTexture = textFromPlateau(renderer, plateau.plateau, white, grilleTextTexture);


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
    SDL_Rect score_rect     = {pourcentage(2, WIDTH), pourcentage(4, HEIGHT), pourcentage(10, WIDTH), pourcentage(6, HEIGHT)};

    

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
            if (up != false) {
                lastPlateau = plateau.plateau;
                switch (e.key.keysym.scancode)
                {
                case 41:
                    SDL_DestroyTexture(score_txt);
                    return 1;
                    break;
                case 79:
                    plateau.plateau = deplacement(plateau.plateau, DROITE);
                    up = false;
                    if ( !estRempli(plateau.plateau) && lastPlateau != plateau.plateau ){
                        plateau = ajouteDeuxOuQuatre(plateau);
                    }
                    scr_str           = to_string(score(plateau));
                    scr_str           = "Score: " + scr_str;
                    scr               = scr_str.c_str();
                    score_txt         = create_text(renderer, (char*)scr, white);
                    grilleTextTexture = textFromPlateau(renderer, plateau.plateau, white, grilleTextTexture);
                    if (score(plateau) >= 1000){
                        score_rect.w = pourcentage(14, WIDTH);
                    }
                    break;
                case 80:
                    plateau.plateau = deplacement(plateau.plateau, GAUCHE);
                    up = false;
                    if ( !estRempli(plateau.plateau) && lastPlateau != plateau.plateau ){
                        plateau = ajouteDeuxOuQuatre(plateau);
                    }
                    scr_str           = to_string(score(plateau));
                    scr_str           = "Score: " + scr_str;
                    scr               = scr_str.c_str();
                    score_txt         = create_text(renderer, (char*)scr, white);
                    grilleTextTexture = textFromPlateau(renderer, plateau.plateau, white, grilleTextTexture);
                    if (score(plateau) >= 1000){
                        score_rect.w = pourcentage(14, WIDTH);
                    }
                    break;
                case 81:
                    plateau.plateau = deplacement(plateau.plateau, BAS);
                    up = false;
                    if ( !estRempli(plateau.plateau) && lastPlateau != plateau.plateau ){
                        plateau = ajouteDeuxOuQuatre(plateau);
                    }
                    scr_str           = to_string(score(plateau));
                    scr_str           = "Score: " + scr_str;
                    scr               = scr_str.c_str();
                    score_txt         = create_text(renderer, (char*)scr, white);
                    grilleTextTexture = textFromPlateau(renderer, plateau.plateau, white, grilleTextTexture);
                    if (score(plateau) >= 1000){
                        score_rect.w = pourcentage(14, WIDTH);
                    }
                    break;
                case 82:
                    plateau.plateau = deplacement(plateau.plateau, HAUT);
                    up = false;
                    if ( !estRempli(plateau.plateau) && lastPlateau != plateau.plateau ){
                        plateau = ajouteDeuxOuQuatre(plateau);
                    }
                    scr_str           = to_string(score(plateau));
                    scr_str           = "Score: " + scr_str;
                    scr               = scr_str.c_str();
                    score_txt         = create_text(renderer, (char*)scr, white);
                    grilleTextTexture = textFromPlateau(renderer, plateau.plateau, white, grilleTextTexture);
                    if (score(plateau) >= 1000){
                        score_rect.w = pourcentage(14, WIDTH);
                    }
                    break;
                default:
                    break;
                }
                if (estGagnant(plateau.plateau)){
                    int best_score = transfertFichier(0, 0, 1)[2];
                    if (score(plateau) > best_score){
                        transfertFichier(0, score(plateau), 2);
                        transfertFichier(2, score(plateau), 2);
                    } else {
                        transfertFichier(0, score(plateau), 2);
                    }
                    return 3;
                } else if (estTermine(plateau.plateau)){
                    int best_score = transfertFichier(0, 0, 1)[2];
                    if (score(plateau) > best_score){
                        transfertFichier(0, score(plateau), 2);
                        transfertFichier(2, score(plateau), 2);
                    } else {
                        transfertFichier(0, score(plateau), 2);
                    }
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
            switch (plateau.plateau[y][x])
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
    Plateau lastPlateau;
    plateau = plateauInitialVariante();

    // Définition couleur(s)
    SDL_Color white = {255, 255, 255};

    // Taille des cases de la grille
    int case_nbr_size = pourcentage(20, HEIGHT);

    // Calcul des marges sur les côtés de la grille
    int margin_lr = (WIDTH - (pourcentage(20, HEIGHT) * 3))/2;
    int margin_tb = (HEIGHT - (pourcentage(20, HEIGHT) * 3))/2;

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


    // CHRONO
    string str_chrono1;
    string str_chrono2;
    string str_chrono3;
    char const * chrono_affiche;
    string point = ".";
    string point2 = ":";
    SDL_Rect chrono_rect = {pourcentage(4, WIDTH), pourcentage(8, HEIGHT), pourcentage(22, WIDTH), pourcentage(8, HEIGHT)};
    char t[] = "Temps: 00:00.00";
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

    bool play = false;
    
    /* -- -- -- -- -- -- -- -- -- -- -- -- -- */
    /*            BOUCLE EVENEMENTS           */

    bool game = true;
    SDL_Event e;
    while (game){
        SDL_PollEvent(&e);
        if (e.type == SDL_QUIT){
            game = false;
        } else if (e.type == SDL_KEYDOWN){
            if (up != false){
                play = true;
                lastPlateau = plateau;
                switch (e.key.keysym.scancode)
                {
                case 41:
                    return 1;
                    break;
                case 79:
                    plateau = deplacement(plateau, DROITE);
                    
                    up = false;
                    if ( !estRempli(plateau) && lastPlateau != plateau ){
                        plateau = ajouteDeux(plateau);
                    }
                    grilleTextTexture = textFromPlateau(renderer, plateau, white, grilleTextTexture);
                    break;
                case 80:
                    plateau = deplacement(plateau, GAUCHE);
                    up = false;
                    if ( !estRempli(plateau) && lastPlateau != plateau ){
                        plateau = ajouteDeux(plateau);
                    }
                    grilleTextTexture = textFromPlateau(renderer, plateau, white, grilleTextTexture);
                    break;
                case 81:
                    plateau = deplacement(plateau, BAS);
                    up = false;
                    if ( !estRempli(plateau) && lastPlateau != plateau ){
                        plateau = ajouteDeux(plateau);
                    }
                    grilleTextTexture = textFromPlateau(renderer, plateau, white, grilleTextTexture);
                    break;
                case 82:
                    plateau = deplacement(plateau, HAUT);
                    up = false;
                    if ( !estRempli(plateau) && lastPlateau != plateau ){
                        plateau = ajouteDeux(plateau);
                    }
                    grilleTextTexture = textFromPlateau(renderer, plateau, white, grilleTextTexture);
                    break;
                default:
                    break;
                }
                if (estGagnantVariante(plateau)){
                    int best_time = transfertFichier(0, 0, 1)[3];
                    if ( chrono_ms + (100 * chrono_s) + (6000 * chrono_min) < best_time || best_time == 0) {
                        transfertFichier(3, chrono_ms + (100 * chrono_s) + (6000 * chrono_min), 2);
                        transfertFichier(1, chrono_ms + (100 * chrono_s) + (6000 * chrono_min), 2);
                    } else {
                        transfertFichier(1, chrono_ms + (100 * chrono_s) + (6000 * chrono_min), 2);
                    }
                    return 6;
                } else if (estTermine(plateau)){
                    return 7;
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
        
        if (play){
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
                str_chrono3 = "Temps: " + str_chrono3;
                chrono_affiche = str_chrono3.c_str();
                chrono_txt = create_text(renderer, (char*)chrono_affiche, white);
                lastTime = currentTime;
            }
        }

        SDL_RenderCopy(renderer, chrono_txt, NULL, &chrono_rect);

        SDL_RenderPresent(renderer);
    }
    return 0;
}
/* ------ ------ ------ ------ ------ ------ ------ ------ ------ ------ ------ ------ ------ ------ ------  */
/* ------ ------ ------ ------ ------ FIN FONCTION GAME_128 ----- ------ ------ ------ ------ ------ ------  */
/* ------ ------ ------ ------ ------ ------ ------ ------ ------ ------ ------ ------ ------ ------ ------  */
