#include "modele.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <iostream>
#include <vector>
#include <string>

/**
 * @brief renvoie une valeur correspondant au poucentage d'une valeur donnée
 * 
 * @param p un entier, pourcentage désiré 
 * @param size un entier, l'élément dont on veut p%
 * @return int p% de size
 **/
int pourcentage(int p, int size){
    return (int)(p * size / 100);
}


/**
 * @brief verifie si (x, y) est sur le rectangle
 * 
 * @param btn le rectangle
 * @param x un entier, la position x
 * @param y un entier, la position y
 * @return true si (x, y) est sur le rectangle
 * @return false si (x, y) n'est pas sur le rectangle
 */
bool touche_bouton(SDL_Rect btn, int x, int y){
    if (x >= btn.x && x <= (btn.x + btn.w) && y >= btn.y && y <= (btn.y + btn.h)){
        return true;
    } else {
        return false;
    }
}



/**
 * Créer une texture d'un texte
 * 
 * @param renderer la zone de rendu
 * @param text le texte à afficher
 * @param color couleur du texte
 * @param font_size taille du texte (plus élevée = meilleurs qualité)
 * @return SDL_Texture* la texture finale
 */
SDL_Texture * create_text(SDL_Renderer * renderer, char * text, SDL_Color color, int font_size){
    TTF_Font * font = NULL;
    font = TTF_OpenFont("Roboto-Bold.ttf", font_size);
    SDL_Surface * surface = TTF_RenderUTF8_Blended(font, text, color);
    SDL_Texture * texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);
    TTF_CloseFont(font);

    return texture;
}



SDL_Texture * genere_cube(SDL_Renderer * renderer){
    int cube = rand()%3;
    SDL_Color deux = {52, 73, 94};
    SDL_Color quatre = {149, 165, 166};
    SDL_Color huit = {211, 84, 0};
    SDL_Texture * texture;
    char nbr2[] = "2";
    char nbr4[] = "4";
    char nbr8[] = "8";
    switch (cube)
    {
    case 0:
        texture = create_text(renderer, nbr2, deux);
        break;
    case 1:
        texture = create_text(renderer, nbr4, quatre);
        break;
    case 2:
        texture = create_text(renderer, nbr8, huit);
        break;
    default:
        texture = create_text(renderer, nbr8, huit);
        break;
    }
    return texture;
}





/** Génère le tableau contenant les coordonnées des cubes du titre
 * @param pourcentage_x un entier correspondant à la marge à gauche
 * @param taille_block une entier donnant la taille des cubes
 * @return le vecteur contenant les blocks
**/
vector<vector<int>> titre_menu(int pourcentage_x, int taille_block){

    vector<vector<int>> titre = {
        {pourcentage_x, 7 * taille_block},
        {pourcentage_x + taille_block, 7 * taille_block},
        {pourcentage_x + (2*taille_block), 7 * taille_block},
        {pourcentage_x + (3*taille_block), 7 * taille_block},
        {pourcentage_x, 6 * taille_block},
        {pourcentage_x + taille_block , 5 * taille_block},
        {pourcentage_x + (2*taille_block), 4 * taille_block},
        {pourcentage_x + (3*taille_block), 3 * taille_block},
        {pourcentage_x + (2*taille_block), 2 * taille_block},
        {pourcentage_x + taille_block, 2 * taille_block},
        {pourcentage_x, 3 * taille_block},

        {pourcentage_x + (6 * taille_block), 7 * taille_block},
        {pourcentage_x + (7 * taille_block), 7 * taille_block},
        {pourcentage_x + (8 * taille_block), 7 * taille_block},
        {pourcentage_x + (5 * taille_block), 6 * taille_block},
        {pourcentage_x + (5 * taille_block), 5 * taille_block},
        {pourcentage_x + (5 * taille_block), 4 * taille_block},
        {pourcentage_x + (5 * taille_block), 3 * taille_block},
        {pourcentage_x + (9 * taille_block), 6 * taille_block},
        {pourcentage_x + (9 * taille_block), 5 * taille_block},
        {pourcentage_x + (9 * taille_block), 4 * taille_block},
        {pourcentage_x + (9 * taille_block), 3 * taille_block},
        {pourcentage_x + (6 * taille_block), 2 * taille_block},
        {pourcentage_x + (7 * taille_block), 2 * taille_block},
        {pourcentage_x + (8 * taille_block), 2 * taille_block},

        {pourcentage_x + (13 * taille_block), 7 * taille_block},
        {pourcentage_x + (13 * taille_block), 6 * taille_block},
        {pourcentage_x + (13 * taille_block), 4 * taille_block},
        {pourcentage_x + (14 * taille_block), 5 * taille_block},
        {pourcentage_x + (13 * taille_block), 5 * taille_block},
        {pourcentage_x + (12 * taille_block), 5 * taille_block},
        {pourcentage_x + (11 * taille_block), 5 * taille_block},
        {pourcentage_x + (11 * taille_block), 4 * taille_block},
        {pourcentage_x + (11 * taille_block), 3 * taille_block},
        {pourcentage_x + (11 * taille_block), 2 * taille_block},

        {pourcentage_x + (17 * taille_block), 7 * taille_block},
        {pourcentage_x + (18 * taille_block), 7 * taille_block},
        {pourcentage_x + (19 * taille_block), 7 * taille_block},
        {pourcentage_x + (16 * taille_block), 6 * taille_block},
        {pourcentage_x + (16 * taille_block), 5 * taille_block + taille_block/2},
        {pourcentage_x + (16 * taille_block), 4 * taille_block - taille_block/2},
        {pourcentage_x + (16 * taille_block), 3 * taille_block},
        {pourcentage_x + (20 * taille_block), 6 * taille_block},
        {pourcentage_x + (20 * taille_block), 5 * taille_block + taille_block/2},
        {pourcentage_x + (20 * taille_block), 4 * taille_block - taille_block/2},
        {pourcentage_x + (20 * taille_block), 3 * taille_block},
        {pourcentage_x + (17 * taille_block), 2 * taille_block},
        {pourcentage_x + (18 * taille_block), 2 * taille_block},
        {pourcentage_x + (19 * taille_block), 2 * taille_block},
        {pourcentage_x + (17 * taille_block), 4 * taille_block + taille_block/2},
        {pourcentage_x + (18 * taille_block), 4 * taille_block + taille_block/2},
        {pourcentage_x + (19 * taille_block), 4 * taille_block + taille_block/2}
  
    };
    return titre;
}





/**
 * @brief transforme le vecteur plateau en un vecteur de textures à afficher à l'écran
 * 
 * @param renderer la zone de rendu
 * @param plateau le plateau de jeu
 * @param color la coulleur du texte à l'écran
 * @param textureTextTable le tableau contenant les textures (à modifier)
 * @return vector<SDL_Texture*> le tableau de textures modifié
 */
vector<SDL_Texture*> textFromPlateau(SDL_Renderer * renderer, Plateau plateau, SDL_Color color, vector<SDL_Texture*> textureTextTable){
    int x = 0, y = 0;
    string plt_str;
    SDL_Color black = {0, 0, 0};
    SDL_Texture * number_case;
    for (int i = 0; i < textureTextTable.size(); i ++){
        plt_str = to_string(plateau[y][x]);
        char const * txt_nbr = plt_str.c_str();
        if (plateau[y][x] == 0){
            textureTextTable[i] = create_text(renderer, (char*)txt_nbr, black);
        } else {
            textureTextTable[i] = create_text(renderer, (char*)txt_nbr, color);
        }
        x++;
        if (x > plateau.size() - 1){
            x = 0;
            y++;
        }
    }
    return textureTextTable;
}