#include <iostream> 
#include <cstdio>
#include <unistd.h>
#include <vector>
#include <termios.h>
#include "Game.h"

using namespace std;

int main(int argc, char **argv) {

	Game game;
	Grid grid;
	grid.AddShape(1, 1, 4, 18);
	// Give game a grid to work with
	game.g = &grid;

	// Get random shape
	game.init_game();

	game.Draw();
	return 0;
}

