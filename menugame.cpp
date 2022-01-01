#include <iostream>
#include "mylib.h"
#include <string>
#define MAX 100
using namespace std;
int x = 50;
int y = 17;
//=============VẼ KHUNG GAME==============
void khung();
//=============BUILD MENU ĐỘNG==============
void box(int x, int y, int w, int h, int b_color, string ndung);
void main()
{
	gotoXY(32, 2);
	cout << "     _______..__   __.      ___       __  ___  _______      " << endl;
	gotoXY(32, 3);
	cout << "    /       ||  \\ |  |     /   \\     |  |/  / |   ____|    " << endl;
	gotoXY(32, 4);
	cout << "   |   (----`|   \\|  |    /  ^  \\    |  '  /  |  |__      " << endl;
	gotoXY(32, 5);
	cout << "    \\   \\    |  . `  |   /  /_\\  \\   |    <   |   __|     " << endl;
	gotoXY(32, 6);
	cout << ".----)   |   |  |\\   |  /  _____  \\  |  .  \\  |  |____    " << endl;
	gotoXY(32, 7);
	cout << "|_______/    |__| \\__| /__/     \\__\\ |__|\\__\\ |_______|" << endl;
	gotoXY(38, 9);
	cout << "  _______      ___      .___  ___.  _______" << endl;
	gotoXY(38, 10);
	cout << " /  _____|    /   \\     |   \\/   | |   ____|" << endl;
	gotoXY(38, 11);
	cout << "|  |  __     /  ^  \\    |  \\  /  | |  |__   " << endl;
	gotoXY(38, 12);
	cout << "|  | |_ |   /  /_\\  \\   |  |\\/|  | |   __|  " << endl;
	gotoXY(38, 13);
	cout << "|  |__| |  /  _____  \\  |  |  |  | |  |____ " << endl;
	gotoXY(38, 14);
	cout << " \\______| /__/     \\__\\ |__|  |__| |_______|" << endl;
	khung();
	//=============MENU ĐỘNG==============
	ShowCur(0);//Làm mất dấu nháy
	box(x, y, 20, 2, 75, "       START");
	box(x, y += 3, 20, 2, 75, "    INSTRUCTION");
	box(x, y += 3, 20, 2, 75, "       QUIT");
	_getch();
}
//=============VẼ KHUNG GAME==============
void khung()
{
	for (int x = 10; x <= 110; x++)
	{
		gotoXY(x, 1);
		cout << char(196);
		gotoXY(x, 28);
		cout << char(196);
	}
	for (int y = 1; y <= 28; y++)
	{
		gotoXY(10, y);
		cout << char(179);
		gotoXY(110, y);
		cout << char(179);
	}
	gotoXY(10, 1); cout << char(218);
	gotoXY(110, 1); cout << char(191);
	gotoXY(10, 28); cout << char(192);
	gotoXY(110, 28); cout << char(217);
}
//=============VẼ BOX==============
void box(int x, int y, int w, int h, int b_color, string ndung)
{
	textcolor(b_color);
	for (int iy = y + 1; iy <= y + h - 1; iy++)
	{
		for (int ix = x + 1; ix <= x + w - 1; ix++)
		{
			gotoXY(ix, iy);
			cout << " ";
		}
	}
	SetColor(7);
	gotoXY(x + 1, y + 1);
	cout << ndung;
	textcolor(1);
	if (h <= 1 || w <= 1)
		return;
	for (int ix = x; ix <= x + w; ix++)
	{
		gotoXY(ix, y);
		cout << char(196);
		gotoXY(ix, y + h);
		cout << char(196);
	}
	for (int iy = y; iy <= y + h; iy++)
	{
		gotoXY(x, iy);
		cout << char(179);
		gotoXY(x + w, iy);
		cout << char(179);
	}
	gotoXY(x, y); cout << char(218);
	gotoXY(x + w, y); cout << char(191);
	gotoXY(x, y + h); cout << char(192);
	gotoXY(x + w, y + h); cout << char(217);
}


