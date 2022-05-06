#include <stdio.h>
#include <windows.h>
#include <conio.h>
#include <time.h>
#include <stdlib.h>
#include<stdbool.h>
#define	GREEN	FOREGROUND_GREEN	//2 前景深绿 0x02
#define	CYAN		FOREGROUND_GREEN|FOREGROUND_BLUE	//3 前景青
#define	RED		FOREGROUND_RED	//4 前景红
#define	MAGENTA	FOREGROUND_RED|FOREGROUND_BLUE	//5 前景洋红
#define	YELLOW	FOREGROUND_RED|FOREGROUND_GREEN	//6 前景黄
#define	WHITE	FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE	//7 前景白
#define	BRIGHT_BLUE		FOREGROUND_INTENSITY|FOREGROUND_BLUE	//9 前景亮蓝
#define	BRIGHT_GREEN		FOREGROUND_INTENSITY|FOREGROUND_GREEN	//10 前景亮绿
#define	BRIGHT_CYAN		FOREGROUND_INTENSITY|FOREGROUND_GREEN|FOREGROUND_BLUE	//11 前景亮青
#define	BRIGHT_RED		FOREGROUND_INTENSITY|FOREGROUND_RED	//12 前景亮红
#define	BRIGHT_MAGENTA	FOREGROUND_INTENSITY|FOREGROUND_RED|FOREGROUND_BLUE	//13 前景亮洋红
#define	BRIGHT_YELLOW		FOREGROUND_INTENSITY|FOREGROUND_RED|FOREGROUND_GREEN	//14 前景亮黄
#define	BRIGHT_WHITE FOREGROUND_INTENSITY|FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE //15 前景亮白

#define hOut GetStdHandle(STD_OUTPUT_HANDLE)

int BOX[4][4] = { {0},{0},{0},{0} };//游戏棋盘状态数组
long int count = 0, score = 0, start = 0;//已执行步数 存储游戏分数 游戏开始时间
bool flag = 1;
void Hidecursor()
{
	CONSOLE_CURSOR_INFO CURSOR_INFO = { 1,0 };
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &CURSOR_INFO);
}

void PrtTitle() {                    //打印2048
	COORD pos = { 17,2 };
	COORD pos_1 = { 17,3 };
	COORD pos_2 = { 17,4 };
	COORD pos_3 = { 17,5 };
	COORD pos_4 = { 17,6 };
	SetConsoleCursorPosition(hOut, pos);
	SetConsoleTextAttribute(hOut, BRIGHT_CYAN);
	printf("■■■   ■■■■   ■  ■     ■■■■");
	SetConsoleCursorPosition(hOut, pos_1);
	printf("    ■   ■    ■   ■  ■     ■    ■");
	SetConsoleCursorPosition(hOut, pos_2);
	printf("■■■   ■    ■   ■  ■     ■■■■");
	SetConsoleCursorPosition(hOut, pos_3);
	printf("■       ■    ■   ■■■■   ■    ■");
	SetConsoleCursorPosition(hOut, pos_4);
	printf("■■■   ■■■■       ■     ■■■■");
}

char PrtWelcom(int sym) {

	COORD pos_1 = { 13,9 };
	COORD pos_2 = { 13,10 };
	COORD pos_3 = { 13,11 };
	COORD pos_4 = { 13,12 };
	COORD pos_5 = { 13,13 };
	COORD pos_6 = { 13,14 };
	COORD pos_7 = { 13,15 };
	COORD pos_8 = { 13,16 };
	COORD pos_9 = { 13,17 };
	COORD pos_10 = { 13,18 };
	COORD pos_11 = { 13,19 };
	COORD pos_12 = { 13,20 };
	COORD pos_13 = { 23,12 };
	COORD pos_14 = { 23,17 };

	COORD final = { 20,22 };
	COORD final_1 = { 37,22 };
	COORD final_2 = { 47,22 };

	SetConsoleCursorPosition(hOut, pos_1);
	SetConsoleTextAttribute(hOut, BRIGHT_YELLOW);
	printf("==============================================");
	SetConsoleCursorPosition(hOut, pos_2);
	printf("||                                          ||");
	SetConsoleCursorPosition(hOut, pos_3);
	printf("||                                          ||");
	SetConsoleCursorPosition(hOut, pos_4);
	printf("||                                          ||");
	SetConsoleCursorPosition(hOut, pos_5);
	printf("||                                          ||");
	SetConsoleCursorPosition(hOut, pos_6);
	printf("||                                          ||");
	SetConsoleCursorPosition(hOut, pos_7);
	printf("||                                          ||");
	SetConsoleCursorPosition(hOut, pos_8);
	printf("||                                          ||");
	SetConsoleCursorPosition(hOut, pos_9);
	printf("||                                          ||");
	SetConsoleCursorPosition(hOut, pos_10);
	printf("||                                          ||");
	SetConsoleCursorPosition(hOut, pos_11);
	printf("||                                          ||");
	SetConsoleCursorPosition(hOut, pos_12);
	printf("==============================================");

	SetConsoleTextAttribute(hOut, RED);
	SetConsoleCursorPosition(hOut, pos_13);
	printf("1.开始游戏     2.按键说明");
	SetConsoleCursorPosition(hOut, pos_14);
	printf("3.游戏规则     4.退出-张峻宸");
	SetConsoleCursorPosition(hOut, final);
	SetConsoleTextAttribute(hOut, CYAN);

	if (sym == 0) {
		printf("请选择[1 2 3 4]:[ ]");
		SetConsoleCursorPosition(hOut, final_1);
	}
	else {
		printf("输入错误！请选择[1 2 3 4]:[ ]");
		SetConsoleCursorPosition(hOut, final_2);
	}
	char c;                    //键盘输入
	c = getch();
	return c;

}

void Keys() {                 //打印按键说明

	COORD pos_1 = { 19,22 };
	COORD pos_2 = { 19,24 };
	SetConsoleTextAttribute(hOut, BRIGHT_MAGENTA);
	SetConsoleCursorPosition(hOut, pos_1);
	printf("（1）↑、↓、←、→方向键进行游戏操作！");
	SetConsoleCursorPosition(hOut, pos_2);
	printf("（2）ESC键退出游戏");
	Hidecursor();
	fflush(stdin);
	getch();
	system("cls");
	main();
}

void Rules() {                //打印游戏规则
	system("cls");
	//printf("111");

	COORD pos_1 = { 27,3 };//游戏规则

	COORD pos_2 = { 12,5 };//画框
	COORD pos_3 = { 12,6 };
	COORD pos_4 = { 12,7 };
	COORD pos_5 = { 12,8 };
	COORD pos_6 = { 12,9 };
	COORD pos_7 = { 12,10 };
	COORD pos_8 = { 12,11 };
	COORD pos_9 = { 12,12 };
	COORD pos_10 = { 12,13 };
	COORD pos_11 = { 12,14 };
	COORD pos_12 = { 12,15 };
	COORD pos_13 = { 12,16 };
	COORD pos_14 = { 12,17 };

	COORD pos_15 = { 15,6 };//规则文字
	COORD pos_16 = { 15,8 };
	COORD pos_17 = { 15,10 };
	COORD pos_18 = { 15,12 };
	COORD pos_19 = { 15,14 };
	COORD pos_20 = { 15,16 };

	//HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hOut, BRIGHT_MAGENTA);
	SetConsoleCursorPosition(hOut, pos_1);
	printf("游戏规则");
	SetConsoleCursorPosition(hOut, pos_2);
	SetConsoleTextAttribute(hOut, GREEN);
	printf("========================================================");
	SetConsoleCursorPosition(hOut, pos_3);
	printf("||                                                    ||");
	SetConsoleCursorPosition(hOut, pos_4);
	printf("||                                                    ||");
	SetConsoleCursorPosition(hOut, pos_5);
	printf("||                                                    ||");
	SetConsoleCursorPosition(hOut, pos_6);
	printf("||                                                    ||");
	SetConsoleCursorPosition(hOut, pos_7);
	printf("||                                                    ||");
	SetConsoleCursorPosition(hOut, pos_8);
	printf("||                                                    ||");
	SetConsoleCursorPosition(hOut, pos_9);
	printf("||                                                    ||");
	SetConsoleCursorPosition(hOut, pos_10);
	printf("||                                                    ||");
	SetConsoleCursorPosition(hOut, pos_11);
	printf("||                                                    ||");
	SetConsoleCursorPosition(hOut, pos_12);
	printf("||                                                    ||");
	SetConsoleCursorPosition(hOut, pos_13);
	printf("||                                                    ||");
	SetConsoleCursorPosition(hOut, pos_14);
	printf("========================================================");

	SetConsoleCursorPosition(hOut, pos_15);
	SetConsoleTextAttribute(hOut, CYAN);
	printf("tip1: 玩家可以通过↑ ↓ ← →方向键来移动方块");

	SetConsoleCursorPosition(hOut, pos_16);
	SetConsoleTextAttribute(hOut, GREEN);
	printf("tip2: 按ESC退出游戏");

	SetConsoleCursorPosition(hOut, pos_17);
	SetConsoleTextAttribute(hOut, BRIGHT_YELLOW);
	printf("tip3: 玩家选择的方向上,若有相同的数字则合并");

	SetConsoleCursorPosition(hOut, pos_18);
	SetConsoleTextAttribute(hOut, BRIGHT_CYAN);
	printf("tip4: 每移动一步，空位随机出现一个2或4");

	SetConsoleCursorPosition(hOut, pos_19);
	SetConsoleTextAttribute(hOut, RED);
	printf("tip5: 棋盘被数字填满，无法进行有效移动，游戏失败");

	SetConsoleCursorPosition(hOut, pos_20);
	SetConsoleTextAttribute(hOut, YELLOW);
	printf("tip6: 棋盘上出现2048，游戏胜利");


	Hidecursor();
	fflush(stdin);
	getch();
	system("cls");
	main();
}

void PrtGameBox() {                 //打印4 * 4游戏棋盘框线以及游戏固定信息
	COORD pos_3 = { 13,3 };
	COORD pos_4 = { 13,4 };
	COORD pos_5 = { 13,5 };
	COORD pos_6 = { 13,6 };
	COORD pos_7 = { 13,7 };
	COORD pos_8 = { 13,8 };
	COORD pos_9 = { 13,9 };
	COORD pos_10 = { 13,10 };
	COORD pos_11 = { 13,11 };
	COORD pos_12 = { 13,12 };
	COORD pos_13 = { 13,13 };
	COORD pos_14 = { 13,14 };
	COORD pos_15 = { 13,15 };
	COORD pos_16 = { 13,16 };
	COORD pos_17 = { 13,17 };
	COORD pos_18 = { 13,18 };
	COORD pos_19 = { 13,19 };
	COORD pos_20 = { 13,20 };
	COORD pos_21 = { 13,21 };
	COORD pos_22 = { 13,22 };
	COORD pos_23 = { 13,23 };

	//HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);

	SetConsoleTextAttribute(hOut, BRIGHT_YELLOW);
	SetConsoleCursorPosition(hOut, pos_3);
	printf("-----------------------------------------");
	SetConsoleCursorPosition(hOut, pos_4);
	printf("|         |         |         |         |");
	SetConsoleCursorPosition(hOut, pos_5);
	printf("|         |         |         |         |");
	SetConsoleCursorPosition(hOut, pos_6);
	printf("|         |         |         |         |");
	SetConsoleCursorPosition(hOut, pos_7);
	printf("|         |         |         |         |");
	SetConsoleCursorPosition(hOut, pos_8);
	printf("-----------------------------------------");
	SetConsoleCursorPosition(hOut, pos_9);
	printf("|         |         |         |         |");
	SetConsoleCursorPosition(hOut, pos_10);
	printf("|         |         |         |         |");
	SetConsoleCursorPosition(hOut, pos_11);
	printf("|         |         |         |         |");
	SetConsoleCursorPosition(hOut, pos_12);
	printf("|         |         |         |         |");
	SetConsoleCursorPosition(hOut, pos_13);
	printf("-----------------------------------------");
	SetConsoleCursorPosition(hOut, pos_14);
	printf("|         |         |         |         |");
	SetConsoleCursorPosition(hOut, pos_15);
	printf("|         |         |         |         |");
	SetConsoleCursorPosition(hOut, pos_16);
	printf("|         |         |         |         |");
	SetConsoleCursorPosition(hOut, pos_17);
	printf("|         |         |         |         |");
	SetConsoleCursorPosition(hOut, pos_18);
	printf("-----------------------------------------");
	SetConsoleCursorPosition(hOut, pos_19);
	printf("|         |         |         |         |");
	SetConsoleCursorPosition(hOut, pos_20);
	printf("|         |         |         |         |");
	SetConsoleCursorPosition(hOut, pos_21);
	printf("|         |         |         |         |");
	SetConsoleCursorPosition(hOut, pos_22);
	printf("|         |         |         |         |");
	SetConsoleCursorPosition(hOut, pos_23);
	printf("-----------------------------------------");
}

void PrtNumC(int num, int x, int y) {//打印数字
	COORD num_00 = { 18,6 };
	COORD num_01 = { 28,6 };
	COORD num_02 = { 38,6 };
	COORD num_03 = { 48,6 };
	COORD num_10 = { 18,11 };
	COORD num_11 = { 28,11 };
	COORD num_12 = { 38,11 };
	COORD num_13 = { 48,11 };
	COORD num_20 = { 18,16 };
	COORD num_21 = { 28,16 };
	COORD num_22 = { 38,16 };
	COORD num_23 = { 48,16 };
	COORD num_30 = { 18,21 };
	COORD num_31 = { 28,21 };
	COORD num_32 = { 38,21 };
	COORD num_33 = { 48,21 };
	switch (num) {
	case 2:
		SetConsoleTextAttribute(hOut, BRIGHT_RED);
		break;
	case 4:
		SetConsoleTextAttribute(hOut, BRIGHT_CYAN);
		break;
	case 8:
		SetConsoleTextAttribute(hOut, BRIGHT_GREEN);
		break;
	case 16:
		SetConsoleTextAttribute(hOut, BRIGHT_YELLOW);
		break;
	case 32:
		SetConsoleTextAttribute(hOut, YELLOW);
		break;
	case 64:
		SetConsoleTextAttribute(hOut, GREEN);
		break;
	case 128:
		SetConsoleTextAttribute(hOut, RED);
		break;
	case 256:
		SetConsoleTextAttribute(hOut, CYAN);
		break;
	case 512:
		SetConsoleTextAttribute(hOut, GREEN);
		break;
	case 1024:
		SetConsoleTextAttribute(hOut, BRIGHT_BLUE);
		break;
	case 2048:
		SetConsoleTextAttribute(hOut, WHITE);
		break;
	}
	switch (x) {
	case 0:
		switch (y) {
		case 0:
			SetConsoleCursorPosition(hOut, num_00);
			printf("    ");
			SetConsoleCursorPosition(hOut, num_00);
			break;
		case 1:
			SetConsoleCursorPosition(hOut, num_01);
			printf("    ");
			SetConsoleCursorPosition(hOut, num_01);
			break;
		case 2:
			SetConsoleCursorPosition(hOut, num_02);
			printf("    ");
			SetConsoleCursorPosition(hOut, num_02);
			break;
		case 3:
			SetConsoleCursorPosition(hOut, num_03);
			printf("    ");
			SetConsoleCursorPosition(hOut, num_03);
			break;
		}
		break;
	case 1:
		switch (y) {
		case 0:
			SetConsoleCursorPosition(hOut, num_10);
			printf("    ");
			SetConsoleCursorPosition(hOut, num_10);
			break;
		case 1:
			SetConsoleCursorPosition(hOut, num_11);
			printf("    ");
			SetConsoleCursorPosition(hOut, num_11);
			break;
		case 2:
			SetConsoleCursorPosition(hOut, num_12);
			printf("    ");
			SetConsoleCursorPosition(hOut, num_12);
			break;
		case 3:
			SetConsoleCursorPosition(hOut, num_13);
			printf("    ");
			SetConsoleCursorPosition(hOut, num_13);
			break;
		}
		break;
	case 2:
		switch (y) {
		case 0:
			SetConsoleCursorPosition(hOut, num_20);
			printf("    ");
			SetConsoleCursorPosition(hOut, num_20);
			break;
		case 1:
			SetConsoleCursorPosition(hOut, num_21);
			printf("    ");
			SetConsoleCursorPosition(hOut, num_21);
			break;
		case 2:
			SetConsoleCursorPosition(hOut, num_22);
			printf("    ");
			SetConsoleCursorPosition(hOut, num_22);
			break;
		case 3:
			SetConsoleCursorPosition(hOut, num_23);
			printf("    ");
			SetConsoleCursorPosition(hOut, num_23);
			break;
		}
		break;
	case 3:
		switch (y) {
		case 0:
			SetConsoleCursorPosition(hOut, num_30);
			printf("    ");
			SetConsoleCursorPosition(hOut, num_30);
			break;
		case 1:
			SetConsoleCursorPosition(hOut, num_31);
			printf("    ");
			SetConsoleCursorPosition(hOut, num_31);
			break;
		case 2:
			SetConsoleCursorPosition(hOut, num_32);
			printf("    ");
			SetConsoleCursorPosition(hOut, num_32);
			break;
		case 3:
			SetConsoleCursorPosition(hOut, num_33);
			printf("    ");
			SetConsoleCursorPosition(hOut, num_33);
			break;
		}
		break;
	}
	if (BOX[x][y] == 0)
		printf("    ");
	else {
		printf("%d", BOX[x][y]);
	}
}

int Count() {
	int i, j, amount = 0;
	for (i = 0; i < 4; i++) {
		for (j = 0; j < 4; j++)
			if (BOX[i][j] != 0)
				amount++;
	}
	return amount;
}

void random() {          //随机数生成
	srand((unsigned)time(NULL));
	int i, j, num;
	int a[2] = { 2,4 };
	while (1) {
		i = rand() % 4;
		j = rand() % 4;
		num = rand() % 2;
		if (BOX[i][j] == 0) {
			BOX[i][j] = a[num];
			break;
		}
		else if (Count() == 16)
			break;
	}
}

void left()
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 1, k = 0; j < 4; j++)
		{
			if (BOX[i][j] > 0) /* 找出k后⾯第⼀个不为空的项，下标为j，之后分三种情况 */
			{
				if (BOX[i][k] == BOX[i][j]) /* 情况1：k项和j项相等，此时合并⽅块并计分 */
				{
					score += BOX[i][k++] <<= 1;
					BOX[i][j] = 0;
					flag = 1; /* 需要⽣成随机数和刷新界⾯ */
				}
				else if (BOX[i][k] == 0) /* 情况2：k项为空，则把j项赋值给k项，相当于j⽅块移动到k⽅块 */
				{
					BOX[i][k] = BOX[i][j];
					BOX[i][j] = 0;
					flag = 1;
				}
				else /* 情况3：k项不为空，且和j项不相等，此时把j项赋值给k+1项，相当于移动到k+1的位置 */
				{
					BOX[i][++k] = BOX[i][j];
					if (j != k) /* 判断j项和k项是否原先就挨在⼀起，若不是则把j项赋值为空（值为0） */
					{
						BOX[i][j] = 0;
						flag = 1;
					}
				}
			}
		}
	}
}

void right()
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 2, k = 3; j >= 0; j--)
		{
			if (BOX[i][j] > 0)
			{
				if (BOX[i][k] == BOX[i][j])
				{
					score += BOX[i][k--] <<= 1;
					BOX[i][j] = 0;
					flag = 1;
				}
				else if (BOX[i][k] == 0)
				{
					BOX[i][k] = BOX[i][j];
					BOX[i][j] = 0;
					flag = 1;
				}
				else
				{
					BOX[i][--k] = BOX[i][j];
					if (j != k)
					{
						BOX[i][j] = 0;
						flag = 1;
					}
				}
			}
		}
	}
}

void up() {
	/* 仿照左移操作，区别仅仅是⾏列互换后遍历 */
	for (int i = 0; i < 4; i++)
	{
		for (int j = 1, k = 0; j < 4; j++)
		{
			if (BOX[j][i] > 0)
			{
				{
					if (BOX[k][i] == BOX[j][i])
					{
						score += BOX[k++][i] <<= 1;
						BOX[j][i] = 0;
						flag = 1;
					}
					else if (BOX[k][i] == 0)
					{
						BOX[k][i] = BOX[j][i];
						BOX[j][i] = 0;
						flag = 1;
					}
					else
					{
						BOX[++k][i] = BOX[j][i];
						if (j != k)
						{
							BOX[j][i] = 0;
							flag = 1;
						}
					}
				}
			}
		}
	}
}

void down()
{
	/* 仿照左移操作，区别仅仅是⾏列互换后遍历，且j和k都反向遍历 */
	for (int i = 0; i < 4; i++)
	{
		for (int j = 2, k = 3; j >= 0; j--)
		{
			if (BOX[j][i] > 0)
			{
				if (BOX[k][i] == BOX[j][i])
				{
					score += BOX[k--][i] <<= 1;
					BOX[j][i] = 0;
					flag = 1;
				}
				else if (BOX[k][i] == 0)
				{
					BOX[k][i] = BOX[j][i];
					BOX[j][i] = 0;
					flag = 1;
				}
				else
				{
					BOX[--k][i] = BOX[j][i];
					if (j != k)
					{
						BOX[j][i] = 0;
						flag = 1;
					}
				}
			}
		}
	}
}

void ClearBox() {
	int i, j;
	for (i = 0; i < 4; i++) {
		for (j = 0; j < 4; j++)
			BOX[i][j] = 0;
	}
	count = 0, score = 0, start = 0;
}

int Max() {//遍历数组，查找最大值
	int i, j, max = 0;
	for (i = 0; i < 4; i++) {
		for (j = 0; j < 4; j++)
			if (BOX[i][j] > max)
				max = BOX[i][j];
	}
	return max;
}

void Final() {
	COORD pos_1 = { 58,18 };
	SetConsoleCursorPosition(hOut, pos_1);
	SetConsoleTextAttribute(hOut, BRIGHT_RED);
	printf("我要重新玩一局-------1   不玩了，退出吧！-------2/Esc");

	ClearBox();
}

void PrtWin() {
	COORD pos_1 = { 56,6 };
	COORD pos_2 = { 56,7 };
	COORD pos_3 = { 56,8 };
	COORD pos_4 = { 56,9 };
	COORD pos_5 = { 56,10 };
	COORD pos_6 = { 56,11 };
	COORD pos_7 = { 56,12 };

	COORD pos_8 = { 66,14 };

	SetConsoleTextAttribute(hOut, GREEN);
	SetConsoleCursorPosition(hOut, pos_1);
	printf("■           ■           ■ ■■■■■ ■          ■");
	SetConsoleCursorPosition(hOut, pos_2);
	printf(" ■         ■ ■        ■      ■     ■■        ■");
	SetConsoleCursorPosition(hOut, pos_3);
	printf("  ■       ■   ■      ■       ■     ■  ■      ■");
	SetConsoleCursorPosition(hOut, pos_4);
	printf("   ■     ■     ■    ■        ■     ■    ■    ■");
	SetConsoleCursorPosition(hOut, pos_5);
	printf("    ■   ■       ■  ■         ■     ■      ■  ■");
	SetConsoleCursorPosition(hOut, pos_6);
	printf("     ■ ■         ■■          ■     ■        ■■");
	SetConsoleCursorPosition(hOut, pos_7);
	printf("      ■            ■       ■■■■■ ■          ■");
	SetConsoleCursorPosition(hOut, pos_8);
	SetConsoleTextAttribute(hOut, BRIGHT_MAGENTA);
	printf("胜利啦，你真棒！！！");

}


void GameOver() {
	while (1) {
		printf("over");
		getch();
	}
}

int Check_Over() {

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (BOX[i][j] == BOX[i][j + 1] || BOX[j][i] == BOX[j + 1][i])
			{
				return 0;
			}
		}
	}
	return 1;
}



void Game_Start() {
	int i, j, max;
	time_t time_start, time_now;
	char c, a;

	system("cls");

	COORD pos_1 = { 14,2 };
	COORD pos_2 = { 40,2 };
	COORD pos_24 = { 40,24 };
	COORD pos_25 = { 16,24 };
	PrtGameBox();

	time_start = time(NULL);

	while (1) {
		SetConsoleTextAttribute(hOut, BRIGHT_CYAN);
		SetConsoleCursorPosition(hOut, pos_1);
		printf("游戏分数: %ld", score);

		if (flag == 0)
			count--;

		SetConsoleTextAttribute(hOut, BRIGHT_MAGENTA);
		SetConsoleCursorPosition(hOut, pos_2);
		printf("执行步数: %ld", count);

		SetConsoleTextAttribute(hOut, GREEN);
		SetConsoleCursorPosition(hOut, pos_24);
		printf("已用时： %ld", start);
		if (Count() != 16 && flag == 1) {
			random();
			flag = 0;
		}
		for (i = 0; i < 4; i++) {
			for (j = 0; j < 4; j++)
				PrtNumC(BOX[i][j], i, j);
		}

		Hidecursor();
		fflush(stdin);


		time_now = time(NULL);
		start = time_now - time_start;


		if (Max() == 64) {
			PrtWin();
			Final();
			Game_Start();
		}
		else if (Check_Over()) {
			if (Count() == 16)
				GameOver();
		}
		while (1) {
			c = getch();
			if (c == 27) {
				SetConsoleTextAttribute(hOut, RED);
				SetConsoleCursorPosition(hOut, pos_25);
				printf("确定退出游戏吗? (Y/N)");
				while (1) {
					a = getch();
					if (a == 'y' || a == 'Y') {
						system("cls");
						ClearBox();
						main();
						break;
					}
					else if (a == 'n' || a == 'N') {
						SetConsoleCursorPosition(hOut, pos_25);
						printf("                      ");
						Hidecursor();
						fflush(stdin);
						break;
					}
				}

			}
			else if (c == 80) {//下
				down();
				break;
			}
			else if (c == 72) {//上
				up();
				break;
			}
			else if (c == 75) {//左
				left();
				break;
			}
			else if (c == 77) {//右
				right();
				break;
			}
		}
		count++;
	}
	//printf("111");
}

int main() {
	fflush(stdin);
	SetConsoleTitle("2 0 4 8 游 戏");
	int sym = 0;
	//HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	PrtTitle();             //打印2048
	printf("\n\n");
	while (1) {
		char c = PrtWelcom(sym);     //打印主界面，返回值为键盘输入
		if (c == 27 || c == '4')                       //ESC
			exit(0);

		else if (c == '1')
			Game_Start();
		else if (c == '2')
			Keys();
		else if (c == '3')
			Rules();
		else {
			sym = 1;

		}
	}
	return 0;
}
