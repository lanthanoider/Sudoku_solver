//============================================================================
// Name        : Sudoku_solver_Cpp.cpp
// Author      : Joel Clark
// Version     :
// Copyright   : Open Source!
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <fstream>
#include <string>

#include "sudoku.h"

using namespace std;

int main() {

	int given_array[81];
	int puzzle[81];

	if (fillPuzzle(puzzle)) {
		return 1;
	}

	printPuzzle(puzzle);

	cout << endl << endl;

	// set an array to hold the numbers already given
	setGivenNum(puzzle, given_array);

	printPuzzle(given_array);

	cout << endl << endl;

	for (int i = 0; i < 81; i++) {

		// check the cell is free
		if (given_array[i] != NUM_GIVEN) {
			for (int j = 1; j <= 9; j++) {
				if (!checkNumberInCell(i, j, puzzle)) {
					// code to increment i
					puzzle[i] = j;
				}
			}


		}

	}

	printPuzzle(puzzle);

	return 0;
}

/*
 * function to check whether the current value can be placed in the current cell
 * returns a 0 if the current number can be placed in the cell else returns a 1
 */
int checkNumberInCell(int cell_number, int test_number, int * grid) {

	if (checkRow(cell_number, test_number, grid)) { /* check row */
		return 1;
//	} else if (checkColumn(cell_number, test_number, grid)) { /* check column */
//		return 1;
//	} else if (checkGrid(value)) { /* check 3x3 grid */
//		return 1;
	}

	return 0; /* all tests successful */

}

void setGivenNum(int *puzzle, int *given) {

	for (int i = 0; i < 81; i++) {
		if (puzzle[i] == 0) {
			given[i] = 0;
		} else {
			given[i] = NUM_GIVEN;
		}
	}

}

int fillPuzzle(int *puzzle) {

	ifstream puzzle_file;
	puzzle_file.open("../sudoku.txt");

	if (!puzzle_file) {
		cout << "File could not be opened" << endl;
		return 1;
	}

	for (int i = 0; i < 81; i++) {
			puzzle_file >> puzzle[i];
	}

	puzzle_file.close();
	return 0;

}

void printPuzzle(int *puzzle) {
	int k = 0;
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cout << puzzle[k];
			k++;
		}
		cout << endl;
	}

}

int checkRow(int cell_number, int test_number, int *grid) {
	int offset = 0;
	for (int i = 0; i <= 9; i++) {
		if (test_number == grid[i + offset]) {
			return 1;
		}
	}
	return 0;
}

int checkColumn(int cell_number, int test_number, int *grid) {
	for (int i = 0; i <= 9; i += 10) {
		if (test_number == grid[i]) {
			return 1;
		}
	}
	return 0;
}

int checkGrid(int value) {
	return 0;
}
