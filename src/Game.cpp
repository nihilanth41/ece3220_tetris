#include "Game.h"
#include <cstdio>
#include <cstdlib>
#include <time.h>
#include <iostream>

using namespace std;

Game::Game() {
}

void Game::init_game(void) { 
	// Setup RNG
	srand(time(NULL));
	// Get random shape
	// Random number from 0-6
	shapeType = rand() % 7;
	
// Get random rotation
	shapeRotation = rand() % 4;
	
	// Set initial position of shape
	sX = 4;
	sY = 18;
}

void Game::Draw(void) {
	for(int j=20; j--;)
	{
		cout << "[";
		for(int i=0; i<10; i++)
		{

			cout << " " << g->mGrid[i][j] << " ";
		}
		cout << "]" << endl;
	}
	printf("\033[20A");
}



