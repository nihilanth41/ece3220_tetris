#ifndef __GRID_H
#define __GRID_H
#include <iostream>
#include "tetromino.h"

#define GRID_WIDTH 10
#define GRID_HEIGHT 20
#define TETRO_BOUND 5 // number of blocks in the tetromino bounding square

class Grid { 
	public:
        // Constructor
        Grid(Tetromino *pTetro, int pScreenHeight);

        int GetXPosInPixels         (int pPos);
        int GetYPosInPixels         (int pPos);
        bool IsFreeBlock            (int pX, int pY);
        bool IsPossibleMovement     (int pX, int pY, int pPiece, int pRotation);
        void StorePiece             (int pX, int pY, int pPiece, int pRotation);
        void DeletePossibleLines    ();
        bool IsGameOver             ();

    private:
        enum { POS_FREE, POS_FILLED };          // POS_FREE = free position of the board; POS_FILLED = filled position of the board
        int mGrid [GRID_WIDTH][GRID_HEIGHT]; // Board that contains the pieces
        Pieces *mPieces;
        int mScreenHeight;
        void InitGrid();
        void DeleteLine (int pY);
};

#endif
