#include "grid.h"
#include "tetromino.h"

Grid::Grid(Tetromino *pTetro, int pScreenHeight) {
    
    

}

void Grid::InitGrid(void) {
    // Initialize to empty
    for(int i=0; i<BOARD_WIDTH; i++)
    {
        for(int j=0; j<BOARD_HEIGHT; j++)
        {
            mGrid[i][j] = POS_FREE;
        }
    }
}

void Grid::StorePiece(int x, int y, int piece, int rotation) {
/* Store each block of the specified piece onto the board */
    for(int i1=x, i2=0; i1<x+TETRO_BOUND; i1++, i2++;)
    {
        for(int j1=y, j2=0; j1<y+TETRO_BOUND; j1++, j2++)
        {
            // Store only blocks that are not POS_FREE
            if(mPieces->GetBlockType(piece, rotation, j2, i2) != POS_FREE)
                mGrid[i1][j1] = POS_FILLED;
        }
    }
}
    
