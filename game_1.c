﻿#include<stdio.h>
#include<windows.h>
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
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hOut, pos);
	SetConsoleTextAttribute(hOut, BRIGHT_CYAN);
	printf("■■■   ■■■■   ■  ■     ■■■■");
	COORD pos_1 = { 17,3 };
	SetConsoleCursorPosition(hOut, pos_1);
	printf("    ■   ■    ■   ■  ■     ■    ■");
	COORD pos_2 = { 17,4 };
	SetConsoleCursorPosition(hOut, pos_2);
	printf("■■■   ■    ■   ■  ■     ■■■■");
	COORD pos_3 = { 17,5 };
	SetConsoleCursorPosition(hOut, pos_3);
	printf("■       ■    ■   ■■■■   ■    ■");
	COORD pos_4 = { 17,6 };
	SetConsoleCursorPosition(hOut, pos_4);
	printf("■■■   ■■■■       ■     ■■■■");
}

char PrtWelcom() {

}
int main() {

	PrtTitle();             //打印2048
	char c = PrtWelcom();     //打印主界面，返回值为键盘输入
	return 0;
}
