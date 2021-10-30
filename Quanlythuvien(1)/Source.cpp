#include"DoHoa.h"
#include"xylyacc.h"
#include"Sach.h"
#include"Phieumuon.h"
#include<iomanip>

int main()
{
	resizeConsole(1000, 600);
	char a[100], p[100];
	int i = 0;
	bool menuchinh = true;
	Admin ad;
	int choose;
	mo_file(ad);
	while (i < 3) {
		Dang_Nhap(a, p);
		if (Dang_Nhap_Thanh_Cong(a, p, ad)) {
			while (menuchinh == true) {
				textcolor(19);
				cout << "Lua chon chuc nang" <<setw(20)<< endl;
				cout << "1.Quan ly sach" << endl;
				cout << "2.Quan ly phieu muon" << endl;
				cout << "Nhan nut bat ky de thoat" << endl;
				textcolor(7);
				cin >> choose;
				switch (choose) {
				case 1:
					quanly_sach();
					break;
				case 2:
					break;
				default:
					menuchinh = false;
					break;
				}
			}
			return 0;
		}
		else
		{
			cout << "dang nhap lai";
			if (i == 2) {
				return 0;
			}
			i++;
		}
	}
	system("pause");
	return 0;
}