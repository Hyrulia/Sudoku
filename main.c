#include<stdio.h>
#include<unistd.h>
#include "sudoku_alloc.h"
#include "sudoku_utils.h"
#include "sudoku_solve.h"

int main(int narg, char** varg) {
	if(narg != 10) {
		write(2, "ERROR! No enough arguments!\0", 100);
	}
	Sudoku *s = new_sudoku(varg);
	resolve(s, 0);
	show(s);
	free_sudoku(s);

	return 0;
}


