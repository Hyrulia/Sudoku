#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include "Item.h"
#include "sudoku_alloc.h"
#include "sudoku_utils.h"
#include "sudoku_solve.h"


int getGridIndexe(int value, int i) {
	if(value < i) {
		return i - 3;
	}
	return getGridIndexe(value, i + 3);
}

int resolve(Sudoku* s, int idx) {
	int a, i, j;

	if(idx >= s->itemsLength) {
		return 1;
	}
	i = s->items[idx].i;
	j = s->items[idx].j;

	if(s->cell[i][j]) {
		return resolve(s, idx + 1);
	}
	if(!s->cell[i][j]) {
		a = 1;
		while(a < 10) {
			if(checkCell(s, i, j, a)) {
				s->cell[i][j] = a;
				if(resolve(s, idx + 1)) {
					return 1;
				}
			}
			a++;
		}
		s->cell[i][j] = 0;
	}
	return 0;
}

void searchAvailableItem(Sudoku* s) {
	int k, i, j, a, b;

	k = i = j = 0;
	while(i < 9) {
		j = 0;
		while(j < 9) {
			if(!s->cell[i][j]) {
				b = 9;
				s->items[k].i = i;
				s->items[k].j = j;
				a = 1;
				while(a < 10) {
					if(!checkRow(s, i, a) || !checkColumn(s, j, a) || !checkGrid(s, i, j, a)) {
						b--;
					}
					a++;
				}
				s->items[k].values = b;
				k++;
			}
			j++;
		}
		i++;
	}
}

void sort(Sudoku* s) {
	int i, j;
	Item tmp;

	i = 0;
	while(i < s->itemsLength - 1) {
		j =  i + 1;
		while(j < s->itemsLength) {
			if(s->items[i].values > s->items[j].values)	{
				tmp = s->items[i];
				s->items[i] = s->items[j];
				s->items[j] = tmp;
			}
			j++;
		}
		i++;
	}
}
