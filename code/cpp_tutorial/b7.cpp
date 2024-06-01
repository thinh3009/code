#include<iostream>
using namespace std;
struct Phan_so
{
    float tu_so;
    float mau_so;
};
typedef Phan_so PHANSO;
struct node{
    PHANSO data;
    node *next;
    node *pre;//tro nguoc lai ptu

};
typedef node NODE;
struct dlist
{
    NODE *head;
    NODE *tail;
};
typedef dlist DLIST;
void khoitao_ds(DLIST &l){
    l.head=NULL;
    l.tail=NULL;
}
void nhapPs(PHANSO ps, DLIST& l){
    cout<<"\tnhap phan so: ";
    cout<<"\n\ttu so: ";
    cin>>ps.tu_so;
    cout<<"\n\tnhap mau so: ";
    cin>>ps.mau_so;
}
NODE* tao_node(DLIST &l){
    PHANSO *ps=new PHANSO;
    nhapPs(ps,l);
    NODE* p= new NODE;
    if(p==NULL){
        cout<<"khong du bo nho!!";
        return 0;
    }
    p->data = ps;
    p->next=NULL;
    p->pre=NULL;
    return p;
}
void adHead(DLIST &l, NODE* p){
    if(l.head==NULL){
        l.head=l.tail=p;
    }
    else{
        NODE *p=tao_node(l);
        p->next=l.head;
        l.head->pre=p;
        l.head=p;
    }
    
}
void xuat(DLIST l){
    NODE *k=l.head;
    if(k==NULL){
        cout<<"\tkhong du bo nho!!";
    }
    for(NODE* k=l.head; k!=NULL;k=k->next){
        cout<<"\n\ttu so: "<<k->data.tu_so;
        cout<<"\n\tmau so: "<<k->data.mau_so;
        cout<<"\n\tphan so la: "<<k->data.tu_so<<"/"<<k->data.mau_so<<endl;
    }

    
}
// void left_to_right(const DLIST l){
//     NODE *p=l.head;
//     while(p!=NULL){
//         cout<<p->data<<"\t";
//         p=p->next;
//     }
// }


int main(){
    PHANSO ps;
    DLIST l;
    khoitao_ds(l);

    NODE *p= tao_node(l);
    while(1){
        nhapPs(ps,l);
        if(ps.tu_so==0 && ps.mau_so==0){
            break;
        }
        adHead(l,p);
    }
    xuat(l);

    
}