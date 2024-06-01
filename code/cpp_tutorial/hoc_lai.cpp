//O(log(n))
#include <iostream>
using namespace std;
long long* cmul(long long* sq1, long long* sq2)
{
    long long* ans = new long long[2];
    ans[0] = (sq1[0] * sq2[0]) - (sq1[1] * sq2[1]);
 
    ans[1] = (sq1[1] * sq2[0]) + sq1[0] * sq2[1];
 
    return ans;
}
 

long long* power(long long* x, long long n)
{
    long long* ans = new long long[2];
    if (n == 0) {
        ans[0] = 0;
        ans[1] = 0;
        return ans;
    }
    if (n == 1)
        return x;
 
    
    long long* sq = power(x, n / 2);
    if (n % 2 == 0)
        return cmul(sq, sq);
    return cmul(x, cmul(sq, sq));
}
 

int main()
{
    int n;
    long long* x = new long long[2];
 
    x[0] = 18;
 
    x[1] = -13;
    n = 1000000 ;
 
    long long* a = power(x, n);
    cout << a[0] << " + i ( " << a[1] << " )" << endl;
 
    return 0;
}
//O(n)
#include <iostream>
using namespace std;

int main(){
   int i;
   int n;
   int s;
   cout<<"nhap n= ";
   cin>>n;
   
for (i= 1;i<=n;i++)

            s=s+i;
    
	return 0;
}

//O(n^2)
#include <iostream>
using namespace std;

int main(){
int n;
cout<<"nhap n= ";
cin>>n;
for (int i = 0; i < n; i++)
for (int j = 0; j < n; j++)
cout << i << " " << j << endl;
}
