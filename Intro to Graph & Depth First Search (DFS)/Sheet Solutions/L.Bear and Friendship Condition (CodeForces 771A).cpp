#include <bits/stdc++.h>
#define ll long long
#define Fast ios::sync_with_stdio(false),cout.tie(NULL),cin.tie(NULL);
using namespace std;
#define endl '\n'

vector<vector<ll>>adj(150005);
vector<int>vis(150005);

ll nodes,edges;

void dfs(int node){//O(n+m)

    vis[node] = 1;
    nodes++;
    edges += adj[node].size();

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

    for(int i = 1; i <= n; i++){

        if(!vis[i]){

            nodes = 0;
            edges = 0;

            dfs(i);

            edges /= 2;

            if(edges != nodes * (nodes - 1) / 2){
                cout<<"NO"<<endl;
                return;
            }
        }
    }

    cout<<"YES"<<endl;
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