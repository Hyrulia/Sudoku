#ifndef SUDOKU_UTILS_H_
#define SUDOKU_UTILS_H_


int checkRow(Sudoku*, int, int);
int checkColumn(Sudoku*, int, int);
int checkGrid(Sudoku*, int, int, int);
void show(Sudoku*);
int checkCell(Sudoku*, int, int, int);


#endif
