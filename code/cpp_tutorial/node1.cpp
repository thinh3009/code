/*#include<iostream>
using namespace std;
//khai bao cau truc 1 node
struct node1
{
    int data;//du lieu chua trong 1 node
    struct node1 *pnext;//con tro dung de lien ket giua cac node voi nhau


};

typedef struct node1 NODE;
//khai bao cau truc cua dslk
struct list
{
    NODE *head;//node quan ly dau danh sach
    NODE *tail;//node quan ly cuoi ds
};
typedef struct list LIST;
//khoi tao cau truc ds lien ket don cac so nguyen

void khoi_tao(LIST &l){
    //cho 2 node null, vi chua co phan tu
    l.head=NULL;
    l.tail=NULL;
}

//ham khoi tao 1 node
NODE *khoi_taoNODE(int x){//tao node vao data theo yeu cau de bai
    NODE *p=new NODE;//cap phap vung nho cho node p
    if(p==NULL){
        cout<<"\tkhong du bo nho cap phat!!";
        return NULL;
    }
    p->data =x;//NODE la struct phai dung -> de truy xuat du lieu va truyen x vao data
    p->pnext=NULL;//
    return p;
}
//ham them node vao dau dslk

void them_dau(LIST &l, NODE *p){
    //ds dang rong
    if(l.head==NULL){
        l.head=l.tail=p;//node dau=node cuoi=p
    }
    else{
        p->pnext=l.head;//cho con tro cua node can them la p lien ket node head
        l.head=p;//cap nhat lai heaf la p 
    }
}

//ham them node p vao cuoi dslk
void them_cuoi(LIST &l, NODE *p){
    //ds dang rong
    if(l.head==NULL){
        l.head=l.tail=p;//node dau=node cuoi=p
    }
    else{
        
        l.tail->pnext=p;//cho tail lien ket voi node p
        l.tail=p; 
    }
}
//xuat dslk don
void xuatds(LIST l){
    cout<<"\ndanh sach sau khi nhap:\n";
    for(NODE *k=l.head;k!=NULL;k=k->pnext){
        cout<<k->data<<" ";
    }
}
//ham tim MAX
int tim_max(LIST l){
    int max=l.head->data;//gia su node dau la node lon nhat
    for(NODE *k=l.head->pnext;k!=NULL;k=k->pnext){//bat dau duyet tu node 2
        if(max<k->data){
            max=k->data;//cap nhat lai max
        }

    }
    return max;
}
int main(){
    LIST l;
    khoi_tao(l);//khoi tao danh sach lien ket don

    int n;
    cout<<"\nnhap so luong node can them: ";
    cin>>n;
    for(int i=1;i<=n;i++){
        int x;
        cout<<"\nnhap gia tri so nguyen: ";
        cin>>x;
        NODE *p=khoi_taoNODE(x);//khoi tao 1 node so nguyen
        them_dau(l,p);//them node p vao dau dslk don
    }
    xuatds(l);
    cout<<"\ngia tri lon nhat: "<<tim_max(l);
    
    system("pause");
    return 0;
    

}*/

#include<iostream>
using namespace std;
int n=0;//khai bao bien toan cuc
struct node{
    int data;
    struct node *pnext;

};
typedef struct node NODE;
//khai bao cau truc dslk

struct list
{
    NODE *phead;
    NODE *ptail;
};
typedef list LIST;

//khoi tao cau truc
void khoi_tao(LIST &l){
    l.phead=NULL;
    l.ptail=NULL;
}

//khoi tao 1 node
NODE *tao_node(int x)
{
    NODE *p=new NODE;
    if(p==NULL){
        cout<<"\nko du bo nho!!!!!";
        return NULL;
    }
    p->data=x;//gan gia tri cho data
    p->pnext=NULL;
    return p;
}
//them node vao dau ds
void them_dau(LIST &l,NODE *p){
    if(l.phead==NULL){
        l.phead=l.ptail=p;
    }
    else{
        p->pnext=l.phead;//dung lai con tro node p lk voi l.phead
        l.phead=p;//cap nhat lai

    }
}

//them node vao cuoi ds
void them_cuoi(LIST &l,NODE *p){
    if(l.phead==NULL){
        l.phead=l.ptail=p;
    }
    else{
        l.ptail->pnext=p;
        l.ptail=p;//cap nhat lai p

    }
}
//xuat dslk
void xuat_ds(LIST l){
    for(NODE *k=l.phead;k!=NULL;k=k->pnext){
        cout<<k->data<<" ";
    }
}
//them node p vao sau node q

void them_nodep_sauq(LIST &l,NODE *p){
    int x;
    cout<<"\nnhap gia tri node q: ";
    cin>>x;
    NODE *q=tao_node(x);
    //neu ds co 1 node thi giong nhu them ptu vao trc ds
    if(q->data==l.phead->data && l.phead->pnext==NULL){
        them_cuoi(l,p);
    }
    else{
        //duyet dau den cuoi
        for(NODE *k=l.phead;k!=NULL;k=k->pnext){
            //neu q ton tai thi
            if(q->data==k->data){
                NODE *g=k->pnext;//cho con tro g lm node trung gian tro sau q
                p->pnext=g;//tao moi lien ket giua p den node sau q
                k->pnext=p;//tao moi lien ket tu node q den node p


            }
        }
    }
}
//them node p vao truoc node q
void themp_truocq(LIST &l, NODE *p){
    int x;
    cout<<"\nnhap gia tri node q: ";
    cin>>x;
    NODE *q=tao_node(x);//khoi tao 1 node q
    //ds ton tai duy nhat 1 node va cung chinh la q thi bai toan thanh them 1 node vao ds
    if(q->data == l.phead->data && l.phead->pnext==NULL){
        them_dau(l,p);//them p vao dau

    }
    else{
        NODE *g = new NODE;//node g la node giu lien ket node q trong ds(p trc q == p sau g)
        for(NODE *k=l.phead;k!=NULL;k=k->pnext){
            if(q->data == k->data){//q ton tai thi bat dau them node p trc q
                p->pnext=k;//cho node p tro den node k
                g->pnext=p;//cho node g tro den node p
            }
            g=k;//giu lien ket voi node nam trc node q


        }
    }
}
//CACH 1
//them node p vao vi tri bat ki
// void them_p_batki(LIST &l, NODE *p, int vt,int n){//vt la vi tri can them trong node
   
//     //ds rong
//     if(l.phead==NULL || vt ==1)
//     //them node p vao dau
//     them_dau(l,p);
//     else if(vt == n+1){
//         //them vao cuoi
//         them_cuoi(l,p);
//     }
//     else{//vi tri tu [2,n]
//         int dem=0;//xac dinh vi tri can them
//         NODE *g = new NODE;//node g la node giu lien ket node q trong ds(p trc q == p sau g)
//         for(NODE *k=l.phead;k!=NULL;k=k->pnext){
//             dem++;
//             //tim vt can them
//             if(dem==vt){//q ton tai thi bat dau them node p trc q
//                 NODE *h=tao_node(p->data);//moi lan phat hien 1 node q thi tao 1 p moi
//                 p->pnext=k;//cho node p tro den node k
//                 g->pnext=p;//cho node g tro den node p
//                 break;
//             }
//             g=k;//giu lien ket voi node nam trc node q


//         }
//     }
// }

//CACH 2:dung bien toan cuc cho n
    
void them_p_batki(LIST &l, NODE *p, int vt){//vt la vi tri can them trong node
   
    //ds rong
    if(l.phead==NULL || vt ==1)
    //them node p vao dau
    them_dau(l,p);
    else if(vt == n+1){
        //them vao cuoi
        them_cuoi(l,p);
    }
    else{//vi tri tu [2,n]
        int dem=0;//xac dinh vi tri can them
        NODE *g = new NODE;//node g la node giu lien ket node q trong ds(p trc q == p sau g)
        for(NODE *k=l.phead;k!=NULL;k=k->pnext){
            dem++;
            //tim vt can them
            if(dem==vt){//q ton tai thi bat dau them node p trc q
                NODE *h=tao_node(p->data);//moi lan phat hien 1 node q thi tao 1 p moi
                p->pnext=k;//cho node p tro den node k
                g->pnext=p;//cho node g tro den node p
                break;
            }
            g=k;//giu lien ket voi node nam trc node q


        }
    }
}
//xoa dau
void xoa_dau(LIST &l ){
    if(l.phead ==NULL){
        return;
    }
    NODE *p=l.phead;//node p la node se xoa
    l.phead=l.phead->pnext;//cap nhat phead la phan tu tiep theo
    delete p;
    
}
//xoa cuoi
void xoa_cuoi(LIST &l){
    if(l.phead ==NULL){
        return;
    }
    //duyet tu dau den ke cuoi
    for(NODE *k=l.phead;k!=NULL;k=k->pnext){
        //tim ke cuoi
        if(k->pnext==l.ptail){
            delete l.ptail;//xoa ptu cuoi
            k->pnext==NULL;//cho con tro den pnext
            l.ptail=k;//cap nhat lai l.ptail
            return;

        }
    }
}

//xoa 1 node co khoa bat ki 
void xoa_node_batki(LIST &l, int x){
    //neu node can xoa nam dau ds
    if(l.phead->data==x){
        xoa_dau(l);
        return;
    }    
    if(l.ptail->data==x){
        xoa_cuoi(l);
        return;
    }
    NODE *g = new NODE;//g la node giu lien ket tro den node truc node can xoa
    //duyet dslk de tim
    for(NODE *k=l.phead;k!=NULL;k=k->pnext){
        if(k->data=x){
            
            g->pnext=k->pnext;
            delete k;
            return;
        }
        g=k;//cho node g tro den k
    }
}
//giai phong vung nho
void giai_phong(LIST &l){
    NODE *k=NULL;
    while(l.phead!=NULL){
        k=l.phead;
        l.phead=l.phead->pnext;
        delete k;
    }
}
//menu
void menu(LIST &l){
    int luachon;
    while (true)
    {
        
        cout<<"\t\t\n||============MENU=============||\n";
        cout<<"\t\t\n||1.nhap node cho danh sach----||\n";
        cout<<"\t\t\n||2.xuat danh sach lien ket don||\n";
        cout<<"\t\t\n||3.them p vao sau q-----------||\n";
        cout<<"\t\t\n||4.them p vao truoc q---------||\n";
        cout<<"\t\t\n||5.them vao vi tri bat ki-----||\n";
        cout<<"\t\t\n||6.xoa dau--------------------||\n";
        cout<<"\t\t\n||7.xoa cuoi-------------------||\n";
        cout<<"\t\t\n||8.xoa node sau node q--------||\n";
        cout<<"\t\t\n||9.xoa node co khoa k bat ki--||\n";
        cout<<"\t\t\n||0.thoat----------------------||\n";
        cout<<"\t\t\n||============END==============||\n";
        cout<<"\nnhap lua chon: ";
        cin>>luachon;
        if(luachon<0 || luachon>9){
            cout<<"nhap sai,nhap lai!!!!";
            system("pause");
        }
        else if(luachon==1){
            n++;//CACH 2
            int x;
            cout<<"\nnhap gia tri so nguyen: ";
            cin>>x;
            NODE *p=tao_node(x);//khoi tao 1 node
            them_cuoi(l,p);
        }
        else if(luachon==2){
            xuat_ds(l);
            system("pause");
        }
        else if(luachon==3){
            int x;
            cout<<"\nnhap gia tri node p can them: ";
            cin>>x;
            NODE *p=tao_node(x);
            them_nodep_sauq(l,p);
        }
        else if(luachon==4){
            int x;
            cout<<"\nnhap gia tri node p can them: ";
            cin>>x;
            NODE *p=tao_node(x);
            themp_truocq(l,p);
        }
        else if(luachon==5){
            //CACH 1
            //lap lay so node trong ds
            // int n=0;
            // for(NODE *k=l.phead;k!=NULL;k=k->pnext){
            //     n++;
            // }
            int x;
            cout<<"\nnhap gia tri cua x: ";
            cin>>x;
            NODE *p=tao_node(x);
            //nhap vi tri can them cho p
            int vt;
            do{
                cout<<"\nnhap vi tri can them node p: ";
                cin>>vt;
                if(vt<1 || vt>n+1){
                    cout<<"\nvi tri can them trong doan[1, "<<n+1<<"]";
                    system("pause");
                }

            }while(vt<1 || vt>n+1);
            //them_p_batki(l,p,vt,n);-->CÁCH 1
            them_p_batki(l,p,vt);//CÁCH 2
            n++;
        }
        else if(luachon==6){
           
            xoa_dau(l);
        }
        else if(luachon==7){
           
            xoa_cuoi(l);
        }
        // else if(luachon==8){
           
        //     int x;
        //     cout<<"\nnhap node q: ";
        //     cin>>x;
        //     NODE *q=tao_node(x);
        //     xoaq_sau(l,q);
        // }
        else if(luachon==9){
           
            int x;
            cout<<"\nnhap node can xoa: ";
            cin>>x;
            NODE *q=tao_node(x);
            xoa_node_batki(l,x);
        }
        else{
            break;
        }
    }
    
}



int main(){
    LIST l;
    khoi_tao(l);//muon co dslk luon phai khoi tao dslk trc khi thao tac
    menu(l);
    giai_phong(l);
    xuat_ds(l);
    system("pause");
    return 0;
    
}