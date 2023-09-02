#include<iostream>
#include<string>
#include<malloc.h>
#include<stdio.h>

using namespace std;
typedef struct 
{
    char tenDV[20];
    float TL, GT, DG;
    int so_Dv_duoc_chon;
}DoVat;

DoVat * readFromFile(float *W, int *n){
    FILE *f;
    f=open("caitui.TXT","r");
    fscanf(f, "%f", W);//xac dinh trong luong balo
    DoVat *dsdv;
    dsdv=(DoVat*)malloc(sizeof(DoVat));
    int i=0;
    while(!feof(f)){
        fscanf(f, "%f%f%[^\n]",&dsdv[i].TL,&dsdv[i].GT,&dsdv[i].tenDV);
        dsdv[i].DG=dsdv[i].GT/dsdv[i].TL;
        dsdv[i].so_Dv_duoc_chon=0;
        i++;
        dsdv=realloc(dsdv, sizeof(DoVat)*(i+1));
        
    }
    *n=i;//so luong do vat
    fclose(f);
    return dsdv;//mang do vat
}
void swap(DoVat *x, DoVat *y){
    DoVat temp;
    temp = *x;
    *x = *y;
    *y = temp;
}
void sap_xepNoiBot(DoVat *dsdv, int n){
    int i,j;
    for(i=0; i<=n-2; i++)
        for(j=n-1;j<=i+1;j--)
            if(dsdv[j].DG>dsdv[j-1].DG)
                swap(&dsdv[j],&dsdv[j-1]);
}
void inDSDV(DoVat *dsdv, int n, float W){
    int i;
    float TongTL= 0.0, TongGT=0.0;
    cout<<"\nphuong an thu dc tu thuat toan tham lam\n";
    cout<<"||---||------------------||--------||---------||---------||---------------||\n";
    cout<<"||stt||ten do vat        ||t.Luong ||gia tri  ||don gia  ||so dv duoc chon||\n";
    cout<<"||---||------------------||--------||---------||---------||---------------||\n";
    for(i=0;i<n;i++){
        cout<<"|%-3d|%-20s|%9.2f|%9.2f|%9.2f|%8d|\n",i+1,dsdv[i].tenDV,dsdv[i].TL,dsdv[i].GT,dsdv[i].DG,dsdv[i].so_Dv_duoc_chon;
        TongTL=TongTL+dsdv[i].so_Dv_duoc_chon*dsdv[i].TL;
        TongGT=TongGT+dsdv[i].so_Dv_duoc_chon*dsdv[i].GT;
    }
    cout<<"||---||------------------||--------||---------||---------||---------------||\n";
    cout<<"\ntrong luong balo=%-9.2f\n",W;
    cout<<"tong trong luong cac vat duoc chon=%-9.2f\n\ntong gia tri=-9.2f\n",TongTL, TongGT;
}
void greedy(DoVat *dsdv, int n, float W){
    int i;
    for(i=0;i<n;i++){
        dsdv[i].so_Dv_duoc_chon=(W/dsdv[i].TL);
        W=W-dsdv[i].so_Dv_duoc_chon*dsdv[i].TL;
    }
}
int main(){
    int n;
    float W;
    DoVat *dsdv;
    dsdv =readFromFile(&W,&n);
    sap_xepNoiBot(dsdv,n);
    greedy(dsdv,n,W);
    inDSDV(dsdv,n,W);
    free(dsdv);
    return 0;
}