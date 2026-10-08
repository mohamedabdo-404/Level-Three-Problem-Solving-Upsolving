#include <bits/stdc++.h>
#define ll long long
#define Fast ios::sync_with_stdio(false),cout.tie(NULL),cin.tie(NULL);
using namespace std;
#define endl '\n'

vector<vector<ll>>adj(100005);
vector<int>vis(100005);

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

    vector<ll>roots;

    for(int i = 1; i <= n; i++){

        if(!vis[i]){

            roots.push_back(i);

            dfs(i);
        }
    }

    cout<<roots.size()-1<<endl;

    for(int i = 1; i < roots.size(); i++){

        cout<<roots[i-1]<<' '<<roots[i]<<endl;
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