#include <bits/stdc++.h>
#define ll long long
#define Fast ios::sync_with_stdio(false),cout.tie(NULL),cin.tie(NULL);
using namespace std;
#define endl '\n'

// ==================== Graph ====================

vector<vector<ll>> adj(100005);
vector<int> vis(100005);

// ==================== BFS ====================

vector<int> level(100005),travel;
bool hasCycle = false;

void bfsLevel(int start){//O(n+m)
    queue<int> q;

    q.push(start);
    vis[start] = 1;
    level[start] = 0;

    while(!q.empty()){
        int cur = q.front();
        q.pop();

        travel.push_back(cur);

        for(auto i : adj[cur]){
            if(!vis[i]){
                vis[i] = 1;
                level[i] = level[cur] + 1;
                q.push(i);
            }
        }
    }
}

// ==================== Cycle Detection - Undirected ====================

vector<int> par(100005);

void bfsCycle(int start){//O(n+m)
    queue<int> q;

    q.push(start);
    vis[start] = 1;
    par[start] = -1;

    while(!q.empty()){
        int cur = q.front();
        q.pop();

        for(auto i : adj[cur]){
            if(!vis[i]){
                vis[i] = 1;
                par[i] = cur;
                q.push(i);
            }
            else if(i != par[cur]){
                hasCycle = true;
            }
        }
    }
}

// ==================== Cycle Detection - Directed ====================

vector<int> indegree(100005);

void bfsDirectedCycle(int n){//O(n+m)

    queue<int> q;

    for(int i = 1; i <= n; i++){
        if(indegree[i] == 0){
            q.push(i);
        }
    }

    int cnt = 0;

    while(!q.empty()){

        int cur = q.front();
        q.pop();

        cnt++;

        for(auto i : adj[cur]){
            indegree[i]--;

            if(indegree[i] == 0){
                q.push(i);
            }
        }
    }

    if(cnt != n){
        hasCycle = true;
    }
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