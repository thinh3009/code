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


// ========== KHAI BÁO CẤU TRÚC 1 CÁI NODE ==========
struct node
{
	SINHVIEN *data; // dữ liệu của node
	struct node *pNext; // con trỏ dùng để liên kết giữa các cái node với nhau
};
typedef struct node NODE;

// ========== KHAI BÁO CẤU TRÚC DANH SÁCH LIÊN KẾT ĐƠN =========

struct list
{
	NODE *pHead;
	NODE *pTail;
};
typedef struct list LIST;


// hàm khởi tạo danh sách liên kết đơn
void KhoiTaoDanhSach(LIST &l)
{
	l.pHead = NULL;
	l.pTail = NULL;
}


void nhap_sv(SINHVIEN* sv){
	cin.ignore();
	cout<<"\n\tnhap ma so sinh vien: ";
	fflush(stdin);
	getline(cin,sv->ma);
	cout<<"\n\tnhap ten sinh vien: ";
	fflush(stdin);
	getline(cin,sv->ten);
	cout<<"\n\tnhap lop: ";
	fflush(stdin);
	getline(cin,sv->lop);
	cout<<("\n\tnhap ngay sinh: ");
	fflush(stdin);
	getline(cin,sv->ngaysinh);
	cout<<"\n\tnhap diem trung binh: ";
	cin>>sv->diemtb;

}
NODE *KhoiTaoNode()
{
	SINHVIEN* sv = new SINHVIEN;
	nhap_sv(sv);
	NODE *p=new NODE;
	if (p == NULL)
	{
		cout << "\nCap phat that bai !";
		return 0;
	}
	p->data = sv; // đưa dữ liệu của biến sv vào data của cái Node p
	p->pNext = NULL; // khởi tạo node p nhưng node p chưa có liên kết đến node nào hết
	return p;
}
//them node vao cuoi ds
void them_cuoi(LIST &l,NODE *p){
    if(l.pHead==NULL){
        l.pHead=l.pTail=p;
    }
    else{
        l.pTail->pNext=p;
        l.pTail=p;//cap nhat lai p

    }
}

// void them_dau(LIST &l, NODE *p){
//     //ds dang rong
//     if(l.pHead==NULL){
//         l.pHead=l.pTail=p;//node dau=node cuoi=p
//     }
//     else{
//         p->pNext=l.pHead;//cho con tro cua node can them la p lien ket node head
//         l.pHead=p;//cap nhat lai heaf la p 
//     }
// }

//show list sinh vien tu phead den ptail
void xuat_dsSV(LIST l){
	NODE *k=l.pHead;
	if(k==NULL){
		cout<<"\n\tdanh sach rong\n";
		return;
	}
	for(NODE *k=l.pHead;k!=NULL;k=k->pNext){
		cout<<"\tma so sinh vien: "<<k->data->ma<<endl;
		cout<<"\tten sinh vien: "<<k->data->ten<<endl;
		cout<<"\tlop cua sinh vien: "<<k->data->lop<<endl;
		cout<<"\tngay sinh: "<<k->data->ngaysinh<<endl;
		cout<<"\tdiem trung binh: "<<k->data->diemtb<<endl; 
	}

}

//show node sinh vien
void xuat_NodeSV(NODE *k){
	cout<<"\n\t********************\n";
	cout<<"\t\tma so sinh vien: "<<k->data->ma<<endl;
	cout<<"\t\tten sinh vien: "<<k->data->ten<<endl;
	cout<<"\t\tlop cua sinh vien: "<<k->data->lop<<endl;
	cout<<"\t\tngay thang sinh vien: "<<k->data->ngaysinh<<endl;
	cout<<"\t\tdiem sinh vien: "<<k->data->diemtb<<endl;
	
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
}*/
/*void tim_theo_lop(LIST l){
 	string lop;
 	cout<<"\n\tnhap lop can tim: ";
 	getline(cin, lop);
 	for(NODE *k=l.pHead;k!=NULL;k=k->pNext){
 		if(k->data->lop==lop){
 			xuat_NodeSV(k);
 		}
 	}
}*/
void tim_theo_ma(LIST l){
	string ma;
	cin.ignore();
	cout<<"\n\tnhap ma so can tim: ";
	fflush(stdin);
	getline(cin,ma);
	for(NODE *k=l.pHead;k!=NULL;k=k->pNext){
		if(k->data->ma==ma){
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
void sua_diem(LIST &l){
	float diem;
	cout<<"\n\tnhap diem can sua: ";
	cin>>diem;
	for(NODE *k=l.pHead;k!=NULL;k=k->pNext){
		if(k->data->diemtb==diem){
			cout<<"\n\tsua sinh vien co diem "<<diem<<" la: ";
			cin>>k->data->diemtb;
			cout<<"\n\tsua thanh cong!!!";
		}
	}
	
}



// hàm xóa 
// void xoa_ma(LIST &l,string ma){
// 	NODE *xoa=l.pHead;
// 	if(xoa==NULL){
// 		cout<<"\tdanh sach rong!!\n";

// 	}
// 	else{
// 		NODE *pre=NULL;
// 		while(xoa!=NULL){
// 			SINHVIEN *sv=xoa->data;
// 			if(sv->ma==ma)
// 				break;
// 			pre=xoa;
// 			xoa=xoa->pNext;
// 		}
// 		if(xoa==NULL){
// 			cout<<"\tkhong tim thay ma sinh vien nay!!\t\n";
// 		}
// 		else{
// 			if(xoa=l.pHead){
// 				l.pHead=l.pHead->pNext;
// 				xoa->pNext=NULL;
// 				delete xoa;
// 				xoa=NULL;
// 				cout<<"\tda xoa sinh vien khoi danh sach!!";
// 			}
// 			else{
// 				pre->pNext=xoa->pNext;
// 				xoa->pNext=NULL;
// 				delete xoa;
// 				xoa=NULL;
// 			}
// 		}
// 	}
// }
// void xoa_ten(LIST &l,string ten){
// 	NODE *xoa=l.pHead;
// 	if(xoa==NULL){
// 		cout<<"\tdanh sach rong!!\n";

// 	}
// 	else{
// 		NODE *pre=NULL;
// 		while(xoa!=NULL){
// 			SINHVIEN *sv=xoa->data;
// 			if(sv->ten==ten)
// 				break;
// 			pre=xoa;
// 			xoa=xoa->pNext;
// 		}
// 		if(xoa==NULL){
// 			cout<<"\tkhong tim thay ten sinh vien nay!!\t\n";
// 		}
// 		else{
// 			if(xoa=l.pHead){
// 				l.pHead=l.pHead->pNext;
// 				xoa->pNext=NULL;
// 				delete xoa;
// 				xoa=NULL;
// 				cout<<"\tda xoa sinh vien khoi danh sach!!";
// 			}
// 			else{
// 				pre->pNext=xoa->pNext;
// 				xoa->pNext=NULL;
// 				delete xoa;
// 				xoa=NULL;
// 			}
// 		}
// 	}
// }

//xoa cuoi
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

// void xoa_dau(LIST &l){
// 	if(l.pHead==NULL){
// 		return;
// 	}
// 	NODE *p=l.pHead;
// 	l.pHead=l.pHead->pNext;
// 	delete p;
// }

// void xoa_node_batki(LIST &l, SINHVIEN sv){
//     //neu node can xoa nam dau ds
//     if(l.pHead->data==sv){
//         xoa_dau(l);
//         return;
//     }    
//     if(l.pTail->data==sv){
//         xoa_cuoi(l);
//         return;
//     }
//     NODE *g = new NODE;//g la node tro den node truoc node can xoa "sv"
//     //duyet dslk de tim
//     for(NODE *k=l.pHead;k!=NULL;k=k->pNext){
// 		//tim ptu can xoa
//         if(k->data==sv){
//             g->pNext=k->pNext;//cap nhat moi lien ket giua node k voi node nam sau node bi xoa
//             delete k;
//             return;
//         }
//         g=k;//cho node g tro den k
//     }
// }
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

// hàm menu
void Menu(LIST &l)
{
	int luachon;
	while (true)
	{
		//system("cls");
		cout<<"\t\t\n||=========== MENU ==========||\n";
		cout<<"\t\t\n||1.Nhap sinh vien-----------||\n";
		cout<<"\t\t\n||2.Xuat danh sach-----------||\n";
		cout<<"\t\t\n||3.Tim ma sinh vien---------||\n";
		cout<<"\t\t\n||4.Sua diem sinh vien-------||\n";
		cout<<"\t\t\n||5.Xoa cuoi-----------------||\n";
		cout<<"\t\t\n||7.sap xep------------------||\n";
		cout<<"\t\t\n||0.Ket thuc-----------------||\n";
		cout<<"\t\t\n||=========== END ===========||";

		cout<<"\nNhap lua chon: ";
		cin>>luachon;
		if(luachon==1)
		{
			int x;
			cout << "\nNhap so luong sinh vien can them: ";
			cin >> x;
			for(int i=1;i<=x;i++){
				cout<<"\tsinh vien thu "<<i<<":"<<endl;
				NODE *p = KhoiTaoNode();
				them_cuoi(l, p);
			}
			
		}
		else if (luachon == 2)
		{
			cout << "\n\t\t=====Danh sach sinh vien=====\n";
			xuat_dsSV(l);
			
		}
		else if (luachon == 3)
		{
			tim_theo_ma(l);	
			
		}
		else if (luachon == 4){	
			sua_diem(l);
			
		}
		else if (luachon == 5)
		{
			xoa_cuoi(l);
	
			/*string ma;
			cout<<"\tnhap ma muon xoa: ";
			getline(cin, ma);
			xoa_ma(l,ma);
		 	cout<<"\txoa thanh cong!!";*/
		}
		else if (luachon == 7){
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
		else{
			cout<<"cam on da dung chuong trinh!!";
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

