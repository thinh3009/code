//selecion sort
#include<iostream>
using namespace std;
void selection_sort(int a[], int n){
    for(int i=0; i<n-1;i++){
        //dung 1 bien de luu chi so cua phan tu nho nhat
        int min_pos=i;
        //duyet tat ca ptu dung sau ptu hien tai va hoan vi
        for(int j=i+1;j<n;j++){
            if(a[j]<a[min_pos]){//neu phan tu duyet nho hon ptu nho nhat thi hoan vi
                min_pos =j;
            }
        }
        swap(a[i], a[min_pos]);

    }
}
//bubble sort
void bubble_sort(int a[], int n){
    for(int i =0; i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(a[j]>a[j+1]){
                swap(a[j], a[j+1]);
            }
        }
    }
}
//insertion sort 
void insertion_sort(int a[], int n){
    for(int i =1; i<n;i++){
        //lay ra phan tu o chi so i
        int x =a[i], pos =i-1;//pos la vi tri de chen bat dau tu 0->n
        while(pos>=0 && x<a[pos]){
            a[pos +1] = a[pos];
            --pos;
        } 
        a[pos+1] = x;//ptu chen ra sau phan tu dau tien trong mang
    }
}
int main(){
    int a[100], n;
    cout<<"nhap so luong phan tu: ";
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    //selection_sort(a, n);
    //bubble_sort(a,n);
    insertion_sort(a,n);
    for(int i=0; i<n;i++){
        cout<<a[i]<<" ";

    }
    return 0;
}

