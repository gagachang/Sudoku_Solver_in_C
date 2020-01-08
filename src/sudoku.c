#include "sudoku.h"

int POSSIBLE = 0x1FF;
int SIZE_ROWS = 9;
int SIZE_COLUMNS = 9;

int main()
{
	int **puzzle;
	Square ***sudoku;

	puzzle = create_puzzle();

	print_puzzle(puzzle);

	sudoku = set_up_puzzle(puzzle);

	return 0;
}
