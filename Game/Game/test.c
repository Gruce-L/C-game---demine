#define _CRT_SECURE_NO_WARNINGS 1
/*
ɨ����Ϸ����
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
	//��Ų��úõ��׵���Ϣ
	char mine[ROWS][COLS] = { 0 };	//'0' - ������
	//����Ų�����׵���Ϣ
	char show[ROWS][COLS] = { 0 };	//'*' - δ�Ų�
	//��ʼ������
	InitBoard(mine, ROWS, COLS, '0');
	InitBoard(show, ROWS, COLS, '*');
	//��ӡ����
	//����Ҫ��ӡ11*11��������Ȧ��ֻ��ʾ�涨��9*9���̣�����ֻ�ǲ�����Χ����
	//DisPlayBoard(mine, ROW, COL);
	//DisPlayBoard(show, ROW, COL);
	//������
	SetMine(mine, ROW, COL);
	//DisPlayBoard(mine, ROW, COL);
	DisPlayBoard(show, ROW, COL);
	//�Ų���
	FindMine(mine, show, ROW, COL);
}

void test()
{
	int input = 0;
	srand((unsigned int)time(NULL));
	do
	{
		menu();
		printf("��ѡ��");
		scanf("%d", &input);

		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("�˳���Ϸ\n");
			break;
		default:
			printf("ѡ�����\n");
			break;
		}
	} while (input);
}

int main()
{
	test();

	return 0;
}