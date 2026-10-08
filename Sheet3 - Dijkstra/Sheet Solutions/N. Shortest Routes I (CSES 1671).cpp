#include <bits/stdc++.h>
#define ll long long
#define Fast ios::sync_with_stdio(false),cout.tie(NULL),cin.tie(NULL);
using namespace std;
#define endl '\n'

vector<vector<pair<ll,ll>>>adj(100005);
vector<ll>dist(100005,LLONG_MAX);

void dijkstra(int start){//O((n+m)log n)
    priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>>pq;
    dist[start]=0;
    pq.push({0,start});

    while(!pq.empty()){
        auto[cur_dist,cur_node]=pq.top();pq.pop();
        if(cur_dist!=dist[cur_node]) continue;

        for(auto[nb,w]:adj[cur_node]){
            if(dist[cur_node]+w<dist[nb]){
                dist[nb]=dist[cur_node]+w;
                pq.push({dist[nb],nb});
            }
        }
    }
}

void solve(){
    ll n,m;
    cin>>n>>m;

    for(int i=0;i<m;i++){
        ll u,v,w;
        cin>>u>>v>>w;
        adj[u].push_back({v,w}); // directed
    }

    dijkstra(1);

    for(int i=1;i<=n;i++) cout<<dist[i]<<' ';
    cout<<endl;
}

int main(){
    Fast

    ll T=1;
    // cin>>T;
    // cin.ignore();

    while(T--){
        solve();
    }
}
