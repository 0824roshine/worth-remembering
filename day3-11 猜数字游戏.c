#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>    // 一 先得能玩儿，需要一个交互界面！
#include<stdlib.h>   // 将 Game 视作一个函数。
#include<time.h>
void menu()
{
	printf("********main menu********\n");
	printf("***  1.play  2.exit  ****\n");               //%100 可以让 一个很大的随机数变小。
	printf("*************************\n");
}
//RAND_MAX  // 0-32767之间；
void game()
{
	int player = 0;
	int unk = 0;     //  通过时间戳来获取随机数的起始点
	//srand((unsigned int)time(NULL));       // srand 的值得是变量，才能产生随机数。  不要多次调用。
	unk = rand()%100+1;   // srand 和 rand 函数在 lib中，这3 行可以生成一个随机数。
	printf("***GAME START!***\n");
	printf("请猜一个1-100的数\n");
	while (1)
	{
		scanf("%d", &player);
		if (player > unk)
			printf("猜大了!\n");      //
		else if(player <unk)
			printf("猜小了!\n");
		else
		{
			printf("猜对了!\n");
			break;
		}
	}
}
int main()
{
	int input = 0;
	srand((unsigned int)time(NULL));      // 

	do
	{
		menu();
		printf(" choose one ; ) "); // do while 因为至少执行一次。
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 2:
			printf("Game Over\n");
			break;
		default:
			printf("Input Error\n");
			break;
		}
	} while (input == 1);
    return 0;
}