#include <iostream>
#include <stdio.h>
#include <conio.h>
#include "common.h"
using namespace std;

int main(void) {
	printd("Hello World\n");
	
	//Create GRID
	cout << "Height:" << HEIGHT << " Width:" << WIDTH << "\n";
	int array[HEIGHT][WIDTH] = { 0 };
	displayGrid(array);

	int x_pos, y_pos;

	x_pos = WIDTH / 2;
	y_pos = HEIGHT / 2;
	setPoint(array, x_pos,y_pos);
	//array[y_pos][x_pos] = 1;
	cout << "TEST x:" << x_pos << " y:" << y_pos << "\n";
	displayGrid(array);

	char userInput = '0';
	while (true && userInput != 'q'){
		cout << "Enter Input\n";
		userInput = _getch();
		system("CLS");
		cout << "You Entered " << userInput << "\n";
		switch (userInput) {
			case 'w':
				moveUp(array, x_pos, y_pos);
				break;
			case 'a':
				moveLeft(array, x_pos, y_pos);
				break;
			case 's':
				moveDown(array, x_pos, y_pos);
				break;
			case 'd':
				moveRight(array, x_pos, y_pos);
				break;
			default:
				break;
		}
		displayGrid(array);
	}


}