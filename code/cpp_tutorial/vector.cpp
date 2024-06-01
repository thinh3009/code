//vector la mang 1 chieu, chua tat ca cac kieu du lieu ke ca do ng dung dinh nghia 
//dung mang thi khai bao kich thuoc mang truoc
//vector ko can khai bao vi no tu dong them phan tu vao cuoi la "push_back()"
//vector ko can them, xoa, cai dat

//CU PHAP: vector<T> <ten vector>
//T: kieu du lieu
/*vd:
vector<int> arr; khai bao mang vector chua cac so nguyen
vector<sinh_vien> list; khai bao mang vector chua cac sinh vien
*/

#include<iostream>
#include<string>
#include<vector>
using namespace std;
//xuat mang vector
void xuat_mang(vector<int> arr){
    for(int i=0;i<arr.size();i++){
        cout<<arr[i]<<" ";
    }
}


int main(){
    vector<int> arr;
    arr.resize(5, 10);//cap phat cho mang vector chua 5 ptu, gia tri mac dinh la 10
    cout<<"mang: \n";
    xuat_mang(arr);
    //co mang vector
    /*arr.resize(3);
    cout<<"mang: ";
    xuat_mang(arr);*/
    //gian mang vector
    /*arr.resize(10);
    cout<<"\nmang: \n";
    xuat_mang(arr);*/
    system("pause");
    return 0;
}