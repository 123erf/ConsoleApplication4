#include <iostream>
#include <stdio.h>

#include "common.h"
using namespace std;

int main(void) {
	printd("Hello World\n");
	
	//Create GRID
	cout << "Height:" << HEIGHT << " Width:" << WIDTH << "\n";
	int array[HEIGHT][WIDTH] = { 0 };
	displayGrid(array);
	char userInput = '0';
	while (true && userInput != 'q'){
		cout << "Enter Input\n";
		cin >> userInput;
		cout << "You Entered " << userInput << "\n";
	}


}