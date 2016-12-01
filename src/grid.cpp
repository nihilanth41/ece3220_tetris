#include "grid.h"
#include "tetromino.h"

Grid::Grid(Tetromino *pPieces, int pScreenHeight) {
	// Get the screen height
	mScreenHeight = pScreenHeight;
	// Get the pointer to the pieces class
	mPieces = pPieces;
	//Init the board blocks with free positions
	InitGrid();
}

void Grid::InitGrid(void) {
    // Initialize to empty
    for(int i=0; i<GRID_WIDTH; i++)
    {
        for(int j=0; j<GRID_HEIGHT; j++)
        {
            mGrid[i][j] = POS_FREE;
        }
    }
}

void Grid::StorePiece(int x, int y, int piece, int rotation) {
/* Store each block of the specified piece onto the board */
    for(int i1=x, i2=0; i1<x+TETRO_BOUND; i1++, i2++)
    {
        for(int j1=y, j2=0; j1<y+TETRO_BOUND; j1++, j2++)
        {
            // Store only blocks that are not POS_FREE
            if(mPieces->GetBlockType(piece, rotation, j2, i2) != POS_FREE)
                mGrid[i1][j1] = POS_FILLED;
        }
    }
}


bool Grid::IsGameOver() {
	// If top line has blocks then the game is over
	for(int i=0; i < GRID_WIDTH; i++)
	{
		if(mGrid[i][0] == POS_FILLED)
		{
			return 1;
		}
	}
	return 0;
}

/*
======================================                                 
Delete a line of the board by moving all above lines down
 
Parameters:
 
>> pY:        Vertical position in blocks of the line to delete
======================================
*/
void Grid::DeleteLine (int pY) {
    // Moves all the upper lines one row down
    for (int j = pY; j > 0; j--)
    {
        for (int i = 0; i < GRID_WIDTH; i++)
        {
            mGrid[i][j] = mGrid[i][j-1];
        }
    } 
}

void Grid::DeletePossibleLines(void) {
	for(int j=0; j<GRID_HEIGHT; j++)
	{
		int i=0;
		while(i < GRID_WIDTH) {
			if(mGrid[i][j] != POS_FILLED)
			{ break; }

			i++;
		}
		if(i == GRID_WIDTH)
			DeleteLine(j);
	}
}

bool Grid::IsFreeBlock(int pX, int pY) {
	if(mGrid[pX][pY] == POS_FREE)
		return true;
	else
		return false;
}

int Grid::GetXPosInPixels(int pPos) {
	return ((BOARD_POSITION - (BLOCK_SIZE*(GRID_WIDTH/2))) + (pPos * BLOCK_SIZE));
}

int Grid::GetYPosInPixels(int pPos) {
	return ((mScreenHeight - (BLOCK_SIZE * GRID_HEIGHT)) + (pPos * BLOCK_SIZE));
}

/*
======================================                                 
Check if the piece can be stored at this position without any collision
Returns true if the movement is  possible, false if it not possible
 
Parameters:
 
>> pX:        Horizontal position in blocks
>> pY:        Vertical position in blocks
>> pPiece:    Piece to draw
>> pRotation: 1 of the 4 possible rotations
======================================
*/
bool Grid::IsPossibleMovement (int pX, int pY, int pPiece, int pRotation)
{
    // Checks collision with pieces already stored in the board or the board limits
    // This is just to check the 5x5 blocks of a piece with the appropriate area in the board
    for (int i1 = pX, i2 = 0; i1 < pX + TETRO_BOUND; i1++, i2++)
    {
        for (int j1 = pY, j2 = 0; j1 < pY + TETRO_BOUND; j1++, j2++)
        {  
            // Check if the piece is outside the limits of the board
            if (    i1 < 0           ||
                i1 > GRID_WIDTH  - 1    ||
                j1 > GRID_HEIGHT - 1)
            {
                if (mPieces->GetBlockType (pPiece, pRotation, j2, i2) != 0)
                    return 0;      
            }
 
            // Check if the piece have collisioned with a block already stored in the map
            if (j1 >= 0)
            {
                if ((mPieces->GetBlockType (pPiece, pRotation, j2, i2) != 0) &&
                    (!IsFreeBlock (i1, j1)) )
                    return false;
            }
        }
    }
 
    // No collision
    return true;
}
	
	
