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
