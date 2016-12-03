#ifndef __GAME_H
#define __GAME_H
#include "Grid.h"
#include "Shapes.h"
#include "Util.h"

class Game {
	public: 
		Game();
		Grid *g;
		// Draw grid to screen
		void Draw();
		// Setup RNG, Init Random Shape
		void init_game();
		// Vars for shape
		int shapeType;
		int shapeRotation;
		// Coordinates for shape
		int sX, sY;
};


#endif
