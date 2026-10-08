#include <bits/stdc++.h>
#define ll long long
#define Fast ios::sync_with_stdio(false),cout.tie(NULL),cin.tie(NULL);
using namespace std;
#define endl '\n'

vector<vector<pair<ll,ll>>>adj(100005);
vector<int>vis(100005);
vector<ll>ans(100005);

void dfs(int node,ll val){//O(n)

    vis[node] = 1;

    for(auto [i,id]:adj[node]){

        if(!vis[i]){

            ans[id] = val;

            dfs(i,5-val);
        }
    }
}

void solve(){

    ll n;
    cin>>n;

    // Reset
    for(int i = 1; i <= n; i++){
        adj[i].clear();
        vis[i] = 0;
        ans[i] = 0;
    }

    for(int i = 1; i < n; i++){

        ll x,y;
        cin>>x>>y;

        adj[x].push_back({y,i});
        adj[y].push_back({x,i});//Undirected
    }

    // Any vertex with degree > 2 makes it impossible
    for(int i = 1; i <= n; i++){

        if(adj[i].size() > 2){
            cout<<-1<<endl;
            return;
        }
    }

    ll start = 1;

    for(int i = 1; i <= n; i++){

        if(adj[i].size() == 1){
            start = i;
            break;
        }
    }

    dfs(start,2);

    for(int i = 1; i < n; i++){
        cout<<ans[i]<<' ';
    }

    cout<<endl;
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