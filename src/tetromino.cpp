#include "tetromino.h"

/*
  Params:
    {
        piece -- Piece to draw {0 - 6}
        rotation -- Rotation of piece {0 - 3}
        x -- horizontal position
        y -- vertical position
    }
  Returns:
    Type of block:
        {
            0 => No block
            1 => Normal block
            2 => Pivot point
        }
*/

int Tetromino::GetBlockType(int piece, int rotation, int x, int y)
{
    return mPieces[piece][rotation][x][y];
}

/* Returns horizontal displacement that should be applied to piece */
int Tetromino::GetXInitialPosition(int piece, int rotation)
{
	return mPiecesInitialPosition[piece][rotation][0];
}

/* Returns vertical displacement that should be applied to piece */
int Tetromino::GetYInitialPosition(int piece, int rotation)
{
	return mPiecesInitialPosition[piece][rotation][1];
}

