#include"xylyacc.h"


void doc_file(fstream& filein, Admin& ad) {
	filein >> ad.acc;
	filein >> ad.pass;
}
void xuat(Admin ad) {
	cout << ad.acc << endl;
	cout << ad.pass << endl;
}
void mo_file(Admin& ad) {
	fstream filein;
	//Mở file nhớ đóng file
	filein.open("Admin.txt", ios_base::in);
	doc_file(filein, ad);
	filein.close();
}
void Dang_Nhap(char a[], char p[]) {
	textcolor(14);
	gotoxy(50, 5);
	cout << "* * * * * * * * * * * * * * * * * * * * *" << endl;
	gotoxy(50, 6);
	cout << "*            DANG NHAP HE THONG         *" << endl;
	gotoxy(50, 7);
	cout << "* * * * * * * * * * * * * * * * * * * * *" << endl;
	gotoxy(45, 9);
	cout << "\t\tUser    :"; cin >> a;
	//cout << endl;
	gotoxy(45, 10);
	cout << "\t\tPassword:"; cin >> p;
	cout << endl;
	textcolor(7);

}
bool Dang_Nhap_Thanh_Cong(char a[], char p[], Admin& ad) {
	int x = strcmp(a, ad.acc);
	int y = strcmp(p, ad.pass);
	if (x == 0 && y == 0) {

		return true;
	}
	else
		return false;
}
