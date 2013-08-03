#ifndef SUDOKU_SOLVE_H_
#define SUDOKU_SOLVE_H_

int getGridIndexe(int, int);
int resolve(Sudoku*, int);
void searchAvailableItem(Sudoku*);
void sort(Sudoku*);

#endif
