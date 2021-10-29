#include"Sach.h"

void InitList(LIST& l) {
	l.head = NULL;
	l.tail = NULL;
}
NODE *getNode(SACH s) {
	NODE* p = new NODE();
	p->data = s;
	p->next = NULL;
	return p;
}
void AddHead(LIST& l, NODE* p) {
	if (l.head == NULL) {
		l.head = l.tail = p;
	}
	else 
	{
		p->next = l.head;
		l.head = p;
	}
}
void AddTail(LIST& l, NODE* p) {
	if (l.head == NULL) {
		l.head = l.tail = p;
	}
	else
	{
		l.tail->next = p;
		l.tail = p;
	}
}
//Đọc file ngày tháng năm
void doc_file_datetime(ifstream &filein,DATETIME &a) {
	filein >> a.ngay;
	filein.seekg(1, 1);
	filein >> a.thang;
	filein.seekg(1, 1);
	filein >> a.nam;
	filein.seekg(1, 1);
}
//Hàm đọc dữ liệu sinh viên từ file
void doc_1_quyen_sach(ifstream& filein, SACH& s) {
	filein.open("Sach.txt", ios_base::in);
	filein >> s.ma;
	filein.seekg(2, 1);
	getline(filein, s.ten,',');//nhap chuoi
	filein.seekg(1, 1);
	getline(filein, s.nxb,',');//nhap chuoi
	filein.seekg(1, 1);
	filein >> s.gia;
	filein.seekg(1, 1);
	filein >> s.nam;
	filein.seekg(1, 1);
	filein >> s.page;
	filein.seekg(1, 1);
	doc_file_datetime(filein,s.ngay);
	filein.seekg(1, 1);
	filein >> s.status;
	string x;
	getline(filein, x);
	filein.close();
}
void nhap_thong_tin_sach(SACH& s) {
	cout << "Nhap vao ma sach";
	cin >> s.ma;
	cin.ignore();
	cout << "Nhap vao ten sach";
	getline(cin, s.ten);
	cout << "Nhap vao nha xuat ban";
	getline(cin, s.nxb);
	cout << "Nhap vao gia";
	cin >> s.gia;
	cout << "Nhap vao nam";
	cin >> s.nam;
	cout << "Nhap vao trang sach";
	cin >> s.page;
	cout << "Nhap ngay nhap kho";
	cin >> s.ngay.ngay >> s.ngay.thang >> s.ngay.nam;
	cout << "Nhap vao trang thai";
	cin >> s.status;
}
void ghi_1_quyen_sach(ofstream& fileout, SACH s) {
	nhap_thong_tin_sach(s);
	fileout.open("Sach.txt", ios_base::app);
	fileout << endl;
	fileout << s.ma << ", ";
	fileout << s.ten << ", ";
	fileout << s.nxb << ", ";
	fileout << setprecision(3) << s.gia<< ", ";
	fileout << s.nam << ", ";
	fileout << s.page << ", ";
	fileout << s.ngay.ngay << "/" << s.ngay.thang << "/" << s.ngay.nam << ", ";
	fileout << s.status;
	fileout.close();
}
void doc_all_sach(ifstream& filein, LIST& l) {//co loi
	while (!filein.eof()) {
		SACH s;
		//Đọc thông tin 1 quyển sách
		doc_1_quyen_sach(filein,s);
		//Khởi tạo node
		NODE* p = getNode(s);
		AddTail(l, p);
	}

}

void xuat(SACH& s) {
	textcolor(12);
	cout << s.ma << endl;
	cout << s.ten << endl;
	cout << s.nxb << endl;
	cout << s.ngay.ngay << endl;
	cout << s.page << endl;
	cout << s.status << endl;
	textcolor(7);
}
void xuat_tat_ca_sach(list& l) {
	
	for (NODE* p = l.head; p != NULL; p=p->next) {
		xuat(p->data);
	}
	//giai_phong(l);
}
//Hàm giải phóng vùng nhớ cho danh sách liên kết
void giai_phong(LIST& l) {
	NODE* p = NULL;
	while (l.head != NULL) {
		p = l.head;
		l.head = l.head->next;
		delete(p);
	}
}
void quanly_sach() {
	int chon1;
	LIST l;
	SACH s;
	InitList(l);
	ifstream filein;
	ofstream fileout;
	bool menuconsach=true;
	while (menuconsach==true) {
	cout << "Lua chon chuc nang" << endl;
	cout << "1.Xem thong tin sach" << endl;
	cout << "2.Them sach" << endl;
	cout << "3.Xoa sach" << endl;
	cin >> chon1;
		switch (chon1)
		{
		case 1:
			doc_all_sach(filein, l);
			xuat_tat_ca_sach(l);
			break;
		case 2:
			//Them_Sach();
			break;
		case 3:
			//Xoa_Sach();
			break;
		default:
			menuconsach=false;
			break;
		}
	}
	
}
