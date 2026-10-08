#include <bits/stdc++.h>
#define ll long long
#define Fast ios::sync_with_stdio(false),cout.tie(NULL),cin.tie(NULL);
using namespace std;
#define endl '\n'

// ==================== Graph ====================

vector<vector<pair<ll,ll>>> adj(100005);
vector<int> vis(100005);

// ==================== Dijkstra ====================

vector<ll> dist(100005,INT_MAX);

void dijkstra(int start){
    //dist , node
    priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>>pq;
    dist[start]=0;
    pq.push({0,start});

    while (!pq.empty())
    {
        auto [cur_dist,cur_node] = pq.top();
        pq.pop();

        if(cur_dist != dist[cur_node]){
            continue;
        }

        for(auto i:adj[cur_node]){//node , dist
            if(dist[cur_node] + i.second < dist[i.first]){
                dist[i.first] = dist[cur_node] + i.second;
                pq.push({dist[i.first],i.first});
            }
        }
    }
}

void solve(){
    ll n,m;
    cin >> n >> m;

    // ==================== Take Graph ====================

    for(int i = 0; i < m; i++){
        ll u,v,w;
        cin >> u >> v >> w;

        adj[u].push_back({v,w});
        adj[v].push_back({u,w}); // Comment this if graph is directed
    }

    dijkstra(1);

    for(int i = 1; i <= n; i++){
        cout << dist[i] << ' ';
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