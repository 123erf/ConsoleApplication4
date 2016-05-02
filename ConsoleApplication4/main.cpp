#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>


#include "common.h"
using namespace std;

int main(void) {
	int x_pos, y_pos;
	int score = 0;
	int ex_pos, ey_pos;
	int array[HEIGHT][WIDTH] = { 0 };
	int status = 0;
	//Create GRID
	cout << "Height:" << HEIGHT << " Width:" << WIDTH << "\n";
	displayGrid(array);
	
	ex_pos = rand() % WIDTH;
	ey_pos = rand() % HEIGHT;


	x_pos = WIDTH / 2;
	y_pos = HEIGHT / 2;
	
	setPoint(array, x_pos,y_pos, PLAYER_ID);
	setPoint(array, ex_pos, ey_pos, ENEMY_ID);
	
	cout << "TEST x:" << x_pos << " y:" << y_pos << "\n";
	system("CLS");
	displayGrid(array);

	char userInput = '0';

	while (true && userInput != 'q'){
		cout << "Enter Input\n";
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
		displayGrid(array);
		if (status == ENEMY_KILLED) {
			cout << "ENEMY KILLED!!\n"; 
			score += 10;
			ex_pos = rand() % WIDTH;
			ey_pos = rand() % HEIGHT;
			setPoint(array, ex_pos, ey_pos, ENEMY_ID);
		}
		cout << "Player Position (" << x_pos << ", " << y_pos << ")\n";
		cout << "Player Score (" << score << ")\n";
		//displayInfo(array, x_pos, y_pos);
	}


}