#include <curses.h>


void dessineCouleur(string plateau){
    initscr();
    start_color();
    init_pair(1, COLOR_RED, COLOR_BLACK);
    attron(COLOR_PAIR(1));
    printw(plateau);
    attoff(COLOR_PAIR(1));
    endwin();
}


int main() {
    int c;
    initscr();
    keypad(stdscr, true);
    printw("Bonjour!\nIl est temps de presser quelques touches au clavier...\n");
    do {
        c = getch();
        addch(c);
    } while (c != KEY_UP);
    endwin();
    return 0;
}