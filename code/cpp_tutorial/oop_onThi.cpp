#include<iostream>
using namespace std;
class parent{
    protected:
        int data;
    public:
        parent(){data =3;}
        int product() {return data*data}
        

        
};
class child: public parent{
    public:
        child()
}




int main(){
    int number =2;
    classA obj;
    number++;
    obj.number +=2;
    classA::number +=1;
    cout<<obj.number<<endl;
    return 0;
}