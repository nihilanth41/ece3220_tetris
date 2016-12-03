#ifndef __GAME_H
#define __GAME_H
#include "Grid.h"
#include "Shapes.h"
#include "Util.h"

class Game {
	public: 
		Game();
		Grid grid;
		Shapes shapes;
		void Draw();
		void init_game();
	private:
		// Vars for shape
		int shapeType;
		int shapeRotation;
		// Shape coordinates
		int sX, sY;
};


#endif
