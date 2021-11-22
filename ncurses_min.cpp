#include <iostream>
#include <vector>
#include "modele.h"
#include <ncurses.h>

using namespace std;

#define COLOR 1

void dessineCouleur(string plateau){
    start_color();

	init_pair(1, COLOR_BLUE, COLOR_BLACK);
	init_pair(2, COLOR_WHITE, COLOR_BLACK);

	for (int i = 0; i < plateau.size(); i++){
		int j = 1;
		if (plateau[i] == '*'){
			j = 2;
		}
		attron(COLOR_PAIR(j));
		printw("%c", plateau[i]);
		attroff(COLOR_PAIR(j));
	}
}
