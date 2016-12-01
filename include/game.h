#ifndef __GAME_H
#define __GAME_H
#include "grid.h"
#include "tetromino.h"

class Game {
public:
    Game (Grid *pBoard, Tetromino *pPieces, int pScreenHeight);

    void DrawScene ();
    void CreateNewPiece ();
 
    int mPosX, mPosY;               // Position of the piece that is falling down
    int mPiece, mRotation;          // Kind and rotation the piece that is falling down
 
private:
 
    int mScreenHeight;              // Screen height in pixels
    int mNextPosX, mNextPosY;       // Position of the next piece
    int mNextPiece, mNextRotation;  // Kind and rotation of the next piece
 
    Grid *mBoard;
    Tetromino *mPieces;
    //IO *mIO;
 
    int GetRand (int pA, int pB);
    void InitGame();
    void DrawPiece (int pX, int pY, int pPiece, int pRotation);
    void DrawBoard ();
};
 

#endif
