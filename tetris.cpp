#include <iostream> 
#include <cstdio>
#include <unistd.h>
#include <sys/select.h>
#include <termios.h>
//#include <stropts.h>
#include <sys/ioctl.h>
#include <vector>
using namespace std;

int _kbhit(void);

// Standard size
#define GRID_WIDTH 10
#define GRID_HEIGHT 20

int grid1[GRID_WIDTH][GRID_HEIGHT] = { 0 };
int grid2[GRID_WIDTH][GRID_HEIGHT] = { 0 };

void clearScreen(void){
	cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n"<<endl;
}



void print_grid(void) {
#define ANSI_COLOR_CYAN    "\x1b[36m"
#define ANSI_COLOR_RESET   "\x1b[0m"
	int i, j;
	// Iterate backwards i.e. top to bottom
	for(j=GRID_HEIGHT; j--;)
	{

		printf("[");
		// Iterate forwards i.e. left to right
		for(i=0; i<GRID_WIDTH; i++)
		{
			{

				if(grid1[j][i] == 1)
					printf(ANSI_COLOR_CYAN " %d " ANSI_COLOR_RESET, grid1[j][i]);
				else
					printf(" %d ", grid1[j][i]);
			}
		}
		printf("]\n");
	}
	// Go up 
	printf("\033[20A");

}

class Game{

public: void init_Game(){
		char userInput;

		int shape [4][5] = {0,0,0,0,0,	
				    0,1,1,0,0,
				    0,1,1,0,0,
				    0,0,0,0,0		
				};
		
		for(int i=GRID_HEIGHT; i--;)
                { 
		    // len of block
                    grid1[i][5] = 1;
                    grid1[i][4] = 1;
                        
		    grid2[i][2] = 2;
		    grid2[i][2] = 2;

			if(i<GRID_HEIGHT)
                        {
                           grid1[i+1][5] = 1;
                           grid1[i+2][5] = 1;
			   grid1[i+3][5] = 0;
		   	   grid1[i+1][4] = 0;
                       }
                        
			print_grid();
			sleep(2);
		
			
		}
	
          }
};


int main(int argc, char **argv) {
	int i;
	//vector scores<int>;
	int temp;
	int userChoice;	




	cout<<"+++++++++   +++++++++   +++++++++   +++++++++   ++   +++++++++"<<endl;
	cout<<"    +       +               +       +       +   ++   +"<<endl;
	cout<<"    +       ++++++          +       +++++++++   ++   +++++++++"<<endl;
	cout<<"    +       +               +       +    +      ++           +"<<endl;
	cout<<"    +       +++++++++       +       +       +   ++   +++++++++"<<endl;
	clearScreen();

	sleep(1);

	cout<<"Main Menu: Select one of the following\n"<<endl;
	cout<<"1 Play Game"<<endl;
	cout<<"2 Highscores"<<endl;
	cout<<"3 Settings"<<endl;
	cout<<"4 Quit"<<endl;

	cin>>userChoice;

	if(userChoice==1){
		clearScreen();
		Game game;
		game.init_Game();	
	}
	else if(userChoice == 2){
		vector scores<int>;
		FILE* fp = fopen("highscores.txt", "r");	
		while(fscanf(fp, "%d", &temp)){
			scores.push_back(temp);

		}
		clearScreen();

		cout<<"High Scores\n"<<endl;
		
		for(int x: scores){
			cout<<x<<endl;
		}
		close(fp);
	}

	else if(userChoice == 3){

	}
	else if(userChoice == 4){
		return 0;
	}

	clearScreen();

	struct termios term_old, term_new;
	
	while(1)
	{

		// Turn off echoing else fail
		if (tcgetattr (fileno (stdout), &term_old) != 0)
			return -1;

		term_new = term_old;
		term_new.c_lflag &= ~ECHO;
		if (tcsetattr (fileno (stdout), TCSAFLUSH, &term_new) != 0)
			return -1;


		if( ! _kbhit() )
		{
			char val;
			scanf(" %c", &val);
			printf("Value pressed: %c\n", val);
			break;
		}

	}
	// Restore echo
	(void) tcsetattr (fileno (stdout), TCSAFLUSH, &term_old);
	fflush(stdout);

	usleep(2000);
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
