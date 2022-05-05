#include<stdio.h>
#include<windows.h>
#include <conio.h>
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
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
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

char PrtWelcom(int flag) {

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
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
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

	if (flag == 0) {
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
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
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
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
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
	getch();
}

void Game_Start() {
	//printf("111");
}

int main() {
	int flag = 0;
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	PrtTitle();             //打印2048
	printf("\n\n");
	while (1) {
		char c = PrtWelcom(flag);     //打印主界面，返回值为键盘输入
		if (c == 27 || c == '4')                       //ESC
			exit(0);

		else if (c == '1')
			Game_Start();
		else if (c == '2')
			Keys();
		else if (c == '3')
			Rules();
		else {
			flag = 1;

		}
	}
	return 0;
}
