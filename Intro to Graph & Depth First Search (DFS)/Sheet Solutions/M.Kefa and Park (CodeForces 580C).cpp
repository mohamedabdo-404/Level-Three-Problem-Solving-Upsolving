#include <bits/stdc++.h>
#define ll long long
#define Fast ios::sync_with_stdio(false),cout.tie(NULL),cin.tie(NULL);
using namespace std;
#define endl '\n'

vector<vector<ll>>adj(100005);
vector<int>vis(100005);
vector<int>cat(100005);

ll n,m;
ll ans = 0;

void dfs(int node,int cnt){//O(n+m)

    vis[node] = 1;

    if(cat[node]){
        cnt++;
    }
    else{
        cnt = 0;
    }

    if(cnt > m){
        return;
    }

    bool leaf = true;

    for(auto i:adj[node]){

        if(!vis[i]){

            leaf = false;
            dfs(i,cnt);
        }
    }

    if(leaf){
        ans++;
    }
}

void solve(){

    cin>>n>>m;

    for(int i = 1; i <= n; i++){
        cin>>cat[i];
    }

    for(int i = 0; i < n-1; i++){//Undirected

        ll x,y;
        cin>>x>>y;

        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    dfs(1,0);

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