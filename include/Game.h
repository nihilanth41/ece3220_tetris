#ifndef __GAME_H
#define __GAME_H
#include "Grid.h"
#include "Shapes.h"
#include "Util.h"

class Game {
	public: 
		Game();
		Grid *g;
		// Main loop
		void Play();
		// Draw grid to screen
		void Draw();
		// Setup RNG, Init Random Shape
		void init_game();
		// Vars for shape
		int shapeType;
		int shapeRotation;
		// Coordinates for shape
		int sX, sY;
		void mainMenu();
		//user selection from main menu
		int selection;

		//Stores score value
		int score;
		// For keyboard echo in terminal
		void disableEcho();
		void restoreEcho();
	private:
		// For disabling keyboard echo
		struct termios old_term, new_term;
		int nread;

				
};


#endif
