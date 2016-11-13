#ifndef __GRID_H
#define __GRID_H
#include <iostream>
#include "tetromino.h"

class Grid { 
	private:
		static const int grid_width = 10;
		static const int grid_height = 20;
		int grid[grid_width][grid_height];
		Tetromino *curr_tetromino;
	public:
		void print(void);
		void addTetromino(Tetromino *);
		Grid();
		~Grid();
};
#endif
