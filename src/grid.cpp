#include "grid.h"
#include "tetromino.h"

Grid::Grid() {
	// Initialize to 0
	for(int j=grid_height; j--;)
	{
		for(int i=0; i<grid_width; i++)
		{
			grid[j][i]=0;
		}
	}
}

Grid::~Grid() {
};

void Grid::print(void) {
	// Iterate backwards i.e. top to bottom
	for(int j=grid_height; j--;)
	{

		printf("[");
		// Iterate forwards i.e. left to right
		for(int i=0; i<grid_width; i++)
		{
			{

				//if(grid1[j][i] == 1)
			//		printf(ANSI_COLOR_CYAN " %d " ANSI_COLOR_RESET, grid1[j][i]);
			//	else
					printf(" %d ", grid[j][i]);
			}
		}
		printf("]\n");
	}
	// Go up 
	printf("\033[20A");

}

void Grid::addTetromino(Tetromino *t) 
{
	curr_tetromino = t;
	// Index of the top left corner xpos
	curr_tetromino->xpos = 3 
	// Index of top left corner ypos
	curr_tetromino->ypos = grid_height;
	// Iterate the tetromino bounding square
	// Place each element into the position on the top center Grid
	for(int j=curr_tetromino->bound_height; j--;)
	{
		for(int i=0; i<curr_tetromino->bound_width; i++)
		{
			
			grid[curr_tetromino->ypos][curr_tetromino->xpos] = curr_tetromino->square[j][i];
		}
	}
}
