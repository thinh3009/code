Dễ dàng sử dụng Drive của tôi thông qua các lối tắt … 
Trong những tuần tới, các mục trong nhiều thư mục sẽ được thay thế bằng lối tắt. Quyền truy cập vào các tệp và thư mục sẽ không thay đổi.Tìm hiểu thêm
#include<iostream>
#include<string>
#include<fstream>
#include<iomanip>

using namespace std;
struct sinh_vien
{
	string ma;
	string ten;
	string lop;
	float diemtb;
	string ngaysinh;

};
typedef sinh_vien SINHVIEN;

// ========== KHAI BÁO CẤU TRÚC 1 CÁI NODE ==========
struct node
{
	SINHVIEN* data;
	/*struct*/ node* pNext;
};
typedef struct node NODE;

struct list
{
	NODE* pHead;
	NODE* pTail;
};
typedef struct list LIST;

void KhoiTaoDanhSach(LIST& l)
{
	l.pHead = NULL;
	l.pTail = NULL;
}
//////////////////////////////////////////////////////////////////////////////////
NODE* middle(NODE* start, NODE* last)
{
	if (start == NULL)
		return NULL;
	NODE* slow = start;
	NODE* fast = start->pNext;
	while (fast != last)
	{
		fast = fast->pNext;
		if (fast != last)
		{
			slow = slow->pNext;
			fast = fast->pNext;
		}
	}
	return slow;
}


//vu
NODE* tim_kiemNhiPhan(NODE* head, string tim)
{
	NODE* start = head;
	NODE* last = NULL;
	do
	{
		NODE* mid = middle(start, last);
		if (mid == NULL)
			return NULL;
		if (mid->data->ma.compare(tim) == 0)
			return mid;
		else if (mid->data->ma.compare(tim) < 0)
			start = mid->pNext;
		else
			last = mid;
	} while (last == NULL || last != start);
	return NULL;
}

//vu
int Ktra_ma(LIST& l, string tim)
{
	NODE* pTemp = tim_kiemNhiPhan(l.pHead, tim);
	if (pTemp != NULL)
		return 0;
	else
		return 1;
}
//vu
void nhap_sv(SINHVIEN* sv, LIST& l) {
	cin.ignore();

	do
	{
		cout << "Nhap ma so sinh vien: ";
		getline(cin, sv->ma);
		if (Ktra_ma(l, sv->ma) == 0)
			cout << "MSSV da ton tai. Vui long nhap lai!\n";
	} while (Ktra_ma(l, sv->ma) == 0);
	
	cout << "\n\tnhap ten sinh vien: ";
	fflush(stdin);
	getline(cin, sv->ten);
	cout << "\n\tnhap lop: ";
	fflush(stdin);
	getline(cin, sv->lop);
	cout << ("\n\tnhap ngay sinh: ");
	fflush(stdin);
	getline(cin, sv->ngaysinh);
	fflush(stdin);

	do
	{
	check_point_again:
		cout << "Diem trung binh theo he so (0   -  5.0): ";
		cin >> sv->diemtb;
		if (sv->diemtb < 0 || sv->diemtb>5)
			cout << "Diem trung binh khong hop le. Vui long nhap lai!\n";
	} while (sv->diemtb < 0 || sv->diemtb>5);

}


NODE* KhoiTaoNode(LIST& l)
{
	SINHVIEN* sv = new SINHVIEN;
	nhap_sv(sv, l);
	NODE* p = new NODE;
	if (p == NULL)
	{
		cout << "\nCap phat that bai !";
		return 0;
	}
	p->data = sv;
	p->pNext = NULL; // khởi tạo node p nhưng node p chưa có liên kết đến node nào hết
	return p;
}
//mai hoang khanh
void xuat_dsSV(LIST l) {
	NODE* k = l.pHead;
	if (k == NULL) {
		cout << "\n\tdanh sach rong\n";
		return;
	}
	
	cout << setw(12) << right << "MSSV" << " |";
	cout << setw(20) << right << "Ho va ten" << " |";
	cout << setw(12) << right << "Lop" << " |";
	cout << setw(12) << right << "Ngay sinh" << " |";
	cout << setw(12) << right << "dtb" << " |";
	cout << endl;
	cout << setfill('-');
	cout << setw(76) << "-" << endl;

	while (k != NULL)
	{
		cout << setfill(' ');
		cout << setw(12) << right << k->data->ma;
		cout << setw(20) << right << k->data->ten;
		cout << setw(12) << right << k->data->lop;
		cout << setw(12) << right << k->data->ngaysinh;
		cout << setw(12) << right << k->data->diemtb;
		cout << endl;
		k = k->pNext;
	}

}




void xuat_NodeSV(NODE* k) {

	/*
	cout << setw(12) << right << "MSSV"<<" |";
	cout << setw(20) << right << "Ho va ten"<<" |";
	cout << setw(12) << right << "Lop"<<" |";
	cout << setw(12) << right << "Ngay sinh"<<" |";
	cout << setw(12) << right << "dtb"<<" |";
	cout << endl;
	cout << setfill('-');
	cout << setw(76) << "-" << endl;
	*/
	cout << "\n\t********************\n";
	cout << "\t\tma so sinh vien: " << k->data->ma << endl;
	cout << "\t\tten sinh vien: " << k->data->ten << endl;
	cout << "\t\tlop cua sinh vien: " << k->data->lop << endl;
	cout << "\t\tngay sinh sinh vien: " << k->data->ngaysinh << endl;
	cout << "\t\tdiem sinh vien: " << k->data->diemtb << endl;



}
///////////////////////////////////////////////////////////////////////////////////////
//thinh
void hoan_vi(SINHVIEN* a, SINHVIEN* b) {
	SINHVIEN tam = *a;
	*a = *b;
	*b = tam;
}


void sap_xep(LIST& l) {
	NODE* p, * q, * min;
	p = l.pHead;
	while (p != l.pTail) {
		min = p;
		q = p->pNext;
		while (q != NULL) {
			if (q->data->diemtb > p->data->diemtb)
				min = q;
			q = q->pNext;
		}
		hoan_vi(p->data, min->data);
		p = p->pNext;
	}
}




void sap_xep_Ma(LIST& l) {
	NODE* p, * q, * min;
	p = l.pHead;
	while (p != l.pTail) {
		min = p;
		q = p->pNext;
		while (q != NULL) {
			if (q->data->ma > p->data->ma)
				min = q;
			q = q->pNext;
		}
		hoan_vi(p->data, min->data);
		p = p->pNext;
	}
}





void them_cuoi(LIST& l, NODE* p) {
	if (l.pHead == NULL) {
		l.pHead = l.pTail = p;
	}
	else {
		l.pTail->pNext = p;
		l.pTail = p;//cap nhat lai p

	}
}






int CountSV(LIST l)
{
	NODE* pTemp = l.pHead;
	int count = 0;
	while (pTemp != NULL)
	{
		count++;
		pTemp = pTemp->pNext;
	}
	return count;
}

//vu
void Remove(LIST &l)
{
   	string xoa;
   	getline(cin, xoa);
	
	
	sap_xep_Ma(l);
	if(Ktra_ma(l,xoa) == 1)
		cout<<"Khong tim thay ma so "<<xoa<<" trong danh sach vui long nhap lai!!!!\n";
	else
	{
		NODE *pTemp = tim_kiemNhiPhan(l.pHead,xoa);
		if(pTemp!=NULL) 
		{
			if(pTemp == l.pHead)
			{
				l.pHead = pTemp->pNext;
				delete pTemp;
			}
			else
			{
				NODE *pTemp2 = l.pHead;
				while (pTemp2->pNext != pTemp)
				{
					pTemp2 = pTemp2->pNext;			
				}
				pTemp2->pNext = pTemp->pNext;
				delete pTemp;
			}
		}
	}
}
//phat
void tim_theo_ma(LIST l)
{
	string ma;
	cin.ignore();
	cout << "\n\tnhap ma so can tim: ";
	fflush(stdin);
	getline(cin, ma);
	for (NODE* k = l.pHead; k != NULL; k = k->pNext) {
		if (k->data->ma == ma) {
			xuat_NodeSV(k);
		}
	}
}


//phat
void sua(LIST &l)
{
	SINHVIEN  data;
	string sua;
	getline(cin,sua);
	NODE *pTemp = tim_kiemNhiPhan(l.pHead,sua);
	string ma;
	cin.ignore();
	fflush(stdin);
	getline(cin, ma);
	for (NODE* k = l.pHead; k != NULL; k = k->pNext) {
		if (k->data->ma == ma) {
			xuat_NodeSV(k);	
		}
	}
	    cout<<"----------------HO SO SINH VIEN-------"<<endl;
	    cout<<"Sinh vien: "<<pTemp->data->ten;
	    cout<<"\nDiem ban dau: "<<pTemp->data->diemtb;
	    cout<<"\nMa so ban ban dau: "<<pTemp->data->ma<<endl;
	    
	    
	    
	    int x;
	    cout<<"------------ NHAP LUA CHON  ---------"<<endl;
		cout<<"1.Sua ho va ten cua sinh vien"<<endl;
		cout<<"2.Sua diem so cua sinh vien"<<endl;
		cout<<"3.Sua ma cua sinh vien"<<endl;
	    cout<<"nhap lua chon cua ban "<<endl;
	    cout<<"-------------------------------------\n";
	    cin>>x;
	    
		if(x==1)
		{		
			cout<<"\nNhap lai ho va ten moi: ";
			cin.ignore();
			getline(cin,pTemp->data->ten);
			cout<<"Da sua ho va ten.\n";
			xuat_dsSV(l);	
		}
				
		    else if(x == 2 ){
				cout<<"\nNhap lai diem moi: ";
				cin.ignore();
				do
				{
					cin>>pTemp->data->diemtb;
					if (pTemp->data->diemtb < 0 || pTemp->data->diemtb>5){
						cout << "Diem trung binh khong hop le. Vui long nhap lai!\n"<<endl;
						cout<<" Hay nhap diem moi:";
					}
					else{
					
						cout<<"Da sua diem.\n";
						xuat_dsSV(l);
					}
				}while (pTemp->data->diemtb < 0 || pTemp->data->diemtb>5);
					
				

			}
		
			else if( x ==3 ){
				cout<<"\nNhap lai ma moi: ";
				cin.ignore();
				getline(cin,pTemp->data->ma);	
				do
				{
					//getline(cin,pTemp->data->ma);
					if (Ktra_ma(l, data.ma) == 1)
					cout << "MSSV da ton tai. Vui long nhap lai!\n";
					else{
						cout<<"Da sua ma.\n";
						xuat_dsSV(l);
					}
				} while (Ktra_ma(l, data.ma) == 0);
					
					
			}
}
		        
void ReadFile(LIST  &l)
{
    SINHVIEN d;
	char c;
	fstream sv("danhsachsvtt.txt", ios::in);
	if(sv)
	{
		while(!sv.eof())
		{
			sv>>d.ma;
			sv.get(c);
			getline(sv, d.ten, ',');
			sv>>d.ngaysinh;
			sv>>d.lop;
			sv>>d.diemtb;
		    NODE* sv = KhoiTaoNode(l);
			if(l.pHead==NULL)
			{
				l.pHead =l.pTail= sv;
			}
			else
			{
				sv->pNext=l.pHead;
				l.pHead=sv;
			}
		}
		sv.close();
	}
}


/*void WriteFile(SINHVIEN d, int count)
{
    fstream sv("danhsachsvtt.txt", ios::out | ios::app);
    sv<<d.ma<<' '<<d.ten<<','<<d.ngaysinh<<' '<<d.lop<<' '<<d.diemtb;
	if(count > 1)
		sv<<'\n';
    sv.close();
}*/


/*void Save(LIST l)
{

	remove("C:\\Users\\ASUS TUF\\Downloads\\danhsachsvtt.txt");
	int count = CountSV(l);
	NODE *ppt = l.pHead;
	while(ppt!= NULL)
	{
		WriteFile(ppt->data,count);
		count--;
		ppt = ppt->pNext;
	}
} */  
//mai hoang khanh
void Menu(LIST& l)
{
	int luachon;
	while (true)
	{
		//system("cls");
		cout << "\t\t\n||=========== MENU ==========||\n";
		cout << "\t\t\n||1.Nhap sinh vien-----------||\n";
		cout << "\t\t\n||2.Xuat danh sach-----------||\n";
		cout << "\t\t\n||3.Tim sinh vien------------||\n";
		cout << "\t\t\n||4.Sua sinh vien------------||\n";
		cout << "\t\t\n||5.Xoa sinh vien------------||\n";
		cout << "\t\t\n||6.Sap xep -----------------||\n";
		cout << "\t\t\n||0.Ket thuc-----------------||\n";
		cout << "\t\t\n||=========== END ===========||";

		cout << "\nNhap lua chon: ";
		cin >> luachon;
		if (luachon == 1)
		{
			int x;
			cout << "\nNhap so luong sinh vien can them: ";
			cin >> x;
			for (int i = 1; i <= x; i++) {
				cout << "\tsinh vien thu " << i << ":" << endl;
				NODE* p = KhoiTaoNode(l);
				them_cuoi(l, p);
			}

		}
		else if (luachon == 2)
		{
			cout << "\n\t\t=====Danh sach sinh vien=====\n";
			xuat_dsSV(l);
			system("pause");
		}

		else if (luachon == 3)
		{
			tim_theo_ma(l);
		}

		else if (luachon == 4)
		{
           	string t;
			cout << endl << "Nhap ma so sinh vien muon sua: ";
			getline(cin, t);
	     	sua(l);
		}

		else if (luachon == 5)
		{
			string xoa;
			cout << endl << "Nhap ma so sinh vien muon xoa: ";
			getline(cin, xoa);
			Remove(l);
			xuat_dsSV(l);
		}
	
   		else if (luachon == 6)
		{
			sap_xep(l);
			cout<<"da sap xep!!!";
		}

		else {
			cout << "cam on da dung chuong trinh!!";
			break;
		}
	}
}


int main()
{
	LIST l;
	KhoiTaoDanhSach(l);
	Menu(l);

	system("pause");
	return 0;
}