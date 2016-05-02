#ifndef COMMON_H
#define COMMON_H

/* This File is for storing any globally used functions and constants */
#include <iostream>
#include <stdio.h>
#include <string>

#define DEBUG_M true

using namespace std;

void printd(char* msg) {
	if (DEBUG_M == true) {
		cout << msg;
	}


}






#endif COMMON_H
