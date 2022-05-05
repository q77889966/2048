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
	COORD pos_1 = { 20,22 };
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hOut, BRIGHT_YELLOW);
}

void Rules() {                //打印游戏规则
	system("cls");
	printf("111");
}

void Game_Start() {
	printf("111");
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
			PrtWelcom(flag);
		}
	}
	return 0;
}
