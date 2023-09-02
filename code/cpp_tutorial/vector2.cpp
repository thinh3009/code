/*#include<iostream>
using namespace std;
#include<vector>
void xuat_mang(vector<int> arr){
    for(int i=0;i<arr.size();i++){
        cout<<arr[i]<<" ";
    }
}
int main()
{
    
    int n;
    cout<<"nhap vao cac so nguyen";
    cin>>n;
    vector<int> list;
    int index;
    for(int i=0;i<n;i++){
        cin>>index;
        list.push_back(index);
    }
    xuat_mang();
}*/

#include<iostream>
using namespace std;
class Base{
    public:
    virtual void show() =0;

};
class Derived: public Base{
    public:
        void show() { cout<<"in derived";}
};
int main(void){
    Derived d;
    Base *br = &d;
    br ->show();
    return 0;
}
   
    

