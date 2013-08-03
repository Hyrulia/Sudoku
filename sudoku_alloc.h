#ifndef SUDOKU_ALLOC_H_
#define SUDOKU_ALLOC_H_

#include "Item.h"

typedef struct sudoku {
	int cell[9][9];
	int itemsLength;
	Item items[99];
} Sudoku;

Sudoku* new_sudoku(char**);
void init_sudoku(Sudoku*, char**);
void free_sudoku(Sudoku*);

#endif
