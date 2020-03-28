#define _CRT_SECURE_NO_WARNINGS 1
/*
扫雷游戏函数的声明
*/
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define ROW 9
#define COL 9

#define EASY_COUNT 10

#define ROWS ROW+2
#define COLS COL+2

//初始化扫雷棋盘
void InitBoard(char board[ROWS][COLS], int rows, int cols,char set);
void DisPlayBoard(char board[ROWS][COLS], int row, int col);
void SetMine(char mine[ROWS][COLS], int row, int col);
void FindMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col);