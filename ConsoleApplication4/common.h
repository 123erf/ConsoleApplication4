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

void displayGrid(int array[HEIGHT][WIDTH]) {
	for (int i = 0; i < HEIGHT; i++) {
		for (int j = 0; j < WIDTH; j++) {
			cout << array[i][j];
		}
		cout << "\n";
	}
}

#endif COMMON_H
