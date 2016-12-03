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

	while(game.sY > 0)
	{
		game.Draw();
		game.sY -= 1;
		// Need some kind of isMovementPossible(), maybe inside the MoveShape() method.
		grid.MoveShape(game.shapeType, game.shapeRotation, game.sX, game.sY, game.sX, game.sY-1);
		sleep(1);
	}

	return 0;
}

