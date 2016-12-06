#include <iostream> 
#include <cstdio>
#include <unistd.h>
#include <vector>
#include <termios.h>
#include "Game.h"

using namespace std;

void selectionHandler(int selection);

int main(int argc, char **argv) {
	FILE* highscores;
	vector<int> scores;
	int temp;	

	// Initialize Game object 
	Game game;
	game.mainMenu();
	cin>>game.selection;
	

	if(game.selection == 1){
		game.Play();
	}
	if(game.selection == 2){
		highscores = fopen("HighScores.txt", "r");
		if(highscores == NULL){
			cout<<"Error viewing highscores"<<endl;
			return -1;
		}
		
		for(int i = 0; i<5; i++){
			fscanf(highscores, "%d", &temp);
			cout<<temp<<endl;
		}
		fclose(highscores);
	}
	if(game.selection == 3){

	}
	if(game.selection == 4){

		cout<<"Terminating Game..."<<endl<<endl;
		return 0;
	}

	return 0;
} 












