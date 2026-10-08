#include <bits/stdc++.h>
#define ll long long
#define Fast ios::sync_with_stdio(false),cout.tie(NULL),cin.tie(NULL);
using namespace std;
#define endl '\n'

vector<vector<ll>>adj(105);
vector<int>vis(105);

void dfs(int node){//O(n+m)

    vis[node] = 1;

    for(auto i:adj[node]){
        if(!vis[i]){
            dfs(i);
        }
    }
}

void solve(){

    ll n,m;
    cin>>n>>m;

    for(int i = 0; i < m; i++){//Undirected

        ll x,y;
        cin>>x>>y;

        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    dfs(1);

    for(int i = 1; i <= n; i++){

        if(!vis[i]){
            cout<<"NO"<<endl;
            return;
        }
    }

    if(m == n){
        cout<<"FHTAGN!"<<endl;
    }
    else{
        cout<<"NO"<<endl;
    }
}

int main(){

    Fast

    ll T = 1;
    // cin >> T;
    // cin.ignore();

    while(T--){
        solve();
    }
}