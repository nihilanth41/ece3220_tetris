#include <iostream> 
#include <cstdio>
#include <unistd.h>
#include <vector>
#include <termios.h>
#include "Game.h"
#include <unistd.h>
using namespace std;


int main(int argc, char **argv) {
	
	cout<<"+++++++++++  +++++++++  +++++++++++  +++++++++++  ++  +++++++++++"<<endl;
	usleep(100000);
	cout<<"     +       +               +       +         +  ++  +"<<endl;
	usleep(100000);
	cout<<"     +       ++++++          +       +++++++++    ++  +++++++++++"<<endl;
	usleep(100000);
	cout<<"     +       +               +       +        +   ++            +"<<endl;
	usleep(100000);
	cout<<"     +       +++++++++       +       +         +  ++  +++++++++++"<<endl;
	





	FILE* highscores;
	vector<int> scores;
	int temp;	

	// Initialize Game object 
	Game game;
	clearScreen(5);
	game.mainMenu();
	cin>>game.menuSelection;
	

	if(game.menuSelection == 1){
		clearScreen(10);
		game.Play();
	}
	if(game.menuSelection == 2){
		// Print scores
		game.printScores();

	}
	if(game.menuSelection == 3){
		clearScreen(5);
		game.settings();
		cin>>game.settingsSelection;

		if(game.settingsSelection == 1){

			cout<<"WARNING ABOUT TO CLEAR HIGH SCORES..."<<endl;
			game.clearScores();
		}

		if(game.settingsSelection == 2){
				

		}

	}
	if(game.menuSelection == 4){

		cout<<"Terminating Game..."<<endl<<endl;
		return 0;
	}

	return 0;
} 












