// Mở file
/*ofstream f (fileName); // Khai báo và mở file
if(!f.is_open) {
cout << “Khong the tao duoc file ” << fileName << endl;
exit(1);
}
// Nhập từ bàn phím, ghi dữ liệu vào file
do {
input=cin.get(); // Đọc kí tự từ bàn phím
f << input << ‘ ‘; // Ghi kí tự vào file
// f.put(input);
// f.put(‘ ‘);
} while((input != ‘.’); //Kết thúc khi nhập vào dấu .
f << endl; // Xuống dòng cuối file
// Đóng file
f.close();
}*/
#include <iostream>
#include<fstream>
const int length = 25;
using namespace std;
struct TG{
    int ng, th,nm;
};

struct  HV{
    char MaHV[5];
    char HoTen[30];
    TG NgaySinh;
    int GT;
    float W,E,P;
};
void Nhap(HV &h){
    
        cout<<"MaHV: ";cin>>h.Ma;
        cout<<"TenHV:"; cin>>h.Ten;
        cout<<"ngay thang nam sinh sinh: \n";
        cin>>h.NS.ng>>h.NS.th>>h.NS.nm;
        cout <<"diem word, exel, powerpoint: ";
        cin>>h.W>>h.E>>h.P;
}
void Xuat(HV &h){
    
        cout<<"MaHV: ";cin>>h.Ma;
        cout<<"TenHV:"; cin>>h.Ten;
        cout<<"ngay thang nam sinh sinh: \n";
       
}
void NhapFile(char *TenF, int h){
    ofstream f(TenF, ios::binary);
    for (int i=0;i<n;i++){
        cout << "nhap thong tin hoc vien thu"<<i<<":\n";
        cout << "MaHv";cin>>h.Ma;
        cout<<"TenHV:"; cin>>h.Ten;
        cout<<"ngay sinh: \n";
        cout<<"ngay: ";cin>>h.NS.ng;
        cout<<"nam: ";cin>>h.NS.nm;
        cout <<"diem word, exel, powerpoint: ";
        cin>>h.W>>h.E>>h.P;
        f.write(reinterpret_cast<char*>(&h),sizeof(HV));

    }
    f.close();
}
void Xem(char *TenF,char *MaHV){
    ifstream f(TenF, ios::binary);
    HV h;
    while (f.read(reinterpret_cast<char*>(&h),sizeof(HV)))
        if(strcmp(h.MaHV,MaHv)==0){
            Xuat(h);
            f.close();
            return;
        }
    
}

