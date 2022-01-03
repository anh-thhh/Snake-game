#include <iostream>
#include "mylib.h"
#include <string>
#include <Windows.h>
#define MAX 100
using namespace std;
//Khai báo biến
string name;
int toadox[MAX] = { 0 };
int toadoy[MAX] = { 0 };
int sl = 4; //CÓ THỂ ĐIỀU CHỈNH CHIỀU DÀI CỦA RẮN BAN ĐẦU
int xqua = -1;//KHỞI TẠO QUẢ
int yqua = -1;//KHỞI TẠO QUẢ
int x = 50;
int y = 17;
//=============VẼ KHUNG GAME==============
void khung();
//=============BUILD MENU ĐỘNG==============
void box(int x, int y, int w, int h, int b_color, string ndung);
//============================================================
void play();//Game
void ve_tuong();//Tường giới hạn của game rắn
void ve_khung_thong_tin();//Khung thông tin người chơi,
void tao_ran();//Khởi tạo rắn
void ve_ran();//Tạo hình rắn
void di_chuyen_ran(int x, int y);//Rắn di chuyển
void tao_qua();//Khỏi tạo quả
void ve_qua();//Tạo hình quả
bool ktra_ran_an_qua();//Kiểm tra trường hợp rắn ăn quả
void xuly_ran_an_qua(int& diem);//Xử lý rắn ăn quả: thân dài thêm 1 đốt và tăng điểm
bool ktra_ran_cham_than();//Kiểm tra rắn chạm thân
void khung_end_game();//Khung kết thúc game
void end_game(string name);//Xuất ra màn hình thông tin kết thúc game
bool game_over();//Các trường hợp xử thua để kết thúc game
//========================HÀM MAIN============================
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
	box(x, y, 20, 2, 75, "      1.START");
	box(x, y += 3, 20, 2, 75, "   2.INSTRUCTION");
	gotoXY(49, 23);
	int luachon;
	cout << "Enter your selection: ";
	cin >> luachon;
	int luachon2;
	if (luachon == 1)
	{
		system("cls");
		string name;
		for (int x = 28; x <= 110; x++)
		{
			gotoXY(x, 3);
			cout << "SNAKE GAME";
			break;
		}
		ve_khung_thong_tin();
		//Điểm
		for (int x = 62; x <= 110; x++)
		{
			gotoXY(80, 3);
			cout << "SCORE: ";
			break;
		}

		srand(time(NULL));//Hàm tạo hạt giống
		play();
		//khung_end_game();
		end_game(name);
	}
	else if (luachon == 2)
	{
		system("cls");
		khung();
		gotoXY(20, 14);
		cout << "- Uses the arrow keys to move." << endl;
		gotoXY(20, 15);
		cout << "- As the snake finds food, it eats the food, and thereby grows longer. " << endl;
		gotoXY(20, 16);
		cout << "- The game ends when the snake either moves off the screen or moves into itself." << endl;
		gotoXY(40, 19);
		cout << "Press 1 to start the SNAKE GAME: ";
		cin >> luachon2;
		if (luachon2 == 1)
		{
			system("cls");
			string name;
			for (int x = 28; x <= 110; x++)
			{
				gotoXY(x, 3);
				cout << "SNAKE GAME";
				break;
			}
			ve_khung_thong_tin();
			//Điểm
			for (int x = 62; x <= 110; x++)
			{
				gotoXY(x, 3);
				cout << "SCORE: ";
				break;
			}

			srand(time(NULL));//Hàm tạo hạt giống
			play();
			//khung_end_game();
			end_game(name);
		}
	}
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
void play()
{
	ShowCur(0);//Làm mất dấu nháy
	//=========BUILD GAME==========
	ve_tuong();
	tao_ran();
	tao_qua();
	ve_qua();
	//0: đi xuống
	//1: đi lên
	//2: đi qua phải
	//3: đi qua trái
	int check = 2;
	int diem = 0;
	int x = toadox[0];
	int y = toadoy[0];
	//=========SETTING GAME==========
	while (true)
	{
		//=========ClEAR DỮ LIỆU CŨ==========
		gotoXY(toadox[sl], toadoy[sl]);
		cout << " ";
		//================IN=================
		ve_ran();
		gotoXY(87, 3);
		cout << diem;
		//===========ĐIỀU KHIỂN RẮN==========
		if (_kbhit())
		{
			char c = _getch();
			if (c == -32)
			{
				c = _getch();
				if (c == 72 && check != 0)//khi đi lên kh đc đi ngược xuống
				{
					check = 1;//Đi lên
				}
				else if (c == 80 && check != 1)//khi đi xuống kh đc đi ngược lên
				{
					check = 0;//Đi xuống
				}
				else if (c == 75 && check != 2)//khi đi qua trái kh đc đi ngược qua phải
				{
					check = 3;//Đi qua trái
				}
				else if (c == 77 && check != 3)//khi đi qua phải kh đc đi ngược qua trái
				{
					check = 2;//Đi qua phải
				}
			}
		}
		//=============DI CHUYỂN=============
		if (check == 0)
		{
			y++;
		}
		else if (check == 1)
		{
			y--;
		}
		else if (check == 2)
		{
			x++;
		}
		else if (check == 3)
		{
			x--;
		}
		//================BIÊN===============
		if (game_over())
		{
			break;
		}
		//==============XỬ LÝ RẮN============
		xuly_ran_an_qua(diem);
		di_chuyen_ran(x, y);
		//==========TỐC ĐỘ DI CHUYỂN=========
		Sleep(100);
	}
	gotoXY(53, 16);
	cout << "YOUR SCORE IS " << diem ;
}
//========================END============================

//VẼ THIẾT KẾ GAME
void ve_khung_thong_tin()//KHUNG TÊN GAME + NAME
{
	//SNAKE GAME
	for (int x = 10; x <= 55; x++)
	{
		gotoXY(x, 1);
		cout << char(196);
		gotoXY(x, 5);
		cout << char(196);
	}
	for (int y = 1; y <= 5; y++)
	{
		gotoXY(10, y);
		cout << char(179);
		gotoXY(55, y);
		cout << char(179);
	}
	gotoXY(10, 1); cout << char(218);
	gotoXY(55, 1); cout << char(191);
	gotoXY(10, 5); cout << char(192);
	gotoXY(55, 5); cout << char(217);
	//NAME AND SCORE
	for (int x = 60; x <= 110; x++)
	{
		gotoXY(x, 1);
		cout << char(196);
		gotoXY(x, 5);
		cout << char(196);
	}
	for (int y = 1; y <= 5; y++)
	{
		gotoXY(60, y);
		cout << char(179);
		gotoXY(110, y);
		cout << char(179);
	}
	gotoXY(60, 1); cout << char(218);
	gotoXY(110, 1); cout << char(191);
	gotoXY(60, 5); cout << char(192);
	gotoXY(110, 5); cout << char(217);
}
void ve_tuong()//KHUNG PLAY SNAKE GAME
{
	//TƯỜNG NGANG
	for (int x = 10; x <= 110; x++)
	{
		gotoXY(x, 7);
		cout << char(196);
		gotoXY(x, 28);
		cout << char(196);
	}
	//TƯỜNG DỌC
	for (int y = 7; y <= 28; y++)
	{
		gotoXY(10, y);
		cout << char(179);
		gotoXY(110, y);
		cout << char(179);
	}
	gotoXY(10, 7); cout << char(218);
	gotoXY(110, 7); cout << char(191);
	gotoXY(10, 28); cout << char(192);
	gotoXY(110, 28); cout << char(217);
}
void tao_ran()//TẠO CON RẮN TRONG GAME
{
	int x_khoi_tao = 50;
	int y_khoi_tao = 18;
	for (int i = 0; i < sl; i++)
	{
		toadox[i] = x_khoi_tao--;
		toadoy[i] = y_khoi_tao;
	}
}
void ve_ran()//ctr home
{
	for (int i = 0; i < sl; i++)
	{
		gotoXY(toadox[i], toadoy[i]);
		if (i == 0)
		{
			cout << "O";
		}
		else
		{
			cout << "o";
		}
	}
}
void di_chuyen_ran(int x, int y)
{
	//Thêm x y vào toadox, toadoy
	for (int i = sl; i > 0; i--)
	{
		toadox[i] = toadox[i - 1];
		toadoy[i] = toadoy[i - 1];
	}
	toadox[0] = x;
	toadoy[0] = y;
}
bool ktra_ran_cham_than()
{
	for (int i = 1; i <= sl; i++)
	{
		if (toadox[0] == toadox[i] && toadoy[0] == toadoy[i])
		{
			return true;
		}
	}
	return false;
}
bool game_over()
{
	//Chạm tường là thua
	if (toadox[0] == 10 || toadox[0] == 110 || toadoy[0] == 7 || toadoy[0] == 28)
	{
		return true;
	}
	//Chạm đuôi
	return ktra_ran_cham_than();
}
bool ktra_ran_trung_qua()
{
	for (int i = 0; i < sl; i++)
	{
		if (xqua == toadox[i] && yqua == toadoy[i])
		{
			return true;
		}
	}
	return false;
}
void tao_qua()//Tạo quả nằm ở vị trí random
{
	do
	{
		xqua = rand() % (109 - 11 + 1) + 11;
		yqua = rand() % (27 - 8 + 1) + 8;
	} while (ktra_ran_trung_qua());
}
void ve_qua()//Vẽ quả
{
	gotoXY(xqua, yqua);
	cout << "O";
}
bool ktra_ran_an_qua()//Kiểm tra rắn có ăn quả hay không
{
	return (toadox[0] == xqua && toadoy[0] == yqua);
}
void xuly_ran_an_qua(int& diem)
{
	if (ktra_ran_an_qua())
	{
		sl++;//tăng thêm độ dài
		tao_qua();//tạo lại quả
		ve_qua();
		diem = diem + 10;
	}
}
void khung_end_game()
{
	for (int x = 40; x <= 80; x++)
	{
		gotoXY(x, 14);
		cout << char(196);
		gotoXY(x, 22);
		cout << char(196);
	}
	for (int y = 14; y <= 22; y++)
	{
		gotoXY(40, y);
		cout << char(179);
		gotoXY(80, y);
		cout << char(179);
	}
	gotoXY(40, 14); cout << char(218);
	gotoXY(80, 14); cout << char(191);
	gotoXY(40, 22); cout << char(192);
	gotoXY(80, 22); cout << char(217);
}
void end_game(string name)
{
	for (int x = 55; x <= 110; x++)
	{
		gotoXY(x, 15);
		cout << " GAME OVER ";
		break;
	}
}


