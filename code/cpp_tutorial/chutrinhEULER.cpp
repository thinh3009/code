#include<iostream>
#include<bits/stdc++.h>
#include<stack>
#include<vector>
using namespace std;
using ll = long long;
int n,m;
set<int> adj[1001];
int degree[1001];
void nhap(){
    cout<<"nhap cac dinh: \n";
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int x,y;
        cin>>x>>y;
        adj[x].insert(y);
        adj[y].insert(x);
        degree[x]++;
        degree[y]++;
    }
}
void euler(int v){
    stack<int> st;
    vector<int> EC;
    st.push(v);
    while(st.empty()){
        int x=st.top();
        if(adj[x].size()!=0){
            int y = *adj[x].begin();
            st.push(y);
            //xoa x,y
            adj[x].erase(y);
            adj[y].erase(x);
        }
        else{
            st.pop();
            EC.push_back(x);
        }
    }
    reverse(begin(EC), end(EC));
    for(int x:EC)
        cout<<x<<" ";

}
int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    nhap();
    euler(1);
}