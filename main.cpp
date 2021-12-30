#include <iostream>
#include "mylib.h"
#include <Windows.h>
#include <string>
#define MAX 100
using namespace std;

string name;
int toadox[MAX] = { 0 };
int toadoy[MAX] = { 0 };
int sl = 4; //CÓ THỂ ĐIỀU CHỈNH CHIỀU DÀI CỦA RẮN BAN ĐẦU
int xqua = -1;//KHỞI TẠO QUẢ
int yqua = -1;//KHỞI TẠO QUẢ

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

int main()
{
    return 0;
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
