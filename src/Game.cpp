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
				sprintf(buf, "%s %d %s", ANSI_COLOR_WHITE, g->mGrid[i][j], ANSI_COLOR_RESET);
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
				cout << "   "; 
			}
		}
		cout << "]" << endl;
	}
	printf("\033[20A");
}

void Game::mainMenu() {
	cout<<"Main Menu"<<endl<<"Select one of the following:"<<endl;
	cout<<"1 Play Game"<<endl;
	cout<<"2 High Score"<<endl;
	cout<<"3 Settings"<<endl;
	cout<<"4 Quit"<<endl;
}

void Game::disableEcho(void) {
	/* Turn echoing off and fail silently if we can’t. */
	tcgetattr(fileno (stdin), &old_term);
	new_term = old_term;
	new_term.c_lflag &= ~ECHO;
	tcsetattr (fileno (stdin), TCSAFLUSH, &new_term);
}

void Game::restoreEcho(void) {
	// Restore terminal
	(void) tcsetattr (fileno (stdin), TCSAFLUSH, &old_term);
}

void Game::Play(void) {
while(1) {
	// Get random shape
	init_game();
	
	// Initialize a Grid
	// Add the shape to the Grid
	Grid grid;
	grid.addShape(shapeType, shapeRotation, sX, sY);

	// Give game a grid to work with
	g = &grid;

	// Disable keyboard echo
	//disableEcho();
	while(sY > -1)
	{
		// Draw screen
		Draw();
		// Decrement y value (if possible)
		sY -= 1;
		// Need some kind of isMovementPossible(), maybe inside the MoveShape() method.
		// Translate shape according to user input and/or sleep.
		for(int i=0; i<5; i++)
		{
			grid.moveShape(shapeType, shapeRotation, sX, sY);
			if( _kbhit() )
			{
				// Get user input
				char c;  
				scanf(" %c" , &c);
				switch(c)
				{
					case 'j': {
							  //left
							  if(grid.isMovementPossible(shapeType, shapeRotation, sX-1, sY)) { 
							  // maybe instead of clearing the old position we just clear the entire grid and redraw?
							  	sX -= 1;
							  	grid.moveShape(shapeType, shapeRotation, sX, sY);
							  	Draw();
							  }
							  break;
						  }
					case 'k': {
							  //right
							  if(grid.isMovementPossible(shapeType, shapeRotation, sX+1, sY)) { 
								sX += 1;
								grid.moveShape(shapeType, shapeRotation, sX, sY);
								Draw();
							  }
							  break;
						  }
					case 'l': {
							  int newRotation;
							  if(shapeRotation == 3)
							  {
								  newRotation = 0;
							
							  } 
							  else {
								  newRotation = shapeRotation+1;
							  }
							  //rotate
							  if(grid.isMovementPossible(shapeType, newRotation, sX, sY)) { 
								shapeRotation = newRotation;
								grid.moveShape(shapeType, shapeRotation, sX, sY);
								Draw();
							  }
							  break;
						  }
					case 'q':
					case 'Q': {
							  // Clear screen
							  // From http://stackoverflow.com/a/7660837
							  printf("\e[1;1H\e[2J");
							  // Restore terminal
							  //restoreEcho();
							  exit(0);
						  }
					default: break;
				}
			}
			// 200ms * 5 = 1 sec
			usleep(100000);
		}

	}
	//restoreEcho();
	} 
}
