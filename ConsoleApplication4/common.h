#ifndef COMMON_H
#define COMMON_H

/* This File is for storing any globally used functions and constants */
#include <iostream>
#include <stdio.h>
#include <string>
#include <Windows.h>
#include <list>

#define DEBUG_M true
#define GAME_TIME 60  //seconds
#define WALLED false
#define HEIGHT 20
#define WIDTH 40
#define START_LENGTH 3
#define MAX_LENGTH 10
//Player and Staus IDs
#define PLAYER_ID 1
#define ENEMY_ID 2
#define PLAYER_KILLED 100
#define ENEMY_KILLED 200
#define ILLEGAL_MOVE 300
#define HIT_WALL 400



using namespace std;
HANDLE  hConsole;
int snake_length;

struct point {
	int x;
	int y;
};

list <point> snake_pos;

void init() {
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	snake_length = START_LENGTH;
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
		int i = 0;
		if (ID == PLAYER_ID) {
			cout << " Adding player\n"; 
			while (i < snake_length) {
				point p1;
				p1.x = x + i;
				p1.y = y;
				snake_pos.push_back(p1);
				array[y][x+i] = ID;
				i++;
			}
		}
		else {
			array[y][x] = ID;
		}
	}
}

int moveUp(int(&array)[HEIGHT][WIDTH], int (&x), int(&y)) {
	int status = 0;
	point p1;
	if (array[y-1][x] == PLAYER_ID) {
		std::list<point>::const_iterator iterator = snake_pos.begin();
		++iterator;
		if (((*iterator).y == (y - 1)) && ((*iterator).x == x)) {
			cout << "Warning Illegal Move!\n";
			return ILLEGAL_MOVE;
		}
		else {
			point bp1 = snake_pos.back();
			if(!((bp1.y == (y - 1)) && (bp1.x == x))) {
				cout << "Player killed!\n";
				return PLAYER_KILLED;
			}
		}

	}
	y = y - 1;
	if (y < 0) {
		WALLED == true ? y = 0 : y = HEIGHT - 1;
	}

	if (array[y][x] == ENEMY_ID) {
		status = ENEMY_KILLED;
		snake_length++;
	}
	p1.y = y;
	p1.x = x;
	if (status == 0) {
		point rp1 = snake_pos.back();
		array[rp1.y][rp1.x] = 0;
		snake_pos.pop_back();
	}
	snake_pos.push_front(p1);
	for (std::list<point>::const_iterator iterator = snake_pos.begin(), end = snake_pos.end(); iterator != end; ++iterator) {
		array[(*iterator).y][(*iterator).x] = PLAYER_ID;
	}
	return status;
}

int moveDown(int(&array)[HEIGHT][WIDTH], int(&x), int(&y)) {
	int status = 0;
	point p1;
	if (array[y+1][x] == PLAYER_ID) {
		std::list<point>::const_iterator iterator = snake_pos.begin();
		++iterator;
		if (((*iterator).y == (y + 1)) && ((*iterator).x == x)) {
			cout << "Warning Illegal Move!\n";
			return ILLEGAL_MOVE;
		}
		else {
			point bp1 = snake_pos.back();
			if (!((bp1.y == (y + 1)) && (bp1.x == x))) {
				cout << "Player killed!\n";
				return PLAYER_KILLED;
			}
		}

	}
	y = y + 1;

	if (y > HEIGHT - 1){
		WALLED == true ? y = HEIGHT - 1 : y = 0;
	}
	p1.y = y;
	p1.x = x;

	if (array[y][x] == ENEMY_ID) {
		status = ENEMY_KILLED;
		snake_length++;
	}
	if (status == 0) {
		point rp1 = snake_pos.back();
		array[rp1.y][rp1.x] = 0;
		snake_pos.pop_back();
	}
	snake_pos.push_front(p1);
	for (std::list<point>::const_iterator iterator = snake_pos.begin(), end = snake_pos.end(); iterator != end; ++iterator) {
		array[(*iterator).y][(*iterator).x] = PLAYER_ID;
	}
	return status;
}

int moveLeft(int(&array)[HEIGHT][WIDTH], int(&x), int(&y)) {
	int status = 0;
	point p1;
	if (array[y][x-1] == PLAYER_ID) {
		std::list<point>::const_iterator iterator = snake_pos.begin();
		++iterator;
		if (((*iterator).y == (y)) && ((*iterator).x == (x-1))) {
			cout << "Warning Illegal Move!\n";
			return ILLEGAL_MOVE;
		}
		else {
			point bp1 = snake_pos.back();
			if (!((bp1.y == (y)) && (bp1.x == (x-1)))) {
				cout << "Player killed!\n";
				return PLAYER_KILLED;
			}
		}

	}
	x = x - 1;

	if (x < 0) {
		WALLED == true ? x = 0 : x = WIDTH - 1;
	}
	p1.y = y;
	p1.x = x;

	if (array[y][x] == ENEMY_ID) {
		status = ENEMY_KILLED;
		snake_length++;
	}
	if (status == 0) {
		point rp1 = snake_pos.back();
		array[rp1.y][rp1.x] = 0;
		snake_pos.pop_back();
	}
	snake_pos.push_front(p1);

	for (std::list<point>::const_iterator iterator = snake_pos.begin(), end = snake_pos.end(); iterator != end; ++iterator) {
		array[(*iterator).y][(*iterator).x] = PLAYER_ID;
	}
	return status;
}

int moveRight(int(&array)[HEIGHT][WIDTH], int(&x), int(&y)) {
	int status = 0;
	point p1;
	if (array[y][x+1] == PLAYER_ID) {
		std::list<point>::const_iterator iterator = snake_pos.begin();
		++iterator;
		if (((*iterator).y == (y)) && ((*iterator).x == (x+1))) {
			return ILLEGAL_MOVE;
		}
		else {
			point bp1 = snake_pos.back();
			if (!((bp1.y == (y)) && (bp1.x == (x + 1)))) {
				return PLAYER_KILLED;
			}
		}

	}
	x = x + 1;

	if (x > WIDTH - 1){
		WALLED == true ? x = WIDTH - 1: x = 0 ;
	}
	p1.y = y;
	p1.x = x;

	if (array[y][x] == ENEMY_ID) {
		status = ENEMY_KILLED;
		snake_length++;
	}
	if (status == 0) {
		point rp1 = snake_pos.back();
		array[rp1.y][rp1.x] = 0;
		snake_pos.pop_back();
	}
	snake_pos.push_front(p1);
	for (std::list<point>::const_iterator iterator = snake_pos.begin(), end = snake_pos.end(); iterator != end; ++iterator) {
		array[(*iterator).y][(*iterator).x] = PLAYER_ID;
	}
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
