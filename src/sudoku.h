/*
 * sudoku.h
 *
 *  Created on: Jan 31, 2013
 *      Author: Luxx
 */

#ifndef SUDOKU_H_
#define SUDOKU_H_

#define NUM_GIVEN 0xFF

int fillPuzzle(int *puzzle);
void printPuzzle(int *puzzle);
void setGivenNum(int *puzzle, int *given);

int checkNumberInCell(int cell_number, int test_number, int * grid);
int checkRow(int cell_number, int test_number, int * grid);
int checkColumn(int cell_number, int test_number, int *grid);
int checkGrid(int value);

#endif /* SUDOKU_H_ */
