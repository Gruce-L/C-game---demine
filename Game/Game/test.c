#define _CRT_SECURE_NO_WARNINGS 1
/*
扫雷游戏测试
*/
#include "game.h"

void menu()
{
	printf("********************\n");
	printf("***    1.play    ***\n");
	printf("***    0.exit    ***\n");
	printf("********************\n");
}

void game(){
	//存放布置好的雷的信息
	char mine[ROWS][COLS] = { 0 };	//'0' - 不是雷
	//存放排查出的雷的信息
	char show[ROWS][COLS] = { 0 };	//'*' - 未排查
	//初始化棋盘
	InitBoard(mine, ROWS, COLS, '0');
	InitBoard(show, ROWS, COLS, '*');
	//打印棋盘
	//不必要打印11*11中外面两圈，只显示规定的9*9棋盘，外面只是测试周围的雷
	//DisPlayBoard(mine, ROW, COL);
	//DisPlayBoard(show, ROW, COL);
	//布置雷
	SetMine(mine, ROW, COL);
	//DisPlayBoard(mine, ROW, COL);
	DisPlayBoard(show, ROW, COL);
	//排查雷
	FindMine(mine, show, ROW, COL);
}

void test()
{
	int input = 0;
	srand((unsigned int)time(NULL));
	do
	{
		menu();
		printf("请选择：");
		scanf("%d", &input);

		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("退出游戏\n");
			break;
		default:
			printf("选择错误\n");
			break;
		}
	} while (input);
}

int main()
{
	test();

	return 0;
}