#ifndef __GAME_H
#define __GAME_H
#include "Grid.h"
#include "Shapes.h"
#include "Util.h"

class Game {
	public: 
		Game();
		Grid *g;
		void Draw();
		void init_game();
		// Vars for shape
		int shapeType;
		int shapeRotation;
		// Shape coordinates
		int sX, sY;
};


#endif
