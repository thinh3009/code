#include<iostream>
#include<string>
#include<fstream>
#include<iomanip>

using namespace std;
struct sinh_vien
{
	string ma;
	string ten;
	float diemtb;

};
typedef sinh_vien SINHVIEN;

//khai bao cau truc node
struct node
{
	SINHVIEN* data;
	node* pNext;
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
	

	do
	{
	check_point_again:
		cout << "Diem trung binh theo he so (0->10): ";
		cin >> sv->diemtb;
		if (sv->diemtb < 0 || sv->diemtb>10)
			cout << "Diem trung binh khong hop le. Vui long nhap lai!\n";
	} while (sv->diemtb < 0 || sv->diemtb>10);

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

void xuat_dsSV(LIST l) {
	NODE* k = l.pHead;
	if (k == NULL) {
		cout << "\n\tdanh sach rong\n";
		return;
	}
	
	cout << setw(12) << right << "MSSV" << " |";
	cout << setw(20) << right << "Ho va ten" << " |";
	cout << setw(12) << right << "diem" << " |";
	cout << endl;
	cout << setfill('-');
	//cout << setw(76) << "-" << endl;

	while (k != NULL)
	{
		cout << setfill(' ');
		cout << setw(12) << right << k->data->ma;
		cout << setw(20) << right << k->data->ten;	
		cout << setw(12) << right << k->data->diemtb;
		cout << endl;
		k = k->pNext;
	}

}



void xuat_NodeSV(NODE* k) {

	
	cout << "\n\t********************";
	cout << "\n\tma so sinh vien: " << k->data->ma << endl;
	cout << "\n\tten sinh vien: " << k->data->ten << endl;
	cout << "\n\tdiem sinh vien: " << k->data->diemtb << endl;



}
///////////////////////////////////////////////////////////////////////////////////////

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
			NODE *pPre = NULL;
			if(pTemp == l.pHead)
			{
				l.pHead = pTemp->pNext;
				delete pTemp;
			}
			else if(pTemp -> pNext == NULL){
		        l.pTail = pPre;
		        pPre -> pNext = NULL;
		        delete pTemp;
		        pTemp = NULL;
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

void xuat_sv_duoi5(LIST &l){
	NODE* k = l.pHead;
	if (k == NULL) {
		cout << "\n\tdanh sach rong\n";
		return;
	}
	
	cout<<"\n\tdanh sach cac sinh vien co diem trung binh duoi 5 la!!\n\t";
	cout << setw(12) << right << "MSSV" << " |";
	cout << setw(20) << right << "Ho va ten" << " |";
	cout << setw(12) << right << "diem" << " |";
	cout << endl;
	cout << setfill('-');
	
	while (k != NULL)
	{
		if(k->data->diemtb<5){
			cout << setfill(' ');
			cout << setw(12) << right << k->data->ma;
			cout << setw(20) << right << k->data->ten;	
			cout << setw(12) << right << k->data->diemtb;
			cout << endl;
			k = k->pNext;
		}
	}
	
	
}



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

void Menu(LIST& l)
{
	int luachon;
	do{
		
		cout << "\t\t\n<>************** MENU **************<>\n";
		cout << "\t\t\n<>1.Nhap sinh vien------------------<>\n";
		cout << "\t\t\n<>2.Xuat danh sach------------------<>\n";
		cout << "\t\t\n<>3.Tim sinh vien-------------------<>\n";
		cout << "\t\t\n<>4.Xoa sinh vien-------------------<>\n";
		cout << "\t\t\n<>5.xuat sinh vien diem duoi 5------<>\n";
		cout << "\t\t\n<>0.Ket thuc------------------------<>\n";
		cout << "\t\t\n<>************** END ***************<>";
		cout<<"\nmoi ban nhap lua chon: ";
		cin>>luachon;
		switch(luachon){
			case 0:{
				cout<<"cam on da su dung chuong trinh!!";
				break;
			}
					
			case 1:{
				int x;
				cout << "\nNhap so luong sinh vien can them: ";
				cin >> x;
				for (int i = 1; i <= x; i++) {
					cout << "\tsinh vien thu " << i << ":" << endl;
					NODE* p = KhoiTaoNode(l);
					them_cuoi(l, p);
				}
				break;
			}		
			case 2:{
				cout << "\n\t\t=====Danh sach sinh vien=====\n";
				xuat_dsSV(l);
				system("pause");
				
				break;
			}
				
			case 3:{
				tim_theo_ma(l);
				
				break;
			}
				
				
		    case 4:{
		    	string xoa;
				cout << endl << "Nhap ma so sinh vien muon xoa: ";
				getline(cin, xoa);
				Remove(l);
				xuat_dsSV(l);
				
				break;
			}
			case 5:
				xuat_sv_duoi5(l);
				system("pause");
		    	break;
			default:{
				cout<<"\nNhap sai, vui long nhap lai!";
				
				break;
			}
				
		}	
	}while(luachon);

}


int main()
{
	LIST l;
	KhoiTaoDanhSach(l);
	Menu(l);

	system("pause");
	return 0;
}