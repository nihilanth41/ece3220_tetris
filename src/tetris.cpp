#include <iostream> 
#include <cstdio>
#include <unistd.h>
#include <sys/select.h>
#include <termios.h>
#include <stropts.h>
#include <sys/ioctl.h>
#include "tetromino.h"
#include "grid.h"
#include "game.h"

using namespace std;

int _kbhit(void);

int main(int argc, char **argv) {
//	int i;
//	for(i=GRID_HEIGHT; i--;)
//	{
//		// len of block
//		grid1[i][5] = 1;
//		grid1[i][4] = 1;
//		if(i<GRID_HEIGHT)
//		{
//			grid1[i+1][5] = 1;
//			grid1[i+2][5] = 1;
//			grid1[i+3][5] = 0;
//			grid1[i+1][4] = 0;
//		}
//		print_grid();
//		sleep(1);
//	}
//
//	struct termios term_old, term_new;
//	while(1)
//	{
//
//		// Turn off echoing else fail
//		if (tcgetattr (fileno (stdout), &term_old) != 0)
//			return -1;
//
//		term_new = term_old;
//		term_new.c_lflag &= ~ECHO;
//		if (tcsetattr (fileno (stdout), TCSAFLUSH, &term_new) != 0)
//			return -1;
//
//
//		if( ! _kbhit() )
//		{
//			char val;
//			scanf(" %c", &val);
//			printf("Value pressed: %c\n", val);
//			break;
//		}
//
//	}
//	// Restore echo
	int mScreenHeight = 20;
	Tetromino mPieces;
	Grid mGrid(&mPieces, mScreenHeight);
	Game mGame(&mGrid, &mPieces, mScreenHeight);

	return 0;
}

	/*
 TODO:
 Need to make UML diagram/flowchart, should help with designing classes

Initialize an empty grid, background, that will hold the blocks that have already fallen
Initialize a grid, foreground, to hold current falling block
Generate a tetromino and place it initially in the top-center of the foreground
Decrement the y-pos of the tetromino in grid2 to simulate falling effect
Want to compare the future position of the bottom-most row *in each column* of the falling tetromino WITH the top-most row *in each column* of grid fallen blocks
	(Left->right, top->bottom)
	Can we do this left to right?
*/
/**
 Linux (POSIX) implementation of _kbhit().
 Morgan McGuire, morgan@cs.brown.edu
 */


int _kbhit() {
    static const int STDIN = 0;
    static bool initialized = false;

    if (! initialized) {
        // Use termios to turn off line buffering
        termios term;
        tcgetattr(STDIN, &term);
        term.c_lflag &= ~ICANON;
        tcsetattr(STDIN, TCSANOW, &term);
        setbuf(stdin, NULL);
        initialized = true;
    }

    int bytesWaiting;
    ioctl(STDIN, FIONREAD, &bytesWaiting);
    return bytesWaiting;
}
