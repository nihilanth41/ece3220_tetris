#include <iostream> 
#include <cstdio>
#include <unistd.h>
#include <vector>
#include <termios.h>
#include "Game.h"

using namespace std;

int main(int argc, char **argv) {
	
	// Initialize Game object 
	Game game;
	// Get random shape
	game.init_game();

	// Initialize a Grid
	// Add the shape to the Grid
	Grid grid;
	grid.AddShape(game.shapeType, game.shapeRotation, game.sX, game.sY);

	// Give game a grid to work with
	game.g = &grid;



	game.Draw();
	return 0;
}

