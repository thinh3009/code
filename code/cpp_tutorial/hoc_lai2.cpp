/*#include<iostream>
using namespace std;
int max(int a , int b ){
    if (a>b)
        return a;
    else
        return b;
}

int main(){
    int x,y,lon;
    cout<<"nhap a";
    cin>>x;
    cout<<"nhap b";
    cin>>y;
    lon = max(x,y);
    cout<<"gia tri lon nhat"<<lon;
}*/

/*#include<iostream>
using namespace std;
int ktra(int n);
int xuat(int n);
int tong_snt(int n);
int main(){
    int n,tong=0;
    cout<<"nhap so nguyen n: ";
    cin>>n;
    xuat(n);
    tong=tong_snt(n);
    cout<<"tong cac so nguyen to tu 2 den n: "<<tong<<endl;

}
int ktra(int n ){
    int dem=0;
    for(int i=1;i<=n;i++){
        if(n%i==0)
            dem++;
    }
    if(dem==2)
        return 1;
    else    
        return 0;
    
}
int xuat(int n)
{
    for(int i=1;i<=n;i++)
        if(ktra(i)==1)
            cout<<" "<<i<<endl;
    
}
int tong_snt(int n)
{
    int tong=0;
    for (int i=1;i<=n;i++)
        if(ktra(i)==1)
            tong+=i;
        
    return tong;

    
}*/
//boi chung nn lay tich 2 so chia uoc chung lon nhat 2 so
/*#include<iostream>
using namespace std;
int uoc_chungln(int m,int n);
int boi_chungnn(int m, int n);
int main(){
    int a,b,tich,boichungnn;
    cout<<"nhap m";
    cin>>a;
    cout<<"nhap n";
    cin>>b;
    uoc_chungln(a,b);
    tich=a*b;
    boichungnn=tich/uoc_chungln(a,b);
    cout<<"boi chung nho nhat cua m va n: "<<boichungnn<<endl;

}
int uoc_chungln(int m ,int n ){
    while(n!=0,m!=0){
        if(n>m)
            n-=m;
        else
            m-=n;
    }
    if(n==0)
        return m;
    else    
        return n;


}
int boi_chungnn(int m ,int n){
    int boichung,tich;
    tich=m*n;
    boichung=tich/uoc_chungln(m,n);
    return boichung;
    
}*/
//bi sai
/*#include<iostream>
using namespace std;
int ktra(int);

int main(){
    int n,i;
    int tong =0;
    do{
        cout<<"nhap n: ";
        cin>>n;
        if(ktra(i)==1)
            tong+=i;
    }
    while(n!=0);
    cout<<"tong cac so chinh phuong: "<<tong_scp(n);
    return tong;
    
}

int ktra(int n){
    if ((int)sqrt(n)==sqrt(n))
        return 0;
    else
        return 1;
}*/

/*#include<iostream>
using namespace std;
int GT(int n)
{
if(n==0)
return 1;
else
return n*GT(n-1);
}
int main(){
    int a,n;
    int giai_thua=0;
    cout<<"nhap n: ";
    cin>>a;
    giai_thua=GT(a);
    cout<<"n!"<<giai_thua;
}*/

/*#include<iostream>
using namespace std;
int f1(int);
int f2(int);
float f3(int);
float f4(int);
int main(){
    int n,tong1,tong2,tong3,tong4;
    cout<<"nhap n:"<<endl;
    cin>>n;
    
    
    cout<<"tong cua f1: "<<f1(n)<<endl;
    
    cout<<"tong cua f2: "<<f2(n)<<endl;
    
    cout<<"tong cua f3: "<<f3(n)<<endl;
    
    cout<<"tong cua f4: "<<f4(n)<<endl;

}
int f1(int n){
    int tong;
    for(int i=1;i<=n;i++){
        tong=tong+i;
    }
    return tong;
}
int f2(int n)
{
    int tong=0;
    for(int i=1;i<=n;i++){
        if(i%2==1)
            tong+=i;
    
    } 
    return tong;
}  
float f3(int n){
    float tong=0;
    for(int i=1;i<=n;i++){
        tong+=1/i;
    } 
    return tong;
}

float f4(int n){
    float tong=0;
    for(int i=1;i<=n;i++){
        if(i%2==1)
            tong+=1/i;
        else
            tong-=1/i;
    } 
    return tong;
}
*/
#include<iostream>
#include<math.h>
using namespace std;
void ktra_snt(int n){
    int dem=0;
    for(int i=1;i<=n;i++){
        if(n%i==0)
            dem++;
        if(dem%i==1)
        
    }
    
}

void ktra_shh(int n){
    int tong=0;
    for(int i=1;i<=n;i++){
        if(n%i==0)
            tong+=i;
    }
    if(tong==n)
        return 1;
    else
        return 0;


}

void menu(int n){
    cout<<"\n========MENU========\n"<<endl;
    cout<<"\n1.Ktra so nguyen to\n"<<endl;
    cout<<"\n2.Ktra so hoan hao\n"<<endl;
    cout<<"\n3.Xem menu\n"<<endl;
    cout<<"\n0.Thoat\n"<<endl;

}
int main()
{
    int n,chon;
    
    cout<<"\nchon chuc nang\n"<<endl;
    menu(n);
    cin>>chon;
    switch (chon)
    {
        case 1:
            int snt;
            cout<<"nhap so nguyen: ";
            cin>>snt;
            if(ktra_snt(snt)){

                cout<<snt<<"day la so nguyen to";
            }
            else{
                cout<<snt<<"day ko la so nguyen to";
            }
            break;
        
        case 2:
            int shh;
            cout<<"nhap so nguyen: ";
            cin>>shh;
            if(ktra_shh(shh)){
                cout<<shh<<"day la so hoan hao"<<endl;
            }
            else{
                cout<<shh<<"day ko la so hoan hao"<<endl;
            }
            
            break;
        case 3:
            char ds;
            cout<<"danh sach da xuat: "<<endl;
            menu(ds);
            break;
        case 0:
            break;
            
    }
    cout<<"tam biet!!";
    return 0;
    
    
}
