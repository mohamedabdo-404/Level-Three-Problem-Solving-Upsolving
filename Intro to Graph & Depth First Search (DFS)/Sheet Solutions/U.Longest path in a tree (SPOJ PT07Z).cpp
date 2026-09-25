#include <bits/stdc++.h>
#define ll long long
#define Fast ios::sync_with_stdio(false),cout.tie(NULL),cin.tie(NULL);
using namespace std;
#define endl '\n'

vector<vector<ll>>adj(10005);
vector<int>vis(10005);
vector<int>level(10005);

void dfs(int node,int lvl){//O(n)

    vis[node] = 1;
    level[node] = lvl;

    for(auto i:adj[node]){

        if(!vis[i]){
            dfs(i,lvl+1);
        }
    }
}

void solve(){

    ll n;
    cin>>n;

    for(int i = 0; i < n-1; i++){//Undirected

        ll x,y;
        cin>>x>>y;

        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    dfs(1,0);

    ll farthest = 1;

    for(int i = 1; i <= n; i++){

        if(level[i] > level[farthest]){
            farthest = i;
        }
    }

    fill(vis.begin(),vis.end(),0);
    fill(level.begin(),level.end(),0);

    dfs(farthest,0);

    ll ans = 0;

    for(int i = 1; i <= n; i++){
        ans = max(ans,(ll)level[i]);
    }

    cout<<ans<<endl;
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