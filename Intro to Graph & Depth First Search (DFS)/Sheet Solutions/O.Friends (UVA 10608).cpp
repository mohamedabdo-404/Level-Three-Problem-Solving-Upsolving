#include <bits/stdc++.h>
#define ll long long
#define Fast ios::sync_with_stdio(false),cout.tie(NULL),cin.tie(NULL);
using namespace std;
#define endl '\n'

vector<vector<ll>>adj(30005);
vector<int>vis(30005);

ll cnt;

void dfs(int node){//O(n+m)

    vis[node] = 1;
    cnt++;

    for(auto i:adj[node]){
        if(!vis[i]){
            dfs(i);
        }
    }
}

void solve(){

    ll n,m;
    cin>>n>>m;

    for(int i = 1; i <= n; i++){
        adj[i].clear();
        vis[i] = 0;
    }

    for(int i = 0; i < m; i++){//Undirected

        ll x,y;
        cin>>x>>y;

        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    ll ans = 0;

    for(int i = 1; i <= n; i++){

        if(!vis[i]){

            cnt = 0;

            dfs(i);

            ans = max(ans,cnt);
        }
    }

    cout<<ans<<endl;
}

int main(){

    Fast

    ll T = 1;
    cin>>T;
    // cin.ignore();

    while(T--){
        solve();
    }
}