#include "Game.h"
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <time.h>
#include <iostream>
#include "Colors.h"
using namespace std;

Game::Game() {
}

void Game::init_game(void) { 
	// Setup RNG
	srand(time(NULL));
	// Get random shape
	shapeType = rand() % 7;
	// Get random rotation
	shapeRotation = rand() % 4;
	// Set initial position of shape
	sX = 4;
	sY = 14;
}

void Game::Draw(void) {
	for(int j=20; j--;)
	{
		cout << "[";
		for(int i=0; i<10; i++)
		{
			char buf[64];
			if(g->mGrid[i][j] == 1){
				sprintf(buf, "%s %d %s", ANSI_COLOR_YELLOW, g->mGrid[i][j], ANSI_COLOR_RESET);
				cout<<buf;
			}
			else if(g->mGrid[i][j] == 2){
				sprintf(buf, "%s %d %s", ANSI_COLOR_CYAN, g->mGrid[i][j], ANSI_COLOR_RESET);
				cout<<buf;
			}
			else if(g->mGrid[i][j] == 3){
				sprintf(buf, "%s %d %s", "\033[48:2:255:165:0m", g->mGrid[i][j], "\033[m");
				cout<<buf;
			}
			else if(g->mGrid[i][j] == 4){
				sprintf(buf, "%s %d %s",ANSI_COLOR_BLUE, g->mGrid[i][j], ANSI_COLOR_RESET);
				cout<<buf;
			}
			else if(g->mGrid[i][j] == 5){
				sprintf(buf, "%s %d %s", ANSI_COLOR_RED, g->mGrid[i][j], ANSI_COLOR_RESET);
				cout<<buf;
			}
			else if(g->mGrid[i][j] == 6){
				sprintf(buf, "%s %d %s", ANSI_COLOR_GREEN, g->mGrid[i][j], ANSI_COLOR_RESET);
				cout<<buf;
			}	
			else if(g->mGrid[i][j] == 7){
				sprintf(buf, "%s %d %s", ANSI_COLOR_MAGENTA, g->mGrid[i][j], ANSI_COLOR_RESET);
				cout<<buf;
			}
			else if(g->mGrid[i][j] == 0){
				cout<<" "<<g->mGrid[i][j]<<" ";
			}
	
			

			
		}
		cout << "]" << endl;
	}
	printf("\033[20A");
}



