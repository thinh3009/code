//cau truc
/*#include<iostream>
#include<string>
using namespace std;
struct Sinh_vien
{
    string ma;
    string ho_ten;
    int nam_sinh;
    float diem;

};
typedef struct Sinh_vien sinhvien;//doi ten struct Sinh_vien thanh sinhvien


void nhap(sinhvien &sv){
    fflush(stdin);
    cout<<"nhap ho ten sinh vien: ";
    getline(cin, sv.ho_ten );
    fflush(stdin);
    cout<<"nhap ma so: ";
    getline(cin, sv.ma);
    cout<<"nhap diem sinh vien: ";
    cin>>sv.diem;
}

void xuat(sinhvien sv){
    cout<<"ho ten sinh vien: "<<sv.ho_ten;
    cout<<"ma so sinh vien: "<<sv.ma;
    cout<<"diem sinh vien: "<<sv.diem;

}
int main(){

    sinhvien x;//khai bao ra 1 sv x
    cout<<"nhap thong tin sinh vien: ";
    nhap(x);
    cout<<"thong tin cua sinh vien: ";
    xuat(x);

}*/

#include<iostream>
#include<cmath>
using namespace std;
struct toado
{
    int x;
    int y;
};
typedef toado TOADO;
//struct toa do ba canh
struct tam_giac
{
    TOADO A;
    TOADO B;
    TOADO C;
};
typedef tam_giac TAMGIAC;

void nhap(TOADO &d){
    cout<<"nhap toa do x: ";
    cin>>d.x;
    cout<<"nhap toa do y: ";
    cin>>d.y;
}

void xuat(TOADO d){
    cout<<"("<<d.x<<","<<d.y<<")";
}
void nhap_toa_do_tgiac(TAMGIAC &tg){
    cout<<"nhap toa do diem A: ";
    nhap(tg.A);
    cout<<"nhap toa do diem B: ";
    nhap(tg.B);
    cout<<"nhap toa do diem C: ";
    nhap(tg.C);
}

void xuat_toa_do_tgiac(TAMGIAC tg){
    cout<<"toa do diem A la: ";
    xuat(tg.A);
    cout<<"toa do diem B la: ";
    xuat(tg.B);
    cout<<"toa do diem C la: ";
    xuat(tg.C);
}

//chua co struct long nhau

float do_dai(TOADO A,TOADO B ){
    return sqrt(pow((B.x-A.x),2)+pow((B.y-A.y),2));

}
int main()
{
    TAMGIAC tg;
    nhap_toa_do_tgiac(tg);
    xuat_toa_do_tgiac(tg);
    cout<<"do dai canh AB: "<<do_dai(tg.A,tg.B);
    cout<<"do dai canh AC: "<<do_dai(tg.A,tg.C);
    cout<<"do dai canh BC: "<<do_dai(tg.B,tg.C);
    /*TOADO A;
    TOADO B;
    TOADO C;
    cout<<"nhap toa do diem A: ";
    nhap(A);
    cout<<"nhap toa do diem B";
    nhap(B);
    cout<<"nhap toa do diem C";
    nhap(C);
    
    cout<<"toa do diem A la: ";
    xuat(A);
    cout<<"toa do diem B la: ";
    xuat(B);
    cout<<"toa do diem C la: ";
    xuat(C);
    //do dai
    cout<<"do dai canh AB: "<<do_dai(A,B);
    cout<<"do dai canh AC: "<<do_dai(A,C);
    cout<<"do dai canh BC: "<<do_dai(B,C);*/
    system("pause");
    return 0;
}