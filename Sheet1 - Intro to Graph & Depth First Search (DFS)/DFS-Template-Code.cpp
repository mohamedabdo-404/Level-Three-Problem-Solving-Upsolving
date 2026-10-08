#include <bits/stdc++.h>
#define ll long long
#define Fast ios::sync_with_stdio(false),cout.tie(NULL),cin.tie(NULL);
using namespace std;
#define endl '\n'

// ==================== Graph ====================

vector<vector<ll>> adj(100005);
vector<int> vis(100005);

// ==================== DFS ====================

void dfs(int node){//O(n+m)
    vis[node] = 1;

    for(auto i : adj[node]){
        if(!vis[i]){
            dfs(i);
        }
    }
}

// ==================== Cycle Detection - Undirected ====================

bool hasCycle = false;

void dfs1(int node,int p){//O(n+m)
    vis[node] = 1;

    for(auto i : adj[node]){
        if(!vis[i]){
            dfs1(i,node);
        }
        else if(i != p){
            hasCycle = true;
        }
    }
}

// ==================== Cycle Detection - Directed ====================

vector<int> ans;

void dfs2(int node){//O(n+m)
    vis[node] = 2;

    for(auto i : adj[node]){
        if(!vis[i]){
            dfs2(i);
        }
        else if(vis[i] == 2){
            hasCycle = true;
        }
    }

    vis[node] = 1;
    ans.push_back(node);
}

// ==================== DFS on 2D Array ====================

ll m,n;
char a[305][305];
bool vis2D[305][305];

void dfs2D(int i,int j){//O(m*n)

    vis2D[i][j] = true;

    // Up
    if((i-1) >= 0 && !vis2D[i-1][j] && a[i-1][j] == '1')
        dfs2D(i-1,j);

    // Down
    if((i+1) < m && !vis2D[i+1][j] && a[i+1][j] == '1')
        dfs2D(i+1,j);

    // Right
    if((j+1) < n && !vis2D[i][j+1] && a[i][j+1] == '1')
        dfs2D(i,j+1);

    // Left
    if((j-1) >= 0 && !vis2D[i][j-1] && a[i][j-1] == '1')
        dfs2D(i,j-1);
}

void solve(){
    ll n,m;
    cin >> n >> m;

    // ==================== Take Graph ====================

    for(int i = 0; i < m; i++){
        ll u,v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u); // Comment this if graph is directed
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