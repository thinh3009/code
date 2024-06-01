//mang 2 chieu
/*#include<iostream>
using namespace std;
int main() {
float a[100][100], min;// a chứa tối đa 10000 số
int i, j, m, n;
cout<< "Nhap so hang va so cot:\n"; cin >> m>> n;
for (i = 0; i<m; i++)
for (j = 0; j<n; j++)
{ cout<< "a[" << i << "]["<<j<<"] = "; cin>>a[i][j]; }
min = a[0][0];//Gán min bằng phần tử đầu tiên
for (i = 1; i<n; i++)
for (j = 0; j < n; j++)
if (a[i][j] < min) min = a[i][j];
cout << "So be nhat la " << min << '\n';
}*/
//chuoi
/*#include<iostream>
#include<stdio.h>
#define max 255
using namespace std;
int main(){
    char str1[max];
    char *str2;
    cout<<"nhap chuoi 1: ";
    gets(str1);
    cout<<"nhap chuoi 2: ";
    str2 = new char[max];
    cin.getline(str2,max);
    cout<<"chuoi 1: "<<str1<<endl;
    cout<<"chuoi 2: ";
    cout<<str2;
}*/
//mang cua chuoi
/*#include<iostream>
#include<string>
using namespace std;
int main(){
    char list[5][20];
    for(int i=0;i<5;i++){
        cout<<"nhap ten thu "<<i<<":";
        gets(list[i]);
    }
    for(int j=0;j<5;j++){
        cout<<","<<list[j];
    }
}*/
//dem so ky tu
/*#include<iostream>
#include<string>
using namespace std;

void dem_chu(char hoa[20], int l){
    int i=0,dem1=0,dem2=0,dem3=0;
    for(i=0;i<l;i++){
        if(islower(hoa[i]))
            dem1++;
        if(isupper(hoa[i]))
            dem2++;
        if(isalpha(hoa[i]))
            dem3++;
    }
    cout<<"so ki tu thuong: "<<dem1<<endl;
    cout<<"so ki tu hoa: "<<dem2<<endl;
    cout<<"so ko phai chu: "<<dem3<<endl;
}
int main(){
    char hoa[100];
    int l;
    cout<<"nhap chuoi: ";
    gets(hoa);
    cout<<"chuoi vua nhap: "<<endl;
    cout<<hoa;
    l = strlen(hoa);
    dem_chu(hoa,l);


}*/

//con tro
//hoan vi
/*#include<iostream>
using namespace std;
int main(){
    int a=20, b=15   , *p1, *p2, tam;
    p1=&a;
    p2=&b;
    tam=*p1;
    *p1=*p2;
    *p2=tam;
    cout<<"a: "<<a<<endl;
    cout<<"&a: "<<&a<<endl;
    cout<<"b: "<<b<<endl;
}*/
/*#include<iostream>
using namespace std;
int main(){
    int a=30, *p,b=20;
    p=&a;
    cout<<"gia tri cua bien a: "<<a<<endl;
    cout<<"dia chi bien a: "<<&a<<endl;
    cout<<"gia tri con tro p: "<<p<<endl;//p=&a
    cout<<"dia chi con tro p: "<<&p<<endl;//p cung la 1 bien nen co dia chi rieng
    cout<<"gia tri con tro p tro toi: "<<*p<<endl;//p tro toi dia chi cua a

    cout<<"=============================================="<<endl;
    *p+=5;
    cout<<"gia tri cua a: "<<a<<endl;
    cout<<"gia tri cua con tro p tro toi: "<<*p<<endl;
    p=&b;
    cout<<"gia tri con tro b tro toi: "<<*p<<endl;
    *p+=9;
    cout<<"gia tri cua b "<<*p<<endl;
    cout<<"dia chi cua p: "<<p<<endl;//dia chi cua p=&b
    cout<<"dia chi cua b: "<<&b<<endl;
}*/

/*#include<iostream>
using namespace std;
int main(){
    int *p=new int;
    if(p==NULL){
        cout<<"loi cap nhat";
        exit(0);
    }
    *p=100;
    cout<<"tai o nho"<<p<<" ";
    cout<<"la gia tri"<<*p<<"\n";
    //tranh hao ton bo nho
    if(p!=NULL){
        delete p;
        p=NULL;
    }
}*/

//con tro va mang
/*#include<iostream>
using namespace std;
void nhap(int *a,int n){
    cout<<"nhap so phan tu cua mang: ";
    for(int i=0;i<n;i++){
        cout<<"a["<<i<<"]: ";
        cin>>*(a+i);
    }
}
void xuat( int *a,int n){
    cout<<"mang sau khi nhap la: ";
    for(int i=0; i<n;i++){
        cout<<" "<<*(a+i);//khoang trang xuat mang
    }
}

int tim_so_lan_xuat_hienMax(int *a,int n){
    int max=1;
    for(int i=0;i<n;i++){
        int dem=1;
        for(int j=i+1;j<n;j++){
            if(*(a+i)==*(a+j))
                dem++;
        }
        if(dem>max)
            max=dem;
    }
    return max;
}
int dem_so_lan_xuat(int *a, int n, int index){
    int dem=1;
    for(int i=index+1;i<n;i++)
        if(*(a+i)==*(a+index))
            dem++;
    return dem;
}

void liet_ke(int *a, int n)
{
    int tan_xuatMax= tim_so_lan_xuat_hienMax(a,n);
    if(tan_xuatMax>1)
    {
        for(int i=0;i<n;i++)
        {
            int tan_xuat=dem_so_lan_xuat(a,n,i);
            if(tan_xuat=tan_xuatMax)
            {
                cout<<"phan tu xuat hien nhieu nhat la: "<<*(a+i)<<endl;
            }
        }
        cout<<"so lan xuat hien nhieu nhat la: "<<tan_xuatMax<<endl;
        
    }
    else{
        cout<<"so lan moi phan tu xuat hien la 1";
        }
}
int main(){
    int *a,n;
    cout<<"nhap so phan tu: ";
    cin>>n;
    a=new int[n];//cap phat, n la so phan tu trong mang
    nhap(a,n);
    xuat(a,n);
    liet_ke(a,n);
    delete a;
}*/


/*#include<iostream>
using namespace std;
int main(){
    int a=10;
    float f=11.5;
    int *pa;
    float *pf;

    void *pV;
    pa=&a;
    pf=&f;

    pV=&f;
    cout<<"float pV: "<<*((float*)pV);
    pV=&a;
    cout<<"int pV: "<<*((int*)pV);
    delete pV;
    cout<<"pv: "<<pV;

}*/

/*#include<iostream>
using namespace std;
void nhap(int *a,int n){
    cout<<"nhap so phan tu: ";
    for(int i=0;i<n;i++){
        cout<<"a["<<i<<"]= ";
        cin>>*(a+i);
    }
}

void xuat(int *a,int n){
    cout<<"mang sau khi nhap la: ";
    for(int i=0;i<n;i++){
        cout<<" "<<*(a+i);
    }
}

int tim_chanMax(int *a,int n){
    int max=0;
    for(int i=0;i<n;i++){
        if(*(a+i)%2==0){
            max=*(a+i);
            break;
        } 
    }
    for(int i=0;i<n;i++){
        if(*(a+i)%2==0 &&*(a+i)>max)
            max=*(a+i);
    }
    return max;
}

int tim_leMin(int *a,int n){
    int min=0;
    for(int i=0;i<n;i++){
        if(*(a+i)%2==0){
            min=*(a+i);
            break;
        } 
    }
    for(int i=0;i<n;i++){
        if(*(a+i)%2!=0 &&*(a+i)<min)
            min=*(a+i);
    }
    return min;
}
int main(){
    int *a, n;
    cout<<"Nhap so phan tu: ";
    cin>>n;
    a = new int[n];
    nhap(a,n);
    xuat(a,n);
    if(tim_chanMax(a,n)==0){
        cout<<"mang ko co so chan"<<endl;
    }
    else{
        cout<<"so chan lon nhat"<<tim_chanMax(a,n);
    }
    if(tim_leMin(a,n)==0){
        cout<<"mang ko co so le"<<endl;
    }
    else{
        cout<<"so le nho nhat"<<tim_leMin(a,n);
    }
    delete a;

}
*/

/*#include<iostream>
using namespace std;
void nhap(int *a,int n){
    cout<<"nhap so phan tu: ";
    for(int i=0;i<n;i++){
        cout<<"a["<<i<<"]= ";
        cin>>*(a+i);
    }
}

void xuat(int *a,int n){
    cout<<"mang sau khi nhap la: ";
    for(int i=0;i<n;i++){
        cout<<" "<<*(a+i);
    }
}

void hoan_vi(int *a, int *b){
    int temp;
    temp =*a;
    *a=*b;
    *b=temp;
    
}

void sap_tang(int *a,int n){
    for(int i=0;i<n-1;i++)
        for(int j=i+1;j<n;j++)
            if(*(a+i)>*(a+j))
                hoan_vi((a+i),(a+j));//truyen dia chi 
}

void sap_giam(int *a,int n, int dem){
    for(int i=dem;i<n-1;i++)
        for(int j=i+1;j<n;j++)
            if(*(a+i)<*(a+j))
                hoan_vi((a+i),(a+j));//truyen dia chi 
}



void sap_xep(int *a,int n){
    int dem=0;
    for(int i=0;i<n-1;i++)
        for(int j=i+1;j<n;j++)
            if(*(a+i)%2==0)
                hoan_vi((a+i),(a+j));//truyen dia chi
    for(int i=0;i<n;i++)
        if(*(a+i)%2!=0)
            dem++;
    sap_tang(a,dem);
    sap_giam(a,n,dem);
}



int main(){
    int *a,n;
    cout<<"nhap so phan tu: ";
    cin>>n;
    a=new int[n];
    nhap(a,n);
    xuat(a,n);
    sap_xep(a,n);
    xuat(a,n);

}*/

/*#include<iostream>
using namespace std;
int main(){
    int a=9;//da co vung nho, co dia chi
    //int *b;//con tro chi co dia chia, chua co vung nho de chua gia tri
    void *b;
    b = &a;//b dua vao vung nho cua a
    cout<<sizeof(b)<<endl;
    cout<<"gia tri bien con tro: "<<*(int*)b;//con tro void tro bat ki kdl nao,nhung phai ep kieu
}*/

//cap phat,giai phong vung nho
#include<iostream>
using namespace std;
int main(){

    
    //cap phat vung nho: <kieu du lieu> *<ten con tro can cap>=new<kdl>[so o nho can cap]
    int *a= new int;

}











