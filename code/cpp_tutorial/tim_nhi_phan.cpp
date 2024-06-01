#include<iostream>
#include<algorithm>
using namespace std;
//tim tuyen tinh
bool ls(int a[], int n, int x){
    for(int i=0;i<n;i++){
        if(a[i]==x)
            return true;

    }
    return false;
}

//binary search
bool binary(int a[], int n, int x){
    int l =0, r =n-1;
    while(l<=r){

        int m=(l+r)/2;
        if(a[m]==x){
            return true;
        }

        //neu middle nho hon x
        else if(a[m]<x){
            l = m+1;
        }
        //phai tim ben trai
        else{
            r = m -1;

        }
    }
    return false;

}

bool tim_nhiphan(int a[], int l, int r, int x){
    if(l>r)
        return false;
    int m =(l+r)/2;
    if(a[m]==x)
        return true;
    else if(a[m]<x)
        return tim_nhiphan(a, m+1, r, x);
    else    
        return tim_nhiphan(a, l, m-1, x);
}
int main(){
    int n,x;
    cout<<"nhap so luong phan tu: \n";
    cin>>n;
    cout<<"nhap phan tu can tim: ";
    cin>>x;
    int a[n];
    for(int i =0;i<n;i++){
        cout<<"nhap phan tu thu "<<i<<"\t";
        cin>>a[i];
    }
    //mang chua sap xep thi dung tim tuyen tinh
    /*if(ls(a, n, x))
        cout<<"found! \n";
    else 
        cout<<"not found!\n";*/

    //tim nhi phan
    if(binary(a, n, x))
        cout<<"found!\n";
    else
        cout<<"not found!\n";
    return 0;

    



}


