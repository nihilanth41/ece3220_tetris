#ifndef __GAME_H
#define __GAME_H
#include "Grid.h"
#include "Shapes.h"
#include "Util.h"

class Game {
	public: 
		Grid *grid;
		Shape *shapes;
		void draw();
		void init_game();
}


#endif
