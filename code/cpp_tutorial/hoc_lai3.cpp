//mang
/*#include<iostream>
using namespace std;
void nhap(int a[],int &n){
    cout<<"nhap so phan tu cua mang";
    cin>>n;
    for(int i=0;i<n;i++){
        cout<<"a["<<i<<"]= ";
        cin>>a[i];
    }


}
void xuat(int a[], int n){
    cout<<"mang vua nhap"<<endl;
    for(int i=0;i<n;i++){
        cout<<"a["<<i<<"]= "<<a[i]<<endl;
    }
}
int main(){
    int n;
    int a[100];
    nhap(a,n);
    xuat(a,n);
}*/

/*#include<iostream>
using namespace std;

void nhap(int a[], int &n){
    cout<<"nhap so phan tu cua mang";
    cin>>n;
    for(int i=0;i<=n;i++){
        cout<<"a["<<i<<"]= "<<endl;
        cin>>a[i];
    }
}
void xuat(int a[], int n){
    cout<<"mang da nhap"<<endl;
    for(int i=0;i<n;i++){
        cout<<"a["<<i<<"]= "<<a[i]<<endl;
    }
}
void tb_cong(int n,int a[], float &duong, float &am){
    int tong_duong=0,dem_duong=0;//dem so duong
    int tong_am=0,dem_am=0;//dem so am
    for(int i=0;i<=n;i++){
        if(a[i]>0){
            dem_duong++;
            tong_duong+=a[i];

        }
        else
            dem_am++;
            tong_am+=a[i];
    }
    if(dem_duong>0)
        duong=(float)tong_duong/dem_duong;
    else
        duong=0;
    if (dem_am>0)
        am=(float)tong_am/dem_am;
    else
        am=0;
}
int main(){
    int a[20],n;
    nhap(a,n);
    xuat(a,n);
    float am, duong;
    tb_cong(n,a,duong,am);
    if(duong>0)
        cout<<"tbc duong"<<duong<<endl;
    else
        cout<<"mang ko co so duong"<<endl;
    if(am>0)
        cout<<"tbc am"<<am<<endl;
    else
        cout<<"ko co tbc am"<<endl;
    
}*/

/*#include<iostream>
using namespace std;

void nhap(int a[],int &n, char ch){
    cout<<"so phan tu cua mang : ";
    cin>>n;
    for(int i=0;i<n;i++){
        cout<<ch<<"["<<i<<"]= ";
        cin>>a[i];
    }
}

void xuat(int a[],int n, char ch){
    cout<<"so phan tu da nhap"<<endl;
    for(int i=0;i<n;i++){
        
        cout<<ch<<"["<<i<<"]= "<<a[i]<<endl;
    }
}


void gop(int a[],int b[], int c[], int n){
    int j=0;//chi so mang c
    for(int i=0;i<n;i++){
        c[j++]=a[i];//lm truoc cong sau gan j=a[i]--->a tang j cung tang
        c[j++]=b[i];
    }

}
int main(){
    int n,a[20],b[20],c[40];
    nhap(a,n,'A');
    xuat(a,n,'A');
    nhap(b,n,'B');
    xuat(b,n,'B');
    gop(a,b,c,n);
    cout<<endl;
    xuat(c,2*n,'C');
    cout<<endl;

}*/
//sai
/*#include<iostream>
using namespace std;
void nhap(int a[],int &n){
    cout<<"so phan tu cua mang : ";
    cin>>n;
    for(int i=0;i<n;i++){
        cout<<"a["<<i<<"]= ";
        cin>>a[i];
    }
}

void xuat(int a[],int n){
    cout<<"so phan tu da nhap"<<endl;
    for(int i=0;i<n;i++){
        
        cout<<"a["<<i<<"]= "<<a[i]<<endl;
    }
}
void huy(int a[],int &n,int p){//mang chay tu a den p(diem can xoa)
    for(int i=p;i<n;i++)
        a[i]=a[i+1];//sau khi xoa phan tu trung se don len thay vi tri bi xoa
    n--;//phan tu cuoi cung trong nen xoa di
}
void xoa_trung(int a[],int &n){
    for(int i=0;i<n;i++)//ptu so 0 tim ptu con lai, trung 0 xoa
        for(int j=i+1;j<n;j++)////ptu i+1 tim ptu con lai, trung i+1 xoa
            if(a[i]==a[j])  huy(a,j,n);
                
}
int main(){
    int a[20],n;
    nhap(a,n);
    xuat(a,n);
    xoa_trung(a,n);
    cout<<"\nmang sau khi xoa: "<<endl;
    xuat(a,n);

}*/

/*#include<iostream>
using namespace std;
void nhap(int a[],int &n){
    cout<<"so phan tu cua mang : ";
    cin>>n;
    for(int i=0;i<n;i++){
        cout<<"a["<<i<<"]= ";
        cin>>a[i];
    }
}

void xuat(int a[],int n){
    cout<<"so phan tu da nhap"<<endl;
    for(int i=0;i<n;i++){
        
        cout<<"a["<<i<<"]= "<<a[i]<<endl;
    }
}

int timX(int a[],int n,int x){//x nho hon ptu sau no va lon hon phan tu trc no
    int i,dem=0;
    for (int i=0;i<n;i++){
        if (a[i]==x)
            dem++;
    }
    return dem;
}

void chen(int a[], int &n,int x){
    int i,j,p;
    //tim vi tri chen x
    for(i=0;i<n;i++){
        if(a[i]>=x)
            p=i-1;
    }
    for(j=n;j>=p;j--)
        a[j+1]=a[j];
    a[p]=x;
    n++;
}

int main(){
    int n,i,a[100],tim,x;
    cout<<"nhap so phan tu trong mang: ";
    cin>>n;
    nhap(a,n);
    cout<<"mang sau khi nhap: "<<endl;
    xuat(a,n);
    cout<<"nhap gia tri phan tu can tim";
    cin>>x;
    tim=timX(a,n,x);
    if(tim!=0){
        cout<<x<<"xuat hien"<<tim<<"lan trong mang"<<endl;
    }
    else{
        cout<<x<<"khong xuat hien lan nao trong mang"<<endl;
        cout<<"chen"<<x<<"vao mang";
    }
    
}*/

#include<iostream>
#include<math.h>
using namespace std;
void nhap(int a[],int &n){
    cout<<"so phan tu cua mang : ";
    cin>>n;
    for(int i=0;i<n;i++){
        cout<<"a["<<i<<"]= ";
        cin>>a[i];
    }
}

void xuat(int a[],int n){
    cout<<"so phan tu da nhap"<<endl;
    for(int i=0;i<n;i++){
        
        cout<<"a["<<i<<"]= "<<a[i]<<endl;
    }
}
//dem so ptu am
int dem_am(int a[],int n){
    int kq=0;
    for(int i=0;i<n;i++){
        if(a[i]<0){
            kq++;
        }
    }
    return kq;
}
//tim min, max
void min_max(int a[],int n){
    int Max=a[0], Min=a[0];
    for (int i=0;i<n;i++){
        if(a[i]>Max)
            Max=a[i];
        if(a[i]<Min)
            Min=a[i];
    }
    cout<<"phan tu max cua mang: "<<Max<<endl;
    cout<<"phan tu min cua mang: "<<Min<<endl;
}



void lke_snt(int a[], int n){
    int snt=1;
    for(int i=0;i<n;i++){
        for(int j=2;j<=sqrt(a[i]);j++){
            if (a[i]%j==0){
                snt=0;
                break;
            }
            if(snt==1){
                cout<<" "<<a[i];
            }
        }
    }
}

void so_chinh_phuong(int a[], int n){
    for(int i=0;i<n;i++){
        if(sqrt(a[i])==(int)sqrt(a[i]) )//a[i] la so chinh phuong
            cout<<" "<<a[i];
    }

}

void hoan_vi(int &a, int &b){
    
    int temp;
    a=b;
    b=temp;
}

void TangDan(int a[], int n){
    int tg;
    for(int i = 0; i < n - 1; i++){
        for(int j = i + 1; j < n; j++){
            if(a[i] > a[j]){
                // Hoan vi 2 so a[i] va a[j]
                tg = a[i];
                a[i] = a[j];
                a[j] = tg;        
            }
        }
    }
}

void GiamDan(int a[], int n){
    int tg;
    for(int i = 0; i < n - 1; i++){
        for(int j = i + 1; j < n; j++){
            if(a[i] < a[j]){
                // Hoan vi 2 so a[i] va a[j]
                tg = a[i];
                a[i] = a[j];
                a[j] = tg;        
            }
        }
    }
}

void menu(int n){
     
    cout<<"\t\t==========MENU=========\t\t\n";
    cout<<"\t\t==========CHON CHUC NANG==========\t\t\n";
    cout<<"\t\t1)Dem cac so am trong mang\t\t\n";
    cout<<"\t\t2)Tim gia tri lon nhat nho nhat cua phan tu trong mang\t\t\n";
    cout<<"\t\t3)Liet ke cac so nguyen to\t\t\n";
    cout<<"\t\t4)So chinh phuong\t\t\n";
    cout<<"\t\t5)Sap xep tang dan\t\t\n";
    cout<<"\t\t6)Sap xep giam dan\t\t\n";
    cout<<"\t\t0)Thoat!\t\t\n";
    cout<<"\t\tVui long chon: \t";

        
}
    
    
int main(){
    int a[100],n,kq,chon;
    nhap(a,n);
    cout<<"mang da nhap"<<endl;
    xuat(a,n);
    cout << "chon: " << endl;
    menu(n);
    cin >> chon;

    switch (chon)
    {
        case 1:
        {
            cout<<"so phan tu am trong mang la: "<<dem_am(a,n)<<endl;
            break;
        }
        case 2:
        {
    
            cout << "gia tri lon nhat, nho nhat trong mang" << endl;
            min_max(a,n);
            break;
        }
      
        case 3:
        {
            
            cout << "cac so nguyen to: "<<endl; 
            lke_snt(a,n);
            break;
        }
        case 4:
        {
            
            cout << "so chinh phuong: ";
            so_chinh_phuong(a,n);
            break;
        }
        case 5:
        {
            TangDan(a,n);
            cout << "sap xep tang dan" << endl;
            xuat(a,n);
            
            break;
        }
        case 6:
        {
            GiamDan(a,n);
            cout << "sap xep giam" <<endl;
            xuat(a,n);
            break;
        }
        case 0:
        {
            
            break;
        }
        
        default:
        {
            cout << "sai r nhap lai" << endl;
        }
        
    }
    cout<<"\ntam biet!!";
    return chon;    

    
}


