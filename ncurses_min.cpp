#include <iostream>
#include <vector>
#include "modele.h"
#include <ncurses.h>

using namespace std;

#define COLOR 1

void dessineCouleur(string plateau){
    start_color();

	/*init_color(1, 250, 0, 0);
	init_color(2, 0, 250, 0);
	init_color(3, 0, 0, 250);
	init_color(4, 250, 250, 0);
	init_color(5, 0, 250, 250);
	init_color(6, 250, 0, 250);
	init_color(7, 500, 0, 0);
	init_color(8, 0, 500, 0);
	init_color(9, 0, 0, 500);
	init_color(10, 500, 500, 0);
	init_color(11, 500, 0, 500);
	init_color(12, 0, 500, 500);
	init_color(13, 1000, 0, 1000);
	init_color(14, 1000, 1000, 0);
	init_color(15, 0, 1000, 0);
	init_color(16, 0, 0, 1000);
	init_color(17, 1000, 0, 0);
	init_color(18, 0, 1000, 1000);
*/
	init_pair(2, COLOR_WHITE, COLOR_BLACK);

	int couleur = 1;
	for (int i = 0; i < plateau.size(); i++){
		int j = 1;
		if (plateau[i] == '*'){
			j = 2;
		} else {
			init_pair(1, COLOR_BLUE, COLOR_BLACK);
		}
		attron(COLOR_PAIR(j));
		printw("%c", plateau[i]);
		attroff(COLOR_PAIR(j));
	}
}
