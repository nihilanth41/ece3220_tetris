#include <iostream> 
#include <cstdio>
#include <unistd.h>
#include <vector>
#include <termios.h>
#include "Game.h"

using namespace std;

int main(int argc, char **argv) {

	Game game;
	game.init_game();
	game.Draw();
	return 0;
}

