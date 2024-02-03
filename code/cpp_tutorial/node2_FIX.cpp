#include<iostream>
#include<string>
#include<iomanip>
#include<conio.h>
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




struct node
{
	SINHVIEN* data;
	struct node* pNext;
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

typedef NODE* ptrNODE;

ptrNODE nodegiua(ptrNODE Nodedau, ptrNODE Nodecuoi)
{
	if (Nodedau == NULL)
		return NULL;
	ptrNODE sll = Nodedau;
	ptrNODE slf = Nodedau->pNext;




	while (slf != Nodecuoi)
	{
		slf = slf->pNext;
		if (slf != Nodecuoi)
		{
			sll = sll->pNext;
			slf = slf->pNext;
		}
	}
	return sll;
}


ptrNODE BinarySearch(ptrNODE head, string tim)
{
	ptrNODE Nodedau = head;
	ptrNODE Nodecuoi = NULL;
	do
	{
		ptrNODE mid = nodegiua(Nodedau, Nodecuoi);
		if (mid == NULL)
			return NULL;
		if (mid->data->ma.compare(tim) == 0)
			return mid;
		else if (mid->data->ma.compare(tim) < 0)
			Nodedau = mid->pNext;
		else
			Nodecuoi = mid;
	} while (Nodecuoi == NULL || Nodecuoi != Nodedau);
	return NULL;
}



int CheckMSSV(LIST& l, string tim)
{
	NODE*
    pTemp =  BinarySearch(l.pHead, tim);
	if (pTemp != NULL)
		return 0;
	else
		return 1;
}


void nhap_sv(SINHVIEN* sv, LIST &l) {
	cin.ignore();
	do
	{
		cout << "Nhap ma so sinh vien: ";
		getline(cin, sv->ma);
		if (CheckMSSV(l, sv->ma) == 0)
			cout << "MSSV da ton tai. Vui long nhap lai!\n";
	} while (CheckMSSV(l, sv->ma) == 0);
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
		cout<<"Diem trung binh (0   -  5.0): ";
		cin>>sv->diemtb;
		if(sv->diemtb<0 || sv->diemtb>5)
			cout<<"Diem trung binh khong hop le. Vui long nhap lai!\n";
	}while(sv->diemtb<0 || sv->diemtb>5);

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
	p->pNext = NULL;
	return p;
}


//them node vao cuoi ds
void them_cuoi(LIST& l, NODE* p) {
	if (l.pHead == NULL) {
		l.pHead = l.pTail = p;
	}
	else {
		l.pTail->pNext = p;
		l.pTail = p;//cap nhat lai p

	}
}


void xuat_dsSV(LIST l) {
	NODE* k = l.pHead;
	if (k == NULL) {
		cout << "\n\tdanh sach rong\n";
		return;
	}
	cout << setw(12) << left << "MSSV" << "||   ";
	cout << setw(18) << left << "Ho va ten" << "||  ";
	cout << setw(12) << left << "Lop" << "||  ";
	cout << setw(12) << left << "Ngay sinh" << "||  ";
	cout << setw(12) << left << "dtb" << "||   ";
	cout << endl;
	cout << setfill('_');
	cout << setw(78) << "_" << endl;

	for (NODE* k = l.pHead; k != NULL; k = k->pNext) {
		cout << setfill(' ');
		cout << setw(12) << left << k->data->ma;
		cout << setw(18) << "|" << left << k->data->ten;
		cout << setw(12) << "|" << left << k->data->lop;
		cout << setw(12) << "|" << left << k->data->ngaysinh;
		cout << setw(12) << "|" << left << k->data->diemtb;
	}

}

//show node sinh vien
void xuat_NodeSV(NODE* k) {
	cout << "\n\t********************\n";
	cout << "\t\tma so sinh vien: " << k->data->ma << endl;
	cout << "\t\tten sinh vien: " << k->data->ten << endl;
	cout << "\t\tlop cua sinh vien: " << k->data->lop << endl;
	cout << "\t\tngay sinh sinh vien: " << k->data->ngaysinh << endl;
	cout << "\t\tdiem sinh vien: " << k->data->diemtb << endl;

}
//tim sinh vien
/*void tim_theo_ten(LIST l){
	string ten;
	cin.ignore();
	cout<<"\n\tnhap ten can tim: ";
	fflush(stdin);
	getline(cin, ten);
	for(NODE *k=l.pHead;k!=NULL;k=k->pNext){
		if(k->data->ten==ten){
			xuat_NodeSV(k);
		}
	}
}

void tim_theo_lop(LIST l){
	string lop;
	cout<<"\n\tnhap lop can tim: ";
	getline(cin, lop);
	for(NODE *k=l.pHead;k!=NULL;k=k->pNext){
		if(k->data->lop==lop){
			xuat_NodeSV(k);
		}
	}
}*/

void tim_theo_ma(LIST l) {
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


//sua thong tin sinh vien
// void sua_ten(list &l){
// 	string ten;
// 	cout<<"\n\tnhap ten sinh vien can sua: ";
// 	getline(cin,ten);
// 	for(NODE *k=l.pHead;k!=NULL;k=k->pNext){
// 		if(k->data->ten==ten){
// 			cout<<"\n\tsua ten sinh vien: "<<ten<<endl;
// 			nhap_sv(k->data);
// 			xuat_dsSV(l);
// 		}
// 	}
// }

// void sua_ngaysinh(LIST &l){
// 	string ngaysinh;
// 	cout<<"\n\tnhap ngay sinh can sua: ";
// 	getline(cin,ngaysinh);
// 	for(NODE *k=l.pHead;k!=NULL;k=k->pNext){
// 		if(k->data->ngaysinh==ngaysinh){
// 			cout<<"\n\tsua sinh vien co ngay sinh "<<ngaysinh<<" la: ";
// 			getline(cin,k->data->ngaysinh);
// 			cout<<"\n\tsua thanh cong!!!";
// 		}
// 	}
// }
void sua_diem(LIST& l) {
	float diem;
	cout << "\n\tnhap diem can sua: ";
	cin >> diem;
	for (NODE* k = l.pHead; k != NULL; k = k->pNext) {
		if (k->data->diemtb == diem) {
			cout << "\n\tsua sinh vien co diem " << diem << " la: ";
			cin >> k->data->diemtb;
			cout << "\n\tsua thanh cong!!!";
		}
	}

}
void xoa_cuoi(LIST &l){
    if(l.pHead ==NULL){
        return;
    }
    //duyet tu dau den ke cuoi
    for(NODE *k=l.pHead;k!=NULL;k=k->pNext){
        //tim ke cuoi
        if(k->pNext==l.pTail){
            delete l.pTail;//xoa ptu cuoi
            k->pNext==NULL;//cho con tro den pnext
            l.pTail=k;//cap nhat lai l.ptail
            return;

        }
    }
}

void hoan_vi(SINHVIEN *a, SINHVIEN *b){
    SINHVIEN tam= *a;
    *a=*b;
    *b=tam;
}

void sap_xep(LIST &l){
    NODE *p, *q,*min;
    p=l.pHead;
    while(p!=l.pTail){
        min=p;
        q=p->pNext;
        while(q!=NULL){
            if(q->data->diemtb>p->data->diemtb)
                min=q;
            q=q->pNext;
        }
        hoan_vi(p->data,min->data);
        p=p->pNext;
    }
}


void sap_xep_Ma(LIST &l){
    NODE *p, *q,*min;
    p=l.pHead;
    while(p!=l.pTail){
        min=p;
        q=p->pNext;
        while(q!=NULL){
            if(q->data->ma>p->data->ma)
                min=q;
            q=q->pNext;
        }
        hoan_vi(p->data,min->data);
        p=p->pNext;
    }
}





int CountSV(LIST l)
{
	NODE *pTemp = l.pHead;
	int count = 0; 
	while(pTemp != NULL)
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
	if(CheckMSSV(l,xoa) == 1)
		cout<<"Khong tim thay ma so "<<xoa<<" trong danh sach\n";
	else
	{
		NODE *pTemp = BinarySearch(l.pHead,xoa);
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
		cout<<"Da xoa ma so "<<xoa<<" ra khoi danh sach\n";
	}
	
}

void Menu(LIST& l)
{
	int luachon;
	while (true)
	{
		//system("cls");
		cout << "\t\t\n||=========== MENU ==========||\n";
		cout << "\t\t\n||1.Nhap sinh vien-----------||\n";
		cout << "\t\t\n||2.Xuat danh sach-----------||\n";
		cout << "\t\t\n||3.Tim ma sinh vien---------||\n";
		cout << "\t\t\n||4.Sua diem sinh vien-------||\n";
		cout << "\t\t\n||5.Xoa sinh vien------------||\n";
		cout << "\t\t\n||6.Sua sinh vien------------||\n";
		cout << "\t\t\n||7.Sap xep diem  sinh vien--||\n";
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
			sua_diem(l);
			// int d;
			// cout<<"\t\t+++SUA+++\t\t\n";
			// cout<<"\t\t1.sua diem\t\t\n";
			// cout<<"\t\t2.sua ngay sinh\t\t\n";
			// cout<<"vui long chon: ";
			// cin>>d;
			// if(d==1){
			// 	sua_diem(l);
			// }
			// else if(d==2){
			// 	sua_ngaysinh(l);
			// }
			// else{
			// 	cout<<"\tnhap sai vui long nhap lai!!";
			// }
		}


		else if (luachon == 5)
		{
			xoa_cuoi(l);
		}
		/*else if (luachon == 6)
		{
			XoaCuoi(l);
		}*/
		else if (luachon == 7)
		{
			sap_xep(l);
            xuat_dsSV(l);
		}
		/*else if (luachon == 8)
		{
			int x;
			cout << "\nNhap node can xoa: ";
			cin >> x;
			XoaNodeCoKhoaBatKy(l, x);
		}*/
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
	return 0;
}