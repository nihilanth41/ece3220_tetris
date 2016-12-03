#ifndef __GRID_H
#define __GRID_H
#include <vector>
#include "Shapes.h"

using namespace std;

#define GRID_HEIGHT 20
#define GRID_WIDTH 10

class Grid { 
	public:
		vector<vector<int>> mGrid;
		Grid(); 
		void AddShape(int type, int rotation, int x, int y);
		void MoveShape(int type, int rotation, int oldx, int oldy, int x, int y);
		Shapes shapes;
};


#endif
