#define _CRT_SECURE_NO_WARNINGS
#include"game1.h"
void initial_board(int row, int col, char board[ROW][COL])
{
	int i = 0; int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
			board[i][j] = ' ';
	}
}
void dispaly(int Row, int Col, char Board[ROW][COL])
{
	int i = 0; int j = 0;
	printf("|");
	for(j = 0; j < Col; j++)
		printf("---|");
	printf("\n");
	for (i = 0; i < Row; i++)
	{
		printf("|");
		for (j = 0; j < Col; j++)
			printf(" %c |", Board[i][j]);
		printf("\n|");
		for (j = 0; j < Col; j++)
			printf("---|");
		printf("\n");
	}
}
void move(int ROw, int COl, int WHO, char BOard[ROW][COL])
{
	int rrr = 0; int ccc = 0; int i=0; int j = 0;
	if ((WHO%2) == 1)
	{
		do {
		printf("输入坐标____(<=7)行____列(<=7)\n");
		scanf("%d %d", &rrr, &ccc);
		rrr--; ccc--;
		} while (BOard[rrr][ccc] != ' ');
	}
	else
	{
		
			rrr = rand() % ROw - 1;                         // 到底怎么生成随机数 啊！！！！‘
			ccc = rand() % COl - 1;
			if (BOard[rrr][ccc] == ' ')
		        ; 
			else 
			{
				for (i = 0; (i < ROw)&&(BOard[rrr][ccc] != ' '); i++)
				{
					ccc = (ccc + 1) % COl;
					for (j = 0; (j < COl)&&(BOard[rrr][ccc] != ' '); j++)
					{
						rrr=(rrr+1) % ROw;
					}
				}
			}
		                               //这里遇到了只在对角线生成，因为只有一个随机数，的bug。   ok
	}
	if ((WHO%2) == 1)
		{
			BOard[rrr][ccc] = 'o';
		}
	else
	{
		Sleep(500);
		BOard[rrr][ccc] = 'x';
	}
}
int JudgeWin(int rOW, int cOL,int Goal, int whom,char BoArd[ROW][COL])    //加油 ，就差一步啦
{
	int count = 0;
	int i = 0; int j = 0; char tmp = 'a'; int k = 0;
	int playerw = 0;
	if((whom % 2) == 1)
		tmp = 'o';
	else
	    tmp = 'x';
	for (i = 0; (i <= rOW-Goal) && (count != Goal); i++)     // 6行，0-5，Goal =4  0,1,2-2345 
	{
		for (j = 0; (j <= cOL - Goal)&&(count!=Goal); j++)
		{
			if (BoArd[i][j] != ' ')
			{
				for (k = 1, count = 1; k < Goal; k++)     //斜着判断
				{
					if (BoArd[i][j] == BoArd[i + k][j + k])
						count++;
					else
						break;
				}
				if (count == Goal)
				{
					return 1;
					break;
				}
				for (k = 1, count = 1; k < Goal; k++)     //竖着
				{
					if (BoArd[i][j] == BoArd[i + k][j])
						count++;
					else
						break;
				}
				if (count == Goal)
				{
					return 1;
					break;
				}
				for (k = 1, count = 1; k < Goal; k++)
				{
					if (BoArd[i][j] == BoArd[i][j + k])
						count++;
					else
						break;
				}
				if (count == Goal)
				{
					return 1;
					break;
				}
			}
			
		}
		if (count == Goal)
		{
			return 1;
			break;
		}
	}
	return 0;
}