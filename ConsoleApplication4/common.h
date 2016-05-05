#ifndef COMMON_H
#define COMMON_H

/* This File is for storing any globally used functions and constants */
#include <iostream>
#include <stdio.h>
#include <string>
#include <Windows.h>

#define DEBUG_M true
#define PLAYER_ID 1
#define ENEMY_ID 2

#define GAME_TIME 30  //seconds

#define ENEMY_KILLED 100  //STATUS ID

#define WALLED false


#define HEIGHT 20
#define WIDTH 40
using namespace std;
HANDLE  hConsole;

void init() {
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
}

void printd(char* msg) {
	if (DEBUG_M == true && msg!=NULL) {
		cout << msg;
	}
}

void setPoint(int (&array)[HEIGHT][WIDTH], int x, int y, int ID) {
	if (y > HEIGHT || x > WIDTH || x < 0 || y < 0) {
		cerr << "ERROR: OUT OF RANGE: " << x << "," << y;
	}
	else {
		array[y][x] = ID;
	}
}

int moveUp(int(&array)[HEIGHT][WIDTH], int (&x), int(&y)) {
	int status = 0;
	array[y][x] = 0;
	y = y - 1;
	if (y < 0) {
		WALLED == true ? y = 0 : y = HEIGHT - 1;
	}
	if (array[y][x] == ENEMY_ID) {
		status = ENEMY_KILLED;
	}
	array[y][x] = 1;

	return status;
}

int moveDown(int(&array)[HEIGHT][WIDTH], int(&x), int(&y)) {
	int status = 0;
	array[y][x] = 0;
	y = y + 1;

	if (y > HEIGHT - 1){
		WALLED == true ? y = HEIGHT - 1 : y = 0;
	}
	if (array[y][x] == ENEMY_ID) {
		status = ENEMY_KILLED;
	}
	array[y][x] = 1;

	return status;
}

int moveLeft(int(&array)[HEIGHT][WIDTH], int(&x), int(&y)) {
	int status = 0;
	array[y][x] = 0;
	x = x - 1;
	if (x < 0) {
		WALLED == true ? x = 0 : x = WIDTH - 1;
	}
	if (array[y][x] == ENEMY_ID) {
		status = ENEMY_KILLED;
	}
	array[y][x] = 1;

	return status;
}

int moveRight(int(&array)[HEIGHT][WIDTH], int(&x), int(&y)) {
	int status = 0;
	array[y][x] = 0;
	x = x + 1;
	if (x > WIDTH - 1){
		WALLED == true ? x = WIDTH - 1: x = 0 ;
	}
	if (array[y][x] == ENEMY_ID) {
		status = ENEMY_KILLED;
	}
	array[y][x] = 1;


	return status;
}

void displayGrid(int array[HEIGHT][WIDTH]) {
	cout << "==================================================================================\n";
	for (int i = 0; i < HEIGHT; i++) {
		hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(hConsole, 15);
		for (int j = 0; j < WIDTH; j++) {
			if (j == 0) cout << "|";
			if (array[i][j] == 0) {
				hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
				SetConsoleTextAttribute(hConsole, 15);
				cout << " " << " ";
			}
			else if(array[i][j] == PLAYER_ID){
				hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
				SetConsoleTextAttribute(hConsole, 10);
				cout << "O" << " ";
			}
			else if (array[i][j] == ENEMY_ID){
				hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
				SetConsoleTextAttribute(hConsole, 12);
				cout << "X" << " ";
			}	
		}
		hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(hConsole, 15);
		cout << "|\n";
	}
	cout << "==================================================================================\n";
}

#endif COMMON_H
