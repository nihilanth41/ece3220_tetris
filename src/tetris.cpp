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
	bool gameOn = true;	
	int speedValue = 100000;
	int gridWidth = GRID_WIDTH;
	int gridHeight = GRID_HEIGHT;
	
	// Initialize Game object 
	Game game;
	while(gameOn != false){
	clearScreen(5);

	game.mainMenu();

	cin>>game.menuSelection;
	

	if(game.menuSelection == 1){
		clearScreen(20);
		cout<<"J = Left\tK = Right\tL = Rotate\tQ = Quit"<<endl<<endl;
		game.Play(speedValue, gridWidth, gridHeight);
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
				
			speedValue = 10000;
		}

		if(game.settingsSelection == 3){
				
			speedValue = 200000;
		}

		if(game.settingsSelection == 4){
				
			speedValue = 100000;
		}


		if(game.settingsSelection == 5){
				
			gridWidth = 30;
			gridHeight = 50;
		}

		if(game.settingsSelection == 6){
			gridWidth = 20;
			gridHeight = 30;		

		}

		if(game.settingsSelection == 7){

		}
		if(game.settingsSelection == 8){
			gameOn = false;
		}
	}
	if(game.menuSelection == 4){

		cout<<"Terminating Game..."<<endl<<endl;
		gameOn = false;
	}
	}

	return 0;
} 












