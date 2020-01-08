#include "sudoku.h"

int **create_puzzle()
{
	int **puzzle;
	int array[9][9] = { 0, 1, 9,  0, 0, 2,  0, 0, 0,
		            4, 7, 0,  6, 9, 0,  0, 0, 1,
		            0, 0, 0,  4, 0, 0,  0, 9, 0,

		            8, 9, 4,  5, 0, 7,  0, 0, 0,
		            0, 0, 0,  0, 0, 0,  0, 0, 0,
		            0, 0, 0,  2, 0, 1,  9, 5, 8,

		            0, 5, 0,  0, 0, 6,  0, 0, 0,
		            6, 0, 0,  0, 2, 8,  0, 7, 9,
		            0, 0, 0,  1, 0, 0,  8, 6, 0  };

	puzzle = (int **) malloc(sizeof(int *) * 9);

	for (int x = 0; x < SIZE_ROWS; x++) {
		puzzle[x] = (int *) malloc(sizeof(int) * 9);

		for (int y = 0; y < SIZE_COLUMNS; y++) {
			puzzle[x][y] = array[x][y];
		}
	}

	return puzzle;
}

void print_puzzle(int **puzzle)
{
	printf("-------------------------------\n");
	for (int x = 0; x < SIZE_ROWS; x++) {
		/* print each row */
		printf("|");
		for (int y = 0; y < SIZE_COLUMNS; y++) {
			printf(" %d ", puzzle[x][y]);
			if ( y % 3 == 2) {
				printf("|");
			}
		}
		printf("\n");
		if (x % 3 == 2) {
			printf("-------------------------------\n");
		}
	}
}

Square ***set_up_puzzle(int **puzzle)
{
	Square ***sudoku;

	sudoku = (Square ***) malloc(sizeof(Square **) * 9);

	/* loop through rows */
	for (int x = 0; x < SIZE_ROWS; x++) {
		sudoku[x] = (Square **) malloc(sizeof(Square *) * 9);

		/* loop through columns */
		for (int y = 0; y < SIZE_COLUMNS; y++) {
			sudoku[x][y] = (Square *) malloc(sizeof(Square) * 9);

			sudoku[x][y]->number = puzzle[x][y];

			sudoku[x][y]->row = x;
			sudoku[x][y]->column = y;

			if (sudoku[x][y]->number != 0) {
				sudoku[x][y]->code = POSSIBLE;
			} else {
				sudoku[x][y]->code = 0x0;
			}
		}
	}
}
