#define _CRT_SECURE_NO_WARNINGS
#include"SearchMine.h"
void generate(int row, int col, int num, char map[ROW][COL], char themap[ROW][COL], char STatus[ROW][COL])
{
	int i = 0, j = 0, count = 0; int space = 0;
	int rorow = 0; int cocol = 0; int position = 0;
	space = row * col;
	int pos[100] = { 0 };
	int k = 0; int l = 0;
	char COPY[ROWS][COLS] = { '0' };
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			map[i][j] = '0';
			themap[i][j] = ' ';
			STatus[i][j] = '0';
		}
	}
	srand((int)time(0));
	for (/*size_t */count = 0; count < num; count++)
	{
		pos[count] = rand() % space;
	}
	for (count = 0; count < num; count++)
	{
		if (pos[count] == 0)
		{
			cocol = 0; rorow = 0;
		}
		else
		{
			cocol = pos[count] % col;//列
			if (cocol == 0)
			{
				cocol = col - 1;
				rorow = pos[count] / col - 1;
			}
			else
			{
				cocol--;
				rorow = pos[count] / col;
			}
		}
		map[rorow][cocol] = '*';
	}
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			COPY[i + 1][j + 1] = map[i][j];
		}
	}
	for (i = 1; i <= row; i++)
	{
		for (j = 1; j <= col; j++)
			if (COPY[i][j] != '*')
			{
				for (k = i - 1; k <= i + 1; k++)
				{
					for (l = j - 1; l <= j + 1; l++)
					{
						if (COPY[k][l] == '*')
							map[i - 1][j - 1]++;
					}
				}
			}
	}
}
void display(int Row, int Col, char Map[ROW][COL])
{
	int k = 0; int l = 0;
	printf("    ");
	for (l = 0; l < Col; l++)
	{
		if(l<9)
		printf("  %d ",l+1);
		else
		printf("  %d", l + 1);
	}
	printf("\n");
	for (k = 0; k < Row; k++)
	{
		printf("    ");
		for (l = 0; l < Col; l++)
		{
			printf("|---");
		}
		printf("|\n");
		for(l = 0; l < Col; l++)
		{
			if(l==0)
			{
				if (k < 9)
					printf("  %d ", k + 1);
				else
					printf(" %d ", k + 1);
			}
			printf("| %c ",Map[k][l]);
		}
		printf("|\n");
	}
	printf("    ");
		for (l = 0; l < Col; l++)
		{
			printf("|---");
		}
			printf("|\n");
}
int mini(int x, int y)
{
	if (x > y)
		return y;
	else
		return x;
}
int maxi(int g,int h)
{
	if (g > h)
		return g;
	else
		return h;
}
int clear(int roW, int coL,int *NOTmine ,char maP[ROW][COL],char shoW[ROW][COL], char Status[ROW][COL])
{
	int a = 0, b = 0, op = 0;//输入量
	int c = 0, d = 0;        //实际位置
	int aaa = 0, bbb = 0;
	int pp = 0, qq = 0;
	printf("请输入三个数字，用空格隔开，\n第____行第____列，对其进行____(1.鼠标左键 0.鼠标右键)操作\n");
	scanf("%d %d %d", &a, &b, &op);
	c = a - 1; d = b - 1;          // 实际位置的转化。
	if (Status[c][d] == '1')                     //对已经探索出来的区域无法操作
	{
		printf("操作错误,该位置探索过了，请重新输入\n");
		return 1;
	}
	if (op==1)
	{
		if (shoW[c][d] == '!')
		{
			printf("这里被标记了，换个位置或者对这里再次“点击右键”取消标记\n");//小旗子
			return 1;
		}
		if (maP[c][d] == '*')
		{
			printf("你踩雷了，游戏结束，祝下次好运\n");
			shoW[c][d] = maP[c][d];
			return 0;                                            // 踩到雷
		}
		else if ((maP[c][d] > '0') && (maP[c][d] < '9'))   //1-8，就单独显示出来
		{
			Status[c][d] = '1';                       //状态为已探索
			shoW[c][d] = maP[c][d];                     //显示
			*NOTmine = *NOTmine - 1;                             // 确认没有雷的地方-1；
		}
		else if((maP[c][d] == '0'))                      // 好麻烦，怎么实现‘铺展’呢。    如果是零，周围9个必然不是雷
		{
			pp = mini(c + 1, ROW-1);                     //铺展本质上应该是求，包含这个零的最大子区域。
			qq = mini(d + 1, COL-1);
			for (aaa = maxi(c - 1,0); aaa <= pp; aaa++)
			{
				for (bbb = maxi(d - 1,0); bbb <= qq; bbb++)
				{
					if (Status[aaa][bbb] != '1')
					{
						*NOTmine = *NOTmine - 1;
						Status[aaa][bbb] = '1';
						shoW[aaa][bbb] = maP[aaa][bbb];
					}
				}
			}
		return 1;
		}
	}
	else if(op ==0)
	{
		if (shoW[c][d] == '!')
		{
			printf("已取消（%d,%d）的标记\n", a, b);
			shoW[c][d] = ' ';
		}
		else
		{
			printf("标记了（%d,%d）\n",a,b);
			shoW[c][d] = '!';
		}
		return 1;
	}
	else
	{
		printf("操作错误,该位置探索过了，请重新输入\n");
		return 1;
	}

}
//void spread(int rOW, int cOL, int C,int D, int* Notmine, char mAP[ROW][COL], char shOW[ROW][COL], char statuS[ROW][COL])
//{
//	int e = 0,f =0;
//	int v = 0, n = 0;
//	e = mini(C + 1, ROW - 1);                     //铺展本质上应该是求，包含这个零的最大子区域。  日后也许会有好的算法。
//	f = mini(D + 1, COL - 1);
//	for (v= mini(C - 1, 0); v <= e; v++)
//	{
//		for (n = mini(D - 1, 0); n <=f; n++)
//		{
//			if (statuS[v][n] == '1')
//				break;
//			else
//			{
//				if (mAP[v][n] == '0')
//				{
//				    statuS[v][n] = '1';
//				    shOW[v][n] = '0';
//					*Notmine= *Notmine -1;
//					spread(ROW, COL, e, f, *Notmine, mAP, shOW, statuS);
//				}
//				else
//				{
//				    statuS[e][f] = '1';
//					shOW[e][f] = mAP[e][f];
//					*Notmine = *Notmine - 1;
//					}
//				}
//			}
//		}
//}