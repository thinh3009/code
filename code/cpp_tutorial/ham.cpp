/*#include <iostream>
#include<cmath> //can bac 2
using namespace std;
int so_nguyen_to(int x);
int main(){
    int x;
    cout<<"nhap so nguyen"<<endl;
    cin>>x;
    if(so_nguyen_to(x)){
        cout<<"day la so nguyen to";
    }
    else{
        cout<<"day ko la so nguyen to";
    }
    return 0;

}
int so_nguyen_to(int x){
    int i; 
    int so_nguyen_to = 1;
    
    for(int i=2;i<=(x/2);i++){
        if (i%2==0){
            so_nguyen_to =0;
            break;
        }
    }
    return so_nguyen_to;
   
}*/
/*#include <iostream>
using namespace std;

//function declaration
int isPrime(int n);

int main()
{
	int num;
	
	cout<<"Enter an integer number: ";
	cin>>num;
	
	if(isPrime(num))
		cout<<num<<" is a prime number"<<endl;
	else
		cout<<num<<" is not a prime number"<<endl;
		
	return 0;
}

//function definition
int isPrime(int n)
{
	int i;
	int prime=1;
	
	for(i=2;i<(n/2);i++)
	{
		if(n%i==0)
		{
			prime=0;
			break;
		}
	}
	return prime;
}


//bai vidu ham cho gia tri tra ve
/*#include <iostream>
using namespace std;
 
void tong(int a =3 , int b=0, int c=9  ) {
    cout << "tham so thu 1: " << a << endl;
    cout << "tham so thu 2: " << b << endl;
    cout << "tham so thu 3: " << c << endl;
    cout << "Tong: " << a+b+c << endl << endl;
    
}
 
int main()
{
    int a = 1;
    int b = 2;
    int c = 5;
    
    tong(a, b, c);
    tong();
  
 
    return 0;
}*/
#include<iostream>
using namespace std;

int main()
{
	int selection;
	do
	{
		cout << "_____Please make a selection_____" << endl;
		cout << "1/ Addition" << endl;
		cout << "2/ Subtraction" << endl;
		cout << "3/ Multiplication" << endl;
		cout << "4/ Division" << endl;

		cout << "Your selection: "; 
		cin >> selection;

		cout << "Do something with your selection here" << endl;

	}while (selection >= 1 && selection <= 4);	
        
	system("pause");
	return 0;
}