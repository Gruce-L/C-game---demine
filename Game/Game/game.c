#define _CRT_SECURE_NO_WARNINGS 1
/*
ɨ����Ϸ
*/
#include "game.h"

void InitBoard(char board[ROWS][COLS], int rows, int cols, char set){
	int i = 0;
	int j = 0;
	for (i = 0; i < rows; i++){
		for (j = 0; j < cols; j++){
			board[i][j] = set;
		}
	}
}

void DisPlayBoard(char board[ROWS][COLS], int row, int col){
	int i = 0;
	int j = 0;
	for (i = 0; i <= col; i++){
		printf("%d ", i);
	}
	printf("\n");
	for (i = 1; i <= row; i++){
		printf("%d ", i);
		for (j = 1; j <= col; j++){
			printf("%c ", board[i][j]);
		}
		printf("\n");
	}
}

void SetMine(char mine[ROWS][COLS], int row, int col){
	int count = EASY_COUNT;
	while (count != 0)
	{
		int x = rand() % row + 1;
		int y = rand() % col + 1;

		if (mine[x][y] == '0'){
			mine[x][y] = '1';
			count--;
		}
	}
}

int GetMineCount(char mine[ROWS][COLS], int x, int y){
	//��λ�ȡ������Χ���ף��ַ�-'0'�������֣���Ӳ�Ϊ0
	return (mine[x - 1][y] +
		mine[x - 1][y - 1] +
		mine[x][y - 1] +
		mine[x + 1][y - 1] +
		mine[x + 1][y] +
		mine[x + 1][y + 1] +
		mine[x][y + 1] +
		mine[x - 1][y + 1] - 8 * '0');
}

void FindMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col){
	int x = 0;
	int y = 0;
	int win = 0;
	//9*9 - EAST_COUNT = 71
	while (win < row * col - EASY_COUNT)
	{
		printf("�������Ų�����꣺");
		scanf("%d%d", &x, &y);

		//һ��ֻ��ʾһ���������Ƿ�Ϊ��
		if (x >= 1 && x <= row && y >= 1 && y <= col){
			if (mine[x][y] == '1'){
				printf("���ź�������\n");
				DisPlayBoard(mine, row, col);
				break;
			}
			else
			{
				//��ȡ������Χ�׵ĸ���
				int count = GetMineCount(mine, x, y);
				show[x][y] = count + '0';		//����+'0'�������ֶ�Ӧ���ַ����֣�eg. 1 + '0' = '1'
				DisPlayBoard(show, row, col);
				win++;
			}
		}

		//�Ż���
			//һ��Ҳ��ʾ��Χ�������Ϣ�����ǵ���Χ��û���׵���Ϣ������ʾ���֣���ʲô������ʾ
			//x��y�����ף���Χ8������Ҳû���� - չ��
			//�ݹ鷽��

		else
		{
			printf("���������Խ�磬��������!\n");

		}
	}
	if (win == row*col - EASY_COUNT){
		printf("��ɹ��ˣ�\n");
		//DisPlayBoard(show, ROW, COL);
	}

}