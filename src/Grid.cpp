#include "Grid.h"
#include "Shapes.h"

Grid::Grid() {
	// Initalize Grid to 0
	mGrid.resize(GRID_WIDTH, vector<int>(GRID_HEIGHT, 0));
}

void Grid::addShape(int type, int rotation, int x, int y) {
	int i1, i2;
	int j1, j2;
	// 
	for(i1=x, i2=0; i1<x+5; i1++, i2++)
	{
		for(j1=y, j2=0; j1 < y+5; j1++, j2++)
		{
			if(shapes.mShapes[type][rotation][i2][j2] != 0) 
			{
				mGrid[i1][j1] = shapes.mShapes[type][rotation][i2][j2];
			}
		}
	}
}

void Grid::moveShape(int type, int rotation, int oldx, int oldy, int x, int y) {
	int i1, i2;
	int j1, j2;
	for(int i = 0; i <GRID_WIDTH; i++){

		for(int j = 0; j < GRID_HEIGHT; j++){

			mGrid[i][j] = 0;
		}
	}

	// Draw new position	
	for(i1=x, i2=0; i1<x+5; i1++, i2++)
	{
		for(j1=y, j2=0; j1 < y+5; j1++, j2++)
		{
			if(shapes.mShapes[type][rotation][i2][j2] != 0) 
			{
				mGrid[i1][j1] = shapes.mShapes[type][rotation][i2][j2];
			}
		}
	}
}
	



