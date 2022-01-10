#define ROW 9
#define COL 9
#define ROWS ROW+2
#define COLS COL+2
#define NUM  10
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void generate(int row, int col, int num, char map[ROW][COL], char themap[ROW][COL], char STatus[ROW][COL]);
void display(int Row, int Col, char Map[ROW][COL]);
int clear(int roW, int coL, int* NOTmine, char maP[ROW][COL], char shoW[ROW][COL], char Status[ROW][COL]);
int mini(int x, int y);
int maxi(int g, int h);
//void spread(int rOW, int cOL, int C, int D, int* Notmine, char mAP[ROW][COL], char shOW[ROW][COL], char statuS[ROW][COL]);