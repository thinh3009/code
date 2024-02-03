/*#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int N, x[100];
void inkq(){
    for(int i=1;i<=N;i++){
        cout<<x[i];
    }
    cout<<endl;
}
void Try(int i){
    //duyet cac kha nang cua x[i]
    for(int j=0;j<=1;j++){
        x[i]=j;
        if(i==N){
            inkq();
        }
        else{
            Try(i+1);
        }
    }
}
int main(){
    freopen("input.txt", "r",stdin);
    freopen("output.txt","w",stdout);
    cin>>N;
    Try(1);
    return 0;
}*/
// #include <iostream>
// using namespace std;
// // lưu thông tin của công việc gồm ID,thời hạn, lợi nhuận 
// struct Job
// {
//     char id;
//     int thoihan;
//     int loinhuan;
// };
// // hàm này được sử dụng để sắp xếp tất cả các công việc theo lợi nhuận 
// bool comparision(Job a,Job b)
// {
//     return (a,loinhuan>b.loinhuan);
// }

// // Tạo công việc cần làm 
// void sapxepcongviec(Job arr[], int n)
// {
//     // sắp xếp tất cả các công việc theo lợi nhuận giảm dần 
//     qsort(arr,arr+n,comparision);

//     int result[n];// Lưu trình tự các công việc được sắp xếp 
//     bool slot[n]; // lưu trữ các khoảng thời gian còn trống 
    
//     // khởi tạo tất cả các vị trí đều rỗng 
//     for (int i=0; i<n,i++) {
//          slot[i] = false;
//     }
    
//     // Lặp qua tất cả các công việc đã sắp xếp
//     for (int i=0; i<n;i++ )
//     {
//         // tìm vị trí thích hợp cho từng công việc 
//         for (int j=min(n, arr[i].thoihan)-1; j>=0; j--)
//         {
//             if (slot[j]==false)
//             {
//                 result[j] = i; // thêm công việc vào chuỗi kết quả trả về
//             }
//         }
//     }   
// }
// // in kết quả trả về 
// for (int i=0;i<n; i++)
//     if (slot[i])
//        cout << arr[result[i]].id << " ";

// int man()
// {
//     Job arr[] = { {'a',9,15},{'b',2,2}, {'c',5,18},
//                 {'d',7,1},{'e',4,25},{'f',2,20},{'g',5,8}, {'h',7,10},
//                 {'k',4,12}, {'m',3,5}};
//     int n = sizeof(arr)/sizeof(arr[0]);
//     cout << "cách sắp xếp công việc cho lợi nhuận cao nhất là:" << " "; 
//     sapxepcongviec(arr, n);

//     return 0;           
// }       
// #include <iostream>
// using namespace std;
// // lưu thông tin của công việc gồm ID,thời hạn, lợi nhuận 
// struct Job
// {
//     char id;
//     int thoihan;
//     int loinhuan;
// };
// // hàm này được sử dụng để sắp xếp tất cả các công việc theo lợi nhuận 
// bool comparision(Job a,Job b)
// {
//     return (a,loinhuan>b.loinhuan);
// }

// // Tạo công việc cần làm 
// void sapxepcongviec(Job arr[], int n)
// {
//     // sắp xếp tất cả các công việc theo lợi nhuận giảm dần 
//     sort(arr,arr+n,comparision);

//     int result[n];// Lưu trình tự các công việc được sắp xếp 
//     bool slot[n]; // lưu trữ các khoảng thời gian còn trống 
    
//     // khởi tạo tất cả các vị trí đều rỗng 
//     for(int i=0; i<n,i++)
//         slot[i] = false;
    
//     // Lặp qua tất cả các công việc đã sắp xếp
//     for (int i=0; i<n;i++ )
//     {
//         // tìm vị trí thích hợp cho từng công việc 
//         for (int j=min(n, arr[i].thoihan)-1; j>=0; j--)
//         {
//             if (slot[j]==false)
//             {
//                 result[j] = i; // thêm công việc vào chuỗi kết quả trả về
//             }
//         }
//     }   
// }
// // in kết quả trả về 
// for(int i=0;i<n; i++){
//     if (slot[i])
//        cout << arr[result[i]].id << " ";
// }
// int main()
// {
//     Job arr[] = { {'a',9,15},{'b',2,2}, {'c',5,18},
//                 {'d',7,1},{'e',4,25},{'f',2,20},{'g',5,8}, {'h',7,10},
//                 {'k',4,12}, {'m',3,5}};
//     int n = sizeof(arr)/sizeof(arr[0]);
//     cout << "cách sắp xếp công việc cho lợi nhuận cao nhất là:" << " "; 
//     sapxepcongviec(arr, n);

//     return 0;           
// }       
/*#include<iostream>
using namespace std;
#define M 5
//khoi tao ban co
void (int board[][M]){
    for(int i=0;i<M; i++){
        for(int j=0;j<M;j++){
            board[i][j]=0;
        }
    }
}
//kiem tra xem vi tri (i,j) co nam trong ban co hay ko
int check(int i;int j){
    return (i>=0 && i<M && j<=0 && j<M);
}
//in ma tran 
void show(int board[][M];i++){
    for(int j=0;j<M;j++){
        cout<<board[i][j];
    }
    cout<<"\n\n";
}
void try(int step, int i, int j, int board[][M], int *I,int *J, int &OK){
    int m, inext, jnext;
    for(m=0;m<8;m++){
        inext=i+I[m];
        jnext=j+J[m];
        if (check(inext,jnext)&&board[inext][jnext]==0){
            board[inext][jnext]=step+1;//thu di toi
            if(step==M*M-1)//hoan tat
                OK=1;
            else{
                try(step+1,inext,jnext,board,I,J,OK);//di tiep
                if(!OK)
                    board[inext][jnext]=0;//tra lai trang thai cu

            }
        }
    }
}
int main(){
    int board[M][M], OK=0,i=2,j=0;//xuat phat tai dong 2 cot 0
    int I[8]={-2,-1,1,2,2,1,-1,-2};
    int J[9]={1,2,2,1,-1,-2,-2,-1};
    Init(board);
    board[i][j]=1;
    try(1,i,j,board,I,J,OK);
    cout<<"\n================\n";
    if(OK)
        show(board);
    else
        cout<<"khong co loi giai!!";
}*/
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;
int n,a[100][100];
vector<string> res;
bool check=false;
void init(){
    cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>a[i][j];
        }
    }
    res.clear();
    check=false;
}
void Try(int i, int j, string s){
    if(i==1 &&j==1&&a[i][j]==0){
        check=false;
        return;
    }
    if(i==n && j==n && a[i][j]){
        res.push_back(s);
        check=true;
        return;
    }
    if(i<n && a[i+1][j])
        Try(i+1,j,s+"D");
    if(j<n && a[i][j+1])
        Try(i,j+1,s+"R");
    if((i<n && j<n && !a[i+1][j]&& a[i][j+1])|| i>n || j>n)
        return;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        init();
        Try(1,1,"");
        if(!check)
            cout<<-1;
        else
            sort(res.begin(),res.end());
            for (int i=0;i<res.size();i++)
                cout<<res[i]<<' ';
        cout<<endl;
    }
    return 0;
    
}
 