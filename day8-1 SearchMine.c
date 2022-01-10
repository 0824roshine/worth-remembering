#define _CRT_SECURE_NO_WARNINGS
#include"SearchMine.h"
void menu()
{
	printf("       扫雷1.0\n  网格:%d*%d，雷个数：%d\n请选择  1. 开始  2.退出\n",ROW,COL,NUM);
}
void game()
{
    char MAP[ROW][COL] = {'0'};
	char show[ROW][COL] = { '0' };
	char status[ROW][COL] = {'0'};
	int notmine = ROW * COL - NUM;
	printf("游戏开始\n");
	generate(ROW,COL,NUM,MAP,show, status);//display(ROW, COL, show);display(ROW, COL, status);
	//display(ROW, COL, MAP);
	do {
		display(ROW, COL, show);
	} while (clear(ROW, COL,&notmine, MAP, show, status)&&(notmine));
	display(ROW, COL, MAP);
	if(notmine == 0)
	{
		printf("你赢了!\n");
	}
}
void test()
{
	int input = 0;
	do
	{
		menu();
		scanf("%d",&input);
		switch (input)
		{
		case(1):
			game();
			break;
		case(2):
			return 0;
			break;
		default:
			printf("输入错误\n");
		}
	} while (input!=2);
}
int main()
{
	test();
	return 0;
}