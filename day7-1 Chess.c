#define _CRT_SECURE_NO_WARNINGS
#include"game1.h"
void menu()
{
	printf("   WELCOME\n");
	printf("1 play 2 exit\n");
}
void game()
{
//需要存放玩家的步骤。
	int count = 0;
	int playerw = 0;
	int who = 1;
	int position = ROW*COL;
	char BOARD[ROW][COL] = { '0' };
//初始化棋盘
	initial_board(ROW, COL, BOARD);
//显示棋盘       
	dispaly(ROW, COL, BOARD);
//下棋 
	while (1)
	{
		move(ROW, COL,who,BOARD);
		position--;
		dispaly(ROW, COL, BOARD);
		printf("\n");
		if (JudgeWin(ROW, COL, GOAL, who, BOARD))
		{
			printf("THE WINNER IS PLAYER %d\n",(who%2));
			break;
		}
		if (position == 0)
		{
			printf("NO POSITION LEFT,NO WINNER, GAME OVER\n");
			break;
		}
		who++;
	}
}
void test()
{
	int choose = 0;
	srand((unsigned int)time(NULL));
	do
	{
		menu();
		printf(" 请选择：\n");
		scanf("%d", &choose);
		switch (choose)
		{
		case(1):
		{
			printf("THE GAME ISON\n");
			game();
			break;
		}
		case(2):
		{
			printf("GAMEOVER\n");
			break;
		}
		default:
		{
			printf("INPUT ERROR\nTRY AGAIN\n");
			Sleep(500);
			break;
		}
		}
	} while(choose!=2);
}
int main()
{
	printf("五子棋version1.0\n电脑难度：只会乱下\n棋盘大小 %d*%d\n连子数%d个\n",ROW,COL,GOAL);
	test();
	return 0;
}