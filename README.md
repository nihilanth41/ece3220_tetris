# Tetris

## Links
Non-blocking IO
http://www.flipcode.com/archives/_kbhit_for_Linux.shtml   

Disable echo to stdout
https://www.gnu.org/savannah-checkouts/gnu/libc/manual/html_node/getpass.html

Rotation systems:  
http://tetris.wikia.com/wiki/Nintendo_Rotation_System   
http://tetris.wikia.com/wiki/SRS  

Examples:  
http://javilop.com/gamedev/tetris-tutorial-in-c-platform-independent-focused-in-game-logic-for-beginners/

## Class design

* Shapes
	- mShapes vector^4 
	- Stores piece, rotation, y, x

* Grid	
	- mGrid vector^2 
	- Stores the grid that will be drawn on screen 
	** Member functions:
		- Grid::Grid() 
			- Initialize grid to 0
			- 
		- void Grid::StoreShape(int x, int y, int piece, int rot)
			- Store each piece of the shape on the grid

		- bool Grid::CanMove(int x, int y, int piece, int rot) 
			- Similar looping construct as StoreShape 
			- Given the x and y position parameters, check if the current shape can be stored in that position. 
* Game
	- (Pointers?):
		- Grid grid
		- Shape shapes;
	- void Game::Draw(void);
	- void Game::InitGame(void);
		 
	
