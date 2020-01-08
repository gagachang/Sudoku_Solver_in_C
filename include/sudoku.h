#ifndef SUDOKU_H_
#define SUDOKU_H_

#include <stdio.h>
#include <stdlib.h>

extern int POSSIBLE;
extern int SIZE_ROWS;
extern int SIZE_COLUMNS;

typedef struct Box {
	struct Box *next;
} Box;

typedef struct {
	int number;
	/* 111101011
	   987654321 */

	int code;
	Box *box;
	int row;
	int column;
} Square;

int **create_puzzle();

void print_puzzle(int **puzzle);

Square ***set_up_puzzle(int **puzzle);

#endif
