//bai 0 chuong 3
#include<iostream>
using namespace std;

void *TaoMang(int *a, int n){
    a = new int[n];
    return a;
}
void Nhap(int *a, int n){
    for(int i=0;i<n;i++){
        cout<<"nhap pt thu"<<i+1<<":";
        cin>>*(a+i);
    }
}
void Nhap(int *a, int n){
    for(int i=0;i<n;i++){
        cout<<*(a+i)<<endl;
    }
}
int main(){
    int *a, n;
    cout<<"nhap so phan tu: ";
    cin>>n;
    TaoMang(a,n);
    Nhap
}
//bai 1
#include<iostream>
using namespace std;
void Nhap(int a[10][],int n, int m){
    for(int i = 0;i<n;i++)
        for(int j=0;j<m;j++){
            cout<<"nhap pt o dong"<<i<<"cot"<<j<<":";
            cin>>a[i][j];
        }
}
void Xuat(int a[10][],int n, int m){
    for(int i = 0;i<n;i++)
        for(int j=0;j<m;j++){
            cout<<a[i][j]<<'\t';
        cout<<endl;
        }
}
int LonNhat(int a[10][],int n, int m){
    int max=a[0][0];
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            if(a[i][j]>max)
                max = a[i][j];
                return max;
}
int DongTongLN(int a[10][],int n, int m){
    int max = 0, dong =0,tongDong = 0;
    for(int j = 0;j<m;j++)
        max+=a[dong][j];
    for(int i = 1;i<n;i++){
        tongDong = 0;
        for(int j =0;j<m;j++)
            tongDong+=a[i][j];
        if(tongDong>max){
            dong = i;
            max = tongDong;
        }
    }
    return dong;
}
void SapXep(int a[10][],int n, int m){
    for(int i=1;i<n;i++)
        //sap xep
        for(int j=0;j<m-1;j++)
            for(int k=j+1;k<m;k++)
                if(a[i][j]<a[i][k]){
                    int tam=a[i][j];
                    a[i][j]=a[i][k];
                    a[i][k]= tam;
                }
    
}
void SapXep(int a[10][], int n,int m){
    int b[100],nb=0;
    //chuyen tu a 2 chieu -->b 1 chieu
    for(int i = 0;i<n;i++)
        for(int j=0;j<m;j++)
            a[nb++]=a[i][j];
    //sap xep mang b
    for(int i = 0;i,nb-1;i++)
        for(int j=i+1;j<nb;j++)
            if(b[i]>b[j]){
                int tam = b[i];
                b[i]=b[j];
                b[j]=tam;
            }
}
//bai2
#include<iostream>
using namespace std;
void Nhap(int a[8][],int n){
    for(int i = 0;i<n;i++)
        for(int j=0;j<n;j++){
            cout<<"nhap pt ("<<i<<","<<j<<") :";
            cin>>a[i][j];
        }
}
void Xuat(int a[8][],int n){
    for(int i = 0;i<n;i++)
        for(int j=0;j<n;j++){
            cout<<a[i][j]<<'\t';
        cout<<endl;
        }
}
int MaxDCC(int a[8][],int n){
    int max=a[0][0];
    for(int i=1;i<n;i++)
        if(a[i][i]>max)
            max =a[i][i];
    return max;
}
int DemSADCP(int a[8][], int n){
    int dem = 0;
    for(int i= 0;i<n;i++)
        for(int j = 0;j<n;j++)
            if((i+j=n-1) && a[i][j]<0)
                dem++;
    return dem;
}
int LaSNT(int n){
    int SoUoc = 0;
    for(int i=1;i<=n;i++)
        it(n%i == 0)
            SoUoc =0;
}

//tim phan tu cot 1 max
int max=0;
for(int i = 0;i<nb;i++)
    if(b[i][1]>b[max][1])
        max = i;
return max;
int soChanDong(int a[8][8], int n, int dong){
    int dem =0;
    for(int i=0;i<n;i++)
        if(a[dong][i]52==0)
            dem++;
    return dem;
}
int MaxChanDong(int a[8][8],int n){
    int max=soChanDong(a,n,0);
    for(int i=1;i<n;i++)
        if(soChanDong(a,n,i)>max)
            max=soChanDong(a,n,i);
    dor(int i=0;i<n;i++)
        if(soChanDong(a,n,i)==max)
            cout<<"dong"<<i<<endl;
}
//bai3
#include<iostream>
using namespace std;
void HVDong(int a[8][8], int n, int i,int j){
    int tam[8];
    for(int k=0;k<n;k++)
        tam[k]=a[i][k];
    for(int k=0;k<n;k++)
        a[i][k]=[j][k];
    for(int k=0;k<nlk++)
        a[j][k]=tam[k];
}
void Dong(int a[8][8], int n){
    for(int i =0; i<n-1)
}

void SXDong(int a[8][9], int n){
    for(int i=0;i<n-1;i++)
        for(int j=i+1;j<n;j++)
            if(a[i][0]>a[j][0])
                HVDong(a,i,j);
}
int TongDong(int a[8][8],int n, int i){
    int s=0;
    for(int k=0; k<n;k++)
        s+=a[i][k];
        return s;
}
void SXTongDong(int a[8][8], int n){
    for (int i = 0; i < n-1; i++)
        
    
}
//bai 2
//f
int max=a[0][0], maxlan=0,pt=0,solan=0;
for(int i =0;i<n;i++){
    if(a[i][j]==max) maxlan++;

}
for(int i =0)
//g. Liệt kê các dòng có nhiều số chẵn nhất
int DemSoChanDong(int a[8][8], int n,int dong){
    int dem=0;
    for(int i=0;i<n;i++)
        if(a[i][dong]%2==0)
            dem++;
    return dem;
}
int MaxChan(int a[8][8],int n){
    int max = DemSoChanDong(a,n,0);
    for(int i=1;i<n;i++)
        if(DeSoChanDong(a,n,i)>max)
            max=DemSoChanDong(a,n,i);

}
void DongMaxChan(int a[8][8],int n){
    for(int i=0;i<n;i++)
        if(DemSoChanDong(a,n,i)==MaxChan(int a[8][8];int n))
            cout<<"dong"<<i<<endl;
}
//bai3
// Ma trận A có đối xứng hoặc phản đối xứng hay không
int DX(int a[8][8],int n){
    for (int i=0;i<n;i++)
        if(a[i][j]!=a[j][i])
            return 0;
    return 1;
}
int DX(int a[8][8],int n){
    for (int i=0;i<n;i++)
        if(a[i][j]!=-a[j][i])
            return 0;
    return 1;
}
//Hoán vị các dòng của A sao cho thứ tự cột 0 tăng dần
void HoanViDong(int a[8][8],int i,int dong1,int dong2){
    int b[8];
    for(int i=0;i<n;i++)
        b[i]=a[dong1][i];
    for(int i=0;i<n;i++)
        a[dong1][i]=a[dong2][i];
    for(int i=0;i<n;i++)
        a[dong2][i]=b[i];
}
void SapXepDongTheoCot(inta[8][8],int n){
    for(int i=0;i<n-1;i++)
        for(int j=i+1;j<n;j++)
            if(a[0][i]>a[0][j])
                HoanViDong(a,n,i,j);
}
// Hoán vị các dòng của A sao cho tổng các phần tử của dòng tăng dần  
void HoanViDong(int a[8][8],int i,int dong1,int dong2){
    int b[8];
    for(int i=0;i<n;i++)
        b[i]=a[dong1][i];
    for(int i=0;i<n;i++)
        a[dong1][i]=a[dong2][i];
    for(int i=0;i<n;i++)
        a[dong2][i]=b[i];
}
int TongDong(int a[8][8],int n,int dong){
    int s=0;
    for(int i=0;i<n;i++)
        s+=a[dong][i];
    return s;
}
void SapXepDongTheoCot(inta[8][8],int n){
    for(int i=0;i<n-1;i++)
        for(int j=i+1;j<n;j++)
            if(TongDong(a,i,n)>TongDong(a,n,j))
                HoanViDong(a,n,i,j);
}
//bai4a
void TongMT(int a[8][8],int b[8][8],int c[8][8]){
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            a[i][j]=a[i][j]+b[i][j];
}
//b
void TongMT(int a[8][8],int b[8][8],int c[8][8]){
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++){
            c[i][j]=0;
            for(int k=0;k<n;k++)
                c[i][j]+=a[i][k]*b[k][j];
        }
}
//c
void ChuyenVi(int a[8][8];int b[8][8]){
    for(int i=0;i<n;i++)
        for(int j=0;i<n;j++)
            c[i][j]=a[j][i];
}
//d
int min(int a[8][8],int na,int b[8][8],int nb){
    int min=a[0][0];
    for(int i=0;i<na;i++)
        for(int j=0;j<na;i++)
            if(a[i][j]<min) main=a[i][j];
    for(int i=0;i<nb;i++)
        for(int j=0;j<nb;i++)
            if(b[i][j]<min) main=b[i][j];
    return min;       
}