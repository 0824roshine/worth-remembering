#define ROW 4     //这里不能有分号！
#define COL 4
#define GOAL 4
#include<stdio.h>    //这里引用头文件后，主函数里就不需要了！
#include<time.h>
#include<stdlib.h>
#include<windows.h>
void initial_board(int row, int col,char board[ROW][COL]);  //声明   这里需要用分号、。
void dispaly(int Row, int Col,char Board[ROW][COL]);
void move(int ROw, int COl, int WHO, char BOard[ROW][COL]);
int JudgeWin(int rOW, int cOL, int Goal, int whom, char BoArd[ROW][COL]);