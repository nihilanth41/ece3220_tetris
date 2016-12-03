#include "Grid.h"
#include "Shapes.h"

Grid::Grid() {
	// Initalize Grid to 0
	mGrid.resize(GRID_WIDTH, vector<int>(GRID_HEIGHT, 0));
}

void Grid::AddShape(int type, int rotation, int x, int y) {
	int i1, i2;
	int j1, j2;
	for(i1=3, i2=0; i1<8; i1++, i2++)
	{
		for(j1=14, j2=0; j1 < 19; j1++, j2++)
		{
			if(shapes.mShapes[type][rotation][i2][j2] != 0) 
			{

			mGrid[i1][j1] = 1;
			}
		}
	}
}
	

