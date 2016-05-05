#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#include <fstream>

#include "common.h"
using namespace std;

int main(void) {
	int x_pos, y_pos;
	int score = 0;
	int highscore = 0;
	int ex_pos, ey_pos;
	int array[HEIGHT][WIDTH] = { 0 };
	int status = 0;
	unsigned long begTime;
	int elapsedTime = 0;
	//Create GRID
	cout << "Height:" << HEIGHT << " Width:" << WIDTH << "\n";
	displayGrid(array);

	init();
	string line;
	ifstream scorefile("highscore.txt");
	if (scorefile.is_open())
	{
		while (getline(scorefile, line))
		{
			highscore = stoi(line);
		}
		scorefile.close();
	}

	x_pos = WIDTH / 2;
	y_pos = HEIGHT / 2;
	ex_pos = (rand() + clock()) % WIDTH;
	ey_pos = (rand() + clock()) % HEIGHT;

	setPoint(array, x_pos,y_pos, PLAYER_ID);
	setPoint(array, ex_pos, ey_pos, ENEMY_ID);
	
	cout << "TEST x:" << x_pos << " y:" << y_pos << "\n";
	//system("CLS");
	displayGrid(array);

	char userInput = '0';
	begTime = clock();
	while (true && userInput != 'q' && ((unsigned long)clock() - begTime) / CLOCKS_PER_SEC < GAME_TIME){
		userInput = _getch();
		system("CLS");
		cout << "You Entered " << userInput << "\n";
		switch (userInput) {
			case 'w':
				status = moveUp(array, x_pos, y_pos);
				break;
			case 'a':
				status = moveLeft(array, x_pos, y_pos);
				break;
			case 's':
				status = moveDown(array, x_pos, y_pos);
				break;
			case 'd':
				status = moveRight(array, x_pos, y_pos);
				break;
			default:
				break;
		}


		hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(hConsole, 15);
		if (status == ENEMY_KILLED) {
			
			score += 10;
			ex_pos = (rand() + clock()) % WIDTH;
			ey_pos = (rand() + clock()) % HEIGHT;
			setPoint(array, ex_pos, ey_pos, ENEMY_ID);
			displayGrid(array);
			cout << "ENEMY KILLED!!\n";
		}
		else {
			displayGrid(array);
		}
		
		cout << "Player Position (" << x_pos << ", " << y_pos << ")\n";
		cout << "Player Score (" << score << ")\n";
		elapsedTime = ((unsigned long)clock() - begTime) / CLOCKS_PER_SEC;
		cout << "Elapsed Time: " << elapsedTime << " Seconds\n"; 
	}
	cout << "GAME OVER!!!\n";
	cout << "YOUR FINAL SCORE: " << score << "!\n";

	if (score > highscore) {
		cout << "NEW HIGH SCORE!!!\n";
		ofstream scorefile("highscore.txt");
		if (scorefile.is_open())
		{
			scorefile << score;
			scorefile.close();
		}
		else cout << "Unable to open file";
	}

	while (userInput != 'q') {
		userInput = _getch();
	}
}