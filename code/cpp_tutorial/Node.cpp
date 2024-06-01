#include<iostream>
using namespace std;
  
typedef int item; //kieu item la kieu nguyen
struct Node
{
     item key; //truong key cua du lieu
     Node *Left, *Right; //con trai va con phai
};
typedef Node *Tree;  //cay
  
int insertNode(Tree &T, item x) // chen 1 Node vao cay
{
    if (T != NULL)
    {
        if (T->key == x) return -1;  // Node nay da co
        if (T->key > x) return insertNode(T->Left, x); // chen vao Node trai
        else if (T->key < x) return insertNode(T->Right, x);   // chen vao Node phai
    }
    T = (Node *) malloc(sizeof(Node));
    if (T == NULL) return 0;    // khong du bo nho
    T->key = x;
    T->Left = T->Right = NULL;
    return 1;   // ok
}
  
void CreateTree(Tree &T)        // nhap cay
{
    int x;
    while (1)
    {
        cout<<"Nhap vao Node: ";
        cin>>x;
        if (x == 0) break;  // x = 0 thi thoat
        int check = insertNode(T, x);
        if (check == -1) cout<<"Node da ton tai!";
        else if (check == 0) cout<<"Khong du bo nho";
  
    }
}
  
// Duyet theo LNR

void LRN(Tree T){
    if(T!=NULL){
        LRN(T->Left);
        LRN(T->Right);
        cout<<"   "<<T->key;
    }
}
  

  
  
int main()
{
    Tree T;
    T=NULL; //Tao cay rong
  
    CreateTree(T); //Nhap cay
    //duyet cay
    cout<<"Duyet cay theo LNR: \n";
    LRN(T);
    printf("\n");
  
    Node *P;
    
    cout<<"Duyet cay theo LRN: \n";
    LRN(T);
    cout<<"\n";
    return 0;
}