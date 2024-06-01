#include<iostream>
using namespace std;

struct node
{
	int data; // queue đang chứa các số nguyên
	struct node *pNext; // con trỏ liên kết giữa các node với nhau
};
typedef struct node NODE;

// khai báo cấu trúc của queue
struct queue
{
	NODE *pHead; //  con trỏ đầu
	NODE *pTail; // con trỏ cuối 
};
typedef struct queue QUEUE;

// hàm khởi tạo queue
void KhoiTaoQueue(QUEUE &q)
{
	q.pHead = NULL;
	q.pTail = NULL;
}


NODE *KhoiTaoNode(int x)
{
	NODE *p = new NODE();
	if (p == NULL)
	{
		cout << "\nKhong du bo nho de cap phat !!!";
		return NULL;
	}
	p->data = x; // thêm giá trị của biến x vào trong data của cái node
	p->pNext = NULL;
	return p;
}

//ktra rong
bool IsEmpty(QUEUE q)
{
	// nếu danh sách rỗng
	if (q.pHead == NULL)
	{
		return true;
	}
	return false;// danh sách có phần tử
}

//them phan tu vao cuoi
bool Push(QUEUE &q, NODE *p)
{
	if (p == NULL)
	{
		return false;
	}

	// nếu danh sách rỗng
	if (IsEmpty(q) == true)
	{
		q.pHead = q.pTail = p;  
	}
	else // danh sách đã có phần tử
	{
		q.pTail->pNext = p; 
		q.pTail = p; // cập nhật lại con trỏ cuối là node p
	}
	return true;
}

//lay phan tu dau
bool Pop(QUEUE &q, int &x) // x chính là giá trị cần lấy trong node
{
	// nếu danh sách rỗng
	if (IsEmpty(q) == true)
	{
		return false;
	}
	else
	{
		NODE *p = q.pHead; 
		x = p->data; 	
		q.pHead = q.pHead->pNext;
		delete p; // xóa node đầu queue vừa lấy 

	}
	return true;
}


//xem thong tin ptu dau khong co thi xoa
bool Top(QUEUE &q, int &x) // x là giá trị cần lấy ra để xem
{
	if (IsEmpty(q) == true)
	{
		return false;
	}
	x = q.pHead->data;
	return true;
}

//xuat queue
void XuatQueue(QUEUE q)
{
	while (IsEmpty(q) == false)
	{
		int x;
		Pop(q, x);
		cout << x << " ";
	}

	if (IsEmpty(q) == true)
	{
		cout << "\ndanh sach rong!!";
	}
	else
	{
		cout << "\ndanh sach da ton tai phan tu!!";
	}
}

//nhap
void NhapQueue(QUEUE &q)
{
	int luachon;
	while (true)
	{
		system("cls");
		cout << "\n\n\t\t ============== Menu ==============";
		cout << "\n\t1. Nhap don hang";
		cout << "\n\t2. Xuat don hang";
		cout << "\n\t3. Hien thi don hang dau tien";
        cout << "\n\t4. Xoa don hang";
		cout << "\n\t0. Ket thuc";
		cout << "\n\n\t\t ============== End ==============";

		cout << "\nNhap lua chon: ";
		cin >> luachon;
		if (luachon == 1)
		{
			int x;
			cout << "\nNhap so don hang: ";
			cin >> x;
			NODE *p = KhoiTaoNode(x);
			Push(q, p);
		}
		else if (luachon == 2)
		{
			XuatQueue(q);
			system("pause");
		}
		else if (luachon == 3)
		{
			int x;
			Top(q, x);
			cout << "\nPhan tu dau queue la: " << x;
			system("pause");
		}
        else if (luachon == 4){
            int x;
            Pop(q,x);
            cout<<"\nxoa thanh cong";
        }
		else
		{
			break;
		}
	}
}

int main()
{
	QUEUE q;
	KhoiTaoQueue(q);
	NhapQueue(q);
	system("pause");
	return 0;
}