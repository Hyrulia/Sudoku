#include<stdio.h>
#include<stdlib.h>
#include "Item.h"
#include "sudoku_alloc.h"
#include "sudoku_utils.h"
#include "sudoku_solve.h"

void init_sudoku(Sudoku* s, char** c) {
	int i, j;

	i = 1;
	j = 0;
	s->itemsLength = 0;
	while(i < 10) {
		j = 0;
		while(j < 9) {

			if(c[i][j] == '.') {
				s->cell[i-1][j] = 0;
				s->itemsLength++;
			} else {
				s->cell[i-1][j] = c[i][j] - '0';
			}
			j++;
		}
		i++;
	}
}

void free_sudoku(Sudoku* s) {
	free(s);
}

Sudoku* new_sudoku(char** c) {
	Sudoku* s = (Sudoku*) malloc(sizeof(Sudoku));
	init_sudoku(s, c);
	searchAvailableItem(s);
	sort(s);
	return s;
}
