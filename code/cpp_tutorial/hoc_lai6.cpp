
//b2
#include<iostream>
#include<string>
using namespace std;
struct sinhvien
{
    string ma;
    string ten;
    int namsinh;
    float dtb;
};
typedef sinhvien SINHVIEN;

void nhap(SINHVIEN &sv){
    cout<<"\t\tnhap thong tin sinh vien\n";
    fflush(stdin);
    cout<<"\tnhap ma sinh vien: ";
    getline(cin,sv.ma);
    cout<<"\tnhap ten sinh vien: ";
    getline(cin,sv.ten);
    cout<<"\tnhap nam sinh: ";
    cin>>sv.namsinh;
    cout<<"\tnhap diem trung binh: ";
    cin>>sv.dtb;
}

void xuat(SINHVIEN sv){
    cout<<"\tma: "<<sv.ma<<endl;
    cout<<"\tten: "<<sv.ten<<endl;
    cout<<"\tnam sinh: "<<sv.namsinh<<endl;
    cout<<"\tdiem trung binh: "<<sv.dtb<<endl;

}
//ham nhap nhieu sinh vien
void nhap_sv(SINHVIEN a[], int n){
    for(int i=0;i<n;i++){
        cout<<"\tnhap sinh vien thu "<<i+1<<endl;
        nhap(a[i]);//goi tu ham nhap thong tin 1 sinh vien
    }
}
void xuat_sv(SINHVIEN a[], int n){
    
    for(int i=0;i<n;i++){
        cout<<"\tthong tin sinh vien thu: "<<i+1<<endl;
        xuat(a[i]);
    }
}
//them sv 
void them_sv(SINHVIEN a[],int &n,int vt, SINHVIEN x){
    for(int i=n-1;i>=vt;i--){
        a[i+1]=a[i];

    }
    a[vt]=x;
    n++;
}
//xoa sv 
void xoa_sv(SINHVIEN a[], int &n,int vt){
    for(int i=vt+1;i<n;i++){
        a[i-1]=a[i];
    }
    n--;
}
//hoan vi
void hoan_vi(SINHVIEN &x, SINHVIEN &y){
    SINHVIEN tam;
    tam=x;
    x=y;
    y=tam;
}
//sap xep ds sinh vien tang dan theo dtb
void sap_xep(SINHVIEN a[],int n){
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n-1;j++)
            if(a[i].dtb>a[j].dtb){
                hoan_vi(a[i],a[j]);
            }
    }
}
//xoa thong tin sv co dtd <5
void dtb_nho5(SINHVIEN a[],int &n){
    for(int i=0;i<n;i++){
        if(a[i].dtb<5){
            xoa_sv(a,n,i);
            i--;
        }
    }
}
//tim thong tin sinh vien
void tim_diem(SINHVIEN a[],int n,float diem){
    int dem=1;
    for(int i=0;i<n;i++){
        if (a[i].dtb==diem){//mang cua 1 sinh vien
            cout<<"\txuat thong tin sinh vien "<<dem++;
            xuat(a[i]);//xuat 1 sinh vien
        }
    }
}
int main(){
    SINHVIEN a[100];//khai bao mang nhieu sinh vien tu struct sinh vien
    int n;
    cout<<"\tnhap so luong sinh vien: ";
    cin>>n;
    cout<<"\tnhap ds sinh vien:\n";
    nhap_sv(a,n);
    cout<<"\txuat ds sinh vien:\n";
    xuat_sv(a,n);
    /*int diem_tk;
    cout<<"nhap diem sinh vien can tim: ";
    cin>>diem_tk;
    tim_diem(a,n,diem_tk);
    int vt;
    SINHVIEN x;//goi lai struct x cua sinh vien
    cout<<"\tnhap vi tri can them: ";
    cin>>vt;
    cout<<"\tnhap thong tin sinh vien can them:";
    nhap(x);
    them_sv(a,n,vt,x);
    cout<<"\txuat ds sinh vien:\n";
    xuat_sv(a,n);*/
    
    
    sap_xep(a,n);
    cout<<"\txuat ds sinh vien sau khi sap xep:\n";
    xuat_sv(a,n);
    int vt_xoa;
    cout<<"\tnhap vi tri can xoa: ";
    cin>>vt_xoa;
    dtb_nho5(a,n);
    cout<<"\txuat ds sinh vien sau khi xoa:\n";
    xuat_sv(a,n);
    system("pause");
    return 0;
}