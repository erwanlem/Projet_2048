#include "modele.h"

using namespace std;

int WIDTH, HEIGHT;

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
    testDeplacementHaut();
    
    srand(time(0));

    SDL_Window *window = NULL;
    SDL_Renderer *renderer = NULL;

    SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER);
    TTF_Init();
    window = SDL_CreateWindow("2048", 100, 100, 1000, 600, SDL_WINDOW_SHOWN);
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

    SDL_GetWindowSize(window, &WIDTH, &HEIGHT);

    int place = 1; // Correspond à notre place dans le jeu
    
    while (place != 0){
        if (place == 1){
            place = menu(renderer);
        } else if (place == 2){
            place = game(renderer);
        } else if (place == 3) {
            place = victoire(renderer, 1);
        } else if (place == 4) {
            place = defaite(renderer, 1);
        } else if (place == 5){
            place = game_128(renderer);
        } else if (place == 6){
            place = victoire(renderer, 2);
        } else if (place == 7){
            place = defaite(renderer, 2);
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
