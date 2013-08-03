#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include "Item.h"
#include "sudoku_alloc.h"
#include "sudoku_utils.h"
#include "sudoku_solve.h"

void show(Sudoku* s) {
	int i, j;
	char out[100];

	i = 0;
	while(i < 9) {
		j = 0;
		while(j < 9) {
			sprintf(out, " %d ", s->cell[i][j]);
			write(1, out, 3);
			j++;
			if(j % 3 == 0) {
				sprintf(out, "|");
				write(1, out, 1);
			}
		}
		write(1, "\n", 1);
		i++;
		if(i % 3 == 0) {
			sprintf(out, "------------------------------\n");
			write(1, out, 31);
		}
	}
}

int checkRow(Sudoku* s, int i, int value) {
	int k;

	k = 0;
	while(k < 9) {
		if(value == s->cell[i][k])
			return 0;
		k++;
	}
	return 1;
}

int checkColumn(Sudoku* s, int j, int value) {
	int k;

	k = 0;
	while(k < 9) {
		if(value == s->cell[k][j])
			return 0;
		k++;
	}
	return 1;
}

int checkGrid(Sudoku* s, int i, int j, int value) {
	int idx;
	int jdx;

	idx = getGridIndexe(i, 0);
	jdx = getGridIndexe(j, 0);
	i = idx;
	while(i < idx + 3) {
		j = jdx;
		while(j < jdx + 3) {
			if(value == s->cell[i][j])
				return 0;
			j++;
		}
		i++;
	}
	return 1;

}

int checkCell(Sudoku* s, int i, int j, int value) {
	return checkRow(s, i, value) && checkColumn(s, j, value) && checkGrid(s, i, j, value);
}
