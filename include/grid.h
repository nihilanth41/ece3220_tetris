#ifndef __GRID_H
#define __GRID_H
#include <iostream>
#include "tetromino.h"

#define BOARD_LINE_WIDTH 6          // Width of each of the two lines that delimit the board
#define BLOCK_SIZE 16               // Width and Height of each block of a piece
#define BOARD_POSITION 320          // Center position of the board from the left of the screen
#define GRID_WIDTH 10              // Board width in blocks
#define GRID_HEIGHT 20             // Board height in blocks
#define MIN_VERTICAL_MARGIN 20      // Minimum vertical margin for the board limit     
#define MIN_HORIZONTAL_MARGIN 20    // Minimum horizontal margin for the board limit
#define TETRO_BOUND 5              // Number of horizontal and vertical blocks of a matrix piece

class Grid { 
	public:
        // Constructor
        Grid(Tetromino *pPieces, int pScreenHeight);

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
        Tetromino *mPieces;
        int mScreenHeight;

        void InitGrid();
        void DeleteLine (int pY);
};

#endif
