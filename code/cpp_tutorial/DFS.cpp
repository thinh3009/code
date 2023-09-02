// 9 9
// 1 2
// 1 3
// 1 5
// 2 4
// 3 6
// 3 7
// 3 9
// 5 8
// 8 9
#include<vector>
#include<iostream>
using namespace std;
//so dinh n so canh m
int n,m;
vector<int> adj[1001];
bool visited[1001];
void input(){
    cin>>n>>m;
    for (int i=0;i<m;i++){
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
        //do thi co huong thi bo cai duoi
        adj[y].push_back(x);
    }
    memset(visited, false,sizeof(visited));
}
void dfs(int u){
    cout<<u<<" ";
    //danh dau u da dc them
    visited[u]=true;
    for(int v:adj[u]){
        //neu dinh v chua dc tham
        if(!visited[v])
            dfs(v);
    }
}
int main(){
    cout<<"nhap gi tri: \n";
    input();
    dfs(1);
}