#ifndef COMMON_H
#define COMMON_H

/* This File is for storing any globally used functions and constants */
#include <iostream>
#include <stdio.h>
#include <string>

#define DEBUG_M true


#define HEIGHT 10
#define WIDTH 20
using namespace std;

void printd(char* msg) {
	if (DEBUG_M == true && msg!=NULL) {
		cout << msg;
	}
}

void setPoint(int (&array)[HEIGHT][WIDTH], int x, int y) {
	if (y > HEIGHT || x > WIDTH || x < 0 || y < 0) {
		cerr << "ERROR: OUT OF RANGE: " << x << "," << y;
	}
	else {
		array[y][x] = 1;

	}
}

void moveUp(int(&array)[HEIGHT][WIDTH], int (&x), int(&y)) {
	array[y][x] = 0;
	y = y - 1;
	if(y<0) y = HEIGHT - 1;
	array[y][x] = 1;
}

void moveDown(int(&array)[HEIGHT][WIDTH], int(&x), int(&y)) {
	array[y][x] = 0;
	y = y + 1;
	if (y> HEIGHT - 1) y = 0;
	array[y][x] = 1;
}

void moveLeft(int(&array)[HEIGHT][WIDTH], int(&x), int(&y)) {
	array[y][x] = 0;
	x = x - 1;
	if (x  < 0) x = WIDTH - 1;
	array[y][x] = 1;
}

void moveRight(int(&array)[HEIGHT][WIDTH], int(&x), int(&y)) {
	array[y][x] = 0;
	x = x + 1;
	if (x > WIDTH - 1) x = 0;
	array[y][x] = 1;
}

void displayGrid(int array[HEIGHT][WIDTH]) {
	for (int i = 0; i < HEIGHT; i++) {
		for (int j = 0; j < WIDTH; j++) {
			cout << array[i][j] << " ";
		}
		cout << "\n";
	}
}

#endif COMMON_H
