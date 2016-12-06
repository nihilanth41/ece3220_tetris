#include <iostream> 
#include <cstdio>
#include <unistd.h>
#include <vector>
#include <termios.h>
#include "Game.h"

using namespace std;

void selectionHandler(int selection);

int main(int argc, char **argv) {
	FILE* highscores;
	vector<int> scores;
	int temp;	

	// Initialize Game object 
	Game game;
	game.mainMenu();
	cin>>game.selection;
	

	if(game.selection == 1){
	
	// Get random shape
	game.init_game();
	
	// Initialize a Grid
	// Add the shape to the Grid
	Grid grid;
	grid.addShape(game.shapeType, game.shapeRotation, game.sX, game.sY);

	// Give game a grid to work with
	game.g = &grid;

	while(game.sY > -1)
	{
		// Disable keyboard echo
		game.disableEcho();
		// Draw screen
		game.Draw();
		// Decrement y value (if possible)
		game.sY -= 1;
		// Need some kind of isMovementPossible(), maybe inside the MoveShape() method.
		// Translate shape according to user input and/or sleep.
		for(int i=0; i<5; i++)
		{
			grid.moveShape(game.shapeType, game.shapeRotation, game.sX, game.sY);
			if( _kbhit() )
			{
				// Get user input
				char c;  
				scanf(" %c" , &c);
				switch(c)
				{
					case 'j': {
							  //left
							  if(grid.isMovementPossible(game.shapeType, game.shapeRotation, game.sX-1, game.sY)) { 
							  // maybe instead of clearing the old position we just clear the entire grid and redraw?
							  	game.sX -= 1;
							  	grid.moveShape(game.shapeType, game.shapeRotation, game.sX, game.sY);
							  	game.Draw();
							  }
							  break;
						  }
					case 'k': {
							  //right
							  if(grid.isMovementPossible(game.shapeType, game.shapeRotation, game.sX+1, game.sY)) { 
							  game.sX += 1;
							  grid.moveShape(game.shapeType, game.shapeRotation, game.sX, game.sY);
							  game.Draw();
							  }
							  break;
						  }
					case 'l': {
							  int newRotation;
							  if(game.shapeRotation == 3)
							  {
								  newRotation = 0;
							
							  } 
							  else {
								  newRotation = game.shapeRotation+1;
							  }
							  //rotate
							  if(grid.isMovementPossible(game.shapeType, newRotation, game.sX, game.sY)) { 
								  game.shapeRotation = newRotation;
								grid.moveShape(game.shapeType, game.shapeRotation, game.sX, game.sY);
								game.Draw();

							  }
							  break;
						  }
					case 'q':
					case 'Q': {
							  // Clear screen
							  // From http://stackoverflow.com/a/7660837
							  printf("\e[1;1H\e[2J");
							  // Restore terminal
							  game.restoreEcho();
							  exit(0);
						  }
					default: break;
				}
			}
			// 200ms * 5 = 1 sec
			usleep(200000);
		}
	}
}

game.restoreEcho();
	
	if(game.selection == 2){
		highscores = fopen("HighScores.txt", "r");
		if(highscores == NULL){
			cout<<"Error viewing highscores"<<endl;
			return -1;
		}
		
		for(int i = 0; i<5; i++){
			fscanf(highscores, "%d", &temp);
			cout<<temp<<endl;

		}

		fclose(highscores);
		
	}

	if(game.selection == 3){


	}
	if(game.selection == 4){

		cout<<"Terminating Game..."<<endl<<endl;
		return 0;

	}



	return 0;
} 












