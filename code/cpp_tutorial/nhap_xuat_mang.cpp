


 //nhap mang
/*#include<iostream>
using namespace std;
void nhap(int a[], int n) {
    for (int i = 0; i < n; i++) {
        cout << "Nhap vao phan tu a[" << i << "] : ";
        cin >> a[i];
    }
}
int main(){
    int a[1000];
    int n;
    cout << "Nhap n: ";
    cin >> n;
    nhap(a, n);
    system("pause");
    return 0;
}
#include<iostream>
using namespace std;
void nhap(int a[], int n) {
    for (int i = 0; i < n; i++) {
        cout << "Nhap vao phan tu a[" << i << "] : ";
        cin >> a[i];
    }
}*/
//xuat mang
#include<iostream>
using namespace std;
void nhap(int a[], int n) {
    for (int i = 0; i < n; i++) {
        cout << "Nhap vao phan tu ";
        cin >> a[i];
    }
}

void xuat(int a[], int n) {
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
}
void chan(int a[], int n){
    int i;
    
    cout<<"day la so chan"<<endl;
    for(i=0;i<=n;i++){
        if(a[i]%2 != 0){
            cin>>a[i];
        }
    }
}
void le(int a[], int n){
    int i;
    
    cout<<"day la so le"<<endl;
    for(i=0;i<=n;i++){
        if(a[i]%2 == 0){
            cin>>a[i];
        }
    }

}
int main(){
    int a[100];
    int n;
    cout<<"nhap phan tu";
    cin>>n;
    xuat(a,n);
    nhap(a,n);
    chan(a,n);
    le(a,n);   
    return 0;
}
//bai 2
// C++ Program to Convert Lowercase Character to Uppercase
// ----codescracker.com----

/*#include<iostream>
#include<conio.h>
using namespace std;
void nhapmang(int a[],int &n);
void hienmang(int a[],int &n);
void sapxeptangdan(int a[],int n);
void sapxepgiamdan(int a[],int n);

void sapxeptangdan(int a[],int n)
{
    int temp;
    for(int i=0;i<n-1;i++)
        for(int j=i+1;j<n;j++)
    {
        if(a[i]>a[j])
            {
                a[i]=temp;
                a[i]=a[j];
                a[j]=temp;
            }
    }
}
void sapxepgiamdan(int a[],int n)
{
    int temp;
    for(int i=0;i<n-1;i++)
        for(int j=i+1;j<n;j++)
    {
        if(a[i]<a[j])
            {
                a[i]=temp;
                a[i]=a[j];
                a[j]=temp;
            }
    }
}
void nhapmang(int a[],int &n)
{
        cout<<"nhap so phan tu trong mang : ";
        cin>>n;
    for(int i=0;i<n;i++)
    {
        cout<<"phan tu thu "<<i<<"trong mang : ";
        cin>>a[i];
    }
}

void hienmang(int a[],int &n)
{
    for(int i=0;i<n;i++)
        cout<<a[i]<<"  ";
}
int main()
{
    int n;
    int a[30];
    nhapmang(a,n);
    hienmang(a,n);
    cout<<" \n sap xep tang dan"<<endl;
    sapxeptangdan(a,n);
    hienmang(a,n);
     cout<<"\n sap xep giam dan"<<endl;
    sapxepgiamdan(a,n);
    hienmang(a,n);
    getch();
}*/
/*void char *XoaTrai(char *S, char x, int pos){
	for(int i =pos-1;i>=0;i--){
		if(S[i]==x)
			strcpy(S+i,S+i+1);
	return S;
	}
}
int main(){
	char S[100]="0123456789";
	cout<<XoaTrai(S,'x',5)<<"-----";
}*/