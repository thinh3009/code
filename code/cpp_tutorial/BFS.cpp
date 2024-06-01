// 10 11 (so dinh va canh)
// 1 2
// 1 3
// 1 5
// 1 10
// 2 4
// 3 6
// 3 7
// 3 9
// 6 7
// 5 8
// 8 9
#include<iostream>
#include<queue>
#include<vector>
using namespace std;

int n, m;
vector<int>adj[1001];
bool visited[100];
void input(){
    cin>>n>>m;
    for (int i=0;i<m;i++){
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
        //do thi co huong thi dung
        adj[y].push_back(x);

    }
    memset(visited,false,sizeof(visited));
}
void bfs(int u){
    //buoic khoi tao
    queue<int>q;
    q.push(u);
    visited[u]=true;
    //buoc lap
    while(!q.empty()){
        int v=q.front();//lay dinh dau hang doi
        q.pop();
        cout<<v<<" ";
        for(int x:adj[v]){
            if(!visited[x]){
                q.push(x);
                visited[x]=true;
            }
        }
    }
}
int main(){
    cout<<"nhap gia tri: \n";
    input();
    bfs(1);
    return 0;
}