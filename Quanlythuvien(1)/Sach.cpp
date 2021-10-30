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
	
}
void nhap_thong_tin_sach(SACH &s,SACH& ss) {//can sua
	//doc_all_sach(filein, l);
	cout << "Nhap vao ma sach: ";
	cin >> ss.ma;
	if (s.ma == ss.ma) {
		cout << "ma sach bi trung";
	}
	else {
	cin.ignore();
	cout << "Nhap vao ten sach: ";
	getline(cin, ss.ten);
	cout << "Nhap vao nha xuat ban: ";
	getline(cin, ss.nxb);
	cout << "Nhap vao gia: ";
	cin >> ss.gia;
	cout << "Nhap vao nam: ";
	cin >> ss.nam;
	cout << "Nhap vao trang sach: ";
	cin >> ss.page;
	cout << "Nhap ngay nhap kho: ";
	cin >> ss.ngay.ngay >> s.ngay.thang >> s.ngay.nam;
	cout << "Nhap vao trang thai";
	cin >> ss.status;
	}
}
void ghi_1_quyen_sach(ofstream& fileout,SACH s, SACH ss) {
	nhap_thong_tin_sach(s,ss);
	fileout.open("Sach.txt", ios_base::app);
	fileout << endl;
	fileout << ss.ma << ", ";
	fileout << ss.ten << ", ";
	fileout << ss.nxb << ", ";
	fileout << ss.gia<< ", ";
	fileout << ss.nam << ", ";
	fileout << ss.page << ", ";
	fileout << ss.ngay.ngay << "/" << s.ngay.thang << "/" << s.ngay.nam << ", ";
	fileout << ss.status;
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
	cout << setw(10) << left << s.ma << setw(20) << left << s.ten << setw(20) << left << s.nxb;
	cout << setw(10) << left << s.gia<< setw(6) << left << s.nam << setw(10) << left << s.page;
	cout << setw(18) << left << s.status << setw(2) << s.ngay.ngay <<"/"<<s.ngay.thang<<"/"<<s.ngay.nam<< endl;
	textcolor(7);
}
void xuat_tat_ca_sach(list& l) {
	
	for (NODE* p = l.head; p != NULL; p=p->next) {
		xuat(p->data);
	}
	giai_phong(l);
	system("pause");
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
	SACH ss;
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
			cout << "\n\n\t\t\t\tThong tin sach co trong thu vien\n\n";
			textcolor(16);
			cout << setw(10) << left << "Ma sach" << setw(20) << left << "Ten sach" << setw(20) << left << "Nha xuat ban";
			cout << setw(10) << left << "Gia" << setw(6) << left << "Nam" << setw(10) << left << "Trang"  
				<< setw(18)<<left  << "Trang thai" << setw(20) << left << "Ngay nhap kho" << endl;
			textcolor(7);
			filein.open("Sach.txt", ios_base::in);
			doc_all_sach(filein, l);
			xuat_tat_ca_sach(l);
			filein.close();
			break;
		case 2:
			doc_all_sach(filein, l);
			ghi_1_quyen_sach(fileout,s, ss);
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
