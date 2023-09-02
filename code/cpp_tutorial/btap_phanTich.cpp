//bai 1
#include <iostream>
using namespace std;
int fact(int num);
int main()
{
    int n, r, var;
  
    cout<<"nhap so luong can r: ";
    cin>>r;
    cout<<"\nso luong dia n: ";
    cin>>n;
    var = fact(n) / fact(n - r);
    cout<<"so cach dua can len dia la: "<<var;
    cout<<"\n-----------------------------------\n";
    
}
int fact(int num)
{
    int k = 1, i;
    // factorial of 0 is 1
    if (num == 0)
    {
        return(k);
    }
    else
    {
        for (i = 1; i <= num; i++)
    {
            k = k * i;
    }
    }
    return(k);
}
//bai 2
