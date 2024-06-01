#include<iostream>
using namespace std;
#include<string>
#include<fstream>

struct sinhvien
{
	string maso;
	string hoten;
	float diem;
};
typedef struct sinhvien SINHVIEN;

// hàm nhập thông tin 1 sinh viên
void Nhap_Thong_Tin_1_Sinh_Vien(SINHVIEN &sv)
{
	fflush(stdin);
	cout << "\nNhap ma so sinh vien: ";
	getline(cin, sv.maso);

	fflush(stdin);
	cout << "\nNhap ho ten sinh vien: ";
	getline(cin, sv.hoten);

	cout << "\nNhap diem sinh vien: ";
	cin >> sv.diem;

}

// hàm xuất thông tin 1 sinh viên
void Xuat_Thong_Tin_1_Sinh_Vien(SINHVIEN sv)
{
	cout << "\nMa so sinh vien: " << sv.maso;
	cout << "\nHo ten sinh vien: " << sv.hoten;
	cout << "\nDiem sinh vien: " << sv.diem;
}

// istream, ostream

// nạp chồng toán tử >> - để nhập dữ liệu cho 1 sinh viên
// is và sv là 2 tham số do người lập trình tạo

istream& operator >> (istream& is, SINHVIEN &sv)
{
	fflush(stdin);
	cout << "\nNhap ma so sinh vien: ";
	getline(is, sv.maso);

	fflush(stdin);
	cout << "\nNhap ho ten sinh vien: ";
	getline(is, sv.hoten);

	cout << "\nNhap diem sinh vien: ";
	is >> sv.diem;

	return is;
}

// nạp chồng toán tử << - xuất dữ liệu trong strut SINHVIEN
ostream& operator << (ostream& os, SINHVIEN sv)
{
	os << "\nMa so sinh vien: " << sv.maso;
	os << "\nHo ten sinh vien: " << sv.hoten;
	os << "\nDiem sinh vien: " << sv.diem;

	return os;
}


int main()
{
	
	SINHVIEN sv1;
	SINHVIEN sv2;
	cout << "\n\n\t\t NHAP THONG TIN SINH VIEN 1\n";
	cin >> sv1; // <=> Nhap_Thong_Tin_1_Sinh_Vien(sv);
	cout << "\n\n\t\t XUAT THONG TIN SINH VIEN 1\n";
	cout << sv1; // <=> Xuat_Thong_Tin_1_Sinh_Vien(sv);
	cout << "\n\n\t\t NHAP THONG TIN SINH VIEN 2\n";
	cin >> sv2; // <=> Nhap_Thong_Tin_1_Sinh_Vien(sv);
	cout << "\n\n\t\t XUAT THONG TIN SINH VIEN 2\n";
	cout << sv2; // <=> Xuat_Thong_Tin_1_Sinh_Vien(sv);

	system("pause");
	return 0;
}

/*#include<iostream>
using namespace std;
struct phanso
{
	int tuso;
	int mauso;
};
struct phanso;

void nhap(phanso &ps){
	cout<<"nhap tu so: ";
	cin>>ps.tuso;
	cout<<"nhap mau so: ";
	cin>>ps.mauso;
}

void xuat(phanso ps){
	cout<<ps.tuso<<"/"<<ps.mauso;
}
//nap chong toan tu ">>" nhap
istream& operator >>(istream &is, phanso &ps)//"is" va "ps" la 2 bien tu dat
{
	cout<<"nhap tu so: ";
	is>>ps.tuso;
	cout<<"nhap mau so: ";
	is>>ps.mauso;
	return is;
}
//nap chong toan tu "<<" xuat
ostream& operator<<(ostream &os, phanso ps)
{
	os<<ps.tuso<<"/"<<ps.mauso;
}
//tinh tong 2 pso

phanso tong(phanso ps1, phanso ps2){
	phanso x;
	x.tuso =(ps1.tuso*ps2.mauso +ps2.tuso*ps1.mauso);
	x.mauso =ps1.mauso*ps2.mauso;
	return x;
}

//nap chong phan so

phanso operator +(phanso ps1, phanso ps2){
	phanso x;
	x.tuso =(ps1.tuso*ps2.mauso +ps2.tuso*ps1.mauso);
	x.mauso =ps1.mauso*ps2.mauso;
	return x;
}

phanso operator *(phanso ps1,phanso ps2){
	phanso y;
	y.tuso=(ps1.tuso*ps2.mauso);
	y.mauso=(ps1.mauso*ps2.mauso);
}
int main(){

	//chua nap chong
	phanso ps1;
	phanso ps2;
	/*cout<<"nhap phan so 1: ";
	nhap(ps1);
	cout<<"phan so thu 1: ";
	xuat(ps1);

	cout<<"nhap phan so 2: ";
	nhap(ps2);
	cout<<"phan so thu 2: ";
	xuat(ps2);

	phanso x=tong(ps1,ps2);
	cout<<"ket qua: ";
	xuat(x);*/
	//cout<<"tong phan so: "<<x.tuso<<"/"<<x.mauso;
	//dung nap chong
	/*cout<<"nhap phan so thu 1: ";
	cin>>ps1;
	cout<<"phan so thu 1: ";
	cout<<ps1;
	cout<<"nhap phan so 2: ";
	nhap(ps2);
	cout<<"phan so 2: ";
	xuat(ps2);

	phanso x=ps1+ps2;
	phanso y=ps1*ps2;
	cout<<"ket qua: ";
	cout<<x<<endl;
	cout<<y;
	system("pause");
	return 0;

}*/