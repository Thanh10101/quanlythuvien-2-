#include<iostream>
#include<string>
#include<fstream>
#include<iomanip>
#include"DoHoa.h"
using namespace std;

struct datetime {
	int ngay;
	int thang;
	int nam;
};
typedef struct datetime DATETIME;

struct sach {
	int ma;
	string ten;
	string nxb;
	double gia;
	int nam;
	int page;
	DATETIME ngay;
	int status;
};
typedef struct sach SACH;

//khai báo cấu trúc 1 nnode sách
struct node {
	SACH data;
	struct node* next;
};
typedef struct node NODE;

struct list {
	NODE* head;
	NODE* tail;
};
typedef struct list LIST;
//Hàm khởi tạo danh sách liên kết đơn các sách
void InitList(LIST& l);
//hàm khởi tạo node
NODE* getNode(SACH s);
void AddHead(LIST& l, NODE* p);
void AddTail(LIST& l, NODE* p);
void doc_file_datetime(ifstream& filein, DATETIME& a);
void doc_1_quyen_sach(ifstream& filein, SACH& s);
void xuat(SACH& s);
void xuat_tat_ca_sach(list& l);
void doc_all_sach(ifstream& filein, LIST& l);
void ghi_1_quyen_sach(ofstream& fileout, SACH s);
void nhap_thong_tin_sach(SACH& s);
void giai_phong(LIST& l);
void quanly_sach();